/*
 * Leggere e stampare a monitor seriale il valore letto 
 * da un potenziometro collegato al pin A1 di Arduino Uno 
 * mappato nell'intervallo 0-100.
 */
 void setup() {
  pinMode(A1,INPUT);
  Serial.begin(9600);

}

void loop() {
  int valore;
  valore = analogRead(A1);
  valoreMappato = map(valore,0,1023,0,100);
  Serial.println(valoreMappato);
}
