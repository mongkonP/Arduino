//  https://www.arduinoall.com/article/220/20-arduino-สอนใช้งาน-arduino-แสดงข้อความ-และ-ค่า-sensor-ต่างๆออกจอ-lcd-1602-แบบ-i2c
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <RTClib.h>
#include <DS3231.h>

RTC_DS3231 RTC;
LiquidCrystal_I2C lcd(0x27, 16, 3); 
DS3231  rtc(SDA, SCL);
//LiquidCrystal_I2C lcd(0x3F, 16, 2); 
void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
 // lcd.print("Arduino By TOR"); //พิมพ์ข้อความ
  Wire.begin();
  RTC.begin();

  RTC.adjust(DateTime(__DATE__, __TIME__)); // คำสั่งตั้งเวลาให้นาฬิกา

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  DateTime now = RTC.now();
  RTC.setAlarm1Simple(0, 49);
  RTC.turnOnAlarm(1);
  if (RTC.checkAlarmEnabled(1)) {
    Serial.println("Alarm Enabled");
  }
  
}
int sensorPin = A0;
void loop() {


DateTime now = RTC.now();


char str[16]; 
lcd.setCursor(0,0);
//lcd.clear();
if(now.hour() == 17 && now.minute() == 35)
{
  lcd.print("Runing...");
}
else
{
sprintf(str,"%02u/%02u/%02u %02u:%02u",now.day(),now.month(),now.year(), now.hour(),now.minute());
lcd.print(str);
}

lcd.setCursor(0,1);
int sensorValue;
sensorValue = analogRead(sensorPin);
sensorValue = map(sensorValue, 0, 1023,  100,0);
lcd.print("HU:");
lcd.print(sensorValue);

delay(1000); 

}
