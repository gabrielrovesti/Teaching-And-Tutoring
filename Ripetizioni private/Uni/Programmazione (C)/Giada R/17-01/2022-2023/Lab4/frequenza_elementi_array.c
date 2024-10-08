#include <stdio.h>
#include <basic/array.h>

/*
 * Scrivete un programma che dato un array di interi positivi, calcoli quante sono le occorrenze di ogni valore presente nell'array.
 * Notate che i valori dell'array, purché positivi, 
 * possono essere grandi a piacere. 
 * Il programma deve poi stampare quanto trovato, utilizzando
 * il comando:
 * printf("il valore %d appare %d volte\n", A[i], freq[i]);
 * 
 * Per esempio se l'array è [1,1,2,3,1,2] si ottiene il seguente output:
 * il valore 1 appare 3 volte
 * il valore 2 appare 2 volte
 * il valore 3 appare 1 volte
 * 
 */

int main()
{
    // Per testare più velocemente il vostro algoritmo potete 
    // usare gli array sotto (modificandoli secondo le vostre necessità)
    // invece di leggerli da input con scanf. Quando siete pronti a
    // consegnare potete ricommentare le 2 righe seguenti.
    
	/*int dim=6;
	int A[6] = {1,2,3,1,1,3};*/
    
    // leggi array e dimensioni
    int dim;
    scanf("%d", &dim);
    
    int A[dim];
    //funzione libreria
    leggi_array(A, dim);

	// inizializzazione
	// utilizza un array di frequenze della stessa dimensione dell'array di valori, inizializzato a 0	  
	int freq[dim], count;
	for(int i = 0; i< dim; i++){
        freq[i]=0;
    }
    
    /*
        Scorro l'array e per ogni valore uso un altro ciclo per
        scorrere i valori successivi e contare la frequenza del valore preso in considerazione
        Segno ogni valore uguale a quello preso in esame con -1 nell'array di frequenze per ricordare che ho già controllato
        e sfrutto questa cosa per ottimizzare il programma e stampare quello che voglio
    */

    for(int i=0; i<dim; i+=1)
    {
        count = 1;  // reset del counter ad ogni iterazione

        if(freq[i]!=-1) {
            for(int j=i+1; j<dim; j+=1) 
            {
                if(A[i]==A[j])
                {
                    count+=1;
                    freq[j] = -1;
                }
            }

            freq[i] = count;
        }
    }
    
    // Stampa
    for(int i=0; i<dim; i+=1)
        if(freq[i]!=-1)
            printf("il valore %d appare %d volte\n", A[i], freq[i]);
            
    return 0;
}