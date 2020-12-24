
// https://www.arduinoall.com/article/219/19-arduino-สอนใช้งาน-arduino-แสดงข้อความออกจอ-lcd-1602
//Example By ArduinoAll
#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,11,12);
void setup() {
lcd.begin(16,2);
lcd.println("HELLO WORD");
delay(2000);
lcd.clear();
}
void loop() {
 lcd.setCursor(0,0);
 lcd.print("Arduino by ToR");
 lcd.setCursor(2,1);
 lcd.print("Arduino by T");
}
