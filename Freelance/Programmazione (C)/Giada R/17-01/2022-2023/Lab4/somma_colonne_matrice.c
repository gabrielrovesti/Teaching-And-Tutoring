#include<stdio.h>
#include <basic/array.h>
/* Data una matrice di dimensioni arbitrarie, definire una funzione calcola_somma che salva in un array somma la somma degli elementi di ciascuna colonna della matrice.
 * (somma[i] = "somma degli elementi dell'i-esima colonna della matrice")
 * e.g.:   [1 2 3
 *          4 5 6    -> [12, 15, 18]
 *          7 8 9]
 * Notare che la matrice è passata alla funzione tramite un puntatore int* al suo primo elemento ed è quindi come se la matrice fosse appiattita, formando un vettore lungo n-colonne*n-righe.
 * E' perciò necessario usare l'aritmetica dei puntatori.
*/ 

int somma_singola_colonna(int *matrix, unsigned int righe, unsigned int colonne, int num_col){
    int acc =0;
    for(int i=0; i < righe; i= i+1){
        acc += *(matrix + num_col + i*colonne);
    }
    return acc;
}

void calcola_somma(int *matrix, unsigned int righe, unsigned int colonne, int* somma){
    for(int i=0; i<colonne; i=i+1){
        *(somma+i) = somma_singola_colonna(matrix, righe, colonne, i);
    }
}

int main(){

    // Per testare più velocemente il vostro algoritmo potete 
    // usare la matrice sotto (modificandola secondo le vostre necessità)
    // invece di leggerla da input con scanf. Quando siete pronti a
    // consegnare potete ricommentare le 2 righe seguenti.
    
    /*int righe = 3, colonne = 3;
    int mat[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};*/

    int righe, colonne;

    scanf("%u", &righe);
    scanf("%u", &colonne);

    int mat[righe][colonne];

    //funzione libreria
    leggi_array(*mat, righe*colonne);

    // array contenente somme per ogni colonna
    int somma[colonne];
    
    calcola_somma(*mat, righe, colonne, somma);    

    for(int i = 0; i < colonne; i = i+1){
        printf("La somma della colonna %d è %d\n", i, somma[i]);
    } 
}
