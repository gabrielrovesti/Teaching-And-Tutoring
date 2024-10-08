/*
   Scrivere un programma che permetta
   di accendere un led collegato al
   pin 4 di Arduino esclusivamente quando
   si riceve il carattere ‘$’ dalla
   comunicazione seriale e lo spegna
   esclusivamente quando si riceve il carattere ‘!’.
*/

void setup() {
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int dato;
    dato = Serial.read();
    if (dato == '$') {
      digitalWrite(4, HIGH);
    }
    if (dato == '!') {
      digitalWrite(4, LOW);
    }
  }
}
