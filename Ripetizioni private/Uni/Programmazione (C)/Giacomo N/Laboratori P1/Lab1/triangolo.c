#include <stdio.h>

/*
 * Scrivete un programma che definisca una costante ALTEZZA=x e disegni un triangolo rettangolo di base ed 
 * altezza x, utilizzando il carattere #. 
 * In particolare il programma stamperà # una volta per la prima riga, # due volte per la seconda riga, 
 * fino a stampare # x volte per la x-esima riga. 
 *
 * Per esempio se ALTEZZA=3 si ottiene il seguente output: 
 * #
 * ##
 * ###
 * 
 * Per la consegna utilizzare ALTEZZA=13
 */

/*
 * Suggerimento: utilizzare due for, uno all'interno
 * dell'altro. Quello interno si deve occupare di
 * stampare il numero corretto di # per la 
 * riga corrente, quello più esterno deve essere 
 * eseguito per ogni riga. 
 * 
 */

int main (void) {

  int i,j;
  const int ALTEZZA = 13;

  /* 
     Poiché non vogliamo cambiare il codice ogni volta che modifichiamo ALTEZZA, dobbiamo prevedere un ciclo 
     per la stampa delle righe del triangolo. 
     Quanti caratteri dobbiamo stampare ad ogni riga? 1 per la prima, 2 per la seconda, 3 per la terza, ecc.. 
     quindi in generale i caratteri per la i-esima riga. 
     Poiché il numero di righe, dalla definizione del problema è ALTEZZA, si dovrà fare un ciclo di ALTEZZA 
     iterazioni.
  */

  for (i=1; i<=ALTEZZA; i+=1) { // il triangolo ha altezza ALTEZZA, per cui si stampano ALTEZZA righe
    for (j=1; j<=i; j+=1) { // stampa i caratteri sulla i-esima riga
      printf("#");
    }
    printf("\n");
  }
 
}
