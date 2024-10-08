#include <stdio.h>

/*
    Definire una funzione ricorsiva che calcoli il numero di percorsi che permettono di attraversare un campo fiorito, dal basso verso l'alto, senza calpestare alcun fiore. 

 */

#define DIM_X 5
#define DIM_Y 5





int main(void) {

    int campo[DIM_X][DIM_Y]={
                         {0,0,0,1,1},
                         {0,1,1,1,1},
                         {1,0,1,1,0},
                         {1,0,1,1,1},
                         {1,0,1,0,0}
                    };
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);

    printf("Numero di percorsi da %d,%d alla riga 0: %d\n", x, y, mossa(campo, x, y));
}
