#include <WiFi.h>
#include <HTTPClient.h>

// Sostituisci con le tue credenziali WiFi
const char* ssid = "IL_TUO_SSID";
const char* password = "LA_TUA_PASSWORD";

void setup() {
  Serial.begin(115200);
  
  // Connessione al WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connessione al WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println(" connesso!");
  
  // Esegui la richiesta HTTP
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Indirizzo del server
    http.begin("http://example.com/api"); // Sostituisci con il tuo URL
    int httpResponseCode = http.GET(); // Esegui una richiesta GET

    if (httpResponseCode > 0) {
      String payload = http.getString(); // Ottieni il payload della risposta
      Serial.println(httpResponseCode); // Stampa il codice di risposta
      Serial.println(payload); // Stampa il contenuto della risposta
    } else {
      Serial.print("Errore nella richiesta: ");
      Serial.println(httpResponseCode);
    }

    http.end(); // Chiudi la connessione
  }
}

void loop() {
  // Non fare nulla nel loop
}
