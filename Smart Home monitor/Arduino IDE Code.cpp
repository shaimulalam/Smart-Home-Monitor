#include <DHT.h>

// Define Pins
#define DHTPIN 2
#define DHTTYPE DHT11

#define ledPin 4
#define buzzerPin 10
#define irPin 6
#define trigPin 7
#define echoPin 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(irPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  //  Read DHT11
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();


  // Read IR Sensor
  int obstacleDetected = !digitalRead(irPin);

  // Read Ultrasonic Sensor
  long duration, distance;
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // cm

  // Print Sensor Values
  Serial.println("---- Sensor Readings ----");
  Serial.print("Temp: "); Serial.print(temperature); Serial.print("°C  ");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println("%");
  Serial.print("IR Obstacle: "); Serial.println(obstacleDetected);
  Serial.print("Distance: "); Serial.print(distance); Serial.println(" cm");
  Serial.println();

 

  //  IR Gesture Detected
  if (obstacleDetected == HIGH) {  // LOW = Obstacle Detected
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin,HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin,LOW);
  }

  // Object closer than 20 cm? Trigger Buzzer
  if (distance < 20) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin,HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin,LOW);
  }
//if temperature
if (temperature > 40){
digitalWrite(ledPin,HIGH);
digitalWrite(buzzerPin,HIGH);
delay(500);
digitalWrite(ledPin,LOW);
digitalWrite(buzzerPin,LOW);
}

  delay(1000);
}