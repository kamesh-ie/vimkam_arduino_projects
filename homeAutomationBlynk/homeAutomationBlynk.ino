/*New blynk app project
   http://srituhobby.com
*/

//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "NER9Skigw5A5E8sGwKXhzvLQ0lBgJxO_" //Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Galaxy M118694";//Enter your WIFI name
char pass[] = "arulsamsung";//Enter your WIFI password

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
}
BLYNK_WRITE(V1) {
  digitalWrite(D1, param.asInt());
}
BLYNK_WRITE(V2) {
  digitalWrite(D2, param.asInt());
}
BLYNK_WRITE(V3) {
  digitalWrite(D3, param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
