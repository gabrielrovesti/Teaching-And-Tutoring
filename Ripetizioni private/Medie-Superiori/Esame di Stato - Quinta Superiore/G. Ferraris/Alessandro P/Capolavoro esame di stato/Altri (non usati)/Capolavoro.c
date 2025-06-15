/*
 * EDU-K.O. – Simulatore di sopravvivenza scolastica
 * Esame di Stato 2025
 * Tema: Disagio nella scuola italiana
 * Autore: Alessandro P.
 *
 * Scopo: Far provare all'utente l'assurdità del sistema attraverso scelte forzate,
 * aumento di stress e voti paradossali.
 * Riferimenti bibliografici:
 *  [1] OECD, PISA 2022 Report – disuguaglianze e stress studentesco
 *  [2] MIUR, Rapporto sulla qualità dell’istruzione (2023)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SCENES 5

/* Stato dello studente */
typedef struct {
    char nome[50];
    int stress;      // contatore stress: 0–100
    int crediti;     // crediti accumulati simbolici
    int voto;        // voto medio simbolico: 0–10
} Studente;

/* Funzioni principali */
void inizializzaStudente(Studente *s);
void stampaIntestazione(const Studente *s);
void scena(int id, Studente *s);
int sceltaUtente(int options);
void riepilogo(const Studente *s);

int main(void) {
    srand((unsigned)time(NULL));
    Studente me;
    inizializzaStudente(&me);
    stampaIntestazione(&me);

    for (int i = 0; i < MAX_SCENES; i++) {
        scena(i, &me);
        printf("\n");
    }

    riepilogo(&me);
    return 0;
}

/* Inizializza lo studente */
void inizializzaStudente(Studente *s) {
    printf("Inserisci il tuo nome: ");
    if (fgets(s->nome, sizeof(s->nome), stdin) == NULL) {
        strcpy(s->nome, "Studente");
    } else {
        s->nome[strcspn(s->nome, "\n")] = '\0';
    }
    s->stress = 30;
    s->crediti = 0;
    s->voto = 6;
}

/* Mostra titolo ASCII-art */
void stampaIntestazione(const Studente *s) {
    printf("\n=== EDU-K.O. – Simulatore di sopravvivenza scolastica ===\n");
    printf("Studente: %s\n", s->nome);
    printf("Stress iniziale: %d/100 | Voto medio: %d/10\n", s->stress, s->voto);
}

/* Singola scena: scelte multiple e conseguenze */
void scena(int id, Studente *s) {
    printf("-- Giorno %d --\n", id + 1);
    switch (id) {
        case 0:
            printf("Hai dormito solo 3 ore. Vai a scuola?\n");
            printf("1) Sì, non voglio essere bocciato\n2) No, ho bisogno di riposo\n");
            break;
        case 1:
            printf("Verifica di matematica: difficoltà altissima. Studi fino a tardi?\n");
            printf("1) Sì\n2) No\n");
            break;
        case 2:
            printf("Assenza non giustificata? Prof usa il registro elettronico. Come reagisci?\n");
            printf("1) Chiedo scusa e giustifico\n2) Ignoro l'avviso\n");
            break;
        case 3:
            printf("Colloquio con il preside: preparato?\n");
            printf("1) Sì, ho riassunto i programmi\n2) No, arrivo impreparato\n");
            break;
        case 4:
            printf("Progetto di gruppo: caricano tutto su di te. Accetti?\n");
            printf("1) Sì\n2) Rifiuto e rischio scontro\n");
            break;
        default:
            printf("Giornata normale, niente di particolare.\n");
            break;
    }

    int op = sceltaUtente(2);
    /* Logica di stress e voto */
    if (op == 1) {
        s->stress += rand() % 20 + 10;  // aumento stress
        s->voto   -= rand() % 2;         // possibile calo voto
    } else {
        s->stress += rand() % 10 + 5;
        s->voto   -= rand() % 3 + 1;
    }

    if (s->stress > 100) s->stress = 100;
    if (s->voto < 0)     s->voto   = 0;

    printf("Stress attuale: %d/100 | Voto medio: %d/10\n", s->stress, s->voto);
}

/* Lettura scelta utente */
int sceltaUtente(int options) {
    int sel;
    do {
        printf("Seleziona (1-%d): ", options);
        if (scanf("%d", &sel) != 1) {
            while (getchar() != '\n');
            sel = 0;
        }
        while (getchar() != '\n');
    } while (sel < 1 || sel > options);
    return sel;
}

/* Riepilogo finale */
void riepilogo(const Studente *s) {
    printf("\n=== RIEPILOGO FINALE ===\n");
    printf("Stress finale: %d/100 | Voto medio finale: %d/10\n", s->stress, s->voto);
    if (s->stress > 80) {
        printf("😞 Il sistema ti ha logorato: profondo disagio e scoramento.\n");
    } else {
        printf("😊 Resisti, ma a caro prezzo: una \"vittoria\" amara.\n");
    }
}