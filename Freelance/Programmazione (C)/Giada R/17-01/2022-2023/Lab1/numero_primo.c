#include <stdio.h>

/*
 * Stampare l'insieme dei divisori non banali 
 * di un numero x>0. Un divisore non banale è 
 * un divisore diverso da 1 e x. 
 * Inoltre, se x è primo, stampare 
 * "il numero x è primo".
 * 
 * Es. se x=5 stampa
 * Il numero 5 è primo
 * 
 * Es. se x=6 stampa
 * Il numero 6 è divisibile per 2
 * Il numero 6 è divisibile per 3
 * 
 * Per la consegna utilizzare x=63
 * 
 */
int numero_primo =0;
int main() {
    int NUMERO =63;
    //[2..NUMERO-1][NUMERO-1..2]
    for(int i =2;i<NUMERO;i=i+1){
        if(NUMERO%i==0){
            numero_primo=1;
            printf("Il numero %d è divisibile per %d\n",NUMERO,i);
        }
    }
    if (numero_primo==0){
        printf("Il numero è primo\n");
    }

}
