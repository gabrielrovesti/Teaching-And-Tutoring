#include <stdio.h>

/*
 Disegnare il perimetro di un quadrato di lato x, utilizzando il carattere #. 
 Per esempio se LATO=4 si ottiene il seguente output: 
 ####
 #  #
 #  #
 #### 
 */

#define LATO 8

int main (void) {
   int i, j;
   for(i = 0; i < LATO; i++) {
       for(j = 0; j < LATO; j++) {
           if(i == 0 || i == LATO - 1 || j == 0 || j == LATO - 1) {
               printf("#");
           } else {
               printf(" ");
           }
       }
       printf("\n");
   }
   return 0;
}
