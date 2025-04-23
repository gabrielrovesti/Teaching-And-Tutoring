#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>

const char *ssid = "tessarolo";
const char *password = "PArbEKar12";

WebServer server(80);

void handleRoot() {
  Serial.println("LED ACCESO");
  server.send(200, "text/html", "<a href='/inline'>spegni</a>");
}

void handleInline() {
  Serial.println("LED SPENTO");
  server.send(200, "text/html", "<a href='/'>accendi</a>");
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/inline",handleInline);

  server.onNotFound(handleNotFound);

  server.begin();
}

void loop(void) {
  server.handleClient();
  delay(2);
}
