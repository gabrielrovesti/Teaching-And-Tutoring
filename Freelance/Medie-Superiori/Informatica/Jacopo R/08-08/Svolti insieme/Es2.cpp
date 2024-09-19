#include <iostream>
#include <string>

using namespace std;

struct Prodotto{
    char nome[50];
    double prezzo;
    int quantita;
};

struct VenditaGiornaliera{
    int giorno;
    int totaleVendite;
};

double calcolaValoreMagazzino(Prodotto magazzino[], int n){
    double totale = 0;

    for(int i = 0; i < n; i++){
        totale += magazzino[i].prezzo * magazzino[i].quantita;
    }
    return totale;
}

// possiamo metterlo come riferimento per fare modifiche sul prodotto
bool vendiProdotto(Prodotto& prodotto, int quantita, double totale){
    if(prodotto.quantita >= quantita){
        prodotto.quantita -= quantita;
        totale += prodotto.prezzo * quantita;
        return true;
    }
    return false;
}

// aumento giorno per giorno delle vendite per valore e per singolo giorno
void aggiornaTabelladiTraccia(VenditaGiornaliera vendite[], int giorno, double venditaGiornaliera){
    vendite[giorno].giorno = giorno + 1;
    vendite[giorno].totaleVendite = venditaGiornaliera;
}

int main(){
    Prodotto magazzino[5] = {
        {"Smartphone", 599.99, 50},
        {"Laptop", 999.99, 30},
        {"Cuffie Bluetooth", 79.99, 100},
        {"Smartwatch", 199.99, 40},
        {"Tablet", 299.99, 25}
    };
    int n = 5;

    double totale = calcolaValoreMagazzino(magazzino, n);

    bool isDone = vendiProdotto(magazzino[1], magazzino[1].quantita, magazzino[1].prezzo);

    VenditaGiornaliera vendite[2] = {
        {1, 599.99},
        {2, 499.99}
    };

    aggiornaTabelladiTraccia(vendite, vendite[1].giorno, vendite[1].totaleVendite);
}