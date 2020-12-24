int digitalPin = 8;
int val = 0;
int ledPin = 2;

void setup() {
 pinMode(ledPin,OUTPUT);
 pinMode(digitalPin,INPUT);
 Serial.begin(9600);

}

void loop() {
  val = digitalRead(digitalPin);
  Serial.print("val = ");
  Serial.println(val);

  if(val ==0)
  digitalWrite(ledPin,HIGH);
  else
  digitalWrite(ledPin,LOW);

delay(100);
}
