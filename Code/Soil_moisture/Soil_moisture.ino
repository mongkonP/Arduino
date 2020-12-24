int sensorPin = A0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:

int sensorValue;
sensorValue = analogRead(sensorPin);
sensorValue = map(sensorValue,0,1023,0,100);
if(sensorValue < 90)
{
Serial.print("Soil moisture");
Serial.print(sensorValue);
Serial.println("%");
}
delay(500);
}
