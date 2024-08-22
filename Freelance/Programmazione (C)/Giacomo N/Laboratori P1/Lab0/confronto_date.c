#include <stdio.h>

/*
* Date due date, espresse dalle variabili giorno1, mese1, anno1 e giorno2, mese2, anno2
* confrontare le due date e dire se la prima è maggiore, minore o uguale alla seconda.
* Esempi:
* 1) Se anno1=2021, mese1=6, giorno1=1 e anno2=2021, mese2=5, giorno2=1, stampare 1/6/2021 > 1/5/2021
* 2) Se anno1=2020, mese1=6, giorno1=1 e anno2=2021, mese2=5, giorno2=1, stampare 1/6/2020 < 1/5/2021
* 3) Se anno1=2021, mese1=6, giorno1=1 e anno2=2021, mese2=6, giorno2=1, stampare 1/6/2021 = 1/6/2021
*
* Per la consegna usare anno1=2021, mese1=6, giorno1=1, anno2=2021, mese2=6, giorno2=7
*/

int main() {

    int anno1=2021, mese1=6, giorno1=1;
    int anno2=2021, mese2=6, giorno2=7;

    printf("%d/%d/%d ", giorno1, mese1, anno1);
    if (anno1>anno2) 
        printf(">");
    else 
        if (anno1<anno2) 
                printf("<");
        else // anno1==anno2
            if(mese1>mese2)
                printf(">");
            else
                if (mese1<mese2)
                    printf("<");
                else // mese1==mese2
                    if (giorno1>giorno2)
                        printf(">");
                    else
                        if (giorno1<giorno2)
                            printf("<");
                        else
                            printf("=");
    printf(" %d/%d/%d\n", giorno2, mese2, anno2);
}
