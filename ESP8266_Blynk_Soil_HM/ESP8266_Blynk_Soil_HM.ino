#include <Blynk.h>



#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "36e260228cda413db2f3ba3ee3782ced";
char ssid[] = "WIFI_TOR";
char pass[] = "4410210091";
int sensorPin = A0;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  delay(500);
  
}

void loop()
{
  Blynk.run();
  int sensorValue;
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 1023, 0, 100);
  Serial.print("Soil moisture: ");
  Serial.print(sensorValue);
  Serial.println(" %");
  Blynk.virtualWrite(V0, sensorValue);
  delay(500); 
  
}
