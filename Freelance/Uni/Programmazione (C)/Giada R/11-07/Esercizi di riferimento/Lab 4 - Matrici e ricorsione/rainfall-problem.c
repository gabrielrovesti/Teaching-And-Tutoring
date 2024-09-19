#include<stdio.h>

// Scrivere un programma che stampi la media dei valori positivi di un array, fino al valore di guardia 99999

/*
Scrivete un programma che, dato un array di N > 0 valori interi (una qualsiasi combinazione di numeri maggiori, minori o uguali a zero),
legga questi valori uno ad uno fino ad incontrare il valore di guardia 99999.
Dopo aver visto il valore di guardia il programma deve stampare la media dei valori positivi (> 0) letti fino a quel momento, escluso il valore di guardia.
Per i test automatici di Moodle potete assumere che l'array contenga sempre il valore di guardia.

Per stampare la media usate il seguente comando (senza spazi e senza a capo):
printf("%.2f", media);

Attenzione, per passare i test la stampa indicata qui sopra deve essere l'unico output del programma.

Note:
- Qualora la media da stampare fosse non definita (ad esempio perché non ci sono valori positivi nell'array), stampate il valore 0.00
- Per i test automatici di Moodle potete assumere che l'array contenga sempre il valore di guardia
*/

int main() {
  /*
    Le seguenti righe di codice (fino a INIZIO SOLUZIONE)
    servono per leggere l'input dei test automatici di Moodle
  */

  /*
  int N;
  // Legge da input la grandezza dell'array
  scanf("%d", &N);

  int array[N];

  // Legge da input i valori contenuti nell'array
  for(int i = 0; i < N; i++){
      scanf("%d", array+i);
  }
  */

 int N = 10;
 int array[] = {1, 42, 1, 3, 15, 0, 0 ,5, 9, 99999};

  // INIZIO SOLUZIONE
  // inserite il vostro codice qui sotto

  int GUARDIA = 99999;

  int numeri_letti = 0;
  int somma_numeri_letti = 0;

  int i = 0;
  // Verifica di non uscire dai confini dell'array e di terminare la
  // lettura non appena si incontra il valore di GUARDIA
  while (i < N && array[i] != GUARDIA) {
    // Verifica di sommare solo i numeri positivi (> 0)
    if (array[i] > 0) {
      numeri_letti += 1;
      somma_numeri_letti += array[i];
    }
    i += 1;
  }

  float media = 0;
  // Controlla il numero di valori letti per evitare una divisione per 0
  if (numeri_letti > 0) {
    media = (float)somma_numeri_letti / (float)numeri_letti;
  }

  printf("%.2f", media);
}