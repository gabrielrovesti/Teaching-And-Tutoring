// TERZO - Connessione ad una rete WiFi con controllo dello stato di connessione

#include <WiFi.h> 

const char *ssid = "tessarolo"; // char* = vettore di caratteri (char[] = stringa)
const char *password = "password";

void setup() {
  Serial.begin(115200); // Inizializza la comunicazione seriale a 115200 baud (bit al secondo)
  delay(10);

  Serial.println();
  Serial.print("[WiFi] Connecting to ");
  Serial.println(ssid); // stampa il nome della rete a cui ci si sta connettendo (es. tessarolo)

  WiFi.begin(ssid, password); // connessione alla rete Wi-Fi con nome "tessarolo" e password "password"
  // Auto reconnect is set true as default
  // To set auto connect off, use the following function
  //    WiFi.setAutoReconnect(false);

  // Proviamo a connetterci alla rete Wi-Fi per 10 secondi (500ms x 20 tentativi)
  int tryDelay = 500; // delay = ritardo di 500 ms
  int numberOfTries = 20; // numero di tentativi di connessione (20)

  // Wait for the WiFi event
  while (true) {

    /*
    
    WiFi.status() restituisce lo stato della connessione Wi-Fi:
    - WL_NO_SSID_AVAIL: SSID non trovato
    - WL_CONNECT_FAILED: connessione fallita
    - WL_CONNECTION_LOST: connessione persa
    - WL_SCAN_COMPLETED: scansione completata
    - WL_DISCONNECTED: Wi-Fi disconnesso
    - WL_CONNECTED: Wi-Fi connesso    
    */

    switch (WiFi.status()) { // switch = seleziona il caso in base al valore di WiFi.status()
      case WL_NO_SSID_AVAIL: Serial.println("[WiFi] SSID not found"); break; 
      // if (Wifi.status() == WL_NO_SSID_AVAIL) { Serial.println("[WiFi] SSID not found"); }
      // equivalente 
      // break = esce dallo switch perché ha eseguito un certo caso specifico
      case WL_CONNECT_FAILED:
        Serial.print("[WiFi] Failed - WiFi not connected! Reason: ");
        return;
        break;
      case WL_CONNECTION_LOST: Serial.println("[WiFi] Connection was lost"); break;
      case WL_SCAN_COMPLETED:  Serial.println("[WiFi] Scan is completed"); break;
      case WL_DISCONNECTED:    Serial.println("[WiFi] WiFi is disconnected"); break;
      case WL_CONNECTED:
        Serial.println("[WiFi] WiFi is connected!");
        Serial.print("[WiFi] IP address: ");
        Serial.println(WiFi.localIP()); // stampa l'indirizzo IP del dispositivo
        return;
        break;
      default:
        Serial.print("[WiFi] WiFi Status: ");
        Serial.println(WiFi.status());
        break;
    }
    delay(tryDelay); // spara un ritardo di 500 ms

    if (numberOfTries <= 0) {
      Serial.print("[WiFi] Failed to connect to WiFi!");
      // Use disconnect function to force stop trying to connect
      WiFi.disconnect();
      return;
    } else {
      numberOfTries--; // decrementa il numero di tentativi (es. da 20 passiamo a 19, etc.)
    }
  }
}

void loop() {

}
