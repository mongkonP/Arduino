/*#include <Wire.h>
#include <DS1302.h>  
#include <LiquidCrystal_I2C.h>
 
DS1302 rtc(2, 3, 4);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 
void setup() {
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);
  lcd.begin(16,2);  
// Modify the below lines just once and upload, then comment or delete them!
  rtc.setDOW(SATURDAY);  // Set the day of the week      
  rtc.setTime(13, 05, 40); // Set the time hh:mm:ss
  rtc.setDate(04, 11, 2017); // Set the date dd:mm:yyyy
}
 
void loop() {
  lcd.setCursor(0, 0);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(8, 0);
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
  lcd.setCursor(1,1);
  lcd.print("*");
  lcd.setCursor(3, 1);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(14, 2);
  lcd.print("*");
  delay (1000);
}*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");
  
  
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello,TOR ");
 // lcd.print("DS1307RTC Test");
}

void loop()
{
    tmElements_t tm;



    lcd.setCursor(0, 1);
    lcd.print(str);
    delay(1000);

}
