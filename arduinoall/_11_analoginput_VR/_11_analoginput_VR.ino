// https://www.arduinoall.com/article/211/11-arduino-สอนใช้งาน-arduino-สัญญาณ-analoginput-จากตัวต้านทานปรับค่าได้-ปรับความสว่างหลอดไฟ-led

//Example By ArduinoAll
int led = 3;
int vr = A5;
void setup()
{
  pinMode(led, OUTPUT);
  // pinMode(vr,INPUT); ไม่ต้องกำหนดเป็นโหมด input เพราะเป็นโหมดค่าเริ่มต้นอยู่แล้ว
  Serial.begin(9600);
}

void loop()
{
  int val = analogRead(vr); // อ่านค่าแบบ analog จากขา vr เก็นไว้ในตัวแปร val
  // แปลงค่าจากช่วง 0-1023 ให้เป็นค่าในช่วง 0-255 แล้วเก็บไว้ในตัวแปร output
  int output = map(val, 0, 1023, 0, 255); 
  Serial.println(output);
  analogWrite(led, output); // สั่งให้ไฟค่า output ออกเป็นแบบ analog ที่ขา led
}
