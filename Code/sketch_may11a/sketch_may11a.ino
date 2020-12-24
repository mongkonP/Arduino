int led_1 = 2;
int led_2 = 3;
int led_3 = 4;
int led_4 = 5;
int led_5 = 6;

int sensorPin = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_1, OUTPUT);
pinMode(led_2, OUTPUT);
pinMode(led_3, OUTPUT);
pinMode(led_4, OUTPUT);
pinMode(led_5, OUTPUT);

Serial.begin(9600);
delay(500);

}

void loop() {
  
int sensorValue;
sensorValue = analogRead(sensorPin);
sensorValue = map(sensorValue,0,1023,0,100);

Serial.println(sensorValue);delay(1000);

/*Serial.print("Soil moisture");
Serial.print(sensorValue);
Serial.println("%");
delay(1000);*/

if(sensorValue < 50)
{
 _digitalWrite(led_1);
}
else
{
   _digitalWrite(led_5);
}

 

 
}

void _digitalWrite(int _led)
{
  digitalWrite(_led, HIGH);   // set the LED on
  delay(1000);                  // wait for a second
  digitalWrite(_led, LOW);    // set the LED off
  delay(1000);                  // wait for a second
  }
