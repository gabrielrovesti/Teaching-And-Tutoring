// ESP32_Summary_WebServer.ino
// File riassuntivo: Web server su ESP32 con gestione HTTP GET/POST e pagina di login

#include <WiFi.h>
#include <WebServer.h>

// --- Configurazione Wi-Fi ---
const char* ssid     = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// --- Credenziali di login ---
const String validUser = "admin";
const String validPwd  = "1234";

// Oggetto WebServer sulla porta 80
WebServer server(80);

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

const char* dashboardPage = R"rawliteral(
<!DOCTYPE html>
<html>
  <head><title>Dashboard</title></head>
  <body>
    <h2>Benvenuto in dashboard</h2>
    <p>Operazioni disponibili:</p>
    <ul>
      <li><a href="/get-example?param=hello">Esempio GET</a></li>
      <li><a href="/post-example">Esempio POST</a></li>
    </ul>
  </body>
</html>
)rawliteral";

// --- Handler root: mostra form di login ---
void handleRoot() {
  server.send(200, "text/html", loginForm);
}

// --- Handler login: elabora POST ---
void handleLogin() {
  String user = server.arg("user");
  String pwd  = server.arg("pwd");

  if (user == validUser && pwd == validPwd) {
    // Redirect a dashboard
    server.sendHeader("Location", "/dashboard");
    server.send(303, "text/plain", "");
  } else {
    server.send(401, "text/html", "<h3>Credenziali errate</h3><a href=\"/\">Riprova</a>");
  }
}

// --- Handler dashboard ---
void handleDashboard() {
  server.send(200, "text/html", dashboardPage);
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

// --- Esempio POST: form POST ---
const char* postForm = R"rawliteral(
<!DOCTYPE html>
<html>
  <head><title>POST Example</title></head>
  <body>
    <h2>Submit POST</h2>
    <form action="/post-example" method="POST">
      Dato: <input name="data" type="text"><br>
      <input type="submit" value="Invia">
    </form>
  </body>
</html>
)rawliteral";

void handlePostForm() {
  server.send(200, "text/html", postForm);
}

void handlePostExample() {
  String d = server.arg("data");
  server.send(200, "text/plain", "Hai inviato POST data= " + d);
}

// --- Setup e loop principale ---
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connessione a Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }
  Serial.println(" connesso");
  Serial.print("IP locale: ");
  Serial.println(WiFi.localIP());

  // Definizione rotte HTTP
  server.on("/", HTTP_GET, handleRoot);
  server.on("/login", HTTP_POST, handleLogin);
  server.on("/dashboard", HTTP_GET, handleDashboard);
  server.on("/get-example", HTTP_GET, handleGetExample);
  server.on("/post-example", HTTP_GET, handlePostForm);
  server.on("/post-example", HTTP_POST, handlePostExample);
  server.onNotFound([]() {
    server.send(404, "text/plain", "Pagina non trovata");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
