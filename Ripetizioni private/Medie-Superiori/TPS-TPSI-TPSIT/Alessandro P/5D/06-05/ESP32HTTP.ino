/*******************************
 * Client (1) - ClientHTTP.ino *
 *******************************
 */

#include <WiFI.h>

// Wi-Fi -> SSID / Password
// Const char* = Puntatore a caratteri = Vettore
const char* ssid = "NomeRete";
const char* psw = "NomeRete";

// Dove ci connettiamo
const char* host = "google.com"
const int httpPort = 80;

void setup(){
    Serial.begin(115200);

    // Connessione Wi-Fi
    WiFi.begin(ssid, psw);

    // Finché non ci siamo connessi...
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }

    // Stampa dati rete connessa
    Serial.println("");
    Serial.println("WiFi connesso!");
    Serial.println("Indirizzo IP: ");
    Serial.println(WiFi.localIP());
}

void loop(){
    // Classe per Client dentro WiFi
    WifiClient client;

    // Se client connesso allora verifica e stampa dati
    if(client.connect(host, httpPort)){
        Serial.println("Bene, mi sono connesso");
        // Esempio timeout da quando si avvia (unsigned long = simil double sempre positivo)
        unsigned long timeout = millis();
        // Finché ci sono client disponibili
        while(client.available()){
            if (millis() - timeout > 5000) {
                Serial.println("Timeout client: lo fermiamo!");
                client.stop();
                return;
            }
        }

        // Finché ci sono client, continua stampare i dati
        while (client.available()) {
            String line = client.readStringUntil('\r');
            Serial.print(line);
        }
    }
    // Altrimenti non ci siamo connessi
    else {
        Serial.print("Non riesco a connettermi");
    }
    delay(100000);
}

/*******************************
 * (2) Server - HelloServer.ino *
 *******************************
 */
#include <WiFi.h>
#include <WebServer.h>

// Creazione dati Wi-Fi
const char *ssid = "tessarolo";
const char *password = "PArbEKar12";

// Creazione oggetto server
WebServer server(80);

void setup(void){
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // MDNS = Lanciare ESP32 - se link inizia con ESP32 allora stampa
    if (MDNS.begin("esp32")) {
        Serial.println("MDNS responder started");
    }

    // Gestione delle pagine = on (richiamo una funzione per ogni pagina)
    server.on("/", handleRoot);
    server.on("/on", handleOn); // esempio pagina "on"
    server.onNotFound(handleNotFound); // 404

    server.begin(); // Lancio server
}

void handleRoot(){
    // Gestione richieste Server
    Serial.println("LED Acceso")
    // Client richiede connessione, server fornisce pagina
    server.send(200, "text/html", "<a href='/inline'>spegni</a>");
}

void handleOn(){
    Serial.println("LED SPENTO");
    server.send(200, "text/html", "<a href='/'>accendi</a>");
}

void handleNotFound() {
    String messaggio = "File non trovato.\n\n";
    // Concatenazione formato stringa del messaggio
    messaggio += "URI: ";
    messaggio += server.uri();
    messaggio += "\nMethod: ";
    messaggio += (server.method() == HTTP_GET) ? "GET" : "POST";
    messaggio += "\nArguments: ";
    messaggio += server.args();
    messaggio += "\n";
    for (uint8_t i = 0; i < server.args(); i++) {
        messaggio += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }
    server.send(404, "text/plain", message);
  }

void loop(void){
    server.handleClient(); // nel loop, gestisco i client.
    delay(2);
}

/*******************************
 * (3) Server - HTTPLogin.ino *
 *******************************
 */
/*
    |---------------------|
    | Username |________| |
    | Password |________| |
    |                     |
    |       (Invia)       |
    |---------------------|

*/

#include <WiFi.h>
#include <WebServer.h>
#include "pagine.h" // Dentro questo file abbiamo tutte le pagine

const char *ssid = "tessarolo";
const char *password = "PArbEKar12";

WebServer server(80);

void homePage(){
  server.send(200, "text/html", loginPage); // Accesso alla pagina di login
}

// Funzione di login = Verifica se user e psw corrispondono!

void login(){
  bool usernameAdmin = false;
  bool passwordAdmin = false;
  bool username = false;
  bool password = false;
  for (uint8_t i = 0; i < server.args(); i++) {
    if(server.argName(i)=="username" && server.arg(i)=="admin")
      usernameAdmin=true;
    if(server.argName(i)=="password" && server.arg(i)=="1234")
      passwordAdmin=true;
    if(server.argName(i)=="username" && server.arg(i)=="client")
      username=true;
    if(server.argName(i)=="password" && server.arg(i)=="pass")
      password=true;
   }
  if(usernameAdmin == true && passwordAdmin == true){
    server.send(200, "text/html", adminPage);    // se admin, dai la pagina ad admin -> adminPage
  }
  else{
    if(username==true && password==true){
      server.send(200, "text/html", clientPage);    // se client, dai la pagina al client -> clientPage
    }
    else{
      server.send(200, "text/html", loginPageError); // se login errato, manda in pagina di errore
    }
  }
}


void handleNotFound() {
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += server.uri();
    message += "\nMethod: ";
    message += (server.method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += server.args();
    message += "\n";

    for (uint8_t i = 0; i < server.args(); i++) {
        message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }
    
    server.send(404, "text/plain", message);
}

void setup(void) {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // Gestione delle pagine di compilazione
    server.on("/", homePage);
    server.on("/index.html", homePage);
    server.on("/login.html", login);
    server.onNotFound(handleNotFound);
    
    // Avvio del server
    server.begin();
}

void loop(void) {
    server.handleClient();
    delay(2);
}

/*** SStruttura/contenuto del file "pagine.h" */

String loginPage=
"<!DOCTYPE html>"
"<html"
"   <body>"
"     <form action='/login.html' method='post'>"
"       <label>Username:</label><input type='text' name='username'><br>"
"       <label>Password:</label><input type='password' name='password'><br><br>"
"       <input type='submit' value='Submit'>"
"     </form>"
"   </body>"
"</html>";

String loginPageError=
"<!DOCTYPE html>"
"<html"
"   <body>"
"     Username o password errati"
"     <form action='/login.html' method='post'>"
"       <label>Username:</label><input type='text' name='username'><br>"
"       <label>Password:</label><input type='password' name='password'><br><br>"
"       <input type='submit' value='Submit'>"
"     </form>"
"   </body>"
"</html>";

String adminPage=
"<!DOCTYPE html>"
"<html"
"   <body>"
"     Pannello Admin"
"   </body>"
"</html>";

String clientPage=
"<!DOCTYPE html>"
"<html"
"   <body>"
"     Pannello Client"
"   </body>"
"</html>";
