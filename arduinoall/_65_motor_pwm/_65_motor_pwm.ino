//  https://www.arduinoall.com/article/226/26-arduino-สอนใช้งาน-arduino-ควบคุมความเร็วมอเตอร์-dc-สัญญาณ-pwm

//Example By ArduinoAll
int MotorL = 2; // กำหนดขา ที่ต่อกับขั้วมอเตอร์
int MotorR = 3;

void setup() {
  pinMode(MotorL, OUTPUT);
  pinMode(MotorR, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(MotorR, 1);
  digitalWrite(MotorL, 0);
  Serial.println("Motor Right"); // หมุนซ้ายคือ มอเตอร์ขั้ว R มีไฟ ขั้ว L ไม่มีไฟ
  delay(3000);
  digitalWrite(MotorR, 0);
  digitalWrite(MotorL, 0);
  Serial.println("Motor STOP"); // หยุด คือ ไม่จ่ายไฟให้มอเตอร์
  delay(2000);
  digitalWrite(MotorR, 0);
  digitalWrite(MotorL, 1);
  Serial.println("Motor Left"); // หมุนขวาคือ มอเตอร์ขั้ว R ไม่มีไฟ ขั้ว L มีไฟ
  delay(3000);
}
