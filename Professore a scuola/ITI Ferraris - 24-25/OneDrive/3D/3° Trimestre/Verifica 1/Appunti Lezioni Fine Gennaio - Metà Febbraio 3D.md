## Accesso Multiplo al Canale Condiviso

Il sottolivello MAC ha la responsabilità fondamentale di gestire l'accesso a un canale di comunicazione condiviso, evitando errori dovuti alle collisioni (interferenze tra trasmissioni simultanee). Questa gestione si basa su regole specifiche definite nei protocolli di accesso al canale.

### Classificazione dei Protocolli di Accesso

I protocolli di accesso si dividono in due categorie principali:

1. **Accesso Ordinato** 
   - Il diritto di trasmissione viene assegnato a una stazione alla volta
   - Basato su criteri predefiniti
   - Elimina completamente le collisioni
   - Esempio: Token Ring

2. **Accesso Casuale**
   - Le stazioni trasmettono quando necessario
   - Possibilità di collisioni che devono essere gestite
   - Si suddivide ulteriormente in:
     - Protocolli senza rivelazione del canale (es. ALOHA)
     - Protocolli con rivelazione del canale (es. CSMA)

### ALOHA e Varianti

#### ALOHA Puro
- Primo protocollo ad accesso casuale (Università delle Hawaii)
- Caratteristiche:
  - Trasmissione immediata quando necessario
  - Nessun controllo preventivo del canale
  - In caso di collisione: ritrasmissione dopo tempo casuale
- Performance:
  - Throughput massimo: Ge^(-2G) frame/tempo
  - G = numero medio trasmissioni per unità di tempo
  - Utilizzo massimo del canale: 18.4%
- Meccanismo di backoff:
  - Tempo di attesa: casuale tra [0, (K-1)T]
  - T = tempo trasmissione frame
  - K = parametro configurabile (può dipendere dal numero di collisioni)

#### Slotted ALOHA
- Evoluzione dell'ALOHA puro
- Modifiche principali:
  - Tempo diviso in slot discreti
  - Trasmissioni permesse solo all'inizio degli slot
  - Sincronizzazione tramite stazione centrale
- Vantaggi:
  - Dimezza la vulnerabilità alle collisioni
  - Raddoppia l'utilizzo massimo del canale (36.8%)
  - Collisioni possibili solo tra frame nello stesso slot

### CSMA (Carrier Sense Multiple Access)

Il CSMA introduce il concetto di "ascolto del canale" prima della trasmissione. Esistono tre varianti principali:

#### 1. CSMA 1-persistente
- Funzionamento:
  - Ascolto continuo del canale
  - Se libero: trasmissione immediata (probabilità 1)
  - Se occupato: attesa e ricontrollo continuo
- Caratteristiche:
  - Data rate superiore al 50%
  - Problemi:
    - Non considera ritardo di propagazione
    - Rischio elevato di collisioni dopo liberazione del canale

#### 2. CSMA non-persistente
- Approccio più conservativo:
  - Se canale occupato: attesa tempo casuale prima di ricontrollare
  - Non monitora continuamente il canale
- Vantaggi:
  - Riduce probabilità di collisioni
  - Migliore utilizzo del canale
- Svantaggi:
  - Latenza maggiore
  - Possibile sottoutilizzo del canale

#### 3. CSMA p-persistente
- Utilizzato su canali slotted
- Algoritmo:
  - Se canale libero: trasmette con probabilità p
  - Se non trasmette: attende prossimo slot (prob. 1-p)
  - Ripete processo fino a trasmissione o rilevazione occupazione
- Caratteristiche:
  - Buon compromesso tra prestazioni e collisioni
  - Richiede sincronizzazione degli slot

### CSMA/CD (Collision Detection)

Il CSMA/CD è l'evoluzione del CSMA che include la rilevazione delle collisioni durante la trasmissione.

- Caratteristiche principali:
  - Ascolta durante la trasmissione (listen while talking)
  - Rilevazione analogica delle collisioni
  - Interruzione immediata in caso di collisione
  - Invio jamming signal per notifica
  - Utilizzo di exponential backoff per ritrasmissione

- Gestione collisioni:
  1. Rilevazione differenza tra segnale trasmesso e letto
  2. Interruzione immediata trasmissione
  3. Invio jamming sequence
  4. Calcolo tempo attesa con exponential backoff
  5. Ritentativo trasmissione

## Ethernet (IEEE 802.3)

### Caratteristiche Fondamentali
- Standard dominante per reti LAN
- Topologia logica: bus
- Mezzo condiviso tra le stazioni
- Protocollo di accesso: CSMA/CD


## Comunicazioni Wireless e Satellitari

## Spettro Elettromagnetico e Bande

### Bande di Frequenza Wireless
1. **ISM (Industrial, Scientific, Medical)**
   - 2.4 GHz: Wi-Fi, Bluetooth
   - 5 GHz: Wi-Fi ad alta velocità
   - Caratteristiche:
     - Uso libero senza licenza
     - Soggette a interferenze
     - Portata limitata

2. **Telefonia Mobile**
   - GSM (900/1800 MHz)
   - UMTS (2100 MHz)
   - LTE (700-2600 MHz)
   - 5G (Sub-6GHz e mmWave 24-47 GHz)
   - Caratteristiche:
     - Uso con licenza
     - Copertura estesa
     - Gestione interferenze

### Propagazione Segnali Wireless
- **Path Loss**: attenuazione proporzionale a d²/d⁴
- **Multipath**: riflessioni multiple del segnale
- **Shadowing**: ostacoli nel percorso
- **Fading**: variazioni di potenza nel tempo

## Reti Infrarossi

### Caratteristiche Principali
1. **Frequenze**: 300 GHz - 430 THz
2. **Vantaggi**:
   - Immunità interferenze RF
   - Sicurezza intrinseca (no attraversamento muri)
   - Costo contenuto
3. **Limitazioni**:
   - Necessità line-of-sight
   - Portata limitata (1-10m)
   - Sensibilità a luce ambiente

### Modalità Operative
4. **Direct IR**
   - LOS diretto tra dispositivi
   - Massima efficienza energetica
5. **Diffuse IR**
   - Riflessione su superfici
   - Maggiore flessibilità
   - Minore efficienza

## Reti Cellulari

### Concetti Base
1. **Cella**: area geografica servita da una BTS
2. **Frequency Reuse**: riutilizzo frequenze tra celle non adiacenti
3. **Cell Splitting**: divisione celle per aumentare capacità
4. **Processo di Handoff**
   - Misurazione continua segnale
   - Decisione basata su threshold
   - Esecuzione cambio cella
   - Aggiornamento routing

## Reti Satellitari

### Orbite Satellitari

1. **LEO (Low Earth Orbit)**
   - Altitudine: 500-2000 km
   - Latenza: 1-4 ms
   - Caratteristiche:
     - Costellazioni numerose
     - Handoff frequenti
     - Copertura non continua
   - Applicazioni:
     - Internet satellitare (Starlink)
     - Osservazione terrestre

2. **MEO (Medium Earth Orbit)**
   - Altitudine: 2000-35786 km
   - Latenza: 50-150 ms
   - Caratteristiche:
     - Orbite semi-sincrone
     - Copertura regionale
     - Handoff moderati
   - Applicazioni:
     - GPS/Galileo
     - Comunicazioni regionali

3. **GEO (Geostationary Earth Orbit)**
   - Altitudine: 35786 km
   - Latenza: ~250 ms
   - Caratteristiche:
     - Posizione fissa rispetto Terra
     - Copertura 1/3 superficie
     - No handoff
   - Applicazioni:
     - Broadcasting TV
     - Telecomunicazioni fisse
     - Meteo

### Parametri Tecnici Satelliti

1. **Problematiche**
   - Ritardo propagazione
   - Attenuazione atmosferica
   - Effetto Doppler
   - Interferenze terrestri

2. **Tecniche di Accesso**
   - FDMA (Frequency Division)
   - TDMA (Time Division)
   - CDMA (Code Division)