/*
 * Circuito:
 * Ci sono due led collegati al pin 3 e 4 
 * e un potenziometro collegato al pin A0
 * 
 * Esercizio:
 * Accendere il primo led esclusivamente
 * quanto il valore letto supera 700 altrimenti
 * acendere il secondo
 */
void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(A0,INPUT);
}

void loop() {
  int pot;
  pot = analogRead(A0);
  if(pot > 700){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else{
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
}
