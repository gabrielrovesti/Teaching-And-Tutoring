#include <stdio.h>
#include <basic/array.h>
#include <basic/matrix.h>

/*
* Scrivete una funzione confronta matrici, che verifichi se due matrici double siano identiche o meno, secondo una certa tolleranza.
*
* La firma della funzione deve essere int confronta_matrici_double(double *Matrice1, double *Matrice2, int righe1, int colonne1, int righe2, int colonne2, double toll)
* e deve fare uso della funzione di libreria confronta_array_double(double *X, double *Y, int dim, double toll) già fornita.
* La funzione deve restituire 1 se le matrici sono identiche e 0 se non lo sono. La tolleranza deve essere di 0.001.
*
* Aggiungete la funzione alla vostra libreria.
* 
* ATTENZIONE: per la consegna su Moodle cambiare il nome della funzione, altrimenti andrà in conflitto con la funzione caricata su Moodle.
*/

int confronta_matrici_double(double *Matrice1, double* Matrice2, int righe1, int colonne1, int righe2, int colonne2, double toll){

    if(righe1 != righe2 || colonne1 != colonne2)
        return 0;
    else
        return confronta_array_double(Matrice1, Matrice2, righe1*colonne1, toll);
}

int main()
{
    // Per testare più velocemente il vostro algoritmo potete 	
	// usare la matrice sotto (modificandola secondo le vostre necessità)
	// invece di leggerla da input con scanf. Quando siete pronti a
	// consegnare potete ricommentare le 3 righe seguenti.

    /*int righe1 = 3, colonne1 = 4, righe2 = 3, colonne2 = 4;
    double mat1[3][4] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
    double mat2[3][4] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};*/

    // creaimo e instanziamo le variabili di supporto per la dimensione della matrice
    int righe1, colonne1;
    scanf("%d %d", &righe1, &colonne1);
    int righe2, colonne2;
    scanf("%d %d", &righe2, &colonne2);

    // definiamo ed instanziamo la matrice
    double mat1[righe1][colonne1];
    leggi_array_double(*mat1, righe1*colonne1); 
    double mat2[righe2][colonne2];
    leggi_array_double(*mat2, righe2*colonne2);

    //confrontare matrici
    double toll = 0.001;
    int res = confronta_matrici_double(*mat1, *mat2, righe1, colonne1, righe2, colonne2, toll);

    if (res == 1)
        printf("Le matrici sono identiche");
    else
        printf("Le matrici sono diverse");


    return 0;
}