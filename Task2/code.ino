#include <Servo.h>

// Define pin connections
const int LDR_PIN = A3;        // LDR connected to Analog Pin A0
const int LED_PIN = 4;         // LED connected to PWM Pin 9
const int PIR_PIN = 12;         // PIR sensor input on Digital Pin 2
const int MOTOR_ENABLE = 5;    // L293D Enable pin (PWM for speed control)
const int MOTOR_INPUT1 = 2;    // L293D Input1
const int MOTOR_INPUT2 = 3;    // L293D Input2
const int SERVO_PIN = 8;       // Servo connected to Pin 3

Servo myServo;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);
    pinMode(MOTOR_ENABLE, OUTPUT);
    pinMode(MOTOR_INPUT1, OUTPUT);
    pinMode(MOTOR_INPUT2, OUTPUT);

    myServo.attach(SERVO_PIN);

    Serial.begin(9600);
}

void loop() {
    // LDR based LED brightness control
    int lightValue = analogRead(LDR_PIN);  // Read LDR value (0-1023)
    int brightness = map(lightValue, 0, 1023, 255, 0);  // Convert to PWM (inverted)
    analogWrite(LED_PIN, brightness);  // Adjust LED brightness
    Serial.print("LDR Value: ");
    Serial.println(lightValue);

    // PIR Sensor based control
    int pirState = digitalRead(PIR_PIN);  // Read PIR sensor state
    if (pirState == HIGH) {
        Serial.println("Motion detected!");

        // Move Servo
        myServo.write(90);  // Move to 90 degrees

        // Turn ON Motor (Forward direction)
        digitalWrite(MOTOR_INPUT1, HIGH);
        digitalWrite(MOTOR_INPUT2, LOW);
        analogWrite(MOTOR_ENABLE, 200); // Moderate speed

        // Turn ON LED
        digitalWrite(LED_PIN, HIGH);

        delay(5000);  // Keep devices ON for 5 seconds

        // Reset System
        myServo.write(0);  // Move servo back to 0 degrees
        digitalWrite(MOTOR_INPUT1, LOW);
        digitalWrite(MOTOR_INPUT2, LOW);
        analogWrite(MOTOR_ENABLE, 0);  // Stop motor
        digitalWrite(LED_PIN, LOW);  // Turn off LED
    }
}
