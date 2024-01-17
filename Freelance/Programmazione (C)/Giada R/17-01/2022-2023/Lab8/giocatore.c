#include "giocatore.h"
#include "board.h"


void scegli_mossa_utente(char board[], int *x, int *y) {
    printf("Inserisci Mossa: ");
    scanf("%d %d", x, y);
}


void scegli_mossa_computer(char board[], int *x, int *y) {
    *x = rand()%BOARD_LATO;
    *y = rand()%BOARD_LATO;
}


int conta_esiti_perdenti(char board[], int x, int y, char S) {
    int i,j;

    board[x*BOARD_LATO+y]=S;
    if(board_vincente(board)){
        board[x*BOARD_LATO+y]=CASELLA_VUOTA;
        if(S==SIMB_X) return 1;
        else return 0;
    }
    if (board_riempita(board)){
        board[x*BOARD_LATO+y]=CASELLA_VUOTA;
        return 0;
    }

    int num_sconfitte=0;
    for(i=0; i<BOARD_LATO; i+=1)
        for(j=0; j<BOARD_LATO; j+=1) {
            if(mossa_ammissibile(board, i, j)==1){
                num_sconfitte += conta_esiti_perdenti(board, i, j, (S==SIMB_O)?SIMB_X:SIMB_O);
            }
        }
    board[x*BOARD_LATO+y]=CASELLA_VUOTA;
    return num_sconfitte;
}


void scegli_mossa_computer_migliore(char board[], int *x, int *y) {
    //provare 2-2, 0-0, 0-1
    int bestx=0, besty=0, num_sconfitte=0, min_sconfitte=__INT_MAX__;
    for(int i=0; i<BOARD_LATO; i+=1)
        for(int j=0; j<BOARD_LATO; j+=1) {
            if(mossa_ammissibile(board, i, j)== 1){
                num_sconfitte = conta_esiti_perdenti(board, i, j, SIMB_O);
                if (num_sconfitte<min_sconfitte) {
                    min_sconfitte=num_sconfitte;
                    bestx=i;
                    besty=j;
                }
            }
        } 
    printf("scelto %d %d con %d sconfitte\n", bestx, besty, min_sconfitte);
    *x=bestx;
    *y=besty;
}


