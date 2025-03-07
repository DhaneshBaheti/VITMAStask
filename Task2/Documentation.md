# Home Automation System using Arduino  

## 1. Introduction  
This home automation system automates household devices using an **Arduino Uno**, enhancing convenience and energy efficiency. The system consists of:  
- **Light (LED):** Adjusts brightness based on ambient light.  
- **Fan (DC Motor):** Turns on when motion is detected.  
- **Door (Servo Motor):** Opens when motion is detected.  
- **PIR Sensor:** Detects movement to trigger the fan and door.  
- **LDR Sensor:** Monitors light levels to adjust LED brightness.  

---

## 2. Components Used  
- **Arduino Uno** – Main microcontroller  
- **LDR (Light Dependent Resistor)** – Detects ambient light  
- **LED** – Represents the room light  
- **PIR Sensor** – Detects human motion  
- **Servo Motor** – Represents an automatic door  
- **DC Motor with L293D Motor Driver** – Controls a fan  
- **9V Battery** – Powers the motor  

---

## 3. Working Principle  

### 3.1 Automatic Light Control  
- The LDR continuously measures ambient light intensity.  
- The system adjusts the LED brightness accordingly using PWM.  
- If the room is dark, the LED brightens; if bright, the LED dims.  

### 3.2 Motion-Activated Fan and Door  
- The PIR sensor detects motion.  
- When motion is detected:  
  - The **door (servo motor) opens**.  
  - The **fan (DC motor) starts running**.  
  - The **light (LED) turns on at full brightness**.  
- After **5 seconds**, the system resets:  
  - The door closes.  
  - The fan turns off.  
  - The light brightness returns to LDR-based control.  

---

## 4. Circuit Connections  

| **Component**          | **Arduino Pin** | **Function**                     |  
|----------------------|---------------|---------------------------------|  
| **LDR Sensor**       | A3            | Reads ambient light levels      |  
| **LED (Light)**      | 4 (PWM)       | Adjusts brightness automatically |  
| **PIR Sensor**       | 12             | Detects motion                  |  
| **Servo Motor (Door)** | 8             | Opens/closes the door           |  
| **L293D Enable (Fan Speed)** | 5 (PWM)       | Controls fan speed              |  
| **L293D Input 1 (Fan Direction)** | 2             | Forward direction control      |  
| **L293D Input 2 (Fan Direction)** | 3             | Reverse (not used)             |  

---

## 5. System Workflow  

1. **Light Control with LDR**  
   - The system continuously monitors the ambient light using the LDR.  
   - The LED brightness is adjusted automatically based on the light intensity.  

2. **Motion Detection with PIR Sensor**  
   - The PIR sensor detects movement in the room.  
   - If motion is detected:  
     - The **door (servo) opens**.  
     - The **fan (DC motor) turns ON**.  
     - The **LED turns ON fully**.  
   - After **5 seconds**, the system resets:  
     - The door closes.  
     - The fan stops.  
     - The light brightness returns to normal.  

---

## 6. Future Enhancements  
- **Wi-Fi Connectivity:** Integrate with ESP8266 for remote control.  
- **Voice Control:** Enable Google Assistant or Alexa support.  
- **Temperature-Based Fan Control:** Adjust fan speed based on temperature.  
- **Mobile App Integration:** Control and monitor the system remotely.  

This home automation system provides energy-efficient and automated control of household appliances, improving convenience and security. 🚀
