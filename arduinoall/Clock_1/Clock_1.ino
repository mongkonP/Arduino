#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 

int Ledpin = 13;
RTC_DS3231 RTC;

void setup () {
  pinMode(Ledpin, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();

  // อัพโหลดโคดลงบอร์ด Arduino แล้ว ให้ใส่คอมมเนต์บรรทัดนี้ออก แล้วอัพโหลดใหม่ เพื่อไม่ให้ตั้งเวลทับซ้อนกัน
  //RTC.adjust(DateTime(__DATE__, __TIME__)); // คำสั่งตั้งเวลาให้นาฬิกา

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // ตั้งค่าเวลาบรรทัดนี้
    // อัพโหลดโคดลงบอร์ด Arduino แล้ว ให้ใส่คอมมเนต์บรรทัดนี้ออก แล้วอัพโหลดใหม่ เพื่อไม่ให้ตั้งเวลทับซ้อนกัน
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  DateTime now = RTC.now();
  RTC.setAlarm1Simple(21, 58);
  RTC.turnOnAlarm(1);
  if (RTC.checkAlarmEnabled(1)) {
    Serial.println("Alarm Enabled");
  }

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print("Arduino TEST HM"); //พิมพ์ข้อความ
  
}

void loop () {
  DateTime now = RTC.now();
  // ดึงค่าเวลาจากโมดูลมาคำนวนตามต้องการ
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  if (RTC.checkIfAlarm(1)) { // ตั้วเวลาเตื่อน แบบใช้ Alarm ในไลบารี
    Serial.println("Alarm Triggered");
  }
  // ตั้งเวลาแบบกำหนดเช็ค if เอง
  if (now.hour() == 22 && now.minute() == 19 ) { //ถ้าชั่วโมงเท่ากับ 22 และนาทีเท่ากับ 19 จะสั่งให้เปิดไฟ LED
    digitalWrite(Ledpin, HIGH); // สั่งให้ LED ติดสว่าง
    Serial.println("LED ON");
  }
  else
  {
    Serial.println("LED OFF");
    digitalWrite(Ledpin, LOW);
  }
  Serial.println();
  delay(3000);
}
