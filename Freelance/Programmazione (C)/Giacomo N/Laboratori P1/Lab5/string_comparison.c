#include <stdio.h>

/*
 * Definire una funzione ricorsiva che confronti
 * alfabeticamente due stringhe. La funzione prende
 * le stringhe come argomento e restituisce -1 se
 * la prima è minore della seconda, 0 se sono uguali,
 * 1 se la seconda è minore della prima. 
 * Ad esempio: ciao < dado; ciao > cia; ciao = ciao
 * Le due stringhe sono lette da tastiera nel main. 
 * Se le stringhe in input sono "ciao", "hello", si
 * stampa:  
   ciao < hello

 * In caso di dubbi sulla definizione di confronto
 * alfabetico tra due caratteri, fate riferimento al
 * risultato del confronto dei valori numerici
 * associati ai caratteri stessi, ovvero usate 
 * semplicemente 'a' < 'b' (vero), 'A'<'a' ecc... 
 * 
 */

int confronta_stringhe(char *s1, char *s2) {
    /* 
        PRE: s1, s2 sono stringhe 
        POST: <,=,> sono definiti rispetto all'ordinamento alfabetico, 
            la funzione restituisce:
            -1 se s1 < s2
             1 se s2 < s1
             0 se s1 = s2
    */

    if (*s1=='\0' && *s2=='\0')
        return 0;
    if (*s1=='\0' || *s1 < *s2)
        return -1; //s1 è più corta di s2, quindi s1 < s2; oppure s1[0]<s2[0]
    if (*s2=='\0' || *s2 < *s1)
        return 1; //s2 è più corta di s1, quindi s2 < s1; oppure s2[0]<s1[0]

    return confronta_stringhe(s1+1, s2+1);

}

void versione_per_consegna_moodle();
void test_confronta_stringhe();


int main(void) {

    test_confronta_stringhe();
    //versione_per_consegna_moodle();    
}

void versione_per_consegna_moodle(){
    char a[50];
    char b[50];
    
    scanf("%s\n%s", a, b);
    printf("%s %c %s\n", a, 61+confronta_stringhe(a, b), b); //valori numerici dei caratteri: 60(<), 61(=), 62(>)

}

void test_confronta_stringhe() {

    printf("output confronta_stringhe(ciao, dado):\n");
    printf("%s %c %s\n", "ciao", 61+confronta_stringhe("ciao", "dado"), "dado");
    printf("\noutput atteso:\nciao < dado\n\n");

    printf("output confronta_stringhe(ciao, cia):\n");
    printf("%s %c %s\n", "ciao", 61+confronta_stringhe("ciao", "cia"), "cia");
    printf("\noutput atteso:\nciao > cia\n\n");

    printf("output confronta_stringhe(test, test):\n");
    printf("%s %c %s\n", "test", 61+confronta_stringhe("test", "test"), "test");
    printf("\noutput atteso:\ntest = test\n\n");

    printf("output confronta_stringhe(a, b):\n");
    printf("%s %c %s\n", "a", 61+confronta_stringhe("a", "b"), "b");
    printf("\noutput atteso:\na < b\n\n");

    printf("output confronta_stringhe(da, ciao):\n");
    printf("%s %c %s\n", "da", 61+confronta_stringhe("da", "ciao"), "ciao");
    printf("\noutput atteso:\nda > ciao\n\n");

}
