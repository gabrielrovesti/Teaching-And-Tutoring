#include <stdio.h>

int main() {
    int inventario[3] = {0}; // Inventario iniziale di smartphone, tablet e laptop
    int scelta, quantita;

    printf("Benvenuto nel gestore di inventario e vendite!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserisci inventario iniziale\n");
        printf("2. Registra vendita\n");
        printf("3. Stampa inventario\n");
        printf("4. Uscita\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Inserisci la quantita iniziale di smartphone: ");
                scanf("%d", &inventario[0]);
                printf("Inserisci la quantita iniziale di tablet: ");
                scanf("%d", &inventario[1]);
                printf("Inserisci la quantita iniziale di laptop: ");
                scanf("%d", &inventario[2]);
                printf("Inventario iniziale inserito!\n");
                break;
            
            case 2:
                printf("Tipo di articolo (1: smartphone, 2: tablet, 3: laptop): ");
                scanf("%d", &scelta);
                printf("Quantita venduta: ");
                scanf("%d", &quantita);
                
                if (scelta >= 1 && scelta <= 3) {
                    inventario[scelta - 1] -= quantita;
                    printf("Vendita registrata!\n");
                } else {
                    printf("Tipo di articolo non valido.\n");
                }
                break;

            case 3:
                printf("\nInventario corrente:\n");
                printf("Smartphone: %d\n", inventario[0]);
                printf("Tablet: %d\n", inventario[1]);
                printf("Laptop: %d\n", inventario[2]);
                break;

            case 4:
                printf("Grazie per aver usato il gestore di inventario e vendite!\n");
                return 0;

            default:
                printf("Scelta non valida. Riprova.\n");
                break;
        }
    }

    return 0;
}
