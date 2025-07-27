# Quadruped Robot with ESP8266 WiFi Control 🤖📶

[![ESP8266](https://img.shields.io/badge/ESP8266-NodeMCU-red)](https://www.espressif.com/en/products/socs/esp8266)
[![Arduino](https://img.shields.io/badge/Arduino%20IDE-Compatible-blue)](https://www.arduino.cc/)
[![License](https://img.shields.io/badge/License-MIT-green)](https://opensource.org/licenses/MIT)

![Quadruped Robot](https://via.placeholder.com/800x400.png?text=Robot+Demo) <!-- Replace with actual image URL -->

A WiFi-controlled quadruped robot built using NodeMCU ESP8266 and servo motors. Controlled through a mobile-friendly web interface with real-time movement commands.

## Features ✨

- **Wireless Control** - WiFi-based control via web interface
- **Mobile Responsive** - Works on any smartphone/tablet
- **Four-Legged Mobility** - Omnidirectional movement capabilities
- **Simple Construction** - Built with accessible materials (ice cream sticks)
- **Low Power Consumption** - Efficient motor control system
- **Access Point Mode** - Creates its own WiFi network for direct control

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

![Wiring Diagram](https://via.placeholder.com/400x300.png?text=Wiring+Diagram) <!-- Replace with actual diagram URL -->

## Installation & Setup ⚙️

### 1. Arduino IDE Configuration
1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Add ESP8266 board support:
   - Go to `File > Preferences`
   - Add to Additional Boards Manager URLs:
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
3. Install ESP8266 boards package:
   - `Tools > Board > Boards Manager`
   - Search for "esp8266" and install

### 2. Upload Code to NodeMCU
1. Connect NodeMCU via USB
2. Select board:
   - `Tools > Board > NodeMCU 1.0 (ESP-12E Module)`
3. Select correct COM port
4. Upload the robot control sketch

### 3. Required Libraries
The project uses these built-in libraries:
- `ESP8266WiFi.h`
- `ESP8266WebServer.h`
- `Servo.h`

## Usage Instructions 🎮

1. Power on the robot
2. Connect to its WiFi network:
   - SSID: `Quadruped_Robot`
   - Password : please refer to your sketch (.ino) 
3. Open web browser to:
