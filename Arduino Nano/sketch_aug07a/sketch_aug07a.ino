void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for(int i = 7;i<12;i++)
  pinMode(i, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
 for(int i = 7;i<12;i++)
 {
  digitalWrite(i, HIGH); 
  delay(10000); 
  digitalWrite(i, LOW);
  delay(10000);  
  }
  
}
