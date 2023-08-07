/*
   Scrivere un programma che accenda il
   led integrato sulla scheda Arduino Uno
   esclusivamente alla pressione di un
   pulsante collegato al pin 3 in configurazione pull-up.
*/
void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}
void loop() {
  int stato;
  stato = digitalRead(2);
  if (stato == 0) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
}
