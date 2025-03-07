# Arduino Ultrasonic Distance Measurement with PING (28015) Sensor and LED Alert

## 1. Introduction
This project measures the distance to an object using the **Parallax PING))) (28015) Ultrasonic Sensor** and an **Arduino Uno**. If the measured distance is **less than 10 cm**, a **red LED** turns **ON**; otherwise, it remains **OFF**. The measured distance is displayed on the **Serial Monitor**.

---

## 2. Components Required
- **Arduino Uno**
- **Parallax PING (28015) Ultrasonic Sensor**
- **Red LED**
- **220Ω Resistor**
- **Jumper Wires**

---

## 3. Circuit Diagram & Connections

### Ultrasonic Sensor to Arduino Connections:
| **PING Pin** | **Arduino Uno Pin** |
|--------------|----------------|
| **VCC**      | **5V**         |
| **GND**      | **GND**        |
| **SIG**      | **D9**         |

### LED to Arduino Connection:
| **LED Pin**  | **Arduino Uno Pin** |
|-----------|----------------|
| **Anode (+) (Long Leg)** | **D6** |
| **Cathode (-) (Short Leg)** | **GND via 220Ω Resistor** |

---

## 4. Code Explanation

### 4.1 Pin Definitions
- **pingPin (D9):** Controls the PING))) sensor (both trigger & echo).
- **redLED (D6):** Controls the red LED.

### 4.2 Setup Function
- Initializes the **LED pin as OUTPUT**.
- Starts the **Serial Monitor** at `9600` baud rate.

### 4.3 Loop Function
1. **Triggering the Sensor:**
   - The sensor pin is set to **OUTPUT**.
   - A **short LOW pulse (2µs)** is sent.
   - A **HIGH pulse (10µs)** is sent to trigger the sensor.
   - The pin is set back to **INPUT** to receive the echo.

2. **Measuring Distance:**
   - The `pulseIn()` function measures the time taken for the echo to return.
   - If no echo is received, it prints **"No echo received!"** and exits.
   - The **duration is converted to distance (cm):**
     ```
     Distance = (Duration / 29) / 2
     ```

3. **LED Alert Logic:**
   - If **distance < 10 cm**, the **LED turns ON**.
   - Otherwise, the **LED turns OFF**.

4. **Serial Output:**
   - The measured distance is printed on the **Serial Monitor**.

---

## 5. Full Arduino Code
```cpp
const int pingPin = 9; 
const int redLED = 6;  

void setup() {
    pinMode(redLED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin, LOW);

    pinMode(pingPin, INPUT);
    long duration = pulseIn(pingPin, HIGH, 50000);

    if (duration == 0) {
        Serial.println("No echo received! Check sensor.");
        digitalWrite(redLED, LOW);
        delay(500);
        return;
    }

    int distance = duration / 29 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 10) {
        digitalWrite(redLED, HIGH);
    } else {
        digitalWrite(redLED, LOW);
    }

    delay(500);
}
