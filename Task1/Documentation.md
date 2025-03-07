# Arduino Ultrasonic Distance Measurement with PING))) (28015) Sensor and LED Alert

## 1. Introduction
This project measures the distance to an object using the **Parallax PING))) (28015) Ultrasonic Sensor** and an **Arduino Uno**. If the measured distance is **less than 10 cm**, a **red LED** turns **ON**; otherwise, it remains **OFF**. The measured distance is displayed on the **Serial Monitor**.

---

## 2. Components Required
- **Arduino Uno**
- **Parallax PING))) (28015) Ultrasonic Sensor**
- **Red LED**
- **220Ω Resistor**
- **Jumper Wires**

---

## 3. Circuit Diagram & Connections

### Ultrasonic Sensor to Arduino Connections:
| **PING))) Pin** | **Arduino Uno Pin** |
|--------------|----------------|
| **VCC**      | **5V**         |
| **GND**      | **GND**        |
| **SIG**      | **D7**         |

### LED to Arduino Connection:
| **LED Pin**  | **Arduino Uno Pin** |
|-----------|----------------|
| **Anode (+) (Long Leg)** | **D13** |
| **Cathode (-) (Short Leg)** | **GND via 220Ω Resistor** |

---

## 4. Working Principle

1. The **Arduino** sends a short **trigger pulse** to the **PING))) sensor** to initiate distance measurement.
2. The **sensor emits an ultrasonic sound wave** and waits for the echo to return.
3. The **time taken** for the echo to return is measured.
4. The **distance is calculated** based on the time taken.
5. If the **distance is less than 10 cm**, the **red LED turns ON**.
6. If the **distance is 10 cm or more**, the **red LED turns OFF**.
7. The measured **distance is displayed on the Serial Monitor**.

---
