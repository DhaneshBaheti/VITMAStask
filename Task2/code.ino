#include <Servo.h>

const int LDR_PIN = A0;        
const int LED_PIN = 9;         
const int PIR_PIN = 2;         
const int MOTOR_ENABLE = 5;    
const int MOTOR_INPUT1 = 6;    
const int MOTOR_INPUT2 = 7;    
const int SERVO_PIN = 3;       

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
    int lightValue = analogRead(LDR_PIN);  
    int brightness = map(lightValue, 0, 1023, 255, 0);  
    analogWrite(LED_PIN, brightness);  

    if (brightness > 0) {
        Serial.print("LED Brightness: ");
        Serial.println(brightness);
    }

    int pirState = digitalRead(PIR_PIN);  
    if (pirState == HIGH) {
        myServo.write(90);  
        digitalWrite(MOTOR_INPUT1, HIGH);
        digitalWrite(MOTOR_INPUT2, LOW);
        analogWrite(MOTOR_ENABLE, 200); 
        digitalWrite(LED_PIN, HIGH);

        delay(5000);  

        myServo.write(0);  
        digitalWrite(MOTOR_INPUT1, LOW);
        digitalWrite(MOTOR_INPUT2, LOW);
        analogWrite(MOTOR_ENABLE, 0);  
        digitalWrite(LED_PIN, LOW);  
    }
}
