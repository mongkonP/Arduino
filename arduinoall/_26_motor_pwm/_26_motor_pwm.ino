//  https://www.arduinoall.com/article/226/26-arduino-สอนใช้งาน-arduino-ควบคุมความเร็วมอเตอร์-dc-สัญญาณ-pwm

//Example By ArduinoAll
int MotorL = 2;
int MotorR = 3;
int MotorPWM = 9;
void setup() {
  pinMode(MotorL, OUTPUT);
  pinMode(MotorR, OUTPUT);
  pinMode(MotorPWM, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // สั่งให้มอเตอร์หมุนขวา
  digitalWrite(MotorL, 1);
  digitalWrite(MotorR, 0);

  // ปรับความเร็วมอเตอร์
  analogWrite(MotorPWM, 100); // ปรับความเร็วมอเตอร์เป็นระดับ 10
  Serial.println("speed 100");
  delay(3000);

  analogWrite(MotorPWM, 0);
  Serial.println("stop");
  delay(2000);

  analogWrite(MotorPWM, 255); // ปรับความเร็วมอเตอร์เป็นระดับ 255
  Serial.println("speed 255");
  delay(3000);

  analogWrite(MotorPWM, 0);
  Serial.println("stop");
  delay(2000);
}
