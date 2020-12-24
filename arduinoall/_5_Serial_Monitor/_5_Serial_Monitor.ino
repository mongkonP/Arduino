
//  https://www.arduinoall.com/article/205/5-arduino-สอนใช้งาน-arduino-แสดงผลออกหน้าจอคอมพิวเตอร์ทาง-serial-monitor
//Example By ArduinoAll
int led = 3; // กำหนดขาใช้งาน
int val = 1;
void setup()
{
  pinMode(led, OUTPUT); // กำหนดขา 3 เป็นโหมด OUTPUT
  Serial.begin(9600); // ตั้งความเร็วสื่อสารที่ 9600 และสั่งให้เริ่มทำงาน
  Serial.println("ArduinoAll");
}
void loop()
{
  digitalWrite(led, 1); // เปิดไฟที่ขา led
  Serial.print(val); //แสดงค่าจากตัวแปร val ออกหน้าจอ
  Serial.print(": ON "); //แสดงคำว่า "ON " ออกหน้าจอ
  Serial.println("LED"); // แสดงคำว่า LED ออกหน้าจอแล้วขึ้นบรรทัดใหม่
  delay(2000); // หน่วงเวลา 2 วินาที
  digitalWrite(led, LOW); // ปิดไฟที่ขา led
  Serial.print(val); //แสดงค่าจากตัวแปร val ออกหน้าจอ
  Serial.print(": OFF "); // Arduino ส่งคำว่า "OFF "
  Serial.println("LED"); // Arduino ส่งคำว่า "LED"
  delay(2000); //หน่วงเวลา 2000 มิลลิวินาที
}
