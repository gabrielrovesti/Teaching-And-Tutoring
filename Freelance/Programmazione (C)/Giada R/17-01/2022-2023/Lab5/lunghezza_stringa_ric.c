#include <stdio.h>

/*
 * Scrivere una funzione ricorsiva che calcoli la 
 * lunghezza di una stringa. 
 * Scegliete voi il nome ed il prototipo della 
 * funzione. 
 * Nel main leggete da tastiera la stringa di cui
 * calcolar la lunghezza. 
 * Ad esempio se la stringa in input è "ciao", viene
 * stampato:
   4

 */

int lunghezza_stringa2(char S[], int i){
    /* 
        PRE: S è una stringa (termina con \0), 0<=i<(lunghezza stringa S) 
        POST: restituisce la 
    */
    if(S[i] == '\0')
        return 0;
    else
        return 1 + lunghezza_stringa2(S, i+1);
}


int lunghezza_stringa(char *p){
    /* 
        PRE: p è un puntatore al primo carattere di una stringa (termina con \0)
        POST: restituisce la lunghezza della stringa puntata da p 
    */
    if(*p == '\0')
        return 0;
    else
        return 1 + lunghezza_stringa(p+1);
}


int main(void) {

    char s[100]; //lunghezza massima stringa in input
    scanf("%s", s);
    int lunghezza_s;

    /* 
     * Inserite qua la chiamata alla vostra funzione 
     * che calcola la lunghezza della stringa salvando
     * il valore restituito in lunghezza_s. 
     */
    lunghezza_s = lunghezza_stringa(s);
    printf("%d\n", lunghezza_s);

}
