const int pingPin = 7; 
const int redLED = 13;  

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
