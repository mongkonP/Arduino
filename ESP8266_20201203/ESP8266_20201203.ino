#define LED0 D0
#define LED1 D1
#define LED2 D2
#define LED3 D3
#define LED4 D4
void setup()
{
pinMode(LED0,OUTPUT);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
}
void loop()
{
SetLED(LED0);delay(1000);
SetLED(LED1);delay(1000);
SetLED(LED2);delay(1000);
SetLED(LED3);delay(1000);
}

void SetLED(int LED)
{
  
  digitalWrite(LED,HIGH);
delay(500);
digitalWrite(LED,LOW);
delay(500);
digitalWrite(LED,HIGH);
delay(500);
digitalWrite(LED,LOW);
delay(500);
digitalWrite(LED,HIGH);
delay(500);
digitalWrite(LED,LOW);
delay(2000);
  }
