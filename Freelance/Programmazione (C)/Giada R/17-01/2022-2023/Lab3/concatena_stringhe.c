#include <stdio.h>

/*
* Date due stringhe, scrivere una funzione che passi come parametri queste stringhe e le concateni.
* La concatenazione deve avvenire nella prima stringa, senza l'utilizzo di altre variabili di tipo array.
* La funzione dovrà sfruttare quanto visto con i puntatori per l'accesso in memoria (non usare S1[i]).
* Una volta fatto ciò, il programma deve stampare la stringa concatenata.
* 
* 
* Per la stampa usare:
* printf("La stringa concatenata è: %s",S1);
*/

/*
  Suggerimento:
  Ricordatevi che, per definizione una stringa termina sempre con il carattere '\0', il quale che viene aggiunto automaticamente quando si assegna una stringa ad un array di caratteri. 
  Quindi possiamo utilizzare questo fatto per 
  1) trovare dove finisce la prima stringa;
  2) copiare i caratteri della seconda stringa nella prima a partire dal termine della prima. 
  3) ricordatevi di aggiungere il carattere '\0' dopo aver aggiunto tutti i caratteri della seconda stringa
*/
void concatenaStringhe(char* S1, char* S2){
    int i = 0, j = 0;
    
    // Incrementa un contatore per trovare la lunghezza della stringa
    while(*(S1+i) != '\0')
        i+=1;
    // i è l'indice del carattere \0, che vogliamo sovrascrivere sotto. 

    // Concatena la seconda stringa alla prima con un secondo contatore che scorre la seconda stringa  
    while(*(S2+j) != '\0'){
        *(S1+i+j) = *(S2+j); // *(S1+i+j) per accedere dall'elemento successivo all'ultimo della prima stringa
        j+=1;
    }
    *(S1+i+j) = '\0'; //dobbiamo riaggiungere il carattere di fine stringa
    
    return;
}

int main() {
 
    //  Per testare più velocemente il vostro algoritmo
    //  potete usare gli array forniti sotto (modificandoli 
    //  secondo le vostre necessità) invece di leggerli 
    //  da input con scanf. Quando siete pronti a 
    //  consegnare potete ricommentare le seguenti righe.
    
    /*char S1[50] = "laboratorio",
         S2[20] = " programmazione";
    */
     
    //  Creazione di stringhe con la dimensione maggiore del contenuto (size < length)
    //  Leggi la dimensione degli array e i valori da tastiera. 
    //   Decommentare le seguenti istruzioni per la consegna. 
    
    int dim1, dim2;
    scanf("%d", &dim1);
    scanf("%d", &dim2);
    char S1[dim1], S2[dim2];
    scanf("%s", S1);
    scanf("%s", S2);
    
    concatenaStringhe(S1,S2);
    
    printf("Stringa concatenata: %s\n",S1);

    return 0;
}
