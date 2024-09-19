#include <stdio.h>

#include <stdio.h>

/*
 * Calcola a che ora sarà cotta la torta, data un orario di inizio cottura
 * e il tempo di cottura (in secondi). 
 * 
 */


int main () {
 int ore=13, minuti=50, secondi=55;       /* orario di inizio cottura */
 int fine_secondi, fine_minuti, fine_ore; /* orario di fine cottura */
 int sec_cottura=10;                     /* tempo di cottura */

 fine_secondi = (sec_cottura + secondi) % 60;
 fine_minuti = minuti + (sec_cottura + secondi) / 60;
 fine_ore = ore + fine_minuti / 60;
 fine_minuti %= 60;

 printf("Inizio cottura: %d:%d:%d\n", ore, minuti, secondi);
 printf("Tempo di cottura (in secondi): %d\n", sec_cottura);
 printf("Fine cottura: %d:%d:%d\n", fine_ore, fine_minuti, fine_secondi);

 return 0;
}

