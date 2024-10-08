/*
 *Quando viene premuto un pulsante collegato in configurazione 
 *pull-up emettere un suono alla frequenza di 1568Hz
 */
 void setup() {
  pinMode(10,OUTPUT);//pin del Buzzer impostato in output
  pinMode(3,INPUT);//pin del pulsante impostato in input

}

void loop() {
  int valorePulsante;
  valorePulsante = digitalRead(3);//Leggo lo stato del pulsante (se premuto vale 0, se non premuto vale 1)
  if(valorePulsante == 0){
    tone(10,1568);//Entro se il pulsante è premuto, quindi genero il suono
  }
  else{
    noTone(10);//Entro se il pulsante non è premuto, quindi fermo la riproduzione di un possibile suono
  }
}
