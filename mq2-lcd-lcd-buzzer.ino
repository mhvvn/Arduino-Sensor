#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define LED 2
#define Buzzer 3
#define Sensor A1

void setup() {
  Serial.begin(9200);
  lcd.init();
  lcd.backlight();
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  int value = analogRead(Sensor);
  lcd.setCursor(0, 0); 
  lcd.print("Value :");
  lcd.print(value);
  lcd.print("  ");

  if (value > 400) {
    digitalWrite(LED, HIGH);
    tone(Buzzer,500);
    lcd.setCursor(0, 1);
    lcd.print("GAS Detected!");
  } else {
    digitalWrite(LED, LOW);
    noTone(Buzzer);
    lcd.setCursor(0, 1);
    lcd.print("No Gas Detected!");
  }
}
