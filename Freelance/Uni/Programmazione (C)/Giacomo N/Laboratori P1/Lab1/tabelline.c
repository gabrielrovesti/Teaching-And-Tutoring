#include <stdio.h>

/*
 * Dati due interi n1 e n2 tali che n1 > 0, n2 > 0 e n1 <= n2, stampare le tabelline di tutti gli interi n tali che n1 <= n <= n2.
 * Per ogni valore n stampare quindi "n*1 n*2 n*3 ... n*10", separando ogni valore con uno spazio, e poi andare a capo.
 *
 * Esempio: se n1 = 3 e n2 = 5 il programma deve stampare
 *
 * "3 6 9 12 15 18 21 24 27 30
 * 4 8 12 16 20 24 28 32 36 40
 * 5 10 15 20 25 30 35 40 45 50
 *"
 *
 * Per la consegna usare n1 = 1 e n2 = 10
 */


int main () {

    int n1 = 1;
    int n2 = 10;

    for (int n = n1; n <= n2; n++) {
      for (int i = 1; i <= 10; i++) {
        int val = n * i;
        printf("%d ", val);
      }
      printf("\n");
    }
}
