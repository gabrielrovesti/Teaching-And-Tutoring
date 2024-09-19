#include <stdio.h>
#include <string.h>

/*
 * Scrivete una funzione che, data una stringa, rimuova tutti i caratteri "palindromi". Una coppia di caratteri (x,y) è palindroma se
 * 1) sono lo stesso carattere: x=y
 * 2) si trovano alla stessa distanza, uno dall'inizio della stringa (x) 
 * e uno dalla fine della stringa (y).
 *
 * Esempio:
 * la stringa "parlai" viene trasformata dalla funzione in "pli" 
 * poiché le due a sono "palindrome": la prima 'a' è il secondo carattere 
 * dall'inizio della stringa e la seconda 'a' è il secondo carattere contando dal termine della stringa
 *
 * Altri esempi:
 * "parlo" -> "palo"
 * "palo" -> "palo"
 * "anna" -> ""
 */

int e_palindromo(char *s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

void elimina_palindromi(char *s) {
    int len = strlen(s);
    int scrivi = 0;
    
    for (int leggi = 0; leggi < len; leggi++) {
        int mantieni = 1;
        for (int i = 0; i <= leggi && i < len - leggi; i++) {
            if (e_palindromo(s, leggi - i, leggi + i)) {
                mantieni = 0;
                break;
            }
        }
        if (mantieni) {
            s[scrivi++] = s[leggi];
        }
    }
    s[scrivi] = '\0';
}

int main(void) {
    char s[100];
    printf("Inserisci una stringa: ");
    scanf("%99s", s);
    
    elimina_palindromi(s);
    
    printf("Risultato: %s\n", s);
    return 0;
}