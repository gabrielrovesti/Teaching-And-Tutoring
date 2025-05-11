/*
* EDU-K.O. - Il Simulatore di Sopravvivenza Scolastica
* Un viaggio interattivo nell'assurda realtà del sistema educativo italiano
* 
* "Nel codice, come nella vita: lo studente perde sempre"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Configurazione del gioco
#define MAX_STRESS 100
#define MAX_VOTO 10
#define NOME_LENGTH 50

// Struttura per lo studente virtuale
typedef struct {
    char nome[NOME_LENGTH];
    int stress;
    float media;
    int ore_sonno;
    int assenze;
    int note_disciplinari;
    int voglia_vivere;
} Studente;

// Frasi ironiche del sistema
char* frasi_prof[] = {
    "\"Non dovevi studiare solo l'ultima settimana\"",
    "\"Io alla tua età studiavo 12 ore al giorno\"",
    "\"Non ho tempo per spiegazioni individuali\"",
    "\"La creatività non serve, servono le nozioni\"",
    "\"Non è colpa mia se non capisci\"",
    "\"Questo lo avete già fatto in precedenza\"",
    "\"Nel mondo del lavoro non ti passano nulla\"",
    "\"Dovete imparare a essere autonomi\""
};

char* situazioni_assurde[] = {
    "Ti hanno assegnato 8 materie con verifica questa settimana",
    "Il WiFi non funziona ma pretendono che usi il registro elettronico",
    "Ti chiedono di essere creativo ma poi ti bocciano se esci dal programma",
    "Devi fare 30 ore di alternanza scuola-lavoro non retribuite",
    "Ti fanno studiare poesie del 1200 ma non come fare le tasse",
    "La prof cambia le regole del compito durante il compito",
    "Ti chiedono di avere 'spirito critico' ma solo se concordi con loro"
};

// Prototipi funzioni
void inizializza_studente(Studente *s);
void mostra_status(Studente *s);
void situazione_mattino(Studente *s);
void situazione_lezione(Studente *s);
void situazione_verifica(Studente *s);
void situazione_colloquio(Studente *s);
void situazione_casa(Studente *s);
void risultato_finale(Studente *s);
void ascii_art_intro();
void pausa();
int scelta_utente(int min, int max);

int main() {
    srand(time(NULL));
    
    printf("\033[2J\033[1;1H"); // Pulisce lo schermo
    
    ascii_art_intro();
    
    Studente studente;
    inizializza_studente(&studente);
    
    printf("\n\n=== EDU-K.O. - Il Simulatore di Sopravvivenza Scolastica ===\n");
    printf("     \"Benvenuto nell'incubo quotidiano\"               \n\n");
    
    // Varie situazioni di una giornata scolastica
    situazione_mattino(&studente);
    situazione_lezione(&studente);
    situazione_verifica(&studente);
    situazione_colloquio(&studente);
    situazione_casa(&studente);
    
    // Risultato finale
    risultato_finale(&studente);
    
    return 0;
}

void inizializza_studente(Studente *s) {
    printf("\nInserisci il tuo nome: ");
    fgets(s->nome, NOME_LENGTH, stdin);
    s->nome[strcspn(s->nome, "\n")] = 0; // Rimuove newline
    
    s->stress = 50;
    s->media = 6.0;
    s->ore_sonno = 5; // Realistico per uno studente italiano
    s->assenze = 0;
    s->note_disciplinari = 0;
    s->voglia_vivere = 50;
    
    printf("\nBene %s, benvenuto nella macchina tritacarne.\n", s->nome);
    pausa();
}

void mostra_status(Studente *s) {
    printf("\n--- Status di %s ---\n", s->nome);
    printf("Stress: %d/100 ", s->stress);
    for(int i = 0; i < s->stress/10; i++) printf("█");
    printf("\n");
    
    printf("Media scolastica: %.1f\n", s->media);
    printf("Ore di sonno: %d\n", s->ore_sonno);
    printf("Assenze: %d\n", s->assenze);
    printf("Note disciplinari: %d\n", s->note_disciplinari);
    printf("Voglia di vivere: %d%% ", s->voglia_vivere);
    for(int i = 0; i < s->voglia_vivere/20; i++) printf("♥");
    printf("\n-------------------\n");
}

void situazione_mattino(Studente *s) {
    printf("\n\n=== ORE 06:30 - LA SVEGLIA SUONA ===\n");
    printf("Hai dormito %d ore. Ti senti distrutto.\n", s->ore_sonno);
    
    // Situazione assurda random
    printf("\n%s\n", situazioni_assurde[rand() % 7]);
    
    printf("\nCosa fai?\n");
    printf("1. Vai a scuola da zombie\n");
    printf("2. Fingi di essere malato\n");
    printf("3. Piangi nel cuscino per 10 minuti e poi vai\n");
    
    int scelta = scelta_utente(1, 3);
    
    switch(scelta) {
        case 1:
            printf("\nArrivi in classe con le occhiaie fino ai piedi.\n");
            printf("La prof ti guarda e dice: %s\n", frasi_prof[rand() % 8]);
            s->stress += 15;
            s->voglia_vivere -= 10;
            break;
            
        case 2:
            printf("\nTua madre non ci crede e ti obbliga ad andare.\n");
            printf("Arrivi in ritardo e prendi una nota.\n");
            s->note_disciplinari++;
            s->stress += 20;
            s->assenze++; // Contano come assenza anche se vai
            break;
            
        case 3:
            printf("\nArrivi con gli occhi rossi. Il bidello ti chiede se va tutto bene.\n");
            printf("È l'unica persona che si preoccupa per te oggi.\n");
            s->stress += 10;
            s->voglia_vivere -= 5;
            break;
    }
    
    mostra_status(s);
    pausa();
}

void situazione_lezione(Studente *s) {
    printf("\n\n=== ORE 08:15 - PRIMA ORA: MATEMATICA ===\n");
    printf("La prof entra e dice: 'Spero abbiate studiato il capitolo 7'.\n");
    printf("Tu ovviamente hai studiato il capitolo 6.\n");
    
    printf("\nCosa fai?\n");
    printf("1. Confessi di aver studiato il capitolo sbagliato\n");
    printf("2. Fingi di sapere e speri di non essere interrogato\n");
    printf("3. Fingi un malore e vai in infermeria\n");
    
    int scelta = scelta_utente(1, 3);
    
    switch(scelta) {
        case 1:
            printf("\nLa prof: 'COME È POSSIBILE? È SUL REGISTRO DA DUE SETTIMANE!'\n");
            printf("Vieni interrogato comunque e prendi 3.\n");
            s->media = (s->media * 4 + 3) / 5;
            s->stress += 25;
            s->voglia_vivere -= 15;
            break;
            
        case 2:
            printf("\nViene chiamato il tuo compagno di banco.\n");
            printf("Mentre lui balbetta le risposte, la prof nota che stai leggendo sotto il banco.\n");
            printf("Nota disciplinare per 'comportamento scorretto'.\n");
            s->note_disciplinari++;
            s->stress += 20;
            break;
            
        case 3:
            printf("\nIn infermeria non c'è nessuno (come al solito).\n");
            printf("Ti siedi e apri il libro di matematica, ma è tardi per recuperare.\n");
            s->stress += 15;
            s->ore_sonno--; // Lo stress ti sta consumando
            break;
    }
    
    mostra_status(s);
    pausa();
}

void situazione_verifica(Studente *s) {
    printf("\n\n=== ORE 10:15 - VERIFICA A SORPRESA DI LATINO ===\n");
    printf("'Ragazzi, compito in classe! Spero abbiate ripassato.'\n");
    printf("Nessuno aveva annunciato nulla. Il panico si diffonde.\n");
    
    printf("\nCome affronti la situazione?\n");
    printf("1. Tenti di copiare dal tuo compagno\n");
    printf("2. Scrivi qualsiasi cosa sperando nella pietà\n");
    printf("3. Consegni in bianco con dignità\n");
    
    int scelta = scelta_utente(1, 3);
    
    switch(scelta) {
        case 1:
            printf("\nLa prof ti becca dopo 2 minuti.\n");
            printf("'%s! VERGOGNATI! Voti annullati per entrambi!'\n", s->nome);
            printf("Il tuo compagno ti odia. Hai perso un amico.\n");
            s->media = (s->media * 4 + 2) / 5;
            s->stress += 35;
            s->voglia_vivere -= 20;
            s->note_disciplinari++;
            break;
            
        case 2:
            printf("\nScrivi frasi con errori grammaticali italiani nella versione latina.\n");
            printf("La prof ti corregge con inchiostro rosso dappertutto.\n");
            printf("Voto: 4. 'Almeno ci hai provato' dice sarcasticamente.\n");
            s->media = (s->media * 4 + 4) / 5;
            s->stress += 25;
            s->voglia_vivere -= 10;
            break;
            
        case 3:
            printf("\nLa prof apprezza l'onestà ma ti mette 2.\n");
            printf("'Non puoi non sapere nulla dopo un anno di latino!'\n");
            printf("(Come se un anno bastasse per imparare una lingua morta)\n");
            s->media = (s->media * 4 + 2) / 5;
            s->stress += 30;
            s->voglia_vivere -= 15;
            break;
    }
    
    mostra_status(s);
    pausa();
}

void situazione_colloquio(Studente *s) {
    printf("\n\n=== ORE 13:00 - COLLOQUIO CON LA COORDINATRICE ===\n");
    printf("'%s, vieni un momento. Dobbiamo parlare.'\n", s->nome);
    printf("Il cuore ti si ferma. Cosa ho fatto adesso?\n");
    
    printf("\nCome ti presenti?\n");
    printf("1. Umile e pentito (anche se non sai di cosa)\n");
    printf("2. Sicuro di te e pronto al confronto\n");
    printf("3. Rassegnato al destino\n");
    
    int scelta = scelta_utente(1, 3);
    
    switch(scelta) {
        case 1:
            printf("\nProf: 'Ho notato un calo nel tuo rendimento.'\n");
            printf("Tu: 'Ha ragione prof, mi impegnerò di più.'\n");
            printf("Prof: 'Bene, voglio vedere miglioramenti o chiamo i tuoi genitori.'\n");
            s->stress += 20;
            s->voglia_vivere -= 10;
            break;
            
        case 2:
            printf("\nTu: 'Se c'è un problema, parliamone apertamente.'\n");
            printf("Prof: 'Il problema è il tuo atteggiamento! Non ti rendi conto della gravità!'\n");
            printf("Escalation. Nota disciplinare. I tuoi genitori vengono avvisati.\n");
            s->note_disciplinari++;
            s->stress += 35;
            s->voglia_vivere -= 20;
            break;
            
        case 3:
            printf("\nTu: 'Lo so, sono un fallimento.'\n");
            printf("Prof: 'Non dire così... ma effettivamente devi reagire.'\n");
            printf("Ti senti peggio di prima. Almeno non hai preso una nota.\n");
            s->stress += 15;
            s->voglia_vivere -= 15;
            break;
    }
    
    mostra_status(s);
    pausa();
}

void situazione_casa(Studente *s) {
    printf("\n\n=== ORE 15:30 - FINALMENTE A CASA ===\n");
    printf("Guardi l'agenda: 3 compiti scritti, 4 capitoli da studiare, ricerca di gruppo.\n");
    printf("Domani interrogazioni in 2 materie.\n");
    
    printf("\nCome organizzi il pomeriggio?\n");
    printf("1. Studio 6 ore filate per recuperare\n");
    printf("2. Fai una pausa e poi studi (rischi di non finire)\n");
    printf("3. Ti arrendi e guardi Netflix\n");
    
    int scelta = scelta_utente(1, 3);
    
    switch(scelta) {
        case 1:
            printf("\nStudi fino alle 21:30. Riesci a fare quasi tutto.\n");
            printf("Ma hai mal di testa e non hai cenato bene.\n");
            printf("Ti addormenti alle 01:00. Domani saranno 5 ore di sonno.\n");
            s->stress += 25;
            s->ore_sonno = 5;
            s->voglia_vivere -= 15;
            s->media += 0.2; // Piccolo miglioramento nella media
            break;
            
        case 2:
            printf("\nTi riposi 1 ora, poi cominci a studiare.\n");
            printf("Alle 23:00 ti accorgi che hai fatto solo metà.\n");
            printf("Panico. Studi fino alle 02:00 in ansia.\n");
            s->stress += 35;
            s->ore_sonno = 4;
            s->voglia_vivere -= 20;
            break;
            
        case 3:
            printf("\nGuardi una serie fino a tardi. Ti senti in colpa.\n");
            printf("Domani sarà un disastro, ma almeno stasera respiri.\n");
            printf("Ansia da domani: già pensi alle scuse per i prof.\n");
            s->stress += 40;
            s->ore_sonno = 6;
            s->voglia_vivere -= 10;
            s->media -= 0.3; // Peggioramento della media
            break;
    }
    
    mostra_status(s);
    pausa();
}

void risultato_finale(Studente *s) {
    printf("\n\n=== FINE GIORNATA - RIEPILOGO ESISTENZIALE ===\n");
    
    printf("\n📊 STATISTICHE DI %s:\n", s->nome);
    printf("----------------------------------------\n");
    mostra_status(s);
    
    printf("\n💭 ANALISI PSICOLOGICA:\n");
    if(s->stress >= 90) {
        printf("Sei vicino al burnout. Il sistema ha quasi vinto.\n");
    } else if(s->stress >= 70) {
        printf("Il peso del sistema ti sta schiacciando.\n");
    } else if(s->stress >= 50) {
        printf("Sopravvivi, ma a quale prezzo?\n");
    } else {
        printf("Hai resistito, ma domani si ricomincia.\n");
    }
    
    printf("\n📝 REPORT GIORNALIERO:\n");
    printf("- Media scolastica: %.1f (", s->media);
    if(s->media >= 6.0) printf("Sufficiente, ma a che costo?)\n");
    else printf("Insufficiente, come prevedibile)\n");
    
    printf("- Ore di sonno: %d (", s->ore_sonno);
    if(s->ore_sonno >= 8) printf("Miracolo!)\n");
    else if(s->ore_sonno >= 6) printf("Almeno qualcosa)\n");
    else printf("Zombie mode attivo)\n");
    
    printf("- Stress accumulato: %d/100\n", s->stress);
    printf("- Voglia di vivere: %d%%\n", s->voglia_vivere);
    
    printf("\n🎯 CONCLUSIONE:\n");
    printf("----------------------------------------\n");
    printf("Un'altra giornata di sopravvivenza completata.\n");
    printf("La scuola ti prepara alla vita... \n");
    printf("...ti prepara a soffrire.\n\n");
    
    printf("Il sistema non è fatto per lo studente,\n");
    printf("lo studente è fatto per il sistema.\n\n");
    
    printf("\"Nel mondo del lavoro sarà uguale\" dicono.\n");
    printf("E se fosse il momento di cambiare tutto?\n\n");
    
    printf("Grazie per aver giocato a EDU-K.O.\n");
    printf("Domani, stessa ora, stessa sofferenza.\n");
    printf("----------------------------------------\n");
}

void ascii_art_intro() {
    printf("\n");
    printf("   ███████╗██████╗ ██╗   ██╗      ██╗  ██╗     ██████╗ \n");
    printf("   ██╔════╝██╔══██╗██║   ██║      ██║ ██╔╝    ██╔═══██╗\n");
    printf("   █████╗  ██║  ██║██║   ██║█████╗█████╔╝     ██║   ██║\n");
    printf("   ██╔══╝  ██║  ██║██║   ██║╚════╝██╔═██╗     ██║   ██║\n");
    printf("   ███████╗██████╔╝╚██████╔╝      ██║  ██╗ ██╗╚██████╔╝\n");
    printf("   ╚══════╝╚═════╝  ╚═════╝       ╚═╝  ╚═╝ ╚═╝ ╚═════╝ \n");
    printf("\n");
    printf("           Il Simulatore di Sopravvivenza Scolastica\n");
    printf("          \"Benvenuto nel sistema che vuole distruggerti\"\n");
}

void pausa() {
    printf("\nPremi INVIO per continuare...");
    getchar();
}

int scelta_utente(int min, int max) {
    int scelta;
    char buffer[100];
    
    while(1) {
        printf("\nScelta (inserisci il numero): ");
        if(fgets(buffer, sizeof(buffer), stdin) != NULL) {
            scelta = atoi(buffer);
            if(scelta >= min && scelta <= max) {
                return scelta;
            }
        }
        printf("Scelta non valida. Riprova.\n");
    }
}