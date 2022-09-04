#include <ESP8266WiFi.h>
const char* ssid = "Kamesh";
const char* password = "samsungj7";

const char* host = "http://192.168.43.208";

void setup(){
  Serial.begin(9600);
  WiFi.begin(ssid,password);
  Serial.printf("\n[Connecting to %s ... ", host);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print(WiFi.localIP());
  Serial.println("connected");
  delay(2000);
}

void loop()
{
  WiFiClient client;

  Serial.printf("\n[Connecting to %s ... ", host);
  if (client.connect(host, 80))
  {
    Serial.println("connected]");

    Serial.println("[Sending a request]");
    client.print(String("GET /") + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );

    Serial.println("[Response:]");
    while (client.connected() || client.available())
    {
      if (client.available())
      {
        String line = client.readStringUntil('\n');
        Serial.println(line);
      }
    }
    client.stop();
    Serial.println("\n[Disconnected]");
  }
  else
  {
    Serial.println("connection failed!]");
    client.stop();
  }
  delay(5000);
}
