# Flask_RelayNet-iot

## ESP32 Relay Control System

Flask-Based IoT Remote Switching System

## Overview

This project is an IoT-based relay control system that allows users to remotely control electrical devices using an ESP32 and a Flask web server.

The ESP32 connects to WiFi and continuously communicates with the Flask backend to receive the current relay state. A web interface allows users to turn the relay ON or OFF, enabling remote control of devices such as lights, fans, or pumps.

## Features
Remote relay control using web interface
ESP32 to Flask communication using HTTP requests
Simple and responsive control system
WiFi-enabled device switching
Lightweight and easy to deploy
Suitable for home automation and IoT learning

## Technologies Used

ESP32
Arduino (C++) /vs code
Python (Flask)
HTML, CSS, JavaScript
HTTP Protocol

## Project Structure

Flask_RelayNet-iot/
│
├── src/main.cpp
├── app.py
├── templates/
│   └── index.html
└── README.md

## Hardware Requirements
ESP32
Relay Module
Jumper Wires
Power Supply

## Circuit Connections
ESP32 Pin ---->Relay Module
GPIO 23------>IN
GND---------->GND
5V /3.3V----> VCC

## Setup Instructions
1. ESP32 Setup
Connect relay module to ESP32
Update WiFi credentials in the code
Update server IP address
Upload code using Arduino IDE or PlatformIO

3. Flask Server Setup

Install Flask:

pip install flask

Run the server:

python app.py

Server runs at:

http://0.0.0.0:5000

3. Run the System
Power on ESP32
Ensure ESP32 and server are on the same network
Open browser:
http://localhost:5000
Use ON/OFF buttons to control the relay

## System Workflow
User clicks ON or OFF button in web interface
Browser sends POST request to Flask (/control)
Flask updates relay state
ESP32 continuously requests /relay endpoint
Based on response, relay is turned ON or OFF
API Endpoints
GET /relay

Returns current relay state (ON/OFF)

POST /control

## Limitations
Uses polling instead of real-time communication
Works only on local network
No authentication or access control

## Future Improvements
Implement real-time communication using WebSockets or MQTT
Add authentication for secure access
Create mobile app interface
Deploy system to cloud server
Add multiple device control support

## Use Cases
Home automation systems
Remote switching of appliances
IoT learning projects
Basic industrial control

## Author
Harsha G
Learning Python, Embedded Systems, and IoT
