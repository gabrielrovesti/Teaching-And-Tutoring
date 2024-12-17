// SECONDO - Ricerca delle reti Wi-Fi in modo asincrono

/*

In questo caso:

- Il programma avvia la scansione ma continua a eseguire altre operazioni
- Controlla periodicamente se la scansione è completa con WiFi.scanComplete()
- È come prendere il numeretto al supermercato: puoi fare altre cose mentre aspetti il tuo turno

*/

#include "WiFi.h"
const int pinLED = 18;
void setup() {
  Serial.begin(115200); // Inizializza la comunicazione seriale a 115200 baud (bit al secondo)
  WiFi.mode(WIFI_STA);  // Station = Client
  WiFi.disconnect();
  delay(100);
  WiFi.scanNetworks(true); // Inizia la scansione delle reti Wi-Fi (true = asincrono)
}

void loop() {
  int16_t WiFiScanStatus = WiFi.scanComplete(); // Ritorna il numero di reti scannerizzate (asincrono) o -1 se la scansione è in corso
  if (WiFiScanStatus >= 0) { // Se la scansione è completata (se ne arriva almeno una)
  // asincrona = non bloccante, stampa i risultati della scansione anche con qualsiasi stazione che arriva
    if (WiFiScanStatus == 0) {
      Serial.println("no networks found");
    } else {
      Serial.println("\nScan done");
      Serial.print(WiFiScanStatus);
      Serial.println(" networks found");
      Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
      for (int i = 0; i < WiFiScanStatus; ++i) {
        // Print SSID and RSSI for each network found
        Serial.printf("%2d", i + 1);
        Serial.print(" | ");
        Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
        Serial.print(" | ");
        Serial.printf("%4ld", WiFi.RSSI(i));
        Serial.print(" | ");
        Serial.printf("%2ld", WiFi.channel(i));
        Serial.print(" | ");
        switch (WiFi.encryptionType(i)) {
          case WIFI_AUTH_OPEN:            Serial.print("open"); break;
          case WIFI_AUTH_WEP:             Serial.print("WEP"); break;
          case WIFI_AUTH_WPA_PSK:         Serial.print("WPA"); break;
          case WIFI_AUTH_WPA2_PSK:        Serial.print("WPA2"); break;
          case WIFI_AUTH_WPA_WPA2_PSK:    Serial.print("WPA+WPA2"); break;
          case WIFI_AUTH_WPA2_ENTERPRISE: Serial.print("WPA2-EAP"); break;
          case WIFI_AUTH_WPA3_PSK:        Serial.print("WPA3"); break;
          case WIFI_AUTH_WPA2_WPA3_PSK:   Serial.print("WPA2+WPA3"); break;
          case WIFI_AUTH_WAPI_PSK:        Serial.print("WAPI"); break;
          default:                        Serial.print("unknown");
        }
        Serial.println();
        delay(10);

        int r = 0;
      for(int j=0; j<WiFiScanStatus;j++){
        if(WiFi.SSID(j).c_str() == "tessarolo"){
          r=j;
        }
      }
      
      if (WiFi.RSSI(r) > -15){
        digitalWrite (pinLED, HIGH);
      }
      else if(WiFi.RSSI(r) > -20){
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
      Serial.println("");
      WiFi.scanDelete();
    }
    WiFi.scanNetworks(true); // Inizia una nuova scansione asincrona
  }
  else {
    if (WiFiScanStatus == WIFI_SCAN_FAILED) { // Se la scansione è fallita 
      // Variable maiuscola = costante (non modificabile perché prevista dal linguaggio)
      Serial.println("WiFi Scan has failed. Starting again.");
      WiFi.scanNetworks(true); // inizia nuova scansione
    }
  }
}
