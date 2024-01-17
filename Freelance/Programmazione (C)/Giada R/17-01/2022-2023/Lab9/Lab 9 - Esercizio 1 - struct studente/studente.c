#include<basic/array.h>
#include<stdio.h>

#define N_VOTI 5

//DEFINIZIONE: uno studente è rappresentato da un nome, un cognome e una serie di voti per numero N_VOTI di esami
//I voti vanno da 0 a 30. Se un esame non è stato svolto il valore del voto è -1.
typedef 
//definire qui il tipo Studente 
Studente;

//PRE: s è uno studente valido (voti compresi tra 0 e 30 oppure uguali a -1)
//float calcola_media(Studente s);
//POST calcolare la media dei voti conseguiti (esami svolti). Se non ci sono voti la media è 0.

float calcola_media(Studente s) {
   int somma = 0;
   int conteggio = 0;
   for(int i = 0; i < N_VOTI; i++) {
       if(s.voti[i] != -1) {
           somma += s.voti[i];
           conteggio++;
       }
   }
   return (float)somma / conteggio;
}


//PRE: s è uno studente valido
int sufficienza_studente(Studente s);
//POST: restituisce 1 se la media dei voti conseguiti è >= 18, 0 altrimenti

int sufficienza_studente(Studente s) {
   return calcola_media(s) >= 18 ? 1 : 0;
}

//void print_studente(Studente s);
//Funzione di utilità per stampare a schermo tutti i dati dello studente. Seguire l'esempio riportato di seguito.
/* Esempio di stampa
 * Nome: Michele 
 * Cognome: Poggi
 * Voti: [1,2,3,4,5]
 */

void print_studente(Studente s) {
   printf("Nome: %s\n", s.nome);
   printf("Cognome: %s\n", s.cognome);
   printf("Voti: ");
   for(int i = 0; i < N_VOTI; i++) {
       printf("%d ", s.voti[i]);
   }
   printf("\n");
}


int main(){
    Studente s;
    
    //lettura dati studente da tastiera
    scanf("%s %s", s.nome, s.cognome);

    //lettura voti da line di comando
    for(int i=0; i<N_VOTI; i++){
        scanf("%d", s.voti + i);
    }

    //calcolo status studente
    print_studente(s);
    printf("Media: %f\n", calcola_media(s));
    if(sufficienza_studente(s)==1)
        printf("Sufficiente\n");
    else printf("Non sufficiente\n");
}
