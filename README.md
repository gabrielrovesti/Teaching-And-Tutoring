# Teaching & Tutoring

## Scopo del progetto
- **Centralizzare** appunti, esercizi, slide, codici sorgente e altre risorse prodotte durante lezioni private e attività di tutorato universitario.
- **Favorire la condivisione** con studenti e colleghi docenti, garantendo versionamento e aggiornamenti continui.
- **Promuovere il riuso** del materiale in contesti didattici differenti (scuola secondaria di I e II grado, esami di stato, corsi universitari).

## Struttura sintetica
```text
Ripetizioni private/
│
├── Annuncio per ripetizioni/         # Locandine e informazioni generali
└── Medie-Superiori/
    ├── Fisica/                       # Esperienze di laboratorio, schede
    ├── Informatica/                  # Appunti e soluzioni in Java/C/Python
    └── …
Tutorato-UniPD/
├── Basi di Dati/                     # Prove d’esame, query SQL, normalizzazione
├── Programmazione/                   # Java, C++, Python, algoritmi
└── Sistemi & Reti/                   # Esercizi e progetti di reti
└── …
```
*La struttura completa è consultabile con `git ls-tree -R main`.*

## Convenzioni
- **YYYY-MM** nel nome cartella → data della lezione.
- **.pdf** ⟶ slide o dispense; **.docx** ⟶ tracce/esercizi; **.java / .py / .c** ⟶ sorgenti.
- Ogni directory può contenere un `README.md` locale con istruzioni specifiche.

## Come utilizzare i materiali
1. **Clona** il repository  
   ```bash
   git clone https://github.com/<user>/Teaching-And-Tutoring.git
   ```
2. Naviga nei moduli di interesse.  
3. I sorgenti Java/C++ sono organizzati come progetti minimal; compila con `make` o con l’IDE preferito.  
4. Le slide sono in PDF; alcuni file `.drawio` possono essere aperti via [draw.io](https://app.diagrams.net).

## Contributi
Pull‑request e segnalazioni sono benvenute purché:
- Mantengano la coerenza della struttura.
- Contengano materiale originale o liberamente distribuibile (licenza compatibile con **CC BY‑NC 4.0**).
- Vengano corredate da un breve sommario nel messaggio di commit.

## Licenza
Il contenuto è distribuito sotto **Creative Commons Attribution‑NonCommercial 4.0 International**.  
Per usi commerciali contattare il maintainer.