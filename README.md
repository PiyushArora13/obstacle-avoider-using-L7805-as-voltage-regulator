
# Obstacle Avoider using L7805 as Voltage Regulator

### Smart Navigation Meets Power Efficiency

L7805 Obstacle Avoider is a compact, intelligent obstacle-avoiding robot powered by the ESP32 microcontroller. Designed with a focus on power management and real-time autonomous decision-making, this robot combines smart navigation with a reliable hardware setup.

At its core, the robot runs on a 12V battery pack and uses a Buck-Boost Converter along with an L7805 Voltage Regulator to deliver clean and stable 5V power to all electronic modules. This ensures consistent performance and long-term reliability, especially for mobile robotics projects.



## 🔧 Key Features

* Smart power management using a Buck-Boost Converter and L7805 for clean voltage regulation from a 12V supply
* ESP32 handles intelligent control, sensor data, and motor operation
* Real-time obstacle detection using HC-SR04 ultrasonic sensor
* Servo motor for directional control and sensing
* Smooth motion control using motor driver and N20 gear motors



## ⚙️ Hardware Components

| Component             | Description                               |
| --------------------- | ----------------------------------------- |
| ESP32                 | Main microcontroller (dual-core)          |
| HC-SR04               | Ultrasonic distance sensor                |
| SG90 Servo            | For rotation or steering of sensor        |
| L7805 Regulator       | Linear voltage regulator (5V output)      |
| Buck-Boost Converter  | Maintains regulated output from 12V input |
| 12V Battery Pack      | Primary power source                      |
| TB6612 Motor Driver   | Motor control for both wheels             |
| N20 6V 200 RPM Motors | High-speed mini gear motors for movement  |
| Chassis + Wheels      | Robot frame and mobility                  |



## 🧪 Use Cases

* Educational robotics and prototyping
* Autonomous navigation demos
* Low-power mobile robots
* DIY hobby and maker projects



## 🛠 Future Ideas

* Add GPS for outdoor navigation
* Use Wi-Fi or Bluetooth for remote control
* Integrate ML models for smarter movement
* Add IR or LED sensors for low-light navigation

