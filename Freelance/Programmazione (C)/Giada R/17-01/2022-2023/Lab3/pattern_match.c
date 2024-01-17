#include<stdio.h>

/* Date due stringhe N e T, trovare la posizione del primo match di T in N.
 * Trovare un match significa trovare una sottosequenza di caratteri adiacenti in N uguali a T.
 * (ovvero una *(N+k)==*T, *(N+(k+1))==*(T+1), ..., *(N+(k+n))==*(T+n) dove n è (la lunghezza di T)-1 e k è la posizione del match)
 * La posizione del match è uguale a quella del primo carattere matchato in N.
 * ES: N="programmazione2022", T="gra" -> "Match found at position 3"
 * ES: N="programmazione2020", T="ez" -> "No match found"
*/

unsigned int len(char* N){
    for(int i =0; i<256; i=i+1){
        if(N[i]=='\0'){
            return i;
        }
    }
    return 256;
}

/*
    POST: Restituisce 1 se T[0:N_len]=N[0:N_len]
          0 altrimenti
 */
int init_match(char* N, char*T, unsigned int N_len, unsigned int T_len){
    if(N_len < T_len){
        return 0;
    }

    for(int i = 0; i < T_len; i=i+1){
        if(N[i]!=T[i]){
            return 0;
        }
    }
    return 1;
}


int main() {

    // Per testare più velocemente il vostro algoritmo
    // potete usare le istruzioni fornite sotto. 
    // Quando siete pronti a consegnare potete ricommentare le seguenti righe.
    
    /*char N[] = { 'P', 'r', 'o', 'g', 'r', 'a', 'm', 'm', 'a', 'z', 'i', 'o', 'n', 'e','\0' };
    char T[] = { 'g', 'r', 'a', '\0' };*/
 
    //  Decommentare le seguenti 4 istruzioni per la consegna. 
    char N[256];
    char T[256];
    scanf("%255s", N);
    scanf("%255s", T);
    

    int N_len =len(N), T_len =len(T); 

    int found = -1;
    for(int i=0; i<N_len-T_len+1 && found==-1; i =i+1){
        if(init_match(N+i, T, N_len-i, T_len)==1){
            found = i; // esce al primo match
        }
    }

    if(found != -1){
        printf("Match found at position %d\n", found);
    }
    else{
        printf("No match found\n");
    }
}
