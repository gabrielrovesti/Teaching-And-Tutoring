#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>

//Il tipo Corso è un alias di Studente*, puntatore ad array di studenti allocato nello heap
typedef Studente *Corso;

//PRE: esame compreso tra 0 e N_VOTI
float percentuale_superamento_test(Corso s, int n_studenti, int esame);
//POST: calcola la ratio di superamento dell'esame (solo guardando gli studenti che hanno conseguito un voto, chi non ha fatto l'esame non è contato). Se nessuno ha fatto l'esame la percentuale è 0.
//La ratio non deve essere in centemìsimi. Se un esame è stato superato da 1 sola persona su 2, la funzion deve restituire 0.5 e non 50.

//PRE: s è un corso non vuoto
Studente miglior_studente(Corso s, int n_studenti);
//POST: restituisce lo studente con la media più alta. Se più di uno studente ha stessa media viene preso quello con indice minore.

void ordina_studenti(Corso s, int n_studenti);
//POST: ordina gli studenti a seconda della loro media
//NOTA: l'algoritmo di ordinamento da utilizzare è a vostra discrezione. E' consentito riadattare l'esercizio sul quicksort se volete

int main(){
    int n_stud;
    scanf("%d", &n_stud);

    Corso s = malloc(sizeof(Studente)*n_stud);
    for(int i=0; i<n_stud; i++){
        scanf("%s %s", (s+i)->nome, (s+i)->cognome);
        for(int j=0; j<N_VOTI; j++)
            scanf("%d", ((s+i)->voti) + j);
    }

    printf("Miglior Studente:\n");
    print_studente(miglior_studente(s, n_stud));
    for(int i=0; i<N_VOTI; i++){
        printf("Percentuale superamento corso %d: %.2f\n", i, percentuale_superamento_test(s, n_stud, i)*100);
    }

    ordina_studenti(s, n_stud);
    printf("Peggiori 2 Studenti:\n");
    for(int i=0; i<2; i++){
        print_studente(*(s+i));
    }

}

/*

Soluzioni

float percentuale_superamento_test(Corso s, int n_studenti, int esame) {
   int superati = 0;
   for(int i = 0; i < n_studenti; i++) {
       if((*s)[i].voti[esame] != -1 && (*s)[i].voti[esame] > 18) {
           superati++;
       }
   }
   return (float)superati / n_studenti;
}

Studente miglior_studente(Corso s, int n_studenti) {
   float max_media = 0;
   Studente miglior_studente;
   for(int i = 0; i < n_studenti; i++) {
       float media = calcola_media(*(s + i));
       if(media > max_media || (media == max_media && strcmp((*(s + i)).nome, miglior_studente.nome) < 0)) {
           max_media = media;
           miglior_studente = *(s + i);
       }
   }
   return miglior_studente;
}

void ordina_studenti(Corso s, int n_studenti) {
   for(int i = 0; i < n_studenti - 1; i++) {
       for(int j = 0; j < n_studenti - i - 1; j++) {
           if(calcola_media(*(s + j)) < calcola_media(*(s + j + 1))) {
               Studente temp = *(s + j);
               *(s + j) = *(s + j + 1);
               *(s + j + 1) = temp;
           }
       }
   }
}


*/