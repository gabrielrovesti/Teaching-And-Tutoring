// QUARTO - Esempio di connessione a un server web con IP statico e invio di un messaggio

#include <WiFi.h>

const char *ssid = "tessarolo"; // nome wifi
const char *password = "password"; // password

// IPAddress = classe fornita da Arduino per gestire gli indirizzi IP

IPAddress local_IP(192, 168, 0, 33);  // IP statico = 192.168.0.33
IPAddress gateway(192, 168, 0, 1);   // gateway (router di passaggio per la connessione) = 192.168.0.1
IPAddress subnet(255, 255, 255, 0);  // subnet mask = serve per dividere la rete in sottoreti
// es. coppia (IP, subnet) = (192.168.0.3 - 255.255.255.0)
IPAddress primaryDNS(8, 8, 8, 8);    // DNS primario = serve per tradurre gli indirizzi IP in nomi di dominio
// es. scrivo www.google.com e il DNS traduce in automatico "123.456.789.123" per arrivarci
IPAddress secondaryDNS(8, 8, 4, 4); 

const char *host = "192.168.0.3";
const int httpPort = 80;

void setup() {
  Serial.begin(115200);

  // se non riesce a configurare l'IP statico 
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  // altrimenti, ti connetti (come nel caso precedente)
  Serial.print("Connecting to ");
  Serial.println(ssid); // nome rete (tessarolo)

  WiFi.begin(ssid, password); // inizia la connessione alla rete Wi-Fi (tessarolo, password)

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // stampa l'indirizzo IP del dispositivo (sopra. 192.168.0.33)
  Serial.print("ESP Mac Address: ");
  Serial.println(WiFi.macAddress()); // stampa l'indirizzo MAC del dispositivo (es. 00:1a:2b:3c:4d:5e)
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask()); // stampa la subnet mask (sopra. 255.255.255.0)
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP()); // stampa l'indirizzo IP del gateway (es. 192.168.0.1)
  Serial.print("DNS: ");
  Serial.println(WiFi.dnsIP()); // stampa l'indirizzo IP del DNS (es. 8.8.8.8.)
}

void loop() {
  NetworkClient client; // client = oggetto di tipo NetworkClient
  if(client.connect(host,httpPort)){ // se il client si connette all'host (gali, 80)
    client.println("Odorizzi");
    client.stop();
  }
  delay(1000);
}
