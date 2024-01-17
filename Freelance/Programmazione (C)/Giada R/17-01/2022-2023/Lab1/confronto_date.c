#include <stdio.h>

/*
    Date due date, espresse dalle variabili giorno1, mese1, anno1 e giorno2, mese2, anno2, confrontare le due date. 
    Stampare in un messaggio a video il risultato del confronto: "giorno1/mese1/anno1 <=> giorno2/mese2/anno2" a seconda che la prima data sia antecedente, equivalente o posteriore alla seconda, rispettivamente. 
    Ad esempio: 1/2/2018 < 1/2/2019
 */

int main() {

    int anno1=2021, mese1=06, giorno1=1;
    int anno2=2021, mese2=06, giorno2=1;

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
