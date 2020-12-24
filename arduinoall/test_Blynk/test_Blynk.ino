#include <Blynk.h>

#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>


char auth[] = "";
char ssid[] ="ALSNET_1";
char pass[] = "ALS17025";
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();

}
