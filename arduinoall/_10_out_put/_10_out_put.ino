// https://www.arduinoall.com/article/210/10-arduino-สอนใช้งาน-arduino-สัญญาณ-analog-output-pwm-ควบคุมความสว่างหลอดไฟ-led

//Example By ArduinoAll
int led = 11;
void setup()
{
  pinMode(led, OUTPUT);
}
void loop()
{
  for (int i = 0; i < 255; i++) {
    analogWrite(led, i);
    delay(5);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(led, i);
    delay(5);
  }
  delay(1000);
}
