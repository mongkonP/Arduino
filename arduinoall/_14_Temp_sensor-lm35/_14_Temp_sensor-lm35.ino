// https://www.arduinoall.com/article/214/14-arduino-สอนใช้งาน-arduino-วัดอุณหภูมิด้วย-sensor-lm35

//Example By ArduinoAll
int val;
int lm35 = A5; // กำหนดให้ตัวแปร lm35 ที่ขา A5
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  val = analogRead(lm35);
  float mv = ( val / 1024.0) * 5000;
  float temp = mv / 10; //แปลงค่าเป็น องศาเซลเซียส
  Serial.print("TEMPRATURE = ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  delay(1000);
}
