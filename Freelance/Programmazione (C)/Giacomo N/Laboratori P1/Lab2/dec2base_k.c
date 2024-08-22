#include <stdio.h>

/*
    Conversione da decimale a base k di numeri positivi. 
 */


#define BASE 2

/*
    PRE: 
    POST: restituisce un numero x le cui cifre rappresentano la codifica in base k di n
*/
unsigned int dec2base_k(unsigned int n);


int main() {

    unsigned int n;
    scanf("%ud", &n);
    
    printf("%u corrisponde a %u in base %d\n", n, dec2base_k(n), BASE);
}

unsigned int dec2base_k(unsigned int n) {

    unsigned int base_k=0; 
    unsigned int power=1; /* vale 10^i, dove i è l'iterazione del ciclo */

    while(n>0) {
        base_k += power*(n % BASE);
        power*=10;
        n=n/BASE;
    }
    return base_k;
}
