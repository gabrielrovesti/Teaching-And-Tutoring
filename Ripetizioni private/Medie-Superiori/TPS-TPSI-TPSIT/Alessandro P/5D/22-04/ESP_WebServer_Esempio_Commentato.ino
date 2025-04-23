// ESP_WebServer_Esempio_Commentato.ino
// Esempio completo discusso insieme

// Libreria 
#include <WebServer.h>
#include <WiFi.h>

// HTTP (?)
// Client/Server

// Wi-Fi -> Nome (SSID) / Password (Pwd)

const char* ssid = "NomeRete";
const char* password = "Password";
// (*) -> Asterisco = Equivalenza tra puntatori e array

// Creazione oggetto WebServer
WebServer server(80); // HTTP porta

// Metodi aggiuntivi gestione rotte

// Root = Index = Homepage
void handleRoot(){
    String html = "<!DOCTYPE html><html>";
    html += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
    html += "<title>Login</title></head>";
    html += "<body><h1>Login</h1>";
    html += "<form action=\"/login\" method=\"post\">";
    html += "Username: <input type=\"text\" name=\"username\"><br>";
    html += "Password: <input type=\"password\" name=\"password\"><br>";
    html += "<input type=\"submit\" value=\"Login\">";
    html += "</form></body></html>";
    
    server.send(200, "text/html", html);
}



void setup(){
    Serial.begin(115200); // Inizializzazione a solita freq. di baud


    WiFi.mode(WIFI_STA); // STA = Station = Client
    // Avviare la connessione wifi e finché non è connesso stampa punti
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    // Chiamata GET e POST
    server.on("/link", HTTP_GET, [](){
        String id = server.arg("id");
        String valore = server.arg("valore");
        
        Serial.println("ID: " + id);
        Serial.println("Valore: " + valore);
        
        server.send(200, "text/plain", "Parametri ricevuti: ID=" + id + ", Valore=" + valore);
    });

    server.on("/submit", HTTP_POST, []() {
        String username = server.arg("username");
        String password = server.arg("password");
        
        Serial.println("Username: " + username);
        Serial.println("Password: " + password);
        
        server.send(200, "text/plain", "Dati ricevuti");
      });

    server.begin(); // Avvio server
}

void loop(){
    // Gestione dei client
    server.handleClient();
}