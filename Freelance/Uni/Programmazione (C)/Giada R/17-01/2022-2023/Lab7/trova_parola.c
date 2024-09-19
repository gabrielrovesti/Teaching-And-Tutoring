#include <stdio.h>

/*
 * Enigmistica - Parole intrecciate. 
 * Scrivere una funzione che, data una tabella di caratteri
 * di dimensione 13x15 e una stringa, cerchi se la stringa
 * appare nella tabella: la stringa può apparire scritta:
 * 
 * 1) in orizzontale da sinistra a destra 
 * 2) in orizzontale da destra a sinistra
 * 
 * Se la parola è presente nella tabella, restituire le sue
 * coordinate; se la parola non
 * compare, utilizzare le coordinate -1,-1. 
 * Nel main utilizzare il seguente frammento di codice per 
 * stampare il risultato:
    // gli interi x,y contengono le coordinate,
    // dir è un intero che rappresenta la direzione del match (0 se è da sinistra a destra, 1 viceversa) 
    // parola la parola da cercare
    printf("Parola %s ", parola);
    if (x != -1)
        printf("in (%d,%d), direzione %s\n", x, y, dir==0?"s->d":"d->s");
    else
        printf("non trovata\n");;
 * 
 * Ad esempio nella tabella fornita sotto, se
 * parola_cercata = "Riposo"; allora stampa
    Parola Riposo in (1,0), direzione s->d
 * ATTENZIONE: le parole fornite devono avere solo lettere maiuscole, come la tabella
 */

int lunghezza_stringa(char * parola) {
    int i=0;
    while(parola[i]!='\0') {
        i+=1;
    }
    return i;
}

int init_match_riga_sinistra(char* riga, char* parola){
    int l_riga = lunghezza_stringa(riga), l_parola = lunghezza_stringa(parola);

    if(l_riga < l_parola)
        return 0;
    for(int i =0; i<l_parola; i=i+1){
        if(parola[i]!=riga[i]){
            return 0;
        }
    }
    return 1;
}

int init_match_riga_destra(char* riga, int l_riga, char* parola){
    int l_parola = lunghezza_stringa(parola);

    if(l_riga < l_parola)
        return 0;
    for(int i =0; i<l_parola; i=i+1){
        if(parola[i]!=riga[l_riga-i-1]){
            return 0;
        }
    }
    return 1;
}

int match_riga_sinistra(char* riga, char* parola){
    for(int i=0; i<lunghezza_stringa(riga); i=i+1){
        if(init_match_riga_sinistra(riga+i, parola)==1){
            return i;
        }
    }
    return -1;
}

int match_riga_destra(char* riga, char* parola){
    for(int i=lunghezza_stringa(riga); i>0; i=i-1){
        if(init_match_riga_destra(riga, i, parola)==1){
            return i-1;
        }
    }
    return -1;
}

void cerca_stringa(char tabella[][16], int num_righe, int* x, int* y, int* dir, char* parola){
    for(int r =0; r<num_righe; r=r+1){
        int pos = match_riga_sinistra(tabella[r], parola);
        if(pos!=-1){
            *x=r;
            *y=pos;
            *dir=0;
            return;
        }
        pos = match_riga_destra(tabella[r], parola);
        if(pos!=-1){
            *x=r;
            *y=pos;
            *dir=1;
            return;
        }
    }
    *x=-1;
    *y=-1;
    *dir=-1;
}

int main(void) {

    char tabella[13][16] = { 
        {"EISEOPIDLNOTETM"},
        {"RIPOSOTICUCBAOI"},
        {"ETROPSIVOOINMRL"},
        {"RSINNETIITGSFAA"},
        {"ROCKSPCNTOIOOLM"},
        {"OLAUOSSABLLIRLI"},
        {"CAMPINGZCBDAUYN"},
        {"BCOLLEZIONISMOA"},
        {"ALTIROCONLARCOB"},
        {"LAOIGGANIDRAIGM"},
        {"LIBGCINEMAIERLA"},
        {"OROTALIGUPORITS"},
        {"OTENOIZAMROFNIE"}
        };

    int x, y, dir;
    char parola[256];

    scanf("%255s", parola);

    cerca_stringa(tabella, 13, &x, &y, &dir, parola);
    printf("Parola %s ", parola);
    if (x != -1)
        printf("in (%d,%d), direzione %s\n", x, y, dir==0?"s->d":"d->s");
    else
        printf("non trovata\n");

}
//Animali – Arte – Ballo – Basso – Blog – Camping – Cani – Ciclismo – Cinema – Collezionismo – Correre – Cucito – Diario – Divinazione – Film – Forum – Gatti – Giardinaggio – Informazione – Liscio – Mambo – Moto – Musei – Nuoto – Oboe – Poesie – Pugilato – Rally – Ricamo – Riposo – Rock – Samba – Sport – Tango – Tennis – Tiro con l’arco – Trial – Viola

