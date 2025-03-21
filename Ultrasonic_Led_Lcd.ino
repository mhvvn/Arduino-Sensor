#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 9;
const int echoPin = 1;
const int redLedPin = 4;
const int yellowLedPin = 5;
const int greenLedPin = 6; // Added green LED for >20cm
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust address if needed

long duration;
int distance;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT); //Initialize green LED
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  if (distance < 10) {
    lcd.print(" ");
  }
  lcd.print(distance);
  lcd.print(" cm");

  // LED logic
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW); // Turn off all LEDs by default.

  if (distance < 10) {
    digitalWrite(redLedPin, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Sangat Dekat");
  } else if (distance >= 10 && distance < 21) {
    digitalWrite(yellowLedPin, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Hati-Hati");

  } else {
    digitalWrite(greenLedPin, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Jarak Aman");

  }

  delay(500);
}
