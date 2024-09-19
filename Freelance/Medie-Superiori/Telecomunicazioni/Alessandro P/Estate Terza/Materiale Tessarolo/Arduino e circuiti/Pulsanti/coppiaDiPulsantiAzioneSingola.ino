/*
   Scrivere un programma che accenda il led
   integrato sulla scheda Arduino Uno alla
   pressione di un pulsante collegato al
   pin 3 in configurazione pull-up e lo spegna
   alla pressione di un pulsante collegato al
   pin 5 in configurazione pull-down.
*/
void setup() {
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
  pinMode(5, INPUT);
}

void loop() {
  int stato1;
  stato1 = digitalRead(3);
  if (stato1 == 0) {
    digitalWrite(13, HIGH);
  }
  int stato2;
  stato2 = digitalRead(5);
  if (stato2 == 1) {
    digitalWrite(13, LOW);
  }

}
