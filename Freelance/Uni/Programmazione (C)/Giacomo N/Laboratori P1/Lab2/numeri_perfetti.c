#include <stdio.h>

/*
* Scrivete un programma che trovi tutti i numeri perfetti tra due estremi compresi. Sia estremi che i numeri trovati dovranno essere interi.
* Un numero perfetto si definisce tale quando la somma di tutti i suoi divisori eccetto se stesso è uguale al numero stesso.
*
* Il programma deve stampare i valori trovati, utilizzare
* printf("Numero %d perfetto\n", limite_inferiore);
*
* I limiti sono forniti tramite input.
*/

int perfectNumber(int x); // inserisce il prototipo della funzione 

int main()
{
    // inizializzazione e lettura limiti
    int limite_inferiore, limite_superiore;
    scanf("%d %d", &limite_inferiore, &limite_superiore);
    
    // scorre dal limite inferiore al superiore e controlla ogni numero, se perfetto lo stampa

    while (limite_inferiore <= limite_superiore){

        if ( perfectNumber(limite_inferiore) )
            printf("Numero %d perfetto\n", limite_inferiore);

        limite_inferiore+=1;

    }
    
    return 0;
}


int perfectNumber(int x){
    int somma = 0; // utilizza una variabile per calcolare la somma dei divisori eccetto il numero stesso
    
    // calcola la somma
    for (int i = 1; i<x; i+=1){
        if (x%i == 0)
            somma += i; // equivale a somma = somma + i;
    }
    
    // confronta e ritorna se il numero è perfetto o meno (0=Falso, 1=Vero)
    if (somma == x)
        return 1;
    else
        return 0;
}
