#include <DS3231.h>
#include <LiquidCrystal.h>

DS3231  rtc(SDA, SCL);
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
void setup() { 
 rtc.begin();
 lcd.begin(16,2);
}
void loop() { 
 /*lcd.setCursor(0,0);
 lcd.print("Time:  ");
 lcd.print(rtc.getTimeStr());*/
 
 lcd.setCursor(0,1);
 lcd.print("Date: ");
 lcd.print(rtc.getDateStr());
 
 delay(1000); 
}
