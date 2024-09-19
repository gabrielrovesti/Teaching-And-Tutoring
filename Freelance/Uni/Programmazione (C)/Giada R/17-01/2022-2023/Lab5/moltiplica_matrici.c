#include <stdio.h>
#include <basic/array.h>
#include <basic/matrix.h>

/*
* Scrivete la funzione "moltiplica_matrici_double" che calcola la moltiplicazione tra due matrici quadrate di numeri double 
* (sei cifre decimali) possibilmente negativi.
*
* L'operazione consiste nell'effettuare il prodotto scalare tra le righe della prima matrice e le colonne della seconda.
* 
* Esempio:
* 
* |a b| |e f| ____ |a*e+b*g a*f+b*h|
* |c d| |g h|      |c*e+d*g c*f+d*h|
* 
* 
* La firma è void moltiplica_matrici_double(int dim, double *mat1, double *mat2, double *matRisultato). La funzione riceve come argomenti 
* la dimensione, i puntatori alle due matrici e la matrice in cui salvare il risultato.
* Aggiungete la funzione alla vostra libreria.
* 
* ATTENZIONE: per la consegna su Moodle cambiare il nome della funzione, altrimenti andrà in conflitto con la funzione caricata su Moodle.
*/

void moltiplica_matrici_double(int dim, double *mat1, double *mat2, double *matRisultato){
    int i, j, k;
    double scalare;
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            // Esegui prodotto scalare tra le righe di mat1 e le colonne di mat2
            scalare = 0.0;
            for(k=0; k < dim; k++){
                scalare += (*((mat1+i*dim)+k)) * (*((mat2+k*dim)+j));
            }

            *(matRisultato+i*dim+j) = scalare;
        }
    }
}

int main (void) {
	// Per testare più velocemente il vostro algoritmo potete 	
	// usare la matrice sotto (modificandola secondo le vostre necessità)
	// invece di leggerla da input con scanf. Quando siete pronti a
	// consegnare potete ricommentare le 3 righe seguenti.
	
	/*int dim = 3;
	double mat1[3][3] = {1.000000, 2.000000, 3.000000, 4.000000, 5.000000, 6.000000, 7.000000, 8.000000, 9.000000};
	double mat2[3][3] = {9.000000, 8.000000, 7.000000, 6.000000, 5.000000, 4.000000, 3.000000, 2.000000, 1.000000};*/

	// creiamo e instanziamo le variabili di supporto per la dimensione della matrice
	int dim;
	scanf("%d", &dim);

	// definiamo ed instanziamo le matrici
	double mat1[dim][dim];
	leggi_array_double(*mat1, dim*dim);
	
	double mat2[dim][dim];
	leggi_array_double(*mat2, dim*dim);

    double matRisultato[dim][dim];

    moltiplica_matrici_double(dim, *mat1, *mat2, *matRisultato);

	//stampa il risultato
	stampa_matrice_double(*matRisultato, dim, dim);

    return 0;
}