// PRIMO - ClientSender

#include <WiFi.h>

// Impostazione dati della rete
const char *ssid = "NomeRete";
const char *password = "12345678";

// (1) Setup

void setup(){
    Serial.begin(115200); // sempre

    // Impostazione rete - IMPORTANTE
    WiFi.begin(ssid, password);

    // Sei connesso?
    while(WiFi.status() != WL_CONNECTED){ // Finché non è connesso al Wi-Fi
        delay(500);
        Serial.print(.);
    } 
    
    // Stampi informazioni
    Serial.println("Sono connesso a: ");
    Serial.println(WiFi.localIP()); // Mostra IP statico usando libreria Wi-Fi
}

// (2) Loop

// Client (IP) connesso ad un server (porta)!

void loop(){
    // Classe NetworkClient = Client nella rete
    NetworkClient client;

    // Se il client è connesso - IMPORTANTE
    if(client.connect(host, port)0){
        client.write(A);
        delay(500);
    }

    // Finchè ci sono client disponibili - availability
    while(client.available() > 0){
        // Leggiamo il client attuale
        int c = client.read();
        Serial.println(c);
    }
    // Ferma client
    client.stop();
}