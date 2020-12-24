int analogPin = 5;
int val = 0;
int ledPin = 2;
void setup() {
 pinMode(ledPin,OUTPUT);
 Serial.begin(9600);

}

void loop() {
  val = analogRead(analogPin);
  Serial.print("val = ");
  Serial.println(val);

  if(val > 500)
  digitalWrite(ledPin,HIGH);
  else
  digitalWrite(ledPin,LOW);

delay(100);
}
