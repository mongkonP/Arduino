int LED_BUILTIN = 7;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  Serial.println("ArduinoAll TESTED");
  digitalWrite(2, 0);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(2, 1);
  delay(1000);
}
