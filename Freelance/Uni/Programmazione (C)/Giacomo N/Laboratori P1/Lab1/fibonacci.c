#include <stdio.h>

/*
 * Data la costante LIMIT, stampare la serie di 
 * fibonacci, fib(k), a partire da fib(0) fino al
 * valore fib(k) più grande t.c. fib(k) < LIMIT.
 * 
 * La funzione di Fibonacci è definita per casi:
 * 
 * fib(0) = 0
 * fib(1) = 1
 * fib(i) = fib(i-1) + fib(i-2)
 * 
 * Es. se LIMIT = 25 stampa
 * 0
 * 1
 * 1
 * 2
 * 3
 * 5
 * 8
 * 13
 * 21
 * 
 * Per la consegna assegnare LIMIT=56
 * 
 */

/*
 * Suggerimento
 * 
 * Noi partiamo da questa situazione 
 * fib(i-2) = x // precedente 
 * fib(i-1) = y // corrente  
 * 
 * Dobbiamo calcolare il prossimo numero della sequenza, fib(i):
 * fib(i) = x+y // prossimo
 * 
 * all'iterazione successiva dobbiamo calcolare fib(i+1). Se cerchiamo
 * di utilizzare solo le 3 variabili (precedente, corrente, prossimo)
 * per effettuare il calcolo, notiamo 
 * che per calcolare fib(i+1) = fib(i-1) + fib(i) non abbiamo bisogno 
 * del valore di fib(i-2), e dobbiamo "traslare" i valori di precedente, 
 * corrente e prossimo come segue:
 * 
 * fib(i-2) precedente  ->
 * fib(i-1) corrente    -> precedente
 * fib(i)   prossimo    -> corrente
 * fib(i+1)             -> prossimo
 *  
 * Tutto quello che dobbiamo fare è modificare i valori delle tre 
 * variabili precedente, corrente, prossimo nell'ordine giusto in 
 * modo da ottenere l'effetto sopra
 * 
 */

int main() {

    const int LIMIT = 56;  // stampa serie fino al più grande numero k t.c. k < LIMIT
    int precedente = 0;  //fib(i-1)
    int corrente = 1;  //fib(i)
    printf("%d\n%d\n", precedente, corrente);  //stampare primi elementi

    int prossimo = 1;  //prossimo := f(i+1) == f(i)+f(i-1)
    while(prossimo < LIMIT){
        printf("%d\n", prossimo);  //stampo f(i+1)
        precedente = corrente;  //f(i-1) <- f(i)
        corrente = prossimo;  //f(i) <- f(i+1)
        prossimo = precedente + corrente;  //calcolo prossimo valore di fib, ovvero fib(i+2)
    }
}
