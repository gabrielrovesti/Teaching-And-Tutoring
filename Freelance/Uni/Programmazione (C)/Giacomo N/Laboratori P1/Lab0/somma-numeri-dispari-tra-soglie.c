#include <stdio.h>

/*
* Dati due numeri n1 e n2, tali che n1 <= n2, stampare tutti i numeri dispari d tali che n1 < d < n2 (andando a capo dopo ogni numero).
* Esempio: se n1 = 5 e n2 = 13 il programma deve stampare:
* 7
* 9
* 11
*
* Per la consegna usate n1 = 21 e n2 = 47
*/

int main() {
    int n1 = 21;
    int n2 = 47;

    for (int d = n1 + 1; d < n2; d += 1) {
      if (d % 2 != 0) {
        printf("%d\n", d);
      }
    }
}
