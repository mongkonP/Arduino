// https://www.arduinoall.com/article/208/8-สอน-arduino-การรับค่าจากสวิตช์-digitalread
//Example By ArduinoAll.com
int led = 13;
int buttonPin = 3;
int buttonState = 0;
void setup()
{
  pinMode(led, OUTPUT); // กำหนดขา led เป็นโหมด OUTPUT
  pinMode(buttonPin, INPUT);// กำหนดขา buttonPin เป็นโหมด INPUT
}
void loop()
{
  buttonState = digitalRead(buttonPin); // อ่านค่าสถานะขา3
  if (buttonState == 1) {
    digitalWrite(led, 0); // ไฟ LED ดับ
  } else {
    digitalWrite(led, 1); // ไฟ LED 1 ติด
  }
}
