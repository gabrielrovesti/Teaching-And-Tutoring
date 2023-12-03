/*
 * Circuito:
 * Led collegato al pin 2 
 * e potenziometro collegato 
 * al pin A0
 * 
 * Esercizio:
 * Accendere il led esclusivamente
 * quanto il valore letto dal potenziometro 
 * supera la metà
 */
void setup() {
  pinMode(2,OUTPUT);
  pinMode(A0,INPUT);
}

void loop() {
  int pot;
  pot = analogRead(A0);
  if(pot > 511){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2,LOW);
  }
}
