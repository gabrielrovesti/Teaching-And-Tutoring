#include <WiFi.h> // Uguale a prima
#include <WebServer.h> // Per creare un server su una porta
#include "pagine.h" // File a parte con le stringhe contenenti i pezzi di pagina

// Dati Wi-Fi a cui si è connessi
const char *ssid = "tessarolo";
const char *password = "PArbEKar12";

// Apriamo un server HTTP sulla porta 80
WebServer server(80);

// Gestione pagina home
void homePage(){
  server.send(200, "text/html", loginPage);
}

// Gestione autenticazione
void login(){
  bool usernameAdmin=false;
  bool passwordAdmin=false;
  bool username=false;
  bool password=false;
  for (uint8_t i = 0; i < server.args(); i++) {
    // Se lo username è admin = admin entrerà nelle sue pagine
    if(server.argName(i)=="username" && server.arg(i)=="admin")
      usernameAdmin=true;
    // Se l'admin ha messo la password corretta ("1234")
    if(server.argName(i)=="password" && server.arg(i)=="1234")
      passwordAdmin=true;
    // Stesso per il client -> username == "client"
    if(server.argName(i)=="username" && server.arg(i)=="client")
      username=true;
    // Se username ha messo la password corretta ("pass")
    if(server.argName(i)=="password" && server.arg(i)=="pass")
      password=true;
   }
  // Se l'admin ha messo i dati giusti, lo mandiamo alla sua pagina
  if(usernameAdmin==true && passwordAdmin==true){
    server.send(200, "text/html", adminPage);    
  }
  else{
    // Se il client ha messo i dati giusti, lo mandiamo alla sua pagina
    if(username==true && password==true){
      server.send(200, "text/html", clientPage);    
    }
    else{
      // Errore altrimenti
      server.send(200, "text/html", loginPageError);
    }
  }
}

// Uguale a prima
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
  // Uguale a prima
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Gestione pagine
  server.on("/", homePage);
  server.on("/index.html", homePage);
  server.on("/login.html", login);
  // Gestione 404
  server.onNotFound(handleNotFound);
  // Avvio server
  server.begin();
}

void loop(void) {
  server.handleClient();
  delay(2);
}
