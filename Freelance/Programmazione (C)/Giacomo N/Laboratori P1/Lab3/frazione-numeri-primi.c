#include<stdio.h>

// Scrivere una funzione che stampi la frazione di numeri primi contenuti in un array

/*
Dato un array di interi di lunghezza N >= 0, scrivere un programma che stampi la frazione
di elementi dell'array che siano numeri primi.

Esempi:
* Se N = 10 e array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} stampa: "Frazione numeri primi: 0.50"
* Se N = 4 e array = {4, 6, 8, 9} stampa: "Frazione numeri primi: 0.00"
* Se N = 4 e array = {83, 1237, 11, 691} stampa: "Frazione numeri primi: 1.00"
* Se N = 0 e array = {} stampa: "Frazione numeri primi: 0.00"
*/

// PRE: n è un intero >= 1
// POST: restituisce 1 se n è un numero primo, 0 altrimenti
int numeroPrimo(int n);

int main(){
    /* Per comodità potete usare il codice sottostante
    invece che leggere gli input da tastiera.

    RICOMMENTATELO PRIMA DI CONSEGNARE
    */

    /*
    const int N = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    */

    /* Se usate le istruzioni qui sopra commentate fino a INIZIO SOLUZIONE */

    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    //leggere da input dati array
    for(int i = 0; i < N; i++){
        scanf("%d", array+i);
    }

    // INIZIO SOLUZIONE
    int numeriPrimi = 0;
    for (int i = 0; i < N; i+=1) {
      if (numeroPrimo(array[i])) {
        numeriPrimi += 1;
      }
    }

    float frazione = 0;
    if (N > 0) {
      frazione = (float)numeriPrimi / (float)N;
    }

    printf("Frazione numeri primi: %.2f\n", frazione);
}


int numeroPrimo(int n) {
  int primo = 1;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) primo = 0;
  }

  return primo;
}