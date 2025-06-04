#include <Servo.h>
#include <LiquidCrystal_I2C.h>

//Deklarasi Alamat LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);



int sensor = 4;
int buzzer = 10;
int LED = 13;
int tap_servo_pin =5;
int val;
Servo tap_servo;


void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  tap_servo.attach(tap_servo_pin);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("IR Sensor");
  delay(1000);
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);
  if (val == LOW){
    tone(buzzer, 500);
    tap_servo.write(0);
    Serial.println("Sensor Aktif");
    digitalWrite(LED, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Ada Objek");
    lcd.print("        ");
  }
  if (val == HIGH){
    noTone(buzzer);
    digitalWrite(LED, LOW);
    tap_servo.write(100);
    Serial.println("Sensor Non Aktif");
    lcd.setCursor(0, 0);
    lcd.print("Tidak Ada Objek");
    lcd.print("        ");
  }
  delay(1000);
}
