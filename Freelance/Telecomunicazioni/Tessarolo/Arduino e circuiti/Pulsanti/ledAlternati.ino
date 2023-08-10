/*
 * Scrivere un programma che alterni 
 * l’accensione di tre led collegati alla 
 * scheda Arduino Uno. (frequenza a piacere)
 * (Led collegati ai pin 2,3,4)
 */
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(1000);

  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  delay(1000);
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(1000);
}
