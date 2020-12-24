
// https://www.arduinoall.com/article/204/4-สอนใช้งาน-arduino-สัญญาณ-digital-output-ควบคุม-led-ไฟวิ่ง
// Example By ArduinoAll
void setup() {
  pinMode(2, OUTPUT);//กำหนดขา 2 เป็นโหมด Output
}

void loop() {
  digitalWrite(2, HIGH);// สั่งให้เปิดไฟที่ขา 2
  // digitalWrite(2, 1);// สั่งให้เปิดไฟที่ขา 2 เขียนอีกแบบได้เหมือนกัน
  delay(1000);           // หน่วงเวลา 1 วินาที
  digitalWrite(2, LOW); // สั่งปิดไฟที่ขา 2
  //digitalWrite(2, 0); // สั่งปิดไฟที่ขา 2
  delay(1000);          // หน่วงเวลา 1 วินาที
}
