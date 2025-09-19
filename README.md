# 🏠 **IoT-based Home Automation System (Arduino + MIT App Inventor)**

## 📖 **Introduction**
The **IoT-based Home Automation System** is designed to improve energy efficiency, enhance security, and provide users with convenient control over household appliances.  

This system allows users to:
- View **temperature, humidity, and light intensity levels** in real-time.  
- Automatically **control lights, curtains, and door locks**.  
- Monitor and interact with the system using a **mobile app (MIT App Inventor)** via the cloud (Firebase).  

The project leverages **Arduino (NodeMCU ESP8266)** with sensors and actuators to automate everyday household tasks, creating a safer, smarter, and more energy-efficient living environment.  

---

## 🎯 **Objectives**
1. Design an **automatic curtain** system that closes when the LDR detects a certain light intensity.  
2. Implement an **automatic indoor light system** that illuminates the room when it is dark.  
3. Develop a **user-friendly mobile application** that allows the user to monitor home conditions and control devices remotely.  

---

## ⚙️ **Methodology**
### 🔹 **Block Diagram**
<img width="445" height="472" alt="image" src="https://github.com/user-attachments/assets/907d51b1-b07f-452c-b905-1d09960d7518" />

- **Core Controller:** NodeMCU ESP8266 WiFi Module  
- **Sensors:**  
  - LDR (Light Intensity)  
  - DHT22 (Temperature & Humidity)  
- **Outputs:**  
  - Relay Module (Light Bulb)  
  - Servo Motor (Curtain Pulley System)  
  - I2C 20x4 LCD Display  
- **App & Cloud:**  
  - MIT App Inventor (Android app)  
  - Firebase (Cloud database & authentication)  

### 🔹 **Flowchart**
<img width="680" height="702" alt="image" src="https://github.com/user-attachments/assets/e0dbcfef-f87a-42e7-8456-d722467eea69" />

1. User logs in to the MIT App Inventor app.  
   - Wrong password → *Access Denied*.  
   - Correct password → *Welcome Back!* → Access to monitoring dashboard.  
2. LCD & MIT app display sensor readings in real-time.  
3. Curtain and bulb behavior depend on **LDR readings**:  
   - < 800 lux → Bulb ON, Curtain Closed.  
   - ≥ 800 lux → Bulb OFF, Curtain Open.  
4. User can lock/unlock the door from the MIT app (controlled via a servo motor).  

---

## 📐 **Specifications**
- **NodeMCU ESP8266**: WiFi connectivity and main controller.  
- **Servo Motor**: Acts as pulley system for curtain automation.  
- **LDR Sensor**: Measures ambient light intensity.  
- **Relay Module + Light Bulb**: Controls lighting based on room brightness.  
- **DHT22 Sensor**: Measures humidity and temperature.  
- **I2C 20x4 LCD**: Displays all monitoring conditions (temperature, humidity, light level, door, bulb, curtain).  
- **MIT App Inventor**: Provides user interface with password authentication.  

## **Schematic Diagram**

<img width="943" height="553" alt="image" src="https://github.com/user-attachments/assets/fc14ffcd-a952-41ed-8810-46c260e1f0f3" />

---

## ✅ **Conclusion**
The **IoT-based Home Automation System** was successfully designed and tested. It demonstrated:  
- **Energy savings** through automated lighting and curtain control.  
- **Enhanced security** with password-protected door control.  
- **Convenience** for users, including elderly and disabled people, with remote monitoring and control.  
The system is **low-cost, eco-friendly, and reliable**, with potential to expand into more advanced smart home applications.  

---

## 🚀 Future Improvements
- Integration with **voice assistants** (Google Assistant, Alexa).  
- Adding **motion detection (PIR sensor)** for enhanced security.  
- Support for **iOS app** in addition to MIT Android app.  
- Backup power system for uninterrupted operation.  

---

## 🛠️ How to Run
1. Open the project in Arduino IDE.
2. Install required libraries:
- ESP8266WiFi
- FirebaseESP8266
- DHT sensor library
- LiquidCrystal_I2C
3. Flash the code to your NodeMCU ESP8266 board.
4. Connect your hardware components as per the circuit diagram.
5. Open the MIT App Inventor app and connect it to Firebase.

---

## 📜 License
This project is for educational purposes under NMJ40803 - Internet of Things coursework. You may modify and use this project for learning, but proper credit to the author is appreciated.
