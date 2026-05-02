#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// WiFi
const char* ssid = "YOUR_WIFI";
const char* password = "h=YOUR PASS";

// Server
const char* server = "http://add your pc ip here :5000/relay";

#define RELAY 23

void setup() {
  Serial.begin(115200);

  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected");
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    http.begin(server);
    int code = http.GET();

    if (code == 200) {

      String response = http.getString();

      Serial.println(response);

      if (response == "ON") {
        digitalWrite(RELAY, HIGH);
      } else {
        digitalWrite(RELAY, LOW);
      }
    }

    http.end();
  }

  delay(2000);
}
