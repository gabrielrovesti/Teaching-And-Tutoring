 /*
 * Circuito:
 * C'è un led collegato al pin 10 
 * e un potenziometro collegato al pin A3
 * 
 * Esercizio:
 * Quando il valore letto dal potenziometro è
 * al minimo far lampeggiare il led lentamente.
 * Man mano che il valore letto aumenta aumentare la
 * la frequenza di lampeggio
 */
void setup() {
  pinMode(10, OUTPUT);
  pinMode(A3, INPUT);
}

void loop() {
  int pot;
  pot = analogRead(A3);

  digitalWrite(10, HIGH);
  delay(1200-pot);
  digitalWrite(10, LOW);
  delay(1200-pot);
  
}
