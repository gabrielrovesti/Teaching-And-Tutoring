#include <WiFi.h> // Includiamo la libreria Wi-Fi
// Serve per avviare la connessione 

// Wi-Fi -> SSID (Nome) e Password 
// const char* = Array di caratteri (stringa)

const char* ssid     = "NomeRete"; 
const char* password = "Password"; 
// HTTP - Trasferimento dati web (porta 80 = servizio HTTP)
const char* host = "google.com"; // Destinazione
const int httpPort = 80; // 80 = Usata da HTTP

// Setup => Connettiti al WiFi e gestisci client/server
// Loop => Se sei server gestisci i client (qui non viene fatto)
void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println("*******************");
  Serial.print("Connessione in corso: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password); // Lancio connessione
  // ad un SSID con una certa password

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connesso");
  Serial.println("Indirizzo IP: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  WiFiClient client; // Crei un oggetto di tipo Client
  if (client.connect(host, httpPort) == true) {
    Serial.println("Bene, mi sono connesso");
    
    client.print("GET / HTTP/1.1\n"); // Prima parte della risposta -> Connessione? ✔️ | ❌

    client.print("Host: www.google.com\r\nConnection: close\r\n\r\n"); // Seconda parte della risposta -> Connessione? ✔️ | ❌
    
    unsigned long timeout = millis();

    // Finché ci sono client disponibili
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
