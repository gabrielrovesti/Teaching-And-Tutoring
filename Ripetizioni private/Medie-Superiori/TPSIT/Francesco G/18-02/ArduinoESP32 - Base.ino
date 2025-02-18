/*
ESP32

- STA (Station) -> Client
- Access Point (AP) -> Dispositivo di collegamento per rete Wi-Fi

            (WIFI)
              |
[CL1] <---> [AP] <---> [CL2]

- Server + AP
*/

// (1) Librerie

#include <WiFi.h> // STA / Server
#include <WiFiAP.h> // AP

// (2) Configurazione dell'AP (Access Point)

// Nome della rete - SSID 
const char *ssid = "ReteDiCasa"; // Nome della rete da creare
// Password della rete
const char *password = "12345678"; // (min 8 caratteri)

const int ledPin = 2;

// Impostazione (1) come Access Point

void setup(){

    Serial.begin(115200); // sempre fatto
    // esempio accensione pin
    pinMode(ledPin, OUTPUT);

    WiFi.begin(ssid, password); // creazione di una rete Wi-Fi con nome "ssid" e "password"
    // Avvia l'Access Point
    WiFi.softAP(ssid, password); // crea rete e avvia access point

    // IPAddress = Classe Arduino per IP Statici
    IPAddress myIP = WiFi.softAPIP(); // Prendi e stampa l'indirizzo dell'AP
    // Di default sarà una cosa del tipo 192.168.4.1

    Serial.print("Avvia la rete");
}

// Impostazione (1) come Client

void setup(){
    Serial.begin(115200); // sempre fatto

    // Sei un client
    WiFi.mode(WIFI_STA); // Impostati a modalità Station (Client)
    // Disconnessione
    WiFi.disconnect();
    delay(100);
}
