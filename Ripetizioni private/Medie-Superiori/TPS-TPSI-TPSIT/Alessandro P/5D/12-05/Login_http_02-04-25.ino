#include <WiFi.h>
#include <WebServer.h>
#include "pagine.h"

const char *ssid = "tessarolo";
const char *password = "PArbEKar12";

WebServer server(80);

void homePage(){
  server.send(200, "text/html", loginPage);
}

void login(){
  bool usernameAdmin=false;
  bool passwordAdmin=false;
  bool username=false;
  bool password=false;
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
  if(usernameAdmin==true && passwordAdmin==true){
    server.send(200, "text/html", adminPage);    
  }
  else{
    if(username==true && password==true){
      server.send(200, "text/html", clientPage);    
    }
    else{
      server.send(200, "text/html", loginPageError);
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

  server.on("/", homePage);
  server.on("/index.html", homePage);
  server.on("/login.html", login);

  server.onNotFound(handleNotFound);

  server.begin();
}

void loop(void) {
  server.handleClient();
  delay(2);
}
