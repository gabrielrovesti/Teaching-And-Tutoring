#include <stdio.h>
#include <assert.h>

/*
 * Definire una funzione ricorsiva che determini 
 * se esiste un percorso che permetta di attraversare 
 * un campo fiorito, dal basso verso l'alto, 
 * senza calpestare alcun fiore. 
 * Il campo è rappresentato da una matrice, i cui valori
 * rappresentano la presenza di un fiore (0) oppure la sua
 * assenza (1).
 * E' possibile muoversi una casella in alto oppure una 
 * casella verso destra. 
 * Leggere le coordinate della casella di partenza 
 * da tastiera.  
 * Ad esempio se il campo è definito come segue: 
 * {0,0,0,1,0}
 * {0,1,0,1,1}
 * {1,0,1,1,0}
 * {1,0,1,1,1}
 * {1,0,1,0,0}
 * e la casella di partenza è (4,2), un percorso è il 
 * seguente: SU, SU, DESTRA, SU, SU (raffigurato dalle X) 
 * {0,0,0,X,0}
 * {0,1,0,X,1}
 * {1,0,X,X,0}
 * {1,0,X,1,1}
 * {1,0,X,0,0}
 */

int mossa(int dim_x, int dim_y, int campo[dim_x][dim_y], int pos_x, int pos_y) {
    /* 
        PRE: campo è una matrice intera di dimensioni dim*dim, pos_x e pos_y rappresentano riga e colonna di partenza.  
            Le mosse possibili sono: 1) muoversi una cella in alto; 2) muoversi una cella alla destra. 
        POST: restituisce 1 se esiste un percorso che parte da (pos_x, pos_y) e giunge nella riga 0, evitando le celle di percorso uguali a 0. 
            Restituisce 0 se non viene trovato un percorso o se le posizioni iniziali sono out-of-bound. 
    */

    if ( (pos_x<0) || (pos_y<0) || (pos_y>dim_y-1) || (pos_x>dim_x-1) ) { //mossa fuori dal percorso, percorso non valido
        return 0;
    }
    if (campo[pos_x][pos_y]==0) 
        return 0; // calpestato un fiore, percorso non valido
    if (pos_x==0)
        return 1; // sono arrivato nella prima riga, percorso valido
    return ( 
        (mossa(dim_x, dim_y, campo, pos_x-1, pos_y)) || (mossa(dim_x, dim_y, campo, pos_x, pos_y+1)) 
    );
}

void test_campo_fiorito();
void versione_per_consegna_moodle();


int main(void) {

    int campo[5][5]={
                         {0,0,0,1,0},
                         {0,1,0,1,1},
                         {1,0,1,1,0},
                         {1,0,1,1,1},
                         {1,0,1,0,0}
                    };

    
    test_campo_fiorito(5, 5, campo);
    //versione_per_consegna_moodle(5, 5, campo);
 
}

void test_campo_fiorito(int dim_x, int dim_y, int campo[dim_x][dim_y]){

    assert(mossa(dim_x, dim_y, campo, 4, 2)==1);
    assert(mossa(dim_x, dim_y, campo, 4, 0)==0);
    assert(mossa(dim_x, dim_y, campo, 3, 4)==0);
    assert(mossa(dim_x, dim_y, campo, 3, 2)==1);
    assert(mossa(dim_x, dim_y, campo, 1, 5)==0);
    assert(mossa(dim_x, dim_y, campo, 5, 1)==0);
    assert(mossa(dim_x, dim_y, campo, -1, 4)==0);
    assert(mossa(dim_x, dim_y, campo, 4, -1)==0);
    printf("test_campo_fiorito: tutti i test passati con successo\n");

}

void versione_per_consegna_moodle(int dim_x, int dim_y, int campo[dim_x][dim_y]){
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);

    if (mossa(dim_x, dim_y, campo, x, y)==1) {
        printf("Esiste un percorso da %d,%d alla riga 0\n", x, y);
    } else {
        printf("Non esiste un percorso da %d,%d alla riga 0\n", x, y);
    }
}
