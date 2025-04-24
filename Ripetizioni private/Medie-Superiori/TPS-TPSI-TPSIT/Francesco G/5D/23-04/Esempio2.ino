#include <WiFi.h>
#include <HTTPClient.h>

// Sostituisci con le tue credenziali WiFi
const char* ssid = "IL_TUO_SSID";
const char* password = "LA_TUA_PASSWORD";

void setup() {
  Serial.begin(115200);
  
  // Connessione al WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" connesso!");

  // Richiesta GET
  makeGetRequest();

  // Richiesta POST
  makePostRequest();
}

void makeGetRequest() {
  HTTPClient http;
  http.begin("http://example.com/api"); // Sostituisci con il tuo URL
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(payload);
  } else {
    Serial.print("Errore GET: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void makePostRequest() {
  HTTPClient http;
  http.begin("http://example.com/api"); // Sostituisci con il tuo URL
  http.addHeader("Content-Type", "application/json");

  String jsonData = "{\"key\":\"value\"}"; // Dati da inviare
  int httpResponseCode = http.POST(jsonData);

  if (httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(payload);
  } else {
    Serial.print("Errore POST: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void loop() {
  // Non fare nulla nel loop
}
