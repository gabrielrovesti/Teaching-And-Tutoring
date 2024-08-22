#include <stdio.h>
#include <assert.h>

/*
    Il triangolo magico è un triangolo equilatero i cui valori sono calcolati come segue:
        - Il valore più in alto, ovvero in posizione (0,0), è 1
        - il valore in posizione (i,j) è dato dalla somma dei valori (i-1,j) e (i-1,j-1) se questi sono definiti (altrimenti ciascuno di essi assume valore 0). 
    Di seguito un esempio di triangolo di lato 5:
     1 
     1 1
     1 2 1
     1 3 3 1
     1 4 6 4 1
    Scrivere una funzione ricorsiva che, dato un indice di riga x
    ed un indice di colonna y, restituisca il valore in posizione
    (x,y) del triangolo magico. 
    Per esempio magico(4,2) deve restituire 6=3+3, magico(0,1)=0.
 */


int magico(int x, int y);
void test_magico();
void versione_per_consegna_moodle();


int main(void) {

    test_magico();
    // versione_per_consegna_moodle();

}


/*
    PRE:
    POST: dato (x,y) restituisce
            1                               se x=0, y=0
            0                               se x<0, y<0, y>x
            magico(x-1,y)+magico(x-1,y-1)   altrimenti
*/
int magico(int x, int y) {
    
    if ( (x==0) && (y==0) )
        return 1;
    else if ( (y<0) || (x<0) || (y>x) )
        return 0;
    else
        return magico(x-1,y) + magico(x-1,y-1);

}


void test_magico() {

    assert(magico(4,2)==6);
    assert(magico(0,2)==0);
    assert(magico(-1,2)==0);
    assert(magico(0,0)==1);
    assert(magico(3,3)==1);
    assert(magico(4,0)==1);
    assert(magico(7,4)==35);
    printf("test_magico: tutti i test passati con successo\n");

}


void versione_per_consegna_moodle() {

    int x,y;
    scanf("%d %d", &x, &y);
    printf("%d\n", magico(x,y));

}
