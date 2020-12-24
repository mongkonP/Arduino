// https://www.arduinoall.com/article/218/18-arduino-สอนใช้งาน-arduino-tracking-sensor-tcrt5000-ตรวจจับเส้นขาวดำ

//Example By ArduinoAll
int ledPin = 13;
int sensor = A0;
int val = 0;
void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("ArduinoAll TEST");
}
void loop() {
  val = analogRead(sensor);  //อ่านค่าจากเซนเซอร์
  Serial.println(val); // แสดงค่าเซนเซอร์ออกทางหน้าจอ
  if (val < 500) { // ค่า 500 สามารถกำหนดปรับได้ตามค่าแสงในห้องต่างๆ
    digitalWrite(ledPin, HIGH); // ไฟ LED ติด
  } else {
    digitalWrite(ledPin, LOW); // ไฟ LED ดับ
  }
  delay(100);
}
