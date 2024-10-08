#include <stdio.h>

/*
* Dato un numero n maggiore di zero, stampare la somma di tutti i numeri pari p tali che 1 <= p <= n.
* Esempi:
* 1) Se n = 10 stampare "somma finale = 30"
* 2) Se n = 30 stampare "somma finale = 240"
* 3) Se n = 1 stampare "somma finale = 0"
*
* Per la consegna usare n = 42
*/


int main() {
    int n = 42;
    int sum = 0;

    for (int i = 2; i <= n; i += 2) {
      sum += i;
    }

    printf("somma finale = %d", sum);
}
