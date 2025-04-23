// ESP32 - Webserver - Autenticazione

/*
Form di autenticazione

|   ---- -> Utente    ---- -> Password   (Invia)   |
*/

// (1) Inclusione librerie
#include <WebServer.h> // Libreria WebServer
#include <WiFi.h> // Imposta client e server

// (2) Configurazione Wi-Fi (SSID=Nome + Password) -> stringa
const char* ssid     = "RetediCasa";
const char* password = "password";

// Creare un server 
WebServer server(80);   // 80 = Porta = HTTP

// Ti crei prima la pagina come stringa

// --- HTML templates ---
const char* loginForm = R"rawliteral(
    <!DOCTYPE html>
    <html>
      <head><title>Login</title></head>
      <body>
        <h2>Login</h2>
        <form action="/login" method="POST">
          Username: <input name="user" type="text"><br>
          Password: <input name="pwd" type="password"><br>
          <input type="submit" value="Entra">
        </form>
      </body>
    </html>
    )rawliteral";

// Pagina principale contiene il modulo(form) di autenticazione
void handleRoot(){
    server.send(200, "text/html", loginForm);
}

// --- Esempio GET: legge argomenti query ---
void handleGetExample() {
    if (server.hasArg("param")) {
      String val = server.arg("param");
      server.send(200, "text/plain", "Hai passato GET param= " + val);
    } else {
      server.send(400, "text/plain", "Manca parametro 'param'");
    }
}

// https://www.google.com/nome (controllo se link ha un parametro)

void handlePostForm() {
    server.send(200, "text/html", postForm);
}
  
  void handlePostExample() {
    String d = server.arg("data");
    server.send(200, "text/plain", "Hai inviato POST data= " + d);
}
  

const String validUser = "admin";
const String validPwd  = "1234";

void handleLogin(){
    // Logica del login - Vogliamo utente e password

    // arg = Metodo per prendere i dati passati

    String user = server.arg("user");
    // Ti prendi come server il dato "user"
    String pwd = server.arg("pwd");
    // Ti prendi come server il dato "pwd"

    if (user == validUser && pwd == validPwd) {
        // Se con successo, entra in area riservata
        server.sendHeader("Location", "/dashboard");
        server.send(303, "text/plain", "Login completato");
        // Connessione con successo
    } 
    else {
        server.send(401, "text/html", "<h3>Credenziali errate</h3><a href=\"/\">Riprova</a>");
    } 
}

void handleDashboard(){
    const char* paginaDashboard = "<!DOCTYPE html>";
    paginaDashboard += "<html>";
    paginaDashboard += "<head><title>Dashboard</title>";
    paginaDashboard += "</html>";

    server.send(200, "text/html", paginaDashboard);
}

void setup(){
    Serial.begin(115200);

    // Connessione al Wi-Fi con nome e password
    WiFi.begin(ssid, password);

    Serial.print("Connessione a Wi-Fi");
    // Finché non sei connesso, stampa "."
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print('.'); 
    }
    
    // Connessione riuscita, stampiamo dati connessione
    Serial.println("Connesso!");
    Serial.print("IP locale: ");
    Serial.println(WiFi.localIP()); // Indirizzo IP Wi-Fi -> 192.168.1.1 (Esempio)

    // Gestione server / client
    // Rotte di navigazione -> GET / POST

    // - (/) Pagina principale

    // on = Funzione che permette di gestire tutti i casi
    // Per ogni pagina, una funzione -> handleRoot per pagina principale
    // GET = Carichiamo - POST = Mandare dati

    server.on("/", HTTP_GET, handleRoot); // root = radice = pagina principale

    // https://www.gabriel.com/

    // - Login - Prima di entrare

    server.on("/login", HTTP_POST, handleLogin);
    // POST perché all'invio lanciamo nome utente e password

    |   Utente      (....)      |
    |   Password    (....)      |
                (Invia)

    // Client chiede https://www.gabriel.com/login a server e gli risponde con la pagina

    // - Dashboard (Area riservata)

    server.on("/dashboard", HTTP_GET, handleDashboard);

    // Client chiede https://www.gabriel.com/dashboard a server e gli risponde con la pagina

    server.on("/get-example", HTTP_GET, handleGetExample);
    server.on("/post-example", HTTP_GET, handlePostForm);
    server.on("/post-example", HTTP_POST, handlePostExample);

    // 404 - Non trovato
    server.onNotFound([]() {
        server.send(404, "text/plain", "Pagina non trovata");
        // Server invia il codice (404 = Page not found (HTTP), in testo in chiaro
        // con il messaggio "Pagina non trovata"
    });

    // Lancia il server - Inizia
    server.begin();
}

void loop(){
    // Gestione dei client - Handle (Gestire)
    server.handleClient();
    // Ad ogni ciclo, continui come WebServer a gestire il traffico
}

