// https://www.arduinoall.com/article/207/7-arduino-สอนการใช้งาน-if-else-ให้ทำงานตามเงื่อนไข
//Example By ArduinoAll
char key = '0' ; //สำหรับเก็บค่าที่ป้อนจากเครื่องคอมเข้ามา
void setup()
{
  Serial.begin(9600);
  Serial.println("Welcome ArduinoALL");
}
void loop()
{
  if (Serial.available() > 0) { //เช็คว่ามีค่าส่งมาใน Serial
    key = Serial.read(); //อ่านค่าที่รับเข้ามาไว้ในตัวแปร key
    Serial.print("key : ");
    Serial.println(key); // ส่งค่าตัวแปร key จากบอร์ด Arduino ออกไปแสดงที่ Serial Monitor
  }
  if (key == '1') { //ถ้า key เท่ากับ 1
    Serial.println("You Input 1"); //ให้ทำคำสั่งใน if นี้
  } else if (key == '2') {// ถ้า key ไม่ใช่ 1 แล้วถ้าเป็น 2
    Serial.println("You Input 2"); // ทำในคำสั่งนี้
  }
  else { // ถ้าไม่เข้าเงื่อนไขไหนเลย ให้ทำในคำสั่งนี้
    Serial.println("Please Enter Number 1 2");
  }
  delay(3000);
}
