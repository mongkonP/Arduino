// https://www.arduinoall.com/article/213/13-arduino-สอนใช้งาน-arduino-analog-input-ควบคุมการหมุนของ-servo-ด้วยตัวต้านทานปรับค่าได้

#include <Servo.h>
Servo myservo;
int potpin = A0;
int val;
void setup() {
  myservo.attach(9); //กำหนด ตัวแปร myservo แทน Servo ที่ต่ออยู่กับ ขา9
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);         // อ่านค่า Analog ขาA0 เก็บไว้ในตัวแปร Val
  val = map(val, 0, 1023, 0, 180);  // แปลงค่า ระหว่าง 0-1023 เป็น 0-180
  //val = map(val, 0, 1023, 0, 90);  // แปลงค่า ระหว่าง 0-1023 เป็น 0-90
  Serial.print("val = ");           // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println(val);              // พิมพ์ค่าของตัวแปร val
  myservo.write(val);               // นำค่าที่แปลงค่ามาจากตัวต้านทานรับค่าได้ มาควบคุมการหมุน Servo
  delay(15);                        // Delay 15mS
}
