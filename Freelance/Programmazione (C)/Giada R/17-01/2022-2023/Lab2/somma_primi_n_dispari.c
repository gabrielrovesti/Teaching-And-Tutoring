#include <stdio.h>

/*
 * Definire una funzione che, dato un parametro intero n,
 * restituisca la somma dei numeri naturali dispari fino ad n incluso:
 * 
 * int sommaDispariN(int n);
 *  
 * Nel main stampare la somma restituita a video. 
 * Ad es. se n=8 stampa (notate l'a capo finale)
 * Somma dei numeri dispari minori di n: 16
 * 
 */


/* 
    Dato un intero positivo n, restituisce la somma dei dispari tra 1 ed n 
*/
int sommaDispariN(int n) {

    int somma = 0; //mantiene la somma aritmetica dei numeri dispari <= i
    for (int i=1; i<=n; i=i+2) {
        somma += i; // equivale a somma = somma + i;
    }
    return somma;
}


int main (void) {

    int n;
    //leggere da input n
    printf("Inserire un intero e premere Invio: ");
    scanf("%d", &n);

    printf("Somma dei numeri dispari minori di n: %d\n", sommaDispariN(n));

}
