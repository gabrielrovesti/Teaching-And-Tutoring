/*
   Azione multipla: Alla prima pressione
   del pulsante visualizzare sul monitor
   seriale la scritta “Lunedì” e alla
   seconda “Martedì”. Se viene ancora
   premuto ripetere i due passaggi.
   (Pulsante in pull-down)
*/
int stato = 0;
void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int valorePulsante;
  valorePulsante = digitalRead(2);

  if (valorePulsante == 1) {
    if (stato == 0) {
      Serial.println("Lunedì");
      stato = 1;
    }
    else {
      if (stato == 1) {
        Serial.println("Martedì");
        stato = 0;
      }
    }
    do {
      valorePulsante = digitalRead(2);
    } while (valorePulsante == 1);
  }
}
