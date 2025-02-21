// SECONDO - ServerCodebreak

#include <WiFi.h>

// Impostazione dati della rete
const char *ssid = "NomeRete";
const char *password = "12345678";

// Hai bisogno di un server...
// Client -> NetworkClient
// Server -> NetworkServer
NetworkServer server(5000); // Crea server su una porta
// IP -> 192.70.50.2
// Porta -> 5000 (Servizio che si appoggia usando un canale)
// Socket -> IP + Porta

// (1) Setup

void setup(){
    Serial.begin(115200); // sempre

    // Impostazione rete - IMPORTANTE
    WiFi.begin(ssid, password);

    // Impostazione nome host (stazione)
    WiFi.setHostname("Cristiano");

    // Il client è connesso al server?
    while(WiFi.status() != WL_CONNECTED){ // Finché non è connesso al Wi-Fi
        delay(500);
        Serial.print(.);
    } 

    // Inizializziamo il server
    Server.begin();

    // Stampa impostazioni server
    IPAddress myIP = WiFi.localIP();
    Serial.println("Indirizzo IP: ");
    Serial.println(myIP);

}

// (2) Loop

int codice = 50; // stato good

// Accettare una connessione e vedere se ci sono client connessi
void loop(){
    NetworkClient client = server.accept(); // Client si connette ad un server

    // Se un client esiste
    if(client){
        // Finché ci sono client connessi e disponibili
        while(client.connected() && client.available()){
            // Leggiamo stato client
            int stato = client.read();
            if (stato == codice){ // se ci siamo connessi con succeso
                client.write(1337);
            }
        }
    }
}