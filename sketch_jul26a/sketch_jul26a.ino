/*
 *  This sketch demonstrates how to scan WiFi networks. 
 *  The API is almost the same as with the WiFi Shield library, 
 *  the most obvious difference being the different file you need to include:
 */
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "36e260228cda413db2f3ba3ee3782ced";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "ALSNET_1", "ALS17025");

}

void loop()
{
  Blynk.run();
}
