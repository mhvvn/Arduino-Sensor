#include <LiquidCrystal_I2C.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(void) {
  Serial.begin(115200);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  mpu.begin();

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(100);
}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);

  Serial.print(", Y: ");
  Serial.print(g.gyro.y);

  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");


 //print to lcd gyroscope
  lcd.setCursor(0, 0);
  lcd.print("X:");
  lcd.print(g.gyro.x);

  lcd.setCursor(0, 1);
  lcd.print("Y:");
  lcd.print(g.gyro.y);

  lcd.setCursor(0, 2);
  lcd.print("Z:");
  lcd.print(g.gyro.z);

//print to lcd accelerometer
  lcd.setCursor(8, 0);
  lcd.print("X:");
  lcd.print(a.acceleration.x);

  lcd.setCursor(8, 1);
  lcd.print("Y:");
  lcd.print(a.acceleration.y);

  lcd.setCursor(8, 2);
  lcd.print("Z:");
  lcd.print(a.acceleration.z);


  Serial.println("");
  delay(500);
}
