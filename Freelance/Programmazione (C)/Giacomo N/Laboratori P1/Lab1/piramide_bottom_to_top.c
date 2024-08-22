#include <stdio.h>

/*
 * Stampare una piramide rovesciata utilizzando il carattere #,  
 * in modo che la punta della piramide sia in basso e la base in alto. 
 * Per esempio se ALTEZZA=3 si ottiene il seguente output: 
 * 
 * #####
 *  ###
 *   #
 * 
 * Per la consegna utilizzare ALTEZZA=6
 * 
 */

/*
 * Suggerimento 1: Notate che, per ogni riga, la somma degli spazi prima,
 * dei caratteri # e degli spazi seguenti è costante (5 nell'esempio 
 * sotto). 
 *    
 * |#|#|#|#|#|
 * | |#|#|#| |
 * | | |#| | |
 *
 * Dividiamo il problema in due sottoproblemi:
 * 
 * 1) Quanti spazi devo stampare prima di stampare i caratteri # 
 *    della i-esima riga
 * 2) Quanti caratteri # devo stampare per la i-esima riga?
 * 
 * In entrambi i casi cerchiamo di esprimere queste quantità in funzione
 * del numero di riga (num_riga). 
 */

/* 
 * Suggerimento 2: calcoliamo il numero di spazi e di caratteri in 
 * funzione del numero di riga (di seguito assumo avere valori tra 
 * 1 ed ALTEZZA inclusi)
 * 
 * 1) numero spazi: si stampano 0 spazi per la prima riga, 1 
 * per la seconda, in generale i-1 spazi per la i-esima riga
 * 
 * 2) calcoliamo il numero totale di caratteri per una riga 
 * (spazi più #), che è costante, quindi in funzione di ALTEZZA:
 * ALTEZZA*2-1. A questo punto osserviamo che, per ogni riga, 
 * abbiamo lo stesso numero di spazi prima e dopo i caratteri #,
 * quindi il numero di caratteri # nella i-esima riga equivale
 * al numero totale dei caratteri di una riga meno 2 volte il 
 * numero di spazi stampati per quella riga.
 * 
 */

int main (void) {

  const int ALTEZZA = 6;
  int totale_caratteri_riga = ALTEZZA*2-1; // somma degli spazi e dei # per una riga
  int num_riga; // contatore: numero della riga che si sta stampando
  int j;
  
  for (num_riga=1; num_riga<=ALTEZZA; num_riga = num_riga + 1) { 
    // stampa la i-esima riga della piramide rovesciata, con i=num_riga
    
    // stampa tutti gli spazi iniziali della riga corrente
    for (j = 1; j < num_riga; j = j+1) { //stampa num_riga-1 spazi
      printf(" ");
    }

    //stampa tutti i caratteri # della riga corrente
    for (j = 1; j <= totale_caratteri_riga-(num_riga-1)*2; j += 1) { 
          /* 
            il numero di caratteri # da stampare lo calcoliamo come la differenza tra il totale di caratteri da stampare per una 
            riga (costante) e due volte gli spazi da stampare per una riga
          */  
      printf("#");
    }

    /* 
      notate che possiamo evitare di stampare gli spazi dopo 
      i caratteri # perché tanto a schermo non si vedono
    */

    printf("\n");  
  }  
  
}
