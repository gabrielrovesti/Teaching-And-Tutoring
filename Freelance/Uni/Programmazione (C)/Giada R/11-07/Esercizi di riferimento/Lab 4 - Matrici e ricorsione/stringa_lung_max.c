#include <stdio.h>
#include <assert.h>

/*
 * Scrivere una funzione che, dato un array di stringhe,
 * restituisca la stringa di lunghezza massima. 
 * Nel main si dovrà stampare tale stringa.
 * Inoltre, si tratti in modo appropriato il caso in cui
 * il numero di stringhe nell'array sia zero. In particolare,
 * nel main si stampi "array vuoto\n". Se il numero di 
 * stringhe è maggiore di zero, utilizzare il seguente comando
 * nel main per la stampa della stringa più lunga:
 * 
 * printf("%s\n", stringa_lung_max(stringhe, num_stringhe));
 * 
 * Il numero di stringhe e le stringhe stesse sono lette da 
 * tastiera. Potete utilizzare la funzione di test per evitare di 
 * inserire da tastiera ogni volta una serie di stringhe
 * 
 */

int lunghezza_stringa(char *s) {

    int l;
    for(l=0; s[l]!='\0'; l+=1); 
    return l;
}


char * stringa_lung_max(char stringhe[][256], int dim) {

    if(dim<=0)
        return NULL;

    int lung_max = lunghezza_stringa(stringhe[0]), temp_lung, indice_max = 0;

    for(int i=1; i<dim; i+=1) {
        temp_lung = lunghezza_stringa(stringhe[i]);
        if(temp_lung > lung_max) {
            lung_max = temp_lung;
            indice_max = i;
        }
    }
    return stringhe[indice_max];
}


void test_stringa_lung_max() {

    char s[5][256]={{"ciao"}, {"ciaociao"}, {""}, {"hello"},{"c"}};
    assert(stringa_lung_max(s, 5)==s[1]);
    printf("test stringa_lung_max superato\n");

}


int main(void) {

    /* test_stringa_lung_max(); */
    
    int num_stringhe;
    scanf("%d", &num_stringhe);

    char stringhe[num_stringhe][256];
    for(int i=0; i<num_stringhe;i+=1) {
        scanf("%255s", stringhe[i]);
    }

    char *s_max = stringa_lung_max(stringhe, num_stringhe);
    printf("%s\n", (s_max==NULL)?"array vuoto": s_max);
    
}
