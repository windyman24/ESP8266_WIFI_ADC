#include <ESP8266WiFi.h>

const char* ssid     = "WeiCheng";
const char* password = "0911872129";

// specify the port to listen on as an argument
WiFiServer server(8000);
WiFiClient client;
void setup() {
  Serial.begin(115200);
  delay(10);

  // prepare GPIO2
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);

  boolean result = WiFi.softAP("DSDA_ADC", "dsdadsda");
  while (result != true)
  {
    Serial.println("Wait");
    yield();
  }
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
  
}

void loop() {
  client = server.available();
  while (client)
  {
    client.println(analogRead(A0));
//    yield();
  }
}
