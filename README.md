# Quadruped Robot with ESP8266 WiFi Control 🤖📶

[![ESP8266](https://img.shields.io/badge/ESP8266-NodeMCU-red)](https://www.espressif.com/en/products/socs/esp8266)
[![Arduino IDE](https://img.shields.io/badge/Arduino%20IDE-Compatible-blue)](https://www.arduino.cc/)
[![License](https://img.shields.io/badge/License-MIT-green)](https://opensource.org/licenses/MIT)

![Quadruped Robot]

A WiFi-controlled quadruped robot built using NodeMCU ESP8266 and servo motors. The robot is operated via a mobile-friendly web interface, enabling real-time movement commands and omnidirectional control. Designed for educational and prototyping purposes with simple construction and low power requirements.

---

## Features ✨
- **Wireless Control** – Direct WiFi access point, no router required
- **Mobile Responsive** – Optimized for smartphones and tablets
- **Omnidirectional Movement** – Four-legged walking and turning
- **Simple Construction** – Built with ice cream sticks and basic components
- **Low Power Consumption** – Efficient servo control
- **Plug & Play** – No app installation needed, just a browser

## Hardware Requirements 🛠️

| Component          | Quantity | Notes                          |
|--------------------|----------|--------------------------------|
| NodeMCU ESP8266    | 1        | Main controller board          |
| Micro Servo Motors | 4        | SG90 or equivalent             |
| Ice Cream Sticks   | 10-15    | For body structure             |
| Jumper Wires       | 10+      | For connections                |
| 5V Power Supply    | 1        | Battery pack or USB power bank |
| Breadboard         | 1        | Optional for prototyping       |

## Wiring Diagram 🔌

| Servo | Function      | GPIO Pin | NodeMCU Label |
|-------|---------------|----------|---------------|
| s1    | Front Left    | D1       | GPIO5         |
| s2    | Front Right   | D2       | GPIO4         |
| s3    | Back Left     | D5       | GPIO14        |
| s4    | Back Right    | D6       | GPIO12        |

![Wiring Diagram](https://raw.githubusercontent.com/danial-blackhat/esp8266-quadruped-robot/main/docs/wiring-diagram.png) <!-- Replace with actual diagram URL -->

---

## Installation & Setup ⚙️

### 1. Arduino IDE Configuration
- Download and install the [Arduino IDE](https://www.arduino.cc/en/software)
- Add ESP8266 board support:
  - Go to `File > Preferences`
  - Add to Additional Boards Manager URLs:
    ```
    http://arduino.esp8266.com/stable/package_esp8266com_index.json
    ```
  - Open `Tools > Board > Boards Manager`, search for "esp8266" and install

### 2. Upload Code to NodeMCU
- Connect NodeMCU via USB
- Select board: `Tools > Board > NodeMCU 1.0 (ESP-12E Module)`
- Select correct COM port
- Upload the robot control sketch (`.ino` file)

### 3. Required Libraries
- `ESP8266WiFi.h`
- `ESP8266WebServer.h`
- `Servo.h`

---

## Usage Instructions 🎮

1. Power on the robot
2. Connect to its WiFi network:
   - SSID: `Quadruped_Robot`
   - Password: (see your sketch for details)
3. Open a web browser and go to: `http://192.168.4.1`
4. Use the web interface to control movement and actions

---

## Project Notes
- All control is local; no internet or cloud required
- Designed for learning, prototyping, and demonstration
- Construction can be customized with available materials

## License
This project is licensed under the MIT License.

---

> Developed by Wan Muhammad Danial. For questions or collaboration, contact via GitHub.
