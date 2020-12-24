// https://www.arduinoall.com/article/209/9-สอนใช้งาน-arduino-สั่งงานให้โปรแกรมวนลูปทำซ้ำ-ไฟ-led-วิ่ง

//Example By ArduinoAll
void setup()
{
  Serial.begin(9600);
  // กำหนดขา 2 - 6 ให้เป็นโหมด OUTPUT โดยใช้คำสั่ง for ช่วย สะดวกมาก ๆ
  for (int i = 2; i <= 6; i++) {
    pinMode(i, OUTPUT);
  }
}
void loop()
{
 
  for(int a = 0;a<=10;a++)
  {
  int l;
  if(a < 6)
  l=1000;
  else
  l= 150;
  for (int i = 2; i <= 6; i++) {
    digitalWrite(i, 1); // เปิดไฟดวงปัจจุบัน
    delay(l);
    digitalWrite(i, 0); // ปิดไฟดวงปัจจุบัน
    
  }
  }
  for (int i = 5; i <= 2; i--) {
    digitalWrite(i, 1);
    delay(100);
    digitalWrite(i, 0);
  }
}
