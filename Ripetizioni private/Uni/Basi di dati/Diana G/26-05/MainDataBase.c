#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>

#define DBNAME "LotoBianco"
#define USER "postgres"
#define PASSWORD "root"
#define HOST "127.0.0.1"
#define PORT "5432"

void eseguiQuery(char *query, PGconn *con) {
    PGresult *rs = PQexec(con, query);

    if (PQresultStatus(rs) != PGRES_TUPLES_OK) {
        printf("Errore durante l'esecuzione della query: %s\n", PQerrorMessage(con));
    } else {
        int rows = PQntuples(rs);
        int cols = PQnfields(rs);

        printf("Risultati della query:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%s\t", PQgetvalue(rs, i, j));
            }
            printf("\n");
        }
    }
    PQclear(rs);
}

void chiudiConnessione(PGconn *conn) {
    PQfinish(conn);
    exit(1);
}

int main() {
    PGconn *conn;
    PGresult *res;
    int scelta;

    // Connessione al database
    conn = PQsetdbLogin(HOST, PORT, NULL, NULL, DBNAME, USER, PASSWORD);

    // Verifica della connessione
    if (PQstatus(conn) != CONNECTION_OK) {
        printf("Connessione al database fallita: %s\n", PQerrorMessage(conn));
        chiudiConnessione(conn);
    }

    // Loop per l'esecuzione delle query
    do {
        // Menu delle opzioni
        printf("Scegli un'opzione:\n");
        printf("1. Trattamenti che hanno utilizzato un prodotto con scadenza entro 30 giorni dalla data del trattamento con il rispettivo prodotto\n");
        printf("2. Dipendenti specialisti che hanno eseguito trattamenti utilizzando almeno 3 prodotti in una sola volta con rispettivo codice e data del trattamento e numero di prodotti usati \n");
        printf("3. Fatture il cui totale supera la media di tutti i totali con la media stessa e i nomi e cognomi degli specialisti che hanno eseguito i trattamenti di quelle fatture\n");
        printf("4. Cliente che ha speso di più in assoluto\n");
        printf("5. Tutti i trattamenti dal 2025 in poi dove è stato utlizzato il prodotto Bioline Jatò', 'Pure Gel Cleansing e i rispettivi clienti che ne hanno usufruito\n");
        printf("6. Elenco di tutti i dipendenti, mostrando per ciascuno il cf, il nome, il cognome, l’area termale se è addetto, il titolo se è specialista e un’indicazione se è segretario\n");
        printf("7. Turni non assegnati per ciascuna area\n");
        printf("8. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        if(scelta == 1) {
            char *query =

                "SELECT \
                    t.codice AS codice_trattamento,\
                    t.data_ora AS data_trattamento, \
                    u.marca_prodotto,\
                    u.nome_prodotto,\
                    p.data_scadenza AS scadenza_prodotto\
                FROM trattamento t\
                JOIN utilizzo u ON t.codice = u.codice_trattamento\
                JOIN prodotto p ON \
                    u.marca_prodotto = p.marca AND \
                    u.nome_prodotto = p.nome\
                WHERE p.data_scadenza BETWEEN t.data_ora::date AND (t.data_ora + INTERVAL '30 days')::date\
                ORDER BY t.data_ora, t.codice;";

            eseguiQuery(query, conn);

        } else if (scelta == 2) {
            char *query =
                "SELECT \
                    d.nome,\
                    d.cognome, \
                    t.codice AS codice_trattamento, \
                    t.data_ora AS data_trattamento, \
                    COUNT(*) AS numero_prodotti_usati\
                FROM dipendente d\
                JOIN specialista s ON d.cf = s.cf_spe\
                JOIN trattamento t ON s.cf_spe = t.cf_specialista\
                JOIN utilizzo u ON t.codice = u.codice_trattamento\
                GROUP BY d.nome, d.cognome, t.codice, t.data_ora\
                HAVING COUNT(*) >= 3 \
                ORDER BY d.cognome, d.nome, t.data_ora;";

            eseguiQuery(query, conn);

        } else if (scelta == 3) {
            char *query =
                "WITH trattamenti_distinti AS (\
                    SELECT DISTINCT codice, numero_fattura, prezzo, cf_specialista\
                    FROM trattamento\
                ),\
                totali_fattura AS (\
                    SELECT numero_fattura, SUM(prezzo) AS totale_fattura\
                    FROM trattamenti_distinti\
                    GROUP BY numero_fattura\
                ),\
                media_globale AS (\
                    SELECT AVG(totale_fattura) AS media\
                    FROM totali_fattura\
                ),\
                fatture_sopra_media AS (\
                    SELECT t.numero_fattura, t.totale_fattura\
                    FROM totali_fattura t\
                    JOIN media_globale m ON t.totale_fattura > m.media\
                ),\
                specialisti_fatture AS (\
                    SELECT DISTINCT f.numero_fattura, d.nome, d.cognome\
                    FROM trattamento tr\
                    JOIN fatture_sopra_media f ON tr.numero_fattura = f.numero_fattura\
                    JOIN specialista s ON tr.cf_specialista = s.cf_spe\
                    JOIN dipendente d ON s.cf_spe = d.cf\
                )\
                SELECT sf.numero_fattura, sf.nome, sf.cognome, m.media\
                FROM specialisti_fatture sf\
                JOIN media_globale m ON TRUE\
                ORDER BY sf.numero_fattura;";

            eseguiQuery(query, conn);

        } else if (scelta == 4) {
            char *query =
                "CREATE VIEW spesa_clienti AS\
                SELECT f.cf AS cf_cliente, SUM(t.prezzo) AS totale_speso\
                FROM fattura f\
                JOIN trattamento t ON f.numero = t.numero_fattura AND f.cf = t.cf_cliente\
                GROUP BY f.cf;\
                \
                SELECT c.cf, c.nome, c.cognome,\
                    SUM(t.prezzo) AS totale_speso\
                FROM cliente c\
                JOIN trattamento t ON t.cf_cliente = c.cf\
                GROUP BY c.cf, c.nome, c.cognome\
                ORDER BY totale_speso DESC\
                LIMIT 1;";

            eseguiQuery(query, conn);

        } else if (scelta == 5) {
            char *query =
            "SELECT c.cf AS cf_cliente, c.nome,c.cognome,\
                t.codice AS codice_trattamento,\
                t.data_ora,\
                u.marca_prodotto,\
                u.nome_prodotto\
            FROM trattamento t\
            JOIN utilizzo u ON t.codice = u.codice_trattamento\
            JOIN cliente c ON t.cf_cliente = c.cf\
            WHERE u.marca_prodotto = 'Bioline Jatò'\
                AND u.nome_prodotto = 'Pure Gel Cleansing'\
                AND t.data_ora > '2025-01-01 00:00:00'\
            ORDER BY t.data_ora;";

            eseguiQuery(query, conn);

        } else if (scelta == 6) {
            char *query =
                "SELECT DISTINCT\
                    d.cf,\
                    d.nome,\
                    d.cognome,\
                    ar.nome_area AS area_lavoro,\
                    s.titolo AS titolo_specialista,\
                CASE \
                    WHEN se.cf_seg IS NOT NULL THEN 'Sì'\
                    ELSE NULL\
                END AS segretario\
                FROM dipendente d\
                LEFT JOIN addetto_at a ON d.cf = a.cf_add\
                LEFT JOIN area_termale ar ON a.area = ar.id_area\
                LEFT JOIN specialista s ON d.cf = s.cf_spe\
                LEFT JOIN segretario se ON d.cf = se.cf_seg\
                WHERE a.cf_add IS NOT NULL OR s.cf_spe IS NOT NULL OR se.cf_seg IS NOT NULL\
                ORDER BY d.cognome;";

            eseguiQuery(query, conn);

         } else if (scelta == 7) {
            char *query =
                "CREATE VIEW turni AS\
                SELECT 'Mattina' AS turno\
                UNION\
                SELECT 'Pomeriggio'\
                UNION\
                SELECT 'Sera';\
                \
                SELECT a.id_area, a.nome_area, t.turno\
                FROM area_termale a, turni t\
                WHERE \
                    NOT EXISTS (\
                        SELECT *\
                        FROM addetto_at at\
                        WHERE at.area = a.id_area AND at.turno = t.turno\
                    )\
                ORDER BY a.id_area, t.turno;";

            eseguiQuery(query, conn);

        } else if (scelta == 8) {
            printf("Uscita...\n");
        } else {
            printf("Opzione non valida\n");
        }
    } while (scelta != 8);

    // Chiusura della connessione al database
    PQfinish(conn);

    return 0;
}
