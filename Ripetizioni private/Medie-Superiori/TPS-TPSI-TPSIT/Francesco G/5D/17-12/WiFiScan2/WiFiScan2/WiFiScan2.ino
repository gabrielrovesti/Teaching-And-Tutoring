// PRIMO - Scansione delle reti Wi-Fi e accensione del LED in base alla forza del segnale

/*

In questo caso:
- Il programma si ferma e aspetta che la scansione sia completata
- Blocca tutte le altre operazioni mentre scansiona
- È come fare la fila al supermercato: devi aspettare il tuo turno prima di poter fare altro

*/

#include "WiFi.h" // Wi-Fi libreria: include server, client, access point
const int pinLED = 18; 

void setup() {
  Serial.begin(115200); // Inizializza la comunicazione seriale a 115200 baud (bit al secondo)

  // Setta la modalità Wi-Fi in Station Mode (station = client) e disconnette
  WiFi.mode(WIFI_STA); 
  WiFi.disconnect(); // si disconnette perché dopo un certo tempo non trova l'aggancio alla rete
  delay(100); // delay = ritardo di 100 ms
  
  pinMode (pinLED, OUTPUT);
}

void loop() {

  // Ritorno in "n" il numero di reti scannerizzate (n = 60)
  int n = WiFi.scanNetworks(); // se non mettiamo true, la scansione è sincrona (blocca il programma)
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n); // es. stampo n=60
    Serial.println(" networks found"); // stampo "60 networks found"
    Serial.println("Nr | SSID | RSSI | CH | Encryption | MAC"); // intestazione tabella
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.printf("%2d", i + 1);
      Serial.print(" | ");
      Serial.printf("%-32.32s", WiFi.SSID(i).c_str()); // stampa il nome della rete (SSID) (es. WINDTRE-AF8865)
      Serial.print(" | ");
      Serial.printf("%4ld", WiFi.RSSI(i)); // RSSI = forza del segnale (es. simbolo Wi-Fi)
      Serial.print(" | ");
      Serial.printf("%2ld", WiFi.channel(i)); // canale di trasmissione (es. 1, 6, 11) assegnato in quel momento
      Serial.print(" | ");
      switch (WiFi.encryptionType(i)) { // tipo di crittografia
        case WIFI_AUTH_OPEN:            Serial.printf("%-10.10s","open"); break;
        case WIFI_AUTH_WEP:             Serial.printf("%-10.10s","WEP"); break;
        case WIFI_AUTH_WPA_PSK:         Serial.printf("%-10.10s","WPA"); break;
        case WIFI_AUTH_WPA2_PSK:        Serial.printf("%-10.10s","WPA2"); break;
        case WIFI_AUTH_WPA_WPA2_PSK:    Serial.printf("%-10.10s","WPA+WPA2"); break;
        case WIFI_AUTH_WPA2_ENTERPRISE: Serial.printf("%-10.10s","WPA2-EAP"); break;
        case WIFI_AUTH_WPA3_PSK:        Serial.printf("%-10.10s","WPA3"); break;
        case WIFI_AUTH_WPA2_WPA3_PSK:   Serial.printf("%-10.10s","WPA2+WPA3"); break;
        case WIFI_AUTH_WAPI_PSK:        Serial.printf("%-10.10s","WAPI"); break;
        default:                        Serial.printf("%-10.10s","unknown");
      }

      Serial.print(" | ");
      Serial.print(WiFi.BSSIDstr(i)); // stampa l'indirizzo MAC della rete (es. 00:1a:2b:3c:4d:5e) - BSSID
      Serial.println();
      delay(10);

      int r = 0;
      for(int j=0; j<n;j++){
        if(WiFi.SSID(j).c_str() == "tessarolo"){ // se trova la rete "tessarolo"
          r=j;
        }
      }

      // a seconda della forza del segnale, accende il LED come le ondine del Wi-Fi
      
      if (WiFi.RSSI(r) > -15){ // se la forza del segnale è maggiore di -15
        digitalWrite (pinLED, HIGH);  // accende il LED
      }
      else if(WiFi.RSSI(r) > -20){ // mano a mano che la forza del segnale diminuisce, il LED lampeggia più lentamente (per far vedere che non è stabile = non c'è rete)
      // se mi avvicino, lampeggia più velocemente
       digitalWrite (pinLED, HIGH);
        delay(150);
        digitalWrite (pinLED, LOW);
        delay(150);
      }
      else if(WiFi.RSSI(r) > -45){
        digitalWrite (pinLED, HIGH);
        delay(250);
        digitalWrite (pinLED, LOW);
        delay(250);
      }
      else if(WiFi.RSSI(r) > -60){
        digitalWrite (pinLED, HIGH);
        delay(500);
        digitalWrite (pinLED, LOW);
        delay(500);
      }
      else if(WiFi.RSSI(r) > -80){
        
        digitalWrite (pinLED, HIGH);
        delay(1000);
        digitalWrite (pinLED, LOW);
        delay(1000);
      }
    }
  }
  Serial.println("");

  WiFi.scanDelete(); // cancella i risultati della scansione per liberare memoria

  delay(5000);
}
