#include <stdio.h>

/*
  Scrivete un programma che definisca una costante LATO=x e disegni un quadrato di lato x, utilizzando il carattere #. 
  In particolare si deve disegnare il perimetro del quadrato, ovvero l'interno del quadrato deve essere vuoto. 
 
  Per esempio se LATO=4 si ottiene il seguente output: 
  ####
  #  #
  #  #
  ####
  
  Per la consegna utilizzare LATO=8. Inoltre si richiede di utilizzare non più di due comandi for nel programma. 
 */

/*
 * Suggerimento: utilizzare due for annidati. Quello interno si deve occupare di stampare il numero corretto di # per la 
 * riga corrente (che è diverso a seconda che sia la prima, l'ultima o una riga interna), quello più esterno deve essere 
 * eseguito per ogni riga. 
 * 
 */


int main (void) {

  int riga, colonna;
  const int LATO = 8;

  for (riga=1; riga<=LATO; riga+=1) {
    for (colonna=1; colonna<=LATO; colonna+=1) {
        if(riga==1 || riga==LATO || colonna==1 || colonna==LATO)
          printf("#");
        else 
          printf(" ");
    }
    printf("\n");
  }

}
