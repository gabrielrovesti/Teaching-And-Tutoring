#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
    Funzione che concatena due stringhe.
*/


/* 
    PRE:    S1 punta ad un array di caratteri popolato con una stringa. S1 è lungo abbastanza da contenere la concatenazione di S1 ed S2
            S2 puntatore a stringa definita. 
    POST: S1' (S1 al termine dell'esecuzione) contiente il contenuto delle stringhe S1 ed S2 concatenate  
*/
void concatenaStringhe(char* S1, char* S2);
void consegna_moodle();
void test_concatenaStringhe();


int main() {

    // test_concatenaStringhe();
    consegna_moodle();

}


void concatenaStringhe(char* S1, char* S2){
    while(*S1 != '\0')
        S1+=1;

    while(*S2 != '\0'){
        *S1 = *S2;
        S2+=1;
        S1+=1;
    }
    *S1='\0';
}


void consegna_moodle() {

    int dim1, dim2;
    scanf("%d", &dim1);
    scanf("%d", &dim2);
    char S1[dim1], S2[dim2];
    scanf("%s", S1);
    scanf("%s", S2);
    
    concatenaStringhe(S1,S2);
    
    printf("Stringa concatenata: %s\n",S1);

}


void test_concatenaStringhe() {

    char S1[50] = "laboratorio", S2[20] = " programmazione";
    concatenaStringhe(S1, S2);
    assert(strcmp(S1, "laboratorio programmazione")==0); //strcmp confronta due stringhe, restituisce 0 se sono uguali, è definita in string.h

    char S3[20] = "t", S4[20]="est";
    concatenaStringhe(S3, S4);
    assert(strcmp(S3, "test")==0);

    char S5[20] = "passat", S6[20]="o";
    concatenaStringhe(S5, S6);
    assert(strcmp(S5, "passato")==0);

    printf("Tutti i test superati con successo!\n");
}
