// ESP32
// WiFi / Webserver

// Pagina di autenticazione (login) con HTTP
// Client / Server

#include <WiFi.h>
#include <WebServer.h>
// Librerie

// Server aperto su una porta (80 = HTTP)
WebServer server(80);
// Dati fissi Wi-Fi: SSID (Nome) e Password
// Array di caratteri -> const char*

const char* ssid = "NomeRete";
const char* password = "password";

// Funzioni per gestire le singole pagine
void handleHome(){
	Serial.println("LED ACCESO");
	server.send(200, "text/html", "<a href='/inline'>spegni</a>");
}

void handlePage2(){
	Serial.println("LED SPENTO");
	server.send(200, "text/html", "<a href='/'>accendi</a>");
}

void handleNotFound(){
	// Esempio di messaggio completo

	String message = "File Not Found\n\n";
	message += "URI: ";
	message += server.uri();
	message += "\nMethod: ";
	
	// Esempio di metodi HTTP: GET e POST
 	message += (server.method() == HTTP_GET) ? "GET" : "POST";
	message += "\nArguments: ";
	message += server.args();
	message += "\n";

	// uint8_t = intero *solo* positivo con lunghezza ad 8 bit

	for (uint8_t i = 0; i < server.args(); i++) {
		message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
	}
	server.send(404, "text/plain", message);
}

void login(){
	// Dati per utente admin
	bool usernameAdmin=false;
	bool passwordAdmin=false;

	// Dati per utente normale
  	bool username=false;
  	bool password=false;

	for (uint8_t i = 0; i < server.args(); i++) {
		if(server.argName(i)=="username" && server.arg(i)=="admin"
			usernameAdmin=true;

		if(server.argName(i)=="password" && server.arg(i)=="1234"
			passwordAdmin=true;

		if(server.argName(i)=="username" && server.arg(i)=="client"
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

void setup() {
	// Gestire i casi da server
	// Gestire le singole pagine di navigazione
	
	// Aprire connessione WiFi
	WiFi.begin(ssid, password);

  	while (WiFi.status() != WL_CONNECTED) {
   		delay(500);
    		Serial.print(".");
  	}
	
  	Serial.print("IP address: ");
  	Serial.println(WiFi.localIP());

	// Gestire le singole pagine (su = on)
	server.on("/home", handleHome);
	server.on("/page2", handlePage2);
	server.on("/login.html", login);

	// Gestione 404
	server.onNotFound(handleNotFound);

	// Avvio server
	server.begin();
}

void loop(){
	// Gestire client e attendere (brevemente) una risposta
	server.handleClient();
	delay(2);
}