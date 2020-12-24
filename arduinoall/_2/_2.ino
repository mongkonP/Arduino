
//  https://www.arduinoall.com/article/202/2-สอน-arduino-โครงสร้างการเขียนโปรแกรม-arduino
void setup() { 
  // ฟังก์ชั่น setup สำหรับกำหนดค่าเริ่มต้นต้องฟังก์ชั่นนี้
  Serial.begin(9600);
  Serial.println("Setup Function");
}

void loop() {
  // ฟังก์ชั่น loop การทำงานทั้งหมดจะอยู่ในฟังก์ชั่นนี้
  Serial.println("Loop Function");
  delay(1000);
  //all();
}

void all(){
  Serial.println("Arduino All Work");
}
