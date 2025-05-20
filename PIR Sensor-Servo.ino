#include <Servo.h>

int PIR =2;
int sensor = 0;
Servo myservo;

void setup() {
pinMode (PIR,INPUT);
Serial.begin(9600);
myservo.attach(9);
}

void loop() {
  sensor = digitalRead(PIR);
  if (sensor==HIGH) {
    myservo.write(180);
    Serial.println("Buka");
    delay(2000);
  } else {
    myservo.write(90);
    Serial.println("Tutup");
    delay(1000);
  }
}
