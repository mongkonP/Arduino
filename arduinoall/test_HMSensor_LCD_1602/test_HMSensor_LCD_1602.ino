
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  lcd.begin(16, 2);

  lcd.print("HM_Soil @TOR");
  Serial.begin(9600);
}
int sensorPin = A0;
void loop() {

  lcd.setCursor(0, 1);
   int sensorValue;
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 1023, 100, 0);
  Serial.print("Soil moisture: ");
  Serial.print(sensorValue);
  Serial.println(" %");
  Serial.println(sensorValue);
  lcd.print("HM: ");
lcd.print( sensorValue);
  delay(500); 
}
