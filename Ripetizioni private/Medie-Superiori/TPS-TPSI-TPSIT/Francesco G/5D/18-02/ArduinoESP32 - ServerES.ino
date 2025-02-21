// Quarto - ServerES

// (1) Libreria WiFi
#include <WiFi.h>

// (2) Impostazione dati WiFi

// Nome della rete = SSID
const char* ssid = "Nome";
// Password
const char* password = "12345678";

// (3) Server
NetworkServer server(3459); // Server di solito uno = usiamo la classe Arduino

// Setup

void setup(){
    Serial.begin(115200);

    // Crea nome/dati server
    WiFi.setHostname("Server");
    WiFi.begin(ssid, password);

    // Stato connessione
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
    }

    // Inizializzazione/start server
    server.begin();
    delay(2000);
    IPAddress myIP = WiFi.localIP(); 
}

// Loop

// Accettiamo connessione client e leggiamo lo stato se va bene o meno
void loop(){
    NetworkClient client = server.accept();

    if(client){
        while(client.connected() && client.available()){
            char stato = client.read();
            if(stato != "g"){
                Serial.println("Non va bene");
            }
        }
    }
}