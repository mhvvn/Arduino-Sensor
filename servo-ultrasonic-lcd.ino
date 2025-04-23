#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define SERVO_PIN 3
#define Echo_PIN 8
#define Trig_PIN 9

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(Trig_PIN, OUTPUT);
  pinMode(Echo_PIN, INPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(90);  // Palang tertutup

  lcd.init();
  lcd.backlight();
}

void loop() {
  long duration;
  int distance;

  // Trigger sensor ultrasonik
  digitalWrite(Trig_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_PIN, LOW);

  duration = pulseIn(Echo_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.clear();

  if (distance > 50) {
    // Tidak ada kendaraan
    lcd.setCursor(0, 0);
    lcd.print("Selamat Datang");
    lcd.setCursor(0, 1);
    lcd.print("Parkir Tersedia");
    myServo.write(90); // Palang tertutup
  } 
  else if (distance <= 50 && distance > 30) {
    // Kendaraan mendekat
    lcd.setCursor(0, 0);
    lcd.print("Ambil Tiket");
    lcd.setCursor(0, 1);
    lcd.print("Parkir Tersedia");
    myServo.write(90); // Tetap tertutup
  } 
  else if (distance <= 10) {
    // Kendaraan sangat dekat
    lcd.setCursor(0, 0);
    lcd.print("Parkir dgn Rapi");
    lcd.setCursor(0, 1);
    lcd.print("Terima Kasih");
    myServo.write(180); // Palang terbuka
  }
  delay(100);
}
