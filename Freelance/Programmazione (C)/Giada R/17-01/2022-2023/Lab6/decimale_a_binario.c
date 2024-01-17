#include <stdio.h>

/*
    Scrivere una funzione ricorsiva che, dato un intero n>=0, lo stampi convertito in binario. 
    Ad esempio se n=4, la funzione stampa 100. 
    L'algoritmo per la conversione è stato spiegato in una delle prime lezioni. 
 */


void converti_binario_ric(int n);
void converti_binario(int n);
void test_converti_in_binario();
void versione_per_consegna_moodle();


int main() {

    test_converti_in_binario();
    //versione_per_consegna_moodle();

}


/*
    PRE: n>0
    POST: stampato n convertito in binario
 */
void converti_binario_ric(int n) {
    // complessità in termini di n
    if (n>0) {
        converti_binario_ric(n/2);
        printf("%d", n%2);
    } 
}

/*
    PRE: n>=0
    POST: stampato n convertito in binario
 */
void converti_binario(int n) {

    if(n==0)
        printf("0");
    else
        converti_binario_ric(n);
}


void test_converti_in_binario() {

    printf("output converti_binario(5):\n");
    converti_binario(5);
    printf("\noutput atteso:\n101\n\n");

    printf("output converti_binario(0):\n");
    converti_binario(0);
    printf("\noutput atteso:\n0\n\n");

    printf("output converti_binario(1):\n");
    converti_binario(1);
    printf("\noutput atteso:\n1\n\n");

    printf("output converti_binario(8):\n");
    converti_binario(8);
    printf("\noutput atteso:\n1000\n\n");

    printf("output converti_binario(109):\n");
    converti_binario(109);
    printf("\noutput atteso:\n1101101\n\n");
}


void versione_per_consegna_moodle() {

    int n;
    scanf("%d", &n);
    converti_binario(n);

}
