
// https://www.arduinoall.com/article/203/3-arduino-สอนการใช้งานตัวแปร-ประเภทตัวแปรใน-arduino
void setup() { 
  Serial.begin(9600);
}

void loop() {
  int a = 10;
  double b = 20.55;
  double c = 20.00;
  double d = 20;
  String x = "ArduinoAll";
  
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(d);
  Serial.println(x);
  delay(10000);
}
