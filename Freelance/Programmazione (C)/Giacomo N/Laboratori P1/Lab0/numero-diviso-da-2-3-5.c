#include <stdio.h>

/*
* Dato un numero n, verificare se è o non è diviso da almeno uno dei numeri 2, 3 o 5.
* Esempi:
* 1) Se n = 9, stampare "9 è diviso da 2, 3 o 5"
* 2) Se n = 30, stampare "30 è diviso da 2, 3 o 5"
* 3) Se n = 31, stampare "31 non è diviso da 2, 3 o 5"
* 4) Se n = 1, stampare "1 non è diviso da 2, 3 o 5"
*
* Per la consegna usare n = 791
*/

int main() {
    int n1=791;

    printf("%d ", n1);

    if (n1 % 2 != 0) {
      printf("non ");
    } else if (n1 % 3 != 0) {
      printf("non ");
    } else if (n1 % 5 != 0) {
      printf("non ");
    }

    printf("è diviso da 2, 3 o 5\n");
}
