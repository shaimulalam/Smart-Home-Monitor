# Smart-Home-Monitor
Built My First Smart Home Monitor Using Arduino! 💡

Last night, I had a random but exciting thought — what if I combined all the sensors I currently have and made them work together using the Arduino IDE? I grabbed my components and got to work!

🧰 Components Used:

DHT11 (Temperature & Humidity Sensor)

HC-SR04 (Ultrasonic Sensor)

Flying Fish (IR Obstacle Sensor)

Microphone Module

LED + Buzzer for outputs

I named the mini project “Smart Home Monitor” (Yes, I know — quite the name 😄).

I placed the sensors on a breadboard, connected VCC to 5V, GND to GND, and the rest to digital pins (PWM where applicable). Then I added an LED and a buzzer to signal when specific conditions were met.

💻 Main Features:

If an object comes within 20 cm of the ultrasonic sensor, the buzzer beeps.

If the temperature exceeds 40°C and the IR sensor detects an obstacle, the buzzer and LED are triggered.

Sounds smooth, right? Well… not really 😅

At first, the alarm kept ringing for no reason — even when no conditions were met.
After checking the Serial Monitor, I realized the microphone was constantly detecting ambient sounds and sending HIGH signals to the Arduino. Since the 2-pin mic only detects digital signals, any tiny noise would trigger the buzzer. I removed the mic and its code.

🥲 Problem solved? Not yet.

The IR sensor started acting up — constantly detecting obstacles when there were none! After some debugging, I discovered that the sensor was returning values in reverse. I fixed it with a simple ! (NOT) operator in the code, and voilà — it worked perfectly.

✨ Lesson Learned:
Sensor behavior isn’t always straightforward. Hardware quirks can cause confusing bugs, and it takes some digging (and occasional help from ChatGPT 😄) to get things running smoothly.

⚙️ Note: The code doesn’t run on Tinkercad due to missing DHT library support — but it works flawlessly on the Arduino IDE.

Proud of how this turned out — a simple but insightful learning experience on integrating multiple sensors and troubleshooting unexpected behavior.

If you have any insights about why the IR sensor behaved in reverse, I’d love to hear your thoughts!
