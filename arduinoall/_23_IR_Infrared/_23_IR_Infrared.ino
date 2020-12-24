// https://www.arduinoall.com/article/223/23-arduino-สอนใช้งาน-arduino-เซนเซอร์ตรวจจับวัตถุ-แบบแสงอินฟาเรด

//Example By ArduinoAll
int ledPin = 13;
int digitalPin = 8;
int val = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(digitalPin);//อ่านค่าสัญญาณ digital ขา8 ที่ต่อกับ เซ็นเซอร์ตรวจจับวัตถุ IR Infrared
  if (val == 0) { // ค่า เป็น 0 แสดงว่าตรวจพบวัตถุ
    digitalWrite(ledPin, 1); // เปิดไฟ LED
  }
  else {
    digitalWrite(ledPin, 0); // ปิดไฟ LED
  }
  delay(100);
}
