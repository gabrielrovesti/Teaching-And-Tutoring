#include <WiFi.h>
const char* ssid     = "tessarolo"; // Change this to your WiFi SSID
const char* password = "PArbEKar12"; // Change this to your WiFi password

const char* host = "google.com"; // This should not be changed
const int httpPort = 80; // This should not be changed

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(100);
  }

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println("******************************************************");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  WiFiClient client;
  if (client.connect(host, httpPort) == true) {
    Serial.println("Bene, mi sono connesso");
    client.print("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  }
  else {
    Serial.print("Non riesco a connettermi");
  }
  delay(100000);
}
