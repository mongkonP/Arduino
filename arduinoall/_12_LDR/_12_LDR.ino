// https://www.arduinoall.com/article/212/12-arduino-สอนใช้งาน-arduino-สัญญาณ-analog-input-ตัวต้านทานปรับค่าได้ตามแสง-ldr-ควบคุมเปิดปิดหลอดไฟ-led

//Example By ArduinoAll
int led = 13;
int ldr = A5;
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int val = analogRead(ldr); // อ่านค่าแบบ analog จากขา ldr เก็นไว้ในตัวแปร val
  Serial.println(val);
  if (val < 200) {
    Serial.println("LED ON");
    digitalWrite(led, 1);
  } else {
    Serial.println("LED OFF");
    digitalWrite(led, 0);
  }
  delay(100);
}
