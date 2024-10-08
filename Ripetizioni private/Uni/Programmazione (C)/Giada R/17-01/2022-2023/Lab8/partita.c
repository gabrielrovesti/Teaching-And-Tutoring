#include "partita.h"

void gioca(char board[], void(*p1)(char [], int *, int *), void(*p2)(char [], int *, int *)){
    print_board(board);

    int mossa_x, mossa_y;
    int turno = 0;
    while(board_vincente(board)==0 && board_riempita(board)==0){
        if(turno == 0){
            p1(board, &mossa_x, &mossa_y);
            while(mossa_ammissibile(board, mossa_x, mossa_y)==0){
                p1(board, &mossa_x, &mossa_y);
            }
            effettua_mossa(board, mossa_x, mossa_y, SIMB_X);
            turno = 1;
        }
        else{
            p2(board, &mossa_x, &mossa_y);
            while(mossa_ammissibile(board, mossa_x, mossa_y)==0){
                p2(board, &mossa_x, &mossa_y);
            }
            effettua_mossa(board, mossa_x, mossa_y, SIMB_O);
            turno = 0;
        }
        print_board(board);
    }

    if(board_vincente(board)==1)
        printf("Ha vinto il giocatore %d\n", ((turno+1)%2)+1);
    else if (board_riempita(board)==1)
        printf("Parità\n");
}
