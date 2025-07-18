//---------------------------------------------------------------------------------------------------//

 Quadruped Robot with NodeMCU ESP8266 (WiFi Remote Control)
A simple yet functional four-legged spider robot built using ice cream sticks, 4 servo motors, and a NodeMCU ESP8266. 
Controlled via a mobile-friendly web interface over WiFi, including direction buttons.


🖥️ How to Upload Code? 
Install Arduino IDE

Add ESP8266 board manager via URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json

Install Required Libraries

ESP8266WiFi.h (included with ESP8266 board)

Connect and Upload

Choose correct board: NodeMCU 1.0 (ESP-12E Module)

Select COM port

Click Upload

//---------------------------------------------------------------------------------------------------//

🔌 Wiring Reference (Servo Pins)
Servo	Function	GPIO Pin	   NodeMCU Label
s1	Front Left	   D1	               GPIO5
s2	Front Right	   D2	               GPIO4
s3	Back Left	   D5	              GPIO14
s4	Back Right	   D6	              GPIO12

//---------------------------------------------------------------------------------------------------//


Access Web Interface
Connect your device to the robot’s WiFi hotspot (e.g., "Quadruped_Robot")

Open browser and go to:
http://192.168.4.1

Use the on-screen buttons to move the robot.


//---------------------------------------------------------------------------------------------------//


Created By
Wan Muhammad Danial
Freelance IT Technician & Embedded Systems Developer
Email : mrdanial2791@outlook.my
