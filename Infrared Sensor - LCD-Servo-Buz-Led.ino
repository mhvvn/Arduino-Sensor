//Deklarasi Library
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

//Deklarasi Alamat LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Deklarasi PIN sensor dan komponen
int sensor_pin = 2;
int tap_servo_pin =5;
int buzzer = 10;
int led = 13;
int val;
Servo tap_servo;

//Deklarasi fungsi yg akan berjalan sekali ketika arduino di hidupkan
void setup(){
  pinMode(sensor_pin,INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led,OUTPUT);
  tap_servo.attach(tap_servo_pin);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("IR Sensor");
  delay(1000);
  lcd.clear();
  Serial.begin(9600);
}

//Deklarasi fungsi yg akan selalu berjalan / di ulang hingga arduino di matikan
void loop(){
  val = digitalRead(sensor_pin);

  if (val==LOW) {
    tone(buzzer,100);
    tap_servo.write(0);
    digitalWrite(led, HIGH);
    Serial.println("Sensor Aktif");
    lcd.setCursor(0, 0);
    lcd.print("Ada Objek");
    lcd.print("        ");
  }
  if (val==HIGH){
   noTone(buzzer);
    tap_servo.write(180);
    digitalWrite(led,LOW);
    Serial.println("Sensor Non Aktif");
    lcd.setCursor(0, 0);
    lcd.print("TIdak Ada Objek");
    lcd.print("        ");
    }
  delay(1000);
}
