#include <stdio.h>

/*
* Data una costante intera maggiore di 0 NUMERO_CASELLE e due variabili ki e kj tali che 0 <= ki, kj < NUMERO_CASELLE
* Scrivere un programma che stampi una scacchiera con NUMERO_CASELLE caselle e la pedina del re posizionata sulle coordinate (ki, kj)
* In particolare:
* 1) Per stampare i bordi orizzontali della scacchiera utilizzare il carattere "-"
* 2) Per stampare i bordi verticali della scacchiera utilizzare il carattere "|"
* 3) Per stampare le caselle nere della scacchiera utilizzare "#", per quelle bianche utilizzare " "
* 4) Per stampare il re utilizzare il carattere "K"
* Nota: la prima casella nell'angolo in alto a sinistra della scacchiera deve essere bianca.
*
* Esempio: se NUMERO_CASELLE = 4, ki = 1 e kj = 0 stampa:
* ------
* | # #|
* |K # |
* | # #|
* |# # |
* ------
*
* Per la consegna utilizzare NUMERO_CASELLE = 8, ki = 5, kj = 7
*/
int main () {
  const int NUMERO_CASELLE = 8;
  int ki = 5;
  int kj = 7;

  for (int i = 0; i < NUMERO_CASELLE + 2; i++) {
    for (int j = 0; j < NUMERO_CASELLE + 2; j++) {
      if (i == 0 || i == NUMERO_CASELLE + 1) printf("-");
      else if (j == 0 || j == NUMERO_CASELLE + 1) printf("|");
      else if (i == ki + 1 && j == kj + 1) {
        printf("K");
      } else if ((i + j) % 2 == 1) printf("#");
      else printf(" ");
    }
    printf("\n");
  }
}