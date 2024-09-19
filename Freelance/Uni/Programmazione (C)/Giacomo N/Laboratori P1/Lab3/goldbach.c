#include <stdio.h>

/* 
    Dato un N, controllare se la congettura di Golbach è verificata per ogni n<=N.
*/


/*
    PRE: n>2 e pari
    POST: restituisce 0 se la congettura di Goldbach vale per ogni i. 2<i<=n
                      k se la congettura di Goldbach non è verificata per k
*/
int golbach_sequenza(int n);


/*
    PRE: n>2 e pari
    POST: Restituisce   1 se esiste (x,y).x+y=n, x e y sono primi;
                        0 altrimenti
*/
int goldbach_singolo(int n, int *x, int *y); // completate voi la lista dei parametri 


/*
    PRE: 
    POST: Restituisce 
        1 se n è primo
        0 altrimenti
*/    
int primo(int n);


/*
    PRE:
    POST restituisce 1 se n > 2 e pari
                     0 altrimenti
*/
int verifica_input(int n);


int main() {

    int N, res;

    scanf("%d", &N);
    if ( !verifica_input(N) )
        printf("Errore: la congettura di Goldbach è definita per interi pari e maggiori di 2, ricevuto %d\n", N);

    res = golbach_sequenza(N);
    if (res==0) 
        printf("Congettura di Goldbach verificata fino a %d\n", N);
    else 
        printf("Congettura di Goldbach non verificata per %d\n", res);
}


int golbach_sequenza(int n) {

    int x, y, res;
    int goldbach_fallita=0; // =0   -> goldback verificata; 
                            // =k>0 -> goldback non verificata per k
    for (int i=4; i<=n && goldbach_fallita==0; i+=2) {
        res = goldbach_singolo(i, &x, &y);
        if (!res) goldbach_fallita=i;
        else printf("%d=%d+%d\n", i, x, y);
    }
    return goldbach_fallita;
}


int goldbach_singolo(int n, int *x, int *y) {

    int i;
    for(i=2; i<=n/2; i+=1) {            // n/2 efficienza
        if (primo(i) && primo(n-i)) {   // n-i efficienza
            *x=i; *y=n-i;
            return 1;
        }
    }
    return 0;
}


int primo(int n) {

    int i;
    for(i=2;i<=n/2;i+=1)
        if (n%i==0)
            return 0;
    return 1;

}


int verifica_input(int n) {

    if (n<=2 || n%2!=0) 
        return 0;
    return 1;
}



