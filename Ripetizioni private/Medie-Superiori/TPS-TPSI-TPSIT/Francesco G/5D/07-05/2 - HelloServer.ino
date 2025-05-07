#include <WiFi.h>
#include <WebServer.h> // Creazione server su porta 80 (HTTP)
#include <ESPmDNS.h> // Inclusione di MDNS

// Stessi dati di prima
const char *ssid = "NomeRete";
const char *password = "password";

// Va creato un oggetto di tipo WebServer -> server su porta 80 (HTTP)
WebServer server(80);

// Le creiamo noi per comodità per gestire cosa succede all'utente quando naviga su
// una certa pagina


void handleRoot() {
  Serial.println("LED ACCESO");

  // Invio risposta del server al client con codice / codifica / contenuto
  // Vedi teoria HTTP per logica

  server.send(200, "text/html", "<a href='/inline'>spegni</a>");
}

void handleInline() {
  Serial.println("LED SPENTO");

  // Invio risposta del server al client con codice / codifica / contenuto
  // Vedi teoria HTTP per logica
  server.send(200, "text/html", "<a href='/'>accendi</a>");
}

void handleNotFound() {

  // Variabile di tipo stringa che concatena i pezzi di risposta

  String message = "File non trovato. \n\n";
  message += "URI: ";
  message += server.uri();

  message += "\nMetodo: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";

  message += "\nArgomenti: ";
  message += server.args();
  message += "\n";

  // Stampa come byte (uint8_t = byte ad 8 bit positivi)
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  // Messaggio finale di risposta
  server.send(404, "text/plain", message);
}

void setup(void) {
  // Uguale a prima
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Uguale a prima
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Uguale a prima
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Se richiesta DNS viene fatta da scheda ESP32

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  // Gestione pagine web

  // sito.com/
  server.on("/", handleRoot); // pagina principale - home page

  // sito.com/inline
  server.on("/inline",handleInline); // esempio altra pagina

  // sito.com/404
  server.onNotFound(handleNotFound); // pagina non trovata

  // start del server
  server.begin();
}

void loop(void) {
  server.handleClient();
  delay(2);
}
