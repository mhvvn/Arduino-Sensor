
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Alamat LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensor_pin = 2;
int tap_servo_pin =5;
int buzzer = 10;
int led = 13;
int val;

Servo tap_servo;



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
