//  https://www.arduinoall.com/article/220/20-arduino-สอนใช้งาน-arduino-แสดงข้อความ-และ-ค่า-sensor-ต่างๆออกจอ-lcd-1602-แบบ-i2c
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 
//LiquidCrystal_I2C lcd(0x3F, 16, 2); 
void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print("Arduino TEST HM"); //พิมพ์ข้อความ
  //lcd.setCursor(2, 1); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  //lcd.print("arduinoall.com"); //พิมพ์ข้อความ "arduinoall.com"
}
int sensorPin = A0;
void loop() {
lcd.setCursor(0, 1);
   int sensorValue;
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 1023, 100, 0);
  Serial.print("Soil moisture: ");
  Serial.print(sensorValue);
  Serial.println(" %");
  Serial.println(sensorValue);
  lcd.print("HM: ");
lcd.print( sensorValue);
  delay(500); 
}
