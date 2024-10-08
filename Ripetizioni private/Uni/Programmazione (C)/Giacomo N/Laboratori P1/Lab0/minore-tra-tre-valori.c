#include <stdio.h>

/*
 * Date 3 variabili intere: x, y e z, stampare il valore minore delle tre.
 * Esempi:
 *   1) Se x = 15, y = 7 e z = 18, stampare "Il minore dei tre valori è 7"
 *
 * Per la consegna usare x = 15, y = 7, z = 18 
 */

int main() {

    int x=15, y=7, z=18;

    printf("Il minore dei tre valori è ");

    if (x < y) { // so che x<y
        if (x < z) { // x < y e x < z
            printf("%d\n", x);
        } else { // z <= x < y
            printf("%d\n", z);
        }
    } else { // y <= x
        if (y < z) { // y < z e y <= x
            printf("%d\n", y);
        } else { // z <= y <= x
            printf("%d\n", z);
        }
    }
}
