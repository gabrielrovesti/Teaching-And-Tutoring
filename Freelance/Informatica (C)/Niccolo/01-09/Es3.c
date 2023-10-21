#include <stdio.h>

int main() {
    int vendite[12]; // 12 = numero mesi
    
    // Lettura delle vendite mensili
    for (int mese = 0; mese < 12; mese++) {
        printf("Inserisci l'importo delle vendite per il mese %d: ", mese + 1);
        scanf("%d", &vendite[mese]);
    }

    // Visualizzazione dei dati mensili
    printf("\nDati sulle vendite:\n");
    for (int mese = 0; mese < 12; mese++) {
        printf("Mese %d - Importo: %d\n", mese + 1, vendite[mese]);
    }

    // Lettura e visualizzazione dell'importo venduto in un mese specifico
    int meseScelto;
    printf("\nInserisci il numero del mese per visualizzare l'importo venduto: ");
    scanf("%d", &meseScelto);
    printf("Importo venduto nel mese %d: %d\n", meseScelto, vendite[meseScelto - 1]);

    // Calcolo e visualizzazione dell'importo totale annuale
    int totaleAnno = 0;
    for (int mese = 0; mese < 12; mese++) {
        totaleAnno += vendite[mese];
    }
    printf("\nImporto totale venduto nell'anno: %d\n", totaleAnno);

    // Identificazione del mese con importo maggiore e minore
    int importoMassimo = vendite[0], meseMassimo = 1;
    int importoMinimo = vendite[0], meseMinimo = 1;
    for (int mese = 1; mese < 12; mese++) {
        if (vendite[mese] > importoMassimo) {
            importoMassimo = vendite[mese];
            meseMassimo = mese + 1;
        }
        if (vendite[mese] < importoMinimo) {
            importoMinimo = vendite[mese];
            meseMinimo = mese + 1;
        }
    }
    printf("Mese con importo maggiore: Mese %d - Importo %d\n", meseMassimo, importoMassimo);
    printf("Mese con importo minore: Mese %d - Importo %d\n", meseMinimo, importoMinimo);

    // Calcolo e visualizzazione importi per trimestre
    int trimestre = 1;
    int totaleTrimestre = 0;
    for (int mese = 0; mese < 12; mese++) {
        totaleTrimestre += vendite[mese];
        if ((mese + 1) % 3 == 0) {
            printf("Totale venduto nel trimestre %d: %d\n", trimestre, totaleTrimestre);
            totaleTrimestre = 0;
            trimestre++;
        }
    }

    return 0;
}
