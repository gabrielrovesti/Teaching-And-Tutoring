#include <iostream>
#include <cstring>
#include <iomanip>

struct Prodotto {
    char nome[50];
    double prezzo;
    int quantita;
};

struct VenditaGiornaliera {
    int giorno;
    double totaleVendite;
};

const int GIORNI_MONITORAGGIO = 7;

double calcolaValoreMagazzino(Prodotto prodotti[], int n) {
    double totale = 0;
    for (int i = 0; i < n; i++) {
        totale += prodotti[i].prezzo * prodotti[i].quantita;
    }
    return totale;
}

bool vendiProdotto(Prodotto& prodotto, int quantita, double& totaleVendite) {
    if (prodotto.quantita >= quantita) {
        prodotto.quantita -= quantita;
        totaleVendite += prodotto.prezzo * quantita;
        return true;
    }
    return false;
}

void aggiornaTabellaDiTraccia(VenditaGiornaliera vendite[], int giorno, double venditaGiornaliera) {
    vendite[giorno].giorno = giorno + 1;
    vendite[giorno].totaleVendite = venditaGiornaliera;
}

double calcolaPrezzoScontato(double prezzo, double percentualeSconto) {
    double sconto = 0;
    double incremento = prezzo * 0.01;  // 1% del prezzo
    int iterazioni = (int)percentualeSconto;

    for (int i = 0; i < iterazioni; i++) {
        sconto += incremento;
    }

    return prezzo - sconto;
}

void stampaProdotto(const Prodotto& p) {
    std::cout << "Nome: " << std::setw(20) << std::left << p.nome 
              << " Prezzo: $" << std::setw(8) << std::fixed << std::setprecision(2) << p.prezzo 
              << " Quantità: " << p.quantita << std::endl;
}

int main() {
    Prodotto magazzino[5] = {
        {"Smartphone", 599.99, 50},
        {"Laptop", 999.99, 30},
        {"Cuffie Bluetooth", 79.99, 100},
        {"Smartwatch", 199.99, 40},
        {"Tablet", 299.99, 25}
    };
    int n = 5;

    VenditaGiornaliera venditeSettimanali[GIORNI_MONITORAGGIO] = {0};
    double totaleVenditeSettimanali = 0;

    std::cout << "Inventario iniziale:" << std::endl;
    for (int i = 0; i < n; i++) {
        stampaProdotto(magazzino[i]);
    }

    std::cout << "\nValore totale del magazzino: $" << std::fixed << std::setprecision(2) 
              << calcolaValoreMagazzino(magazzino, n) << std::endl;

    // Simulazione vendite per una settimana
    for (int giorno = 0; giorno < GIORNI_MONITORAGGIO; giorno++) {
        double venditaGiornaliera = 0;
        
        // Simula alcune vendite
        if (vendiProdotto(magazzino[0], 2, venditaGiornaliera)) {
            std::cout << "\nVenduti 2 Smartphone" << std::endl;
        }
        if (vendiProdotto(magazzino[2], 5, venditaGiornaliera)) {
            std::cout << "Vendute 5 Cuffie Bluetooth" << std::endl;
        }

        aggiornaTabellaDiTraccia(venditeSettimanali, giorno, venditaGiornaliera);
        totaleVenditeSettimanali += venditaGiornaliera;
    }

    std::cout << "\nTabella di traccia delle vendite settimanali:" << std::endl;
    for (int i = 0; i < GIORNI_MONITORAGGIO; i++) {
        std::cout << "Giorno " << venditeSettimanali[i].giorno 
                  << ": $" << std::fixed << std::setprecision(2) << venditeSettimanali[i].totaleVendite << std::endl;
    }

    std::cout << "\nTotale vendite settimanali: $" << std::fixed << std::setprecision(2) 
              << totaleVenditeSettimanali << std::endl;

    std::cout << "\nInventario aggiornato:" << std::endl;
    for (int i = 0; i < n; i++) {
        stampaProdotto(magazzino[i]);
    }

    // Calcolo del prezzo scontato
    double percentualeSconto = 15;
    double prezzoOriginale = magazzino[1].prezzo;
    double prezzoScontato = calcolaPrezzoScontato(prezzoOriginale, percentualeSconto);
    std::cout << "\nPrezzo scontato del Laptop (" << percentualeSconto << "% di sconto): $" 
              << std::fixed << std::setprecision(2) << prezzoScontato << std::endl;

    return 0;
}