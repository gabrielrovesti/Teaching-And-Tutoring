#include <stdio.h>

/*
Definire una funzione void stampa_piramide(int spazio, int altezza); che stampi una piramide di altezza
uguale ad "altezza" con uno spazio iniziale uguale a "spazio" (nota: assumiamo "altezza", "spazio" >= 0).

Per esempio l'invocazione stampa_piramide(0, 3) deve stampare:
  #
 ###
#####
invece, l'invocazione stampa_piramide(4, 3) deve stampare:
      #
     ###
    #####

Usare la funzione stampa_piramide per definire una funzione void stampa_albero_di_natale(int n_piramidi) che
stampi un albero di natale composto da n_piramidi piramidi allineate verticalmente (assumiamo n_piramidi >= 0).
La piramide sulla "punta" dell'albero deve avere altezza 3, la piramide subito sotto deve avere altezza 4
e così via, aumentando ad ogni passo l'altezza di 1.

Attenzione: le tre piramidi devono essere tutte allineate al centro (cioè la punta di una piramide deve
essere a metà della base della piramide subito sopra).

Per esempio: un albero di natale con n_piramidi = 3 avrà questo aspetto finale:
    #
   ###
  #####
    #
   ###
  #####
 #######
    #
   ###
  #####
 #######
#########

Per la consegna usare n_piramidi = 5
*/

void stampa_piramide(int spazio, int altezza);
void stampa_albero_di_natale(int n_piramidi);

int main () {
  stampa_albero_di_natale(5);
}

void stampa_albero_di_natale(int n_piramidi) {
  for (int i = 0; i < n_piramidi; i++) {
    int spazio_iniziale = n_piramidi - i - 1;
    int altezza = 3 + i;
    stampa_piramide(spazio_iniziale, altezza);
  }
}

void stampa_piramide(int spazio, int altezza) {
  int caratteri_per_riga = 1;
  int massimo_caratteri = (2 * altezza) - 1;

  for (int i = 0; i < altezza; i++) {
    // Come prima cosa, stampa gli spazi iniziali
    for (int j = 0; j < spazio; j++) {
      printf(" ");
    }

    // Poi, stampa il numero di spazi necessario per questa riga
    int inizio_stampa = (massimo_caratteri / 2) - (caratteri_per_riga / 2);
    for (int j = 0; j < inizio_stampa; j++) {
      printf(" ");
    }

    // Infine, stampa i caratteri che costituiscono la piramide e vai a capo
    for (int j = 0; j < caratteri_per_riga; j++) {
      printf("#");
    }
    printf("\n");

    // Ogni riga aumenta il numero di caratteri da stampare di 2
    caratteri_per_riga += 2;
  }
}