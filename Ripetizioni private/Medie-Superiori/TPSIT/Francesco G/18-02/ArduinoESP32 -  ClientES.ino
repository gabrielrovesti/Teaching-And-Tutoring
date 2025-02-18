// TERZO - ClientES

// (1) Libreria WiFi
#include <WiFi.h>

// (2) Impostazione dati WiFi

// Nome della rete = SSID
const char* ssid = "Nome";
// Password
const char* password = "12345678";

// (3) Client - Statico (Esistono tanti = IP manuale)
const char* host = "192.168.1.12";
const int port = 3458;

// Setup 

void setup(){
    Serial.begin(115200);

    WiFi.begin(ssid, password); // crea rete WiFi

    // Stato connessione
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
    }

    // Inizializzazione client
    Serial.println(WiFi.localIP());
}

// Loop

void loop(){
    NetworkClient client;

    // Vedere stato client
    // Finché è connesso
    while(client.connect(host, port)){
        client.write(200);

        while(client.available() > 0){
            Serial.print("Client connesso");
        }
        client.stop();
        delay(5000);
    }
}