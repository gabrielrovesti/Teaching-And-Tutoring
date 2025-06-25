# 1 - Informatica
## 1.1. Basi di Dati - Sicurezza

Noi vogliamo garantire alcuni principi fondamentali, tipici della crittografia = CIA.

- **Confidenzialità** (C = Confidenzialità)
- **Integrità** (I = Integrità)
- **Disponibilità** (A = Availability)

Una base di dati ha alcune proprietà:

- **Persistenza**: i dati sopravvivono ai programmi che li utilizzano
- **Condivisione**: accesso simultaneo da più utenti/applicazioni
- **Affidabilità**: protezione da malfunzionamenti e perdite
- **Efficienza**: prestazioni ottimali nelle operazioni
- **Efficacia**: soddisfa i requisiti dell'utente

---
## 1.2 Modello E-R

Il modello E-R (Entità - Relazione) rappresenta delle **realtà / domini** (es. vuoi modellare una biblioteca / cinema) che permetta di salvarne le informazioni in un *modo semplice ma preciso* (sicuro e permanente)!

È strutturato in:

**1. Entità**

- Oggetti del mondo reale di interesse per l'applicazione
- Rappresentate con rettangoli
- Esempi: STUDENTE, CORSO, DOCENTE

**2 Attributi**

- Proprietà delle entità
- Rappresentati con ellissi
- Tipi:
    - **Semplici**: non scomponibili (Nome)
    - **Composti**: scomponibili (Indirizzo = Via + Città + CAP)
    - **Chiave**: identificano univocamente l'entità (sottolineati)

**3. Relazioni**

- Associazioni tra entità
- Rappresentate con rombi
- **Cardinalità**: 1:1, 1:N, N:N

Regole di Traduzione E/R → Relazionale

1. **Ogni entità** diventa una **tabella**
2. **Ogni attributo** diventa una **colonna**
3. **Relazioni 1:1**: chiave esterna in una delle due tabelle
4. **Relazioni 1:N**: chiave esterna nella tabella "molti"
5. **Relazioni N:N**: nuova tabella con le chiavi delle entità coinvolte

> Possibili collegamenti: 
> - Storia (800/900 rispetto alle guerre - tecnologia e sviluppo dei mezzi di comunicazione (relazioni = salvataggio permanente delle informazioni)
> - Inglese (Figure chiave dell'informatica - Alan Turing)

---
## 1.3. Modello relazione

**Relazione (Tabella)**

- Insieme di *tuple* (righe) con stessa struttura
- Ogni tupla rappresenta un'*istanza* dell'entità

**Schema di Relazione**

- R(A₁, A₂, ..., Aₙ) dove R è il nome e A₁...Aₙ sono gli attributi
	- Es. Studenti("CF", Nome, Cognome, Data)

**Dominio**

- Insieme dei valori ammissibili per un attributo

**Chiave Primaria**

- Attributo/i che identificano univocamente ogni tupla
- Non può contenere valori NULL

**Chiave Esterna (Foreign Key)**

- Attributo che referenzia la chiave primaria di un'altra tabella
- Garantisce l'integrità referenziale

> Possibili collegamenti: 
> - TPS (Salvare i permessi di ogni utente all'interno di XML e fare in modo che siano separati)

---
## 1.4 Normalizzazione

**Prima Forma Normale (1NF)**

Una relazione è in 1NF se:

- Ogni attributo contiene **valori atomici** (non scomponibili) .- singoli logicamente
- Non ci sono **attributi multivalore**

**Esempio NON in 1NF:**
```
STUDENTE(Matricola, Nome, Telefoni)
123, Mario Rossi, "123456, 789012"
```

**Esempio in 1NF:**
```
STUDENTE(Matricola, Nome)
TELEFONO(Matricola, Numero)
```

**Seconda Forma Normale (2NF)**

Una relazione è in 2NF se:

- È in **1NF**
- Ogni attributo non-chiave dipende **completamente** dalla chiave primaria

**Dipendenza Funzionale**: A → B (A determina B)

**Terza Forma Normale (3NF)**

Una relazione è in 3NF se:

- È in **2NF**
- Non ci sono **dipendenze transitive** (A → B → C, quindi A → C)

> Possibili collegamenti:
> - Inglese / Storia


---

## 1.5. SQL

**Classificazione SQL**

**1. Creazione**

- CREATE, ALTER, DROP
- Definisce la struttura del database

**2. Modifica / cancellazione**

- SELECT, INSERT, UPDATE, DELETE
- Manipola i dati

**3. Controllo**

- GRANT, REVOKE
- Gestisce i permessi

> Possibili collegamenti:
> - Sistemi (Crittografia / Permessi solo utili ai singoli utenti + la parte Reti)
> - TPS (GPDR - Framework sicurezza + AI)

**Creazione Database**

```sql
CREATE DATABASE nome_database;
```

**Creazione Tabella**

```sql
CREATE TABLE STUDENTE (
    Matricola INT PRIMARY KEY,
    Nome VARCHAR(50) NOT NULL,
    Cognome VARCHAR(50) NOT NULL,
    DataNascita DATE,
    Email VARCHAR(100) UNIQUE
);
```

**Vincoli di Integrità**

- **PRIMARY KEY**: chiave primaria
- **FOREIGN KEY**: chiave esterna
- **NOT NULL**: campo obbligatorio
- **UNIQUE**: valore univoco
- **CHECK**: controllo su valori ammissibili

**Inserimento**

```sql
INSERT INTO STUDENTE (Matricola, Nome, Cognome)
VALUES (123, 'Mario', 'Rossi');
```

**Modifica**

```sql
UPDATE STUDENTE 
SET Email = 'mario.rossi@email.com'
WHERE Matricola = 123;
```

**Cancellazione**

```sql
DELETE FROM STUDENTE 
WHERE Matricola = 123;
```

**Sintassi Base**

```sql
SELECT attributi
FROM tabelle
WHERE condizioni
GROUP BY attributi
HAVING condizioni_gruppo
ORDER BY attributi;
```

**Operatori di Confronto**

- `=, <>, <, >, <=, >=`
- `LIKE` (pattern matching con % e _)
- `IN` (appartenenza a un insieme)
- `BETWEEN` (intervallo)
- `IS NULL / IS NOT NULL`

**Operatori Logici**

- `AND, OR, NOT`

**Funzioni di Aggregazione**

- `COUNT()`: conta le righe
- `SUM()`: somma valori
- `AVG()`: media
- `MAX(), MIN()`: valore massimo/minimo

**INNER JOIN** (equi-join)

```sql
SELECT s.Nome, c.Titolo
FROM STUDENTE s
INNER JOIN ISCRIZIONE i ON s.Matricola = i.Matricola
INNER JOIN CORSO c ON i.CodCorso = c.CodCorso;
```

**LEFT/RIGHT JOIN**

- Include anche le righe senza corrispondenza

**Tipi di JOIN**

- **Theta JOIN**: condizione generica
- **Equi JOIN**: condizione di uguaglianza
- **Natural JOIN**: su attributi con stesso nome

## 1.6 - Collegamenti Informatica

## **STORIA**

### 1.1 Basi di Dati - Sicurezza (CIA)

- **Controllo dell'informazione nei regimi totalitari**: schedatura fascista e nazista per controllare la popolazione
- **Guerra Fredda**: intelligence e protezione delle informazioni strategiche
- **Archivi storici**: necessità di preservare documenti storici (disponibilità) e garantirne l'autenticità (integrità)

### 1.2 Modello E-R

- **Genealogie reali**: modellazione delle dinastie europee (entità SOVRANO, relazioni SUCCESSIONE)
- **Reti commerciali medievali**: entità MERCANTE, CITTÀ, PRODOTTO con relazioni commerciali
- **Organizzazione militare**: strutture gerarchiche dell'esercito come modelli E-R

### 1.4 Normalizzazione

- **Riorganizzazione amministrativa**: eliminazione di duplicazioni burocratiche nell'Unità d'Italia
- **Standardizzazione industriale**: principi tayloristi e fordisti per eliminare sprechi

## **ITALIANO**

### 1.1 Basi di Dati - Sicurezza

- **Verismo**: documentazione "scientifica" della realtà sociale (persistenza delle informazioni)
- **Archivi letterari**: conservazione e catalogazione del patrimonio culturale

### 1.2 Modello E-R

- **Personaggi dei Malavoglia**: modellazione delle relazioni familiari e sociali
- **Strutture narrative**: entità AUTORE, OPERA, PERSONAGGIO, TEMA
- **Intertestualità**: relazioni tra opere letterarie

### 1.4 Normalizzazione

- **Stile essenziale di Ungaretti**: eliminazione del superfluo poetico
- **Editing letterario**: processo di revisione per eliminare ridondanze

### 1.5 SQL

- **Interrogative indirette**: struttura logica simile alle query SQL
- **Concordanze bibliche**: primi esempi di "query" su testi

## **INGLESE**

### 1.1 Basi di Dati - Sicurezza

- **Cybersecurity**: terminologia tecnica CIA (Confidentiality, Integrity, Availability)
- **Digital privacy**: protezione dei dati personali nell'era digitale

### 1.2 Modello E-R

- **Alan Turing**: pioniere dell'informatica e dei modelli computazionali
- **Database design**: metodologie di progettazione in ambito internazionale

### 1.5 SQL

- **Structured Query Language**: linguaggio standardizzato internazionale
- **Technical documentation**: manuali e specifiche tecniche in inglese

## **MATEMATICA**

### 1.2 Modello E-R

- **Teoria degli insiemi**: entità come insiemi, relazioni come prodotti cartesiani
- **Grafi**: rappresentazione matematica delle relazioni
- **Funzioni**: chiavi primarie come funzioni iniettive

### 1.3 Modello Relazionale

- **Relazioni matematiche**: R ⊆ A × B
- **Algebra relazionale**: operazioni di unione, intersezione, differenza

### 1.4 Normalizzazione

- **Dipendenze funzionali**: f: A → B
- **Ottimizzazione**: minimizzazione della ridondanza

### 1.5 SQL

- **Logica proposizionale**: operatori AND, OR, NOT
- **Funzioni di aggregazione**: operazioni matematiche su insiemi
- **Serie numeriche**: per ottimizzazione delle query

## **SISTEMI E RETI**

### 1.1 Basi di Dati - Sicurezza

- **Crittografia simmetrica e asimmetrica**: protezione dei dati in transito
- **Firewall e DMZ**: protezione perimetrale dei database server
- **VPN**: accesso sicuro ai database remoti

### 1.3 Modello Relazionale

- **Database distribuiti**: frammentazione e replicazione
- **Load balancing**: distribuzione del carico sui server database

### 1.5 SQL

- **Protocolli TCP/IP**: comunicazione client-server con database
- **Backup e recovery**: strategie di disaster recovery

## **TPSIT**

### 1.1 Basi di Dati - Sicurezza

- **GDPR**: regolamentazione europea sulla protezione dati
- **AI Act**: normative su intelligenza artificiale e dati
- **Audit trail**: tracciabilità delle operazioni sui dati

### 1.3 Modello Relazionale

- **ORM**: mapping oggetto-relazionale in sviluppo software
- **API RESTful**: operazioni CRUD via HTTP

### 1.5 SQL

- **Prepared statements**: prevenzione SQL injection
- **Connection pooling**: gestione efficiente delle connessioni database

## **GPOI**

### 1.1 Basi di Dati - Sicurezza

- **Business continuity**: piani di continuità operativa
- **Risk management**: gestione rischi informatici
- **Compliance**: conformità normativa (SOX, GDPR)

### 1.2 Modello E-R

- **Organigramma aziendale**: modellazione strutture organizzative
- **Process mapping**: rappresentazione dei processi business

### 1.4 Normalizzazione

- **Lean management**: eliminazione sprechi (waste)
- **Business Process Reengineering**: ottimizzazione processi

### 1.5 SQL

- **Business Intelligence**: analisi dati per decisioni strategiche
- **KPI dashboard**: indicatori di performance aziendale

---
# 2. Sistemi e Reti

## 2.1 Fondamenti Reti

Classifichiamo le reti per **estensione (grandezza)**:

- **LAN** (Local Area Network): reti locali (edificio, campus)
- **MAN** (Metropolitan Area Network): reti metropolitane
- **WAN** (Wide Area Network): reti geografiche
- **PAN** (Personal Area Network): reti personali (Bluetooth, NFC)

**Per topologia (forma)**

- **Bus**: tutti i nodi collegati a un cavo comune
- **Stella**: nodi collegati a un hub/switch centrale
- **Anello**: nodi collegati in circolo
- **Mesh**: collegamenti multipli tra nodi

**Per prestazioni (Quality of Service - QoS) - Qualità**

- **Larghezza di banda**: capacità di trasmissione (bps)
- **Latenza**: tempo di propagazione del segnale
- **Throughput**: velocità effettiva di trasferimento
- **Jitter**: variazione della latenza

**Le prestazioni dipendono anche dal materiale!**

**Cavi in Rame (Economico ma più lento)**

- **Twisted Pair** (UTP/STP): Cat5e, Cat6, Cat6a
- **Coassiale**: per reti cablaye e satellitari

**Fibra Ottica (Luce) - Velocissima**

- **Monomodale**: lunghe distanze, laser
- **Multimodale**: medie distanze, LED

**Wireless (Senza fili - Access Point)**

- **Wi-Fi**: IEEE 802.11 (a/b/g/n/ac/ax)
- **Bluetooth**: comunicazioni a corto raggio
- **Satellitare**: copertura globale

---
## 2.2 Modelli ISO-OSI e TCP-IP

Ci sono due macro-modelli:
- ISO/OSI = Teorico = Riferimento per applicazioni e programmi
- TCP/IP = Applicativo = Realmente usato nelle applicazioni
### 2.2.1 Modello OSI (7 livelli)

**Livello 7 - Applicazione (Programma dell'utente)**

- Interfaccia con l'utente e scopo dell'applicazione
- Protocolli: HTTP, SMTP, FTP, DNS

**Livello 6 - Presentazione (Forma standard del dato)**

- Crittografia, compressione, codifica (come salvare i dati)
- Formati: JPEG, MPEG, SSL/TLS

**Livello 5 - Sessione (Mantieni attiva l'applicazione)**

- Gestione delle sessioni di comunicazione
- Sincronizzazione, checkpoint

**Livello 4 - Trasporto (Modi affidabili / non-affidabili)**

- Comunicazione end-to-end
- Protocolli: TCP, UDP

**Livello 3 - Rete (Instradamento - Arrivare a destinazione)**

- Routing e indirizzamento logico
- Protocolli: IP, ICMP, OSPF, BGP

**Livello 2 - Collegamento (Accesso al canale condiviso e poi correzione errori)**

- Controllo accesso al mezzo, rilevamento errori
- Protocolli: Ethernet, Wi-Fi, PPP

**Livello 1 - Fisico (Segnali e uso mezzi trasmissivi)**

- Trasmissione bit su mezzo fisico
- Specifiche elettriche, ottiche, radio

### 2.2.2 Architettura TCP/IP (4 livelli)

**Livello Applicazione** (corrisponde a OSI 5-6-7)

- HTTP, HTTPS, SMTP, POP3, IMAP, FTP, DNS, DHCP

**Livello Trasporto** (corrisponde a OSI 4)

- TCP: affidabile, orientato alla connessione
- UDP: veloce, senza connessione

**Livello Internet** (corrisponde a OSI 3)

- IP: indirizzamento e routing
- ICMP: messaggi di controllo

**Livello Accesso alla Rete** (corrisponde a OSI 1-2)

- Ethernet, Wi-Fi, PPP

### 2.2.3. Focus: Indirizzamento IP

#### 2.2.3.1 Indirizzamento Classful

**Classe A**: 1.0.0.0 - 126.255.255.255

- Subnet mask: 255.0.0.0 (/8)
- 16.777.214 host per rete

**Classe B**: 128.0.0.0 - 191.255.255.255

- Subnet mask: 255.255.0.0 (/16)
- 65.534 host per rete

**Classe C**: 192.0.0.0 - 223.255.255.255

- Subnet mask: 255.255.255.0 (/24)
- 254 host per rete

**Indirizzi Speciali**

- **Loopback**: 127.0.0.0/8
- **Private**: 10.0.0.0/8, 172.16.0.0/12, 192.168.0.0/16
- **APIPA**: 169.254.0.0/16

#### 2.2.3.2 Indirizzamento Classless (CIDR)

**Subnet Mask Variabile**

- Notazione CIDR: 192.168.1.0/24
- Supernetting: aggregazione di reti
- VLSM: Variable Length Subnet Mask

**Subnetting**

- Divisione di una rete in sottoreti più piccole
- Formula host: 2^(32-prefix) - 2
- Indirizzo rete: tutti bit host a 0
- Indirizzo broadcast: tutti bit host a 1

---
### 2.2.4. Focus Livello di Trasporto

#### 2.2.4.1 Protocollo TCP (Affidabile)

**Caratteristiche**

- **Affidabile**: controllo errori e ritrasmissioni
- **Orientato alla connessione**: three-way handshake
- **Controllo di flusso**: window sliding
- **Controllo di congestione**: slow start, congestion avoidance

**Three-Way Handshake**

1. Client → Server: SYN
2. Server → Client: SYN-ACK
3. Client → Server: ACK

**Disconnessione (Four-Way Handshake)**

1. Client → Server: FIN
2. Server → Client: ACK
3. Server → Client: FIN
4. Client → Server: ACK

**Formato Pacchetto TCP**

- **Source/Destination Port**: 16 bit ciascuno
- **Sequence Number**: 32 bit
- **Acknowledgment Number**: 32 bit
- **Flags**: SYN, ACK, FIN, RST, PSH, URG

#### 2.2.4.2 Protocollo UDP

**Caratteristiche**

- **Veloce**: overhead minimo
- **Senza connessione**: no handshake
- **Non affidabile**: no controllo errori
- **Applicazioni**: DNS, DHCP, streaming video

**Formato Pacchetto UDP**

- **Source/Destination Port**: 16 bit ciascuno
- **Length**: 16 bit
- **Checksum**: 16 bit
#### 2.2.4.3 Porte e Socket

**Porte Well-Known** (0-1023)

- HTTP: 80, HTTPS: 443
- SMTP: 25, POP3: 110, IMAP: 143
- FTP: 20/21, SSH: 22, Telnet: 23
- DNS: 53, DHCP: 67/68

**Socket**

- Combinazione di IP + Porta
- Endpoint di comunicazione
- Esempio: 192.168.1.100:80

---
### 2.2.5. Focus Livello Applicativo

#### 2.2.5.1 Protocollo HTTP/HTTPS

**HTTP (HyperText Transfer Protocol)**

- Protocollo request-response
- Metodi: GET, POST, PUT, DELETE, HEAD
- Status code: 2xx (successo), 4xx (errore client), 5xx (errore server)

**HTTPS (HTTP Secure)**

- HTTP + SSL/TLS
- Crittografia end-to-end
- Certificati digitali per autenticazione

#### 2.2.5.2 Protocolli Email

**SMTP (Simple Mail Transfer Protocol)**

- Invio email (port 25, 587)
- Relay tra server email

**POP3 (Post Office Protocol v3)**

- Download email dal server (port 110)
- Email cancellate dal server

**IMAP (Internet Message Access Protocol)**

- Accesso email remote (port 143)
- Email rimangono sul server
- Sincronizzazione multi-device

#### 2.2.5.3 Altri Protocolli

**DNS (Domain Name System)**

- Risoluzione nomi → indirizzi IP
- Gerarchia: root, TLD, domini
- Tipi record: A, AAAA, CNAME, MX, NS

**FTP (File Transfer Protocol)**

- Trasferimento file (port 20/21)
- Modalità attiva/passiva

**DHCP (Dynamic Host Configuration Protocol)**

- Assegnazione automatica IP
- Lease time, reservation, scope

---
## 2.3 Sicurezza nelle reti

#### 2.3.4.1 Crittografia

La crittografia è la pratica di codificare informazioni per renderle illeggibili a persone non autorizzate, garantendo la riservatezza e l'integrità dei dati. 
Ne esistono due tipi:

**Crittografia Simmetrica (1 Chiave sola condivisa tra Mittente - A e Destinatario - B)**

- Stessa chiave per cifrare/decifrare
- Algoritmi: AES (Più sicuro), DES, 3DES
- Veloce ma problema distribuzione chiavi

**Crittografia Asimmetrica (1 Chiave condivisa + Coppia chiavi private per A e B)**

- Coppia chiavi: pubblica/privata
- Algoritmi: RSA (Numeri primi), DH, ECC
- Lenta ma risolve distribuzione chiavi

**1. Algoritmo RSA (Rivest-Adleman-Shamir)**

- Basato su fattorizzazione numeri primi
	- 1. Prodotto tra numeri primi "p", "q", 
	- 2. Funzione di Eulero $\phi(n) = (p-1)*(q-1)$ 
	- 3. Prendiamo $e$, numero coprimo (primi tra di loro) con l'input
	- 4. Calcolo chiavi
- Chiave pubblica: $(n, e)$
- Chiave privata: $(n, d)$

**2. Algoritmo Diffie-Hellman**

- Scambio sicuro di chiavi su canale insicuro
- Basato su logaritmo discreto (scambio di chiavi con funzioni logaritmo / modulo)
#### 2.3.4.2 Certificati Digitali e PKI

Un caso d'uso pratico dell'utilizzo di crittografia, abbastanza quotidiano è rappresentato dai seguenti. 

**Certificato Digitale (XML - PEC - SPID)**

- Documento elettronico che lega identità a chiave pubblica
- Standard X.509
- Contiene: nome soggetto, chiave pubblica, CA, scadenza

> Collegamenti: TPS (PEC / XML come formato dati)

**Certification Authority (CA)**

- Ente che emette certificati (Es. Ministero dell'Interno)
- Catena di fiducia
- Root CA (Radice)→ Intermediate CA → End Entity (Finale)

> Esempio: Carta di identità (Ministero dell'Interno --> Comune di Padova --> Te) - Catena di fiducia

**Firma Digitale - Usata dentro i certificati**

- Autenticazione e non ripudio
- Hash del documento cifrato con chiave privata
#### 2.3.4.3 SSL/TLS

Usato a livello sicurezza per crittografare una comunicazione (normalmente in ambito HTTP -> HTTPS oppure a livello trasporto)

**SSL/TLS Handshake (Apertura connessione + Comunicazione sicura tra parti)**

1. Client Hello (Messaggio di apertura)
2. Server Hello + Certificate (Destinatario risponde)
3. Key Exchange (Scambio chiavi e certificati)
4. Change Cipher Spec (Si certificano le parti delle comunicazioni)
5. Finished (Conclusione trasmissione)

#### 2.3.4.4 Sicurezza Perimetrale

All'interno devi salvaguardare il *perimetro* (la porzione controllabile della rete) - ci sono vari modi per farlo.

**Firewall - Può essere sia Hardware (Fisico = Router) oppure Software (Programma - Windows Firewall)**

- **Packet Filtering**: controllo su header pacchetti
- **Stateful**: memoria delle connessioni
- **Application Gateway**: controllo applicativo

**Varie tipologie di firewall**

- **Router Filtrante**: liste di accesso di controllo su router
- **Single-Homed**: un'interfaccia di rete
- **Dual-Homed**: due interfacce separate
- **Host Bastione**: server sicuro in DMZ (Demilitarized Zone)

**DMZ (Demilitarized Zone)**

- Zona intermedia tra rete interna ed esterna
- Ospita server pubblici (web, mail, DNS)

**Proxy Server (Server di controllo intermedio - Meccanismo di controllo esatto)**

- **Forward Proxy**: nasconde client
- **Reverse Proxy**: nasconde server

#### 2.3.4.5 VPN (Virtual Private Network)

VPN = Meccanismo di tunneling (nascondimento delle parti all'interno di una rete) - le parti dentro ad una rete sono schermate.

**Protocolli VPN**

- **IPSec**: cifratura a livello IP
- **L2TP**: tunneling livello 2
- **OpenVPN**: basato su SSL/TLS

---
## 2.4 Modello client-server e distribuito

Modello = Impronta logica di una rete 
Architettura = Impronta fisica di una rete = Impostazione esatta dei ruoli in una rete
### 2.4.1 Modello Client/Server

**Caratteristiche**

- Server: fornisce servizi
- Client: richiede servizi
- Comunicazione request-response

**Vantaggi**

- Centralizzazione risorse (client chiedono a server accessi vari)
- Sicurezza e controllo accessi
- Scalabilità verticale (espandiamo facilmente il numero di server a seconda di quanti client)

**Svantaggi**

- Single point of failure (Se ti va giù il server = Tutto va giù = Collo di bottiglia / Bottleneck)
- Collo di bottiglia server
- Costi hardware server

### 2.4.2 Sistemi Distribuiti

Distribuiti = Tutti hanno stessi ruoli.

**Caratteristiche**

- Elaborazione distribuita su più nodi (punti) della rete
- Trasparenza: location, failure, scaling
- Tolleranza ai guasti (in caso di errori, regge)

**Modelli**

- **Peer-to-Peer**: nodi equivalenti
- **Grid Computing**: risorse condivise
- **Cloud Computing**: servizi on-demand

---
## 2.5 Collegamenti Sistemi e Reti

## **STORIA**

### Fondamenti delle Reti

- **Evoluzione delle comunicazioni**: dal telegrafo ottico (Napoleone) alle reti digitali
- **Prima Guerra Mondiale**: importanza delle comunicazioni militari, sistemi di crittografia
- **Guerra Fredda**: sviluppo di ARPANET per resistere ad attacchi nucleari
- **Globalizzazione**: Internet come fattore di integrazione economica mondiale

### Sicurezza delle Reti

- **Crittografia in guerra**: Enigma tedesca vs. Colossus britannico
- **Intelligence**: nascita dei servizi segreti moderni e intercettazioni
- **Controllo dell'informazione**: censura nei regimi totalitari vs. libertà digitale

### Architetture Distribuite

- **Decentramento**: federalismo vs. centralismo negli stati moderni
- **Resistenza partigiana**: reti clandestine come modello di sistemi distribuiti

## **ITALIANO**

### Modello OSI/TCP-IP

- **Struttura letteraria**: i 7 livelli OSI come la struttura della Divina Commedia (Inferno-Purgatorio-Paradiso con suddivisioni)
- **Comunicazione letteraria**: mittente-messaggio-destinatario vs. client-server

### Protocolli di Comunicazione

- **Linguaggio formale**: protocolli di rete come "grammatica" delle comunicazioni digitali
- **Standardizzazione linguistica**: nascita dell'italiano standard vs. protocolli standardizzati

### Sicurezza

- **Cifrari letterari**: messaggi segreti nella letteratura (Foscolo, Pellico)
- **Censura**: controllo delle comunicazioni nei regimi vs. firewall

## **INGLESE**

### Terminologia Tecnica

- **Protocol**: HTTP, SMTP, FTP - linguaggio tecnico internazionale
- **Cybersecurity**: terminologia specifica (firewall, proxy, encryption)
- **Network administration**: documentazione e manuali tecnici

### Evoluzione Digitale

- **Internet governance**: organismi internazionali (ICANN, IEEE, RFC)
- **Global connectivity**: inglese come lingua franca delle reti
- **Digital divide**: disparità nell'accesso alle tecnologie

## **MATEMATICA**

### Indirizzamento IP

- **Sistemi di numerazione**: binario, decimale, esadecimale
- **Calcoli VLSM**: 2^n per determinare numero host/subnet
- **Algebra booleana**: operazioni logiche AND, OR, NOT per subnet mask

### Crittografia

- **Aritmetica modulare**: base dell'algoritmo RSA
- **Numeri primi**: fattorizzazione in RSA
- **Logaritmo discreto**: algoritmo Diffie-Hellman
- **Funzioni matematiche**: hash crittografici

### Prestazioni di Rete

- **Statistica**: analisi del traffico, throughput medio
- **Teoria delle code**: modelli di congestione di rete
- **Serie numeriche**: convergenza dei protocolli di routing

## **INFORMATICA**

### Database e Reti

- **Database distribuiti**: replicazione, frammentazione, consistency
- **Client-server**: applicazioni web con database MySQL
- **Sicurezza dati**: crittografia per protezione database

### Integrazione Applicativa

- **SQL via rete**: connessioni remote ai database
- **API RESTful**: comunicazione tra sistemi distribuiti
- **Web services**: SOAP, REST per integrazione applicazioni

## **TPSIT**

### Sviluppo Web

- **Stack LAMP**: integrazione Linux-Apache-MySQL-PHP
- **Protocolli applicativi**: HTTP/HTTPS per web applications
- **Sicurezza applicativa**: SQL injection, XSS, CSRF

### Internet of Things

- **ESP32**: microcontrollori per IoT
- **Protocolli IoT**: MQTT, CoAP per comunicazioni M2M
- **Edge computing**: elaborazione distribuita su dispositivi

### Normative

- **GDPR**: protezione dati in transito e a riposo
- **AI Act**: regolamentazione IA e sistemi autonomi
- **Cybersecurity**: framework di sicurezza europei

## **GPOI**

### Gestione di Progetto

- **Infrastruttura IT**: progettazione e implementazione reti aziendali
- **Risk management**: analisi rischi per la continuità operativa
- **SLA**: Service Level Agreement per servizi di rete

### Economia Aziendale

- **TCO**: Total Cost of Ownership per infrastrutture di rete
- **ROI**: Return on Investment per aggiornamenti tecnologici
- **Outsourcing**: cloud vs. infrastruttura in-house

### Organizzazione

- **Strutture distribuite**: organizzazioni virtuali e smart working
- **Business continuity**: piani di disaster recovery
- **Change management**: gestione cambiamenti tecnologici

---
# 3. TPS

## 3.1 Reti e protocolli

Le reti sono evolute da semplice comunicazione locale a interconnessione sempre più frequente e continua. La strutturazione ha preso sempre più conformità in *architetture di rete*:

**Client/Server - Cliente/Servente**

- **Client**: richiede servizi
- **Server**: fornisce servizi
- **Vantaggi**: centralizzazione, sicurezza, controllo
- **Svantaggi**: single point of failure, scalabilità limitata

**Peer-to-Peer (P2P) - Pari a pari - Ognuno nella rete conta uguale = Consenso - Maggioranza**

- Tutti i nodi sono equivalenti
- Condivisione diretta di risorse
- **Vantaggi**: scalabilità, resistenza ai guasti
- **Svantaggi**: sicurezza, controllo difficile

**Architetture Ibride - Unisce le due possibilità**

- Combinazione client/server e P2P
- Esempi: Skype, BitTorrent con tracker

Comunicazione di rete si basa su dei pilastri logici:

**Internet - Modello generalissimo di collegamento tra tutto**

- Rete globale di reti interconnesse
- Basata su protocollo TCP/IP
- Infrastruttura di comunicazione

**World Wide Web (WWW) - Connessione continua tramite ipertesti / collegamenti**

- Servizio che gira su Internet
- Basato su HTTP/HTTPS
- Documenti ipertestuali (HTML)

**Differenze Fondamentali**

- Internet = infrastruttura fisica e logica
- Web = servizio applicativo su Internet
## 3.2 Servizi di rete

I servizi cambiano a seconda del tipo di applicazione.
### 3.2.1 Applicazioni Aziendali e GDPR

**Enterprise Resource Planning (ERP) - Gestionali**

- Integrazione processi aziendali
- Database centralizzato

**Customer Relationship Management (CRM)**

- Gestione relazioni con clienti
- Analisi comportamenti e preferenze
- Marketing automation

**Supply Chain Management (SCM)**

- Gestione catena di fornitura
- Ottimizzazione logistica
- Tracciabilità prodotti

**GDPR (General Data Protection Regulation) - Framework di sicurezza obbligatorio dal 2016 - Linea guida generale**

- Regolamento UE 2016/679
- **Principi**: liceità, correttezza, trasparenza
- **Diritti**: accesso, portabilità, cancellazione
- **Obblighi**: privacy by design, data protection officer
- **Sanzioni**: fino al 4% del fatturato annuo

Esistono varie tipologie di servizi finanziari tramite web.

**Home Banking**

- Accesso online ai servizi bancari
- Autenticazione forte (2FA)
- Crittografia end-to-end

**Pagamenti Digitali**

- **POS**: Point of Sale
- **Mobile payment**: NFC, QR code

### 3.2.2 Crittografia (Uguale a Sistemi)

**Crittografia Simmetrica**

- Stessa chiave per cifratura/decifratura
- **Algoritmi**: AES-128/192/256, DES, 3DES
- **Vantaggi**: velocità
- **Svantaggi**: distribuzione chiavi

**Crittografia Asimmetrica**

- Coppia chiavi: pubblica/privata
- **Algoritmi**: RSA, ECC, Diffie-Hellman
- **Vantaggi**: no problema distribuzione chiavi
- **Svantaggi**: lentezza

**Calcolo Chiavi RSA**

1. Scegliere due primi p, q
2. Calcolare n = p × q
3. Calcolare φ(n) = (p-1)(q-1)
4. Scegliere e coprimo con φ(n)
5. Calcolare d: e × d ≡ 1 (mod φ(n))
6. Chiave pubblica: (n, e)
7. Chiave privata: (n, d)

### 3.2.3 Firma Digitale e PEC (Uguale a Sistemi)

**Firma Digitale**

- **Autenticazione**: identifica il firmatario
- **Integrità**: garantisce non alterazione
- **Non ripudio**: impedisce di negare la firma
- **Processo**: hash del documento + crittografia con chiave privata

**Certificati Digitali**

- Standard X.509
- Certificate Authority (CA)
- Catena di fiducia

**PEC (Posta Elettronica Certificata)**

- Valore legale equivalente a raccomandata A/R
- Ricevute di consegna e accettazione
- Timestamp e firma digitale
- Conservazione sostitutiva
## 3.3 Server per reti e web

La rete comunica in modo standard seguendo vari protocolli:
### 3.3.1 Servizi di Rete Fondamentali

**DNS (Domain Name System) - Risoluzione degli indirizzi IP in parti raggiungibili a gerarchia**

- Risoluzione nomi → indirizzi IP
- **Gerarchia**: root servers, TLD, domini (.it / .com)
- **Funzionamento**: richiesta ricorsiva alla gerarchia dei server per arrivare a una destinazione

**DHCP (Dynamic Host Configuration Protocol) - Routing/instradamento dinamico (se un dispositivo entra, si connette da solo)**

- Assegnazione automatica configurazione IP
- **Parametri**: IP, subnet mask (maschera di sottorete) - subnetting, gateway, DNS
### 3.2 Server Web

**Apache HTTP Server - Open source - Gratuito**

- Web server open source più diffuso
- **Moduli**: Funziona a parti frammentate
### 3.3 Server Email

**Componenti Sistema Email - Posta elettronica - Mittente / corriere / destinatario **

- **MTA** (Mail Transfer Agent): invio/routing email
- **MDA** (Mail Delivery Agent): consegna email
- **MUA** (Mail User Agent): client email

**Protocolli Email - Standard in trasmissione**

- **SMTP**: invio email (port 25, 587, 465)
- **POP3**: download email (port 110, 995)
- **IMAP**: accesso email remote (port 143, 993)
### 3.4 Sicurezza Perimetrale

**NAT (Network Address Translation) - Nascondere indirizzi IP all'esterno**

- Traduzione indirizzi privati ↔ pubblici
- **SNAT**: Source NAT (uscita)
- **DNAT**: Destination NAT (port forwarding)
- **PAT**: Port Address Translation

**Proxy Server - Server intermedi di controllo della trasmissione**

- **Forward proxy**: nasconde client ai server
- **Reverse proxy**: nasconde server ai client
- **Funzioni**: caching (salvataggio dati a seconda del fine), filtering (filtraggio comunicazioni), load balancing (smarcare traffico pacchetti)

**Firewall - Controllo hardware (HW) e software (SW)**

- **Packet filtering**: controllo header pacchetti
- **Stateful inspection**: memoria delle connessioni
- **Application gateway**: controllo applicativo
- **Next-gen firewall**: DPI, IPS, antivirus
### 3.5 Controllo degli Accessi

In una rete c'è il principio del privilegio minimo - chi entra nella rete deve avere meno permessi possibile solitamente. Esistono varie modalità di gestione dati.

**Modelli di Controllo**

- **DAC** (Discretionary Access Control): ciascun utente decide le proprie possibilità
- **MAC** (Mandatory Access Control): policy centralizzate - amministratore di rete decide per tutti

**Autenticazione**

- **Fattori**: something you know/have/are
- **Single Sign-On (SSO)**: accesso unificato
- **Multi-Factor Authentication (MFA)**: più fattori
- **Protocolli**: Kerberos, LDAP, SAML, OAuth

---
## 3.6. Programmi e applicazioni di rete

### 3.6.1 Applicazioni Client/Server 

**Socket Programming (Socket = Indirizzo IP + Porta = Servizio) **

La comunicazione si basa su *primitive* (funzioni che in un certo linguaggio di programmazione ti permettono sempre di connetterti).

- **Socket**: endpoint di comunicazione
- **Server socket**: bind(), listen(), accept()
- **Client socket**: connect(), send(), receive()
- **Protocolli**: TCP (affidabile - funziona accorgendosi nel mentre della trasmissione di possibili errori) vs UDP (veloce - i pacchetti arrivano a frammenti, ma l'importante è che arrivino ad una certa)

### 3.6.2 Protocolli di Comunicazione

**HTTP/HTTPS (Scambio di collegamenti ipertestuali)**

- **Metodi**: GET, POST, PUT, DELETE, PATCH
- **Status codes**: 2xx, 3xx, 4xx, 5xx
- **Headers**: Content-Type, Authorization, Cache-Control
- **HTTPS**: HTTP + TLS/SSL

**REST (Representational State Transfer) - Meccanismo di connessione generale**

- **Principi**: stateless (non salva i dati di comunicazione), layered (organizzato a strati = strutturato)
- **Risorse**: identificate da URI
- **Operazioni**: mappate su metodi HTTP
- **Formati**: JSON, XML

### 3.6.3 XML e Scambio Dati

**XML (eXtensible Markup Language) - Formato dati personalizzabili**

- Linguaggio markup (formattazione di una pagina $\neq$ programmazione) per dati strutturati
- **Ben-formato**: sintassi corretta
- **Valido**: conforme a schema (regole)

**Struttura XML**

```xml
<?xml version="1.0" encoding="UTF-8"?>
<root>
    <elemento attributo="valore">
        <sotto-elemento>contenuto</sotto-elemento>
    </elemento>
</root>
```

**XML Schema (XSD) - Grammatica o insieme di regole per XML**

- Definisce struttura e tipi dati
- Validazione più potente di DTD
- Supporto namespace

### 3.6.4 Web Services

**SOAP (Simple Object Access Protocol)**

- Protocollo per  scambio di messaggi tra client e server
- Basato su XML e HTTP

**Struttura SOAP**

```xml
<soap:Envelope>
    <soap:Header>...</soap:Header>
    <soap:Body>
        <metodo>
            <parametro>valore</parametro>
        </metodo>
    </soap:Body>
</soap:Envelope>
```

**REST vs SOAP**

- **REST**: più semplice, JSON, HTTP
- **SOAP**: più complesso, XML, protocolli multipli

---

## 3.7 AI e Normative

### 3.7.1 Intelligenza Artificiale

**L'AI ha varie definizione**

- **AI debole**: sistemi specifici (Siri, AlphaGo)
- **AI forte**: intelligenza generale (ancora teorica)
- **Machine Learning**: apprendimento da dati
- **Deep Learning**: reti neurali profonde

**AI Quantistica**

- Combinazione quantum computing + AI
- **Vantaggi**: calcoli esponenzialmente più veloci
- **Applicazioni**: crittografia, ottimizzazione, simulazioni
- **Sfide**: hardware instabile, algoritmi specifici

### 3.7.2 GDPR e AI

**Principi GDPR per AI**

- **Liceità**: consenso esplicito per profilazione
- **Minimizzazione**: solo dati necessari
- **Accuratezza**: correzione errori algoritmi
- **Trasparenza**: spiegabilità decisioni automatiche

**Diritti dell'Interessato**

- **Informazione**: logica decisioni automatiche
- **Accesso**: dati utilizzati per training
- **Rettifica**: correzione dati errati
- **Cancellazione**: "diritto all'oblio"
- **Opposizione**: no profilazione automatica

### 3.7.3 AI Act Europeo

**Classificazione Rischi**

- **Rischio inaccettabile**: vietati (social scoring)
- **Alto rischio**: requisiti stringenti (sistemi critici)
- **Rischio limitato**: obblighi trasparenza (chatbot)
- **Rischio minimo**: nessun obbligo specifico

**Obblighi per Sviluppatori**

- **Valutazione conformità**: testing e validazione
- **Documentazione tecnica**: dataset, algoritmi, test
- **Sistema qualità**: gestione ciclo vita
- **Monitoraggio**: performance post-market

### 3.7.4 Fatturazione Elettronica

**Normativa Italiana**

- Obbligatoria dal 2019 per B2B
- Sistema di Interscambio (SdI)
- Formato XML standardizzato

**Struttura XML Fattura**

```xml
<p:FatturaElettronica>
    <FatturaElettronicaHeader>
        <DatiTrasmissione>...</DatiTrasmissione>
        <CedentePrestatore>...</CedentePrestatore>
        <CessionarioCommittente>...</CessionarioCommittente>
    </FatturaElettronicaHeader>
    <FatturaElettronicaBody>
        <DatiGenerali>...</DatiGenerali>
        <DatiBeniServizi>...</DatiBeniServizi>
    </FatturaElettronicaBody>
</p:FatturaElettronica>
```

**Regimi Fiscali**

- **Ordinario**: IVA standard
- **Forfettario**: tassazione semplificata
- **Minimi**: agevolazioni specifiche

---

## 3.8 ESP32 E IOT

### 3.8.1 Microcontrollore ESP32-S3

**Vantaggi ESP32 (Scheda programmabile in modo client/server)**

- Basso consumo energetico
- Connettività integrata
- Costo contenuto
- Ecosistema di sviluppo maturo

### 3.8.2 Programmazione di Rete

**Scansione Reti Wi-Fi**

```cpp
#include "WiFi.h"

void setup() {
    WiFi.mode(WIFI_STA);
    WiFi.scanNetworks();
}
```

**Connessione Wi-Fi**

```cpp
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
}
```

**Web Server ESP32**

```cpp
WebServer server(80);

void handleRoot() {
    server.send(200, "text/html", "<h1>ESP32 Server</h1>");
}

void setup() {
    server.on("/", handleRoot);
    server.begin();
}
```

### 3.8.3 Protocolli di Comunicazione

**I2C (Inter-Integrated Circuit)**

- **Bus seriale**: SDA (dati) + SCL (clock)
- **Master/Slave**: ESP32 può essere entrambi
- **Indirizzamento**: 7-bit address
- **Velocità**: fino a 400kHz (fast mode)

**HTTP Client**

```cpp
HTTPClient http;
http.begin("http://api.example.com/data");
int httpCode = http.GET();
String payload = http.getString();
```

### 3.8.4 Applicazioni IoT

**Web Server con Controllo LED**

- Interfaccia web per controllare GPIO
- HTML con form per input utente
- Gestione stato LED via HTTP requests

**Access Point ESP32**

```cpp
WiFi.softAP(ap_ssid, ap_password);
IPAddress IP = WiFi.softAPIP();
```

**Scambio Dati tra ESP32**

- Comunicazione peer-to-peer
- Protocolli: ESP-NOW, Wi-Fi Direct
- Mesh networking per IoT distribuito

---
# 3.9 Collegamenti TPS

## **STORIA**

### Evoluzione delle Reti

- **Rivoluzione delle comunicazioni**: dal telegrafo elettrico (1840) a Internet
- **Guerra Fredda**: ARPANET come progetto militare per sopravvivere ad attacco nucleare
- **Globalizzazione**: Internet come acceleratore dell'integrazione economica mondiale
- **Democratizzazione dell'informazione**: da stampa a web, controllo vs. libertà di informazione

### Servizi Finanziari e Crittografia

- **Storia della crittografia**: da Cesare a Enigma, da Colossus a RSA
- **Controllo economico**: dal gold standard alle criptovalute
- **Sorveglianza di massa**: NSA, ECHELON, Snowden vs. privacy digitale

### AI e Società

- **Automazione industriale**: dalla macchina a vapore all'IA
- **Controllo sociale**: schedatura fascista vs. social scoring cinese
- **Futuro del lavoro**: dalla rivoluzione industriale alla rivoluzione IA

## **ITALIANO**

### Comunicazione e Linguaggi

- **Protocolli di comunicazione**: come "grammatica" delle reti vs. grammatica italiana
- **Standardizzazione linguistica**: nascita italiano standard vs. protocolli standardizzati
- **Ipertestualità**: struttura web come evoluzione dell'ipertesto letterario

### Documenti Digitali e XML

- **Struttura testuale**: XML come markup vs. struttura poetica (rime, strofe)
- **Metadati**: informazioni sui testi come header HTTP
- **Conservazione digitale**: biblioteche digitali vs. archivi cartacei

### Firma Digitale e Autenticità

- **Autenticità opere**: filologia vs. certificati digitali
- **Pseudonimi letterari**: identità multipla vs. identità digitale
- **Diritto d'autore**: copyright tradizionale vs. licenze digitali

## **INGLESE**

### Terminologia Tecnica Globale

- **Protocolli Internet**: HTTP, SMTP, FTP - standard internazionali
- **AI terminology**: machine learning, deep learning, neural networks
- **Cybersecurity**: firewall, proxy, encryption - linguaggio specialistico

### Governance Digitale

- **Organismi internazionali**: ICANN, W3C, IEEE - standardizzazione globale
- **Digital divide**: disparità linguistiche e tecnologiche
- **Net neutrality**: dibattito anglosassone su neutralità della rete

### IoT e Industry 4.0

- **Smart cities**: terminologia urbanistica digitale
- **Internet of Things**: ecosistema di dispositivi connessi
- **Edge computing**: elaborazione distribuita

## **MATEMATICA**

### Crittografia e Sicurezza

- **Aritmetica modulare**: base algoritmi RSA e Diffie-Hellman
- **Numeri primi**: fattorizzazione per crittografia asimmetrica
- **Logaritmo discreto**: problema matematico alla base della sicurezza
- **Teoria dell'informazione**: entropia e casualità per chiavi crittografiche

### Protocolli di Rete

- **Grafi**: rappresentazione topologie di rete e algoritmi routing
- **Probabilità**: analisi affidabilità sistemi distribuiti
- **Algoritmi di ottimizzazione**: load balancing e gestione risorse

### AI e Machine Learning

- **Calcolo differenziale**: backpropagation nelle reti neurali
- **Algebra lineare**: matrici per deep learning
- **Statistica**: analisi dati e modelli predittivi

## **INFORMATICA**

### Database e Applicazioni Web

- **Architetture 3-tier**: web server + application server + database
- **API RESTful**: interfacce per accesso dati strutturati
- **XML/JSON**: formati scambio dati con database

### Sicurezza Dati

- **Crittografia database**: protezione dati sensibili
- **SQL injection**: vulnerabilità applicazioni web
- **Backup distribuito**: replica dati su più server

### Web Services

- **SOAP/REST**: accesso remoto a funzionalità database
- **Microservizi**: architetture distribuite per scalabilità
- **API Gateway**: controllo accesso ai servizi

## **SISTEMI E RETI**

### Integrazione Tecnologica

- **Stack protocollare**: TPSIT implementa applicazioni su infrastruttura reti
- **Sicurezza multi-livello**: firewall + crittografia applicativa
- **Quality of Service**: prioritizzazione traffico per applicazioni critiche

### IoT e Edge Computing

- **ESP32 networking**: implementazione protocolli TCP/IP su microcontrollori
- **Mesh networks**: reti auto-organizzanti per IoT
- **Protocol translation**: gateway tra protocolli diversi

## **GPOI**

### Digital Transformation

- **ERP systems**: integrazione processi aziendali via tecnologie web
- **E-commerce**: piattaforme digitali per business online
- **Business Intelligence**: dashboard per analisi dati aziendali

### Project Management IT

- **DevOps**: integrazione sviluppo e operations
- **Agile methodology**: sviluppo iterativo applicazioni
- **Risk management**: gestione rischi cyber in progetti IT

### Compliance e Normative

- **GDPR compliance**: implementazione privacy by design
- **Audit trail**: tracciabilità operazioni per compliance
- **Business continuity**: alta disponibilità sistemi critici

---
# 4 - Matematica

## 4.1 Derivate

> Senso pratico: asso di variazione istantaneo (quanto cambia una quantità rispetto a un’altra).

**Uso pratico**:

- **Velocità istantanea**: se guardi il tachimetro di un’auto, stai leggendo la derivata della posizione rispetto al tempo.
    
- **Finanza**: la variazione del prezzo di un’azione nel tempo → usata per valutare rischi e opportunità.
    
- **Machine Learning / Ottimizzazione**: la discesa del gradiente (gradient descent) per trovare minimi di funzioni di costo.
    
- **Domotica / Climatizzazione**: i sistemi PID (proporzionale-integrale-derivativo) regolano il riscaldamento/raffreddamento.
### 4.1.1 Concetto di Derivata

**Definizione** La derivata di una funzione f(x) nel punto x₀ è:

```
f'(x₀) = lim[h→0] [f(x₀+h) - f(x₀)]/h
```

Rapporto incrementale (Limite per "h" (incremento) che tende a 0)

**Interpretazioni**

- **Geometrica**: coefficiente angolare della retta tangente al grafico in x₀
- **Fisica**: velocità istantanea di variazione della funzione
- **Economica**: costo/ricavo marginale

**Notazioni**

- f'(x), Df(x), df/dx, y'

### 4.1.2 Continuità e Derivabilità

**Teorema Fondamentale** Se f(x) è derivabile in x₀, allora è continua in x₀ (continua = la funzione non ha salti). (Il viceversa non è sempre vero)

**Controesempi**

- f(x) = |x| in x₀ = 0: continua ma non derivabile
- Funzioni con cuspidi o punti angolosi

**Derivabilità Laterale**

- f'₊(x₀) = lim[h→0⁺] [f(x₀+h) - f(x₀)]/h
- f'₋(x₀) = lim[h→0⁻] [f(x₀+h) - f(x₀)]/h
- f derivabile in x₀ ⟺ f'₊(x₀) = f'₋(x₀)

### 4.1.3 Derivate delle Funzioni Elementari

**Funzioni Fondamentali**

- (c)' = 0 (costante)
- (x^n)' = n·x^(n-1) (potenza)
- (e^x)' = e^x (esponenziale naturale)
- (a^x)' = a^x · ln(a) (esponenziale)
- (ln x)' = 1/x (logaritmo naturale)
- (log_a x)' = 1/(x·ln a) (logaritmo)

**Funzioni Trigonometriche**

- (sin x)' = cos x
- (cos x)' = -sin x
- (tan x)' = 1/cos²x = sec²x
- (cot x)' = -1/sin²x = -csc²x

**Funzioni Inverse**

- (arcsin x)' = 1/√(1-x²)
- (arccos x)' = -1/√(1-x²)
- (arctan x)' = 1/(1+x²)

### 4.1.4 Regole di Derivazione

**Linearità**

- [af(x) + bg(x)]' = af'(x) + bg'(x)

**Prodotto**

- [f(x)·g(x)]' = f'(x)·g(x) + f(x)·g'(x)

**Quoziente**

- [f(x)/g(x)]' = [f'(x)·g(x) - f(x)·g'(x)]/[g(x)]²

**Funzione Composta (Regola della Catena)**

- [f(g(x))]' = f'(g(x))·g'(x)

**Funzione Inversa**

- [f⁻¹(x)]' = 1/f'(f⁻¹(x))

### 4.1.5 Teoremi Fondamentali

**Teorema di Fermat** Se f(x) ha un estremo relativo in x₀ interno al dominio e f è derivabile in x₀, allora f'(x₀) = 0.

> Senso pratico: Quel punto sarà probabilmente un massimo o un minimo relativo.

**Teorema di Rolle** Se f(x) è:

- continua in [a,b]
- derivabile in (a,b)
- f(a) = f(b)

> Senso pratico: Quel punto sarà probabilmente una tangente

Allora ∃c ∈ (a,b) tale che f'(c) = 0.

**Teorema di Lagrange (Valor Medio)** Se f(x) è:

- continua in [a,b]
- derivabile in (a,b)

Allora ∃c ∈ (a,b) tale che f'(c) = [f(b)-f(a)]/(b-a).

> Senso pratico: Se ho un valor medio, riesco a caratterizzare dei fenomeni

### 4.1.6 Studio di Funzione

**Criteri di Monotonia**

- f'(x) > 0 in I ⟹ f crescente in I
- f'(x) < 0 in I ⟹ f decrescente in I
- f'(x) = 0 in I ⟹ f costante in I

**Punti Stazionari** Punti dove f'(x) = 0:

- **Massimo relativo**: f'(x) cambia da + a -
- **Minimo relativo**: f'(x) cambia da - a +
- **Flesso orizzontale**: f'(x) non cambia segno

**Test della Derivata Seconda** Se f'(x₀) = 0:

- f''(x₀) > 0 ⟹ x₀ è minimo relativo
- f''(x₀) < 0 ⟹ x₀ è massimo relativo
- f''(x₀) = 0 ⟹ test non conclusivo

---

## 4.2. Integrali

> Senso pratico: somma continua di infinitesimi → area sotto una curva.

**Uso pratico**:

- **Calcolo di quantità cumulative**: chilometri percorsi (integrale della velocità), consumo elettrico (integrale della potenza).
    
- **Fatturazione smart**: se la corrente varia nel tempo, la bolletta usa l’integrale della potenza nel tempo.
    
- **Computer Graphics**: calcolo dell’illuminazione globale, antialiasing.
    
- **Fisica quotidiana**: lavoro compiuto da una forza variabile (es. una molla).
### 4.2.1 Integrale Indefinito

**Definizione** F(x) è una primitiva di f(x) se F'(x) = f(x). L'integrale indefinito è: ∫f(x)dx = F(x) + c

> $\int_{a}^{b} f(x) dx = F(b) - F(a)$ -> Teorema fondamentale del calcolo integrale

**Proprietà**

- Linearità: ∫[af(x) + bg(x)]dx = a∫f(x)dx + b∫g(x)dx
- ∫f'(x)dx = f(x) + c
- d/dx[∫f(x)dx] = f(x)

### 4.2.2 Integrali Immediati

**Funzioni Elementari**

- ∫x^n dx = x^(n+1)/(n+1) + c (n ≠ -1)
- ∫1/x dx = ln|x| + c
- ∫e^x dx = e^x + c
- ∫a^x dx = a^x/ln(a) + c
- ∫sin x dx = -cos x + c
- ∫cos x dx = sin x + c
- ∫1/cos²x dx = tan x + c
- ∫1/sin²x dx = -cot x + c
- ∫1/√(1-x²) dx = arcsin x + c
- ∫1/(1+x²) dx = arctan x + c

### 4.2.3 Tecniche di Integrazione

**Integrazione per Sostituzione** Se g(x) è derivabile: ∫f(g(x))·g'(x)dx = ∫f(u)du dove u = g(x)

**Integrazione per Parti** ∫u·v' dx = u·v - ∫u'·v dx

**Selezione u e v':**

- u: funzioni "facilmente derivabili" (polinomi, ln, arctan...)
- v': funzioni "facilmente integrabili" (esponenziali, trigonometriche...)

### 4.2.4 Integrale Definito

**Definizione (Riemann)** ∫[a→b] f(x)dx = lim[n→∞] Σ[i=1→n] f(ξᵢ)·Δxᵢ

> Senso pratico: Somma di tutti i rettangoli di Riemann per approssimare lo studio di una funzione.

**Interpretazione Geometrica** Area con segno compresa tra f(x) e l'asse x nell'intervallo [a,b].

**Proprietà**

- ∫[a→a] f(x)dx = 0
- ∫[a→b] f(x)dx = -∫[b→a] f(x)dx
- ∫[a→c] f(x)dx = ∫[a→b] f(x)dx + ∫[b→c] f(x)dx
- ∫[a→b] [f(x) + g(x)]dx = ∫[a→b] f(x)dx + ∫[a→b] g(x)dx

### 4.2.5 Teoremi Fondamentali

**Teorema del Valor Medio Integrale** Se f(x) è continua in [a,b], allora ∃c ∈ [a,b] tale che: ∫[a→b] f(x)dx = f(c)·(b-a)

**Primo Teorema Fondamentale del Calcolo** Se f(x) è continua in [a,b], allora F(x) = ∫[a→x] f(t)dt è derivabile e F'(x) = f(x).

**Secondo Teorema Fondamentale del Calcolo (Regola di Leibniz-Newton)** Se f(x) è continua in [a,b] e F(x) è una primitiva di f(x), allora: ∫[a→b] f(x)dx = F(b) - F(a) = [F(x)]ᵇₐ

### 4.2.6 Calcolo delle Aree

**Area tra Funzione e Asse x** Area = ∫[a→b] |f(x)|dx

**Area tra Due Funzioni** Area = ∫[a→b] |f(x) - g(x)|dx

**Metodo Pratico**

1. Trovare punti di intersezione f(x) = g(x)
2. Determinare quale funzione è superiore in ogni intervallo
3. Calcolare ∫[xᵢ→xᵢ₊₁] |f(x) - g(x)|dx per ogni intervallo

---

## 4.3 Serie Numeriche

> Senso pratico: somma di infiniti termini (spesso decrescenti).

> $\sum_{n=0}^{\infty} a_n = S$ - limite della successione delle somme parziali

**Uso pratico**:

- **Codifica numerica**: rappresentazione decimale o binaria di numeri → serie infinite.
    
- **Compressione video/audio**: Fourier e trasformate discrete → si basano su serie trigonometriche per rappresentare segnali.
    
- **Calcolo numerico**: funzioni come seno, coseno, esponenziale sono valutate da una macchina tramite **sviluppi in serie**.
    
- **Economia**: valore attuale di una rendita infinita (serie geometrica).
### 4.3.1 Definizioni Base

**Serie Numerica** Somma infinita S = Σ[n=1→∞] aₙ = a₁ + a₂ + a₃ + ...

**Somma Parziale n-esima** Sₙ = Σ[k=1→n] aₖ = a₁ + a₂ + ... + aₙ

**Carattere della Serie**

- **Convergente**: lim[n→∞] Sₙ = S (finito)
- **Divergente**: lim[n→∞] Sₙ = ±∞
- **Irregolare**: lim[n→∞] Sₙ non esiste

### 4.3.2 Condizione Necessaria

**Teorema** Se Σaₙ converge, allora lim[n→∞] aₙ = 0.

**Contronominale** Se lim[n→∞] aₙ ≠ 0, allora Σaₙ diverge.

**Attenzione**: lim[n→∞] aₙ = 0 non garantisce convergenza!

### 4.3.3 Serie Notevoli

**Serie Geometrica** Σ[n=0→∞] qⁿ = 1 + q + q² + q³ + ...

- Converge a 1/(1-q) se |q| < 1
- Diverge se |q| ≥ 1

**Serie Armonica** Σ[n=1→∞] 1/n = 1 + 1/2 + 1/3 + 1/4 + ... (diverge)

**Serie Armonica Generalizzata** Σ[n=1→∞] 1/nᵖ

- Converge se p > 1
- Diverge se p ≤ 1

**Serie Telescopiche** Σ[n=1→∞] (aₙ - aₙ₊₁) = a₁ - lim[n→∞] aₙ₊₁

---
# 4.3 Collegamenti Matematica

## **FISICA (tramite Scienze Motorie)**

### Derivate e Cinematica

- **Posizione, velocità, accelerazione**: s(t), v(t) = s'(t), a(t) = s''(t)
- **Moto uniformemente accelerato**: equazioni del moto e loro derivate
- **Analisi del movimento umano**: biomeccanica e ottimizzazione prestazioni sportive

### Integrali e Lavoro

- **Lavoro**: W = ∫F(s)ds, calcolo lavoro con forza variabile
- **Energia cinetica**: relazione con integrali di velocità
- **Metabolismo energetico**: calcolo calorie consumate durante attività fisica

### Serie e Modelli di Crescita

- **Progressione allenamento**: serie geometriche per incrementi prestazioni
- **Biostatistica**: analisi dati antropometrici e prestazionali

## **INFORMATICA**

### Derivate e Ottimizzazione

- **Algoritmi di ottimizzazione**: gradient descent per machine learning
- **Query optimization**: minimizzazione costi computazionali database
- **Complessità algoritmica**: analisi derivata per efficienza

### Integrali e Calcolo Computazionale

- **Integrazione numerica**: metodi trapezi, Simpson per calcoli approssimati
- **Grafica computazionale**: calcolo aree e volumi per rendering 3D
- **Analisi dati**: integrazione per calcolo medie e tendenze

### Serie e Programmazione

- **Serie di Fourier**: compressione dati e segnali digitali
- **Convergenza algoritmi**: criteri di stop basati su serie convergenti
- **Calcolo parallelo**: somme infinite distribuite su più processori

## **SISTEMI E RETI**

### Derivate e Prestazioni di Rete

- **Throughput istantaneo**: derivata del traffico dati nel tempo
- **Analisi latenza**: ottimizzazione routing tramite calcolo derivate
- **Quality of Service**: controllo flusso basato su derivate del traffico

### Integrali e Monitoraggio

- **Bandwidth utilization**: integrale del traffico per calcolo utilizzo banda
- **Analisi log**: integrazione dati per statistiche d'uso
- **Capacity planning**: proiezioni future basate su integrali

### Serie e Protocolli

- **Algoritmi di routing**: convergenza basata su serie matematiche
- **Timeout exponential backoff**: serie geometriche per ritrasmissioni
- **Load balancing**: distribuzione carico tramite serie convergenti

## **TPSIT**

### Derivate e IoT

- **Sensori analogici**: derivata per rilevare variazioni ambientali rapide
- **Control systems**: PID controller basati su derivate per automazione
- **Signal processing**: analisi derivate per filtraggio segnali

### Integrali e Elaborazione Dati

- **Data integration**: somma continua di stream dati IoT
- **Energy harvesting**: calcolo energia raccolta tramite integrali
- **Pattern recognition**: area sotto curve per riconoscimento forme

### Serie e AI

- **Neural networks**: serie di Taylor per funzioni attivazione
- **Machine learning**: serie infinite per approssimazione funzioni
- **Quantum computing**: serie quantistiche per calcoli paralleli

## **STORIA**

### Derivate e Analisi Storica

- **Demografia**: derivata popolazione per studiare crescita/decrescita
- **Sviluppo economico**: derivata PIL per analizzare crescita economica
- **Velocità cambiamenti sociali**: derivata per analizzare rivoluzioni

### Integrali e Statistica Storica

- **Analisi dati storici**: integrazione per calcolo totali (vittime guerre, produzione industriale)
- **Tendenze a lungo termine**: area sotto curve demografiche ed economiche
- **Impatto cumulativo eventi**: integrazione effetti nel tempo

### Serie e Modelli Storici

- **Cicli economici**: serie periodiche per analisi crisi ricorrenti
- **Progressione tecnologica**: serie esponenziali per innovazioni
- **Diffusione culture**: modelli matematici espansione civiltà

## **ITALIANO**

### Derivate e Analisi Letteraria

- **Evoluzione stile**: derivata per analizzare cambiamenti stilistici autori
- **Frequenza linguistica**: derivata uso parole per studiare evoluzione lingua
- **Intensità emotiva**: derivata per analizzare climax narrativi

### Integrali e Metrica

- **Ritmo poetico**: integrazione per analisi flusso temporale versi
- **Densità semantica**: area sotto curve per ricchezza contenuti
- **Sviluppo tematico**: integrazione temi attraverso opere

### Serie e Strutture Letterarie

- **Narrativa seriale**: convergenza/divergenza serie romanzi
- **Tradizione letteraria**: serie autori e influenze reciproche
- **Forme poetiche**: serie matematiche in strutture metriche

## **INGLESE**

### Derivate e Linguistica Computazionale

- **Natural Language Processing**: derivate per analisi sentiment
- **Machine translation**: ottimizzazione tramite calcolo derivate
- **Speech recognition**: analisi derivate onde sonore

### Integrali e Corpus Linguistics

- **Text analysis**: integrazione frequenze per analisi linguistiche
- **Language evolution**: integrazione cambiamenti nel tempo
- **Statistical linguistics**: area sotto curve distribuzione parole

### Serie e Pattern Recognition

- **Language models**: serie infinite per predizione testo
- **Phonetic patterns**: serie armoniche per analisi suoni
- **Grammar structures**: convergenza serie per regole sintattiche

## **GPOI**

### Derivate e Business Analytics

- **Profitto marginale**: derivata funzione profitto
- **Costo marginale**: derivata funzione costo per ottimizzazione produzione
- **Elasticità domanda**: derivata per analisi mercato

### Integrali e Finance

- **Cash flow**: integrazione flussi monetari nel tempo
- **ROI calculation**: integrazione rendimenti per valutazione investimenti
- **Risk assessment**: area sotto curve probabilità per analisi rischi

### Serie e Modelli Economici

- **Crescita composta**: serie geometriche per interessi capitalizzati
- **Depreciation models**: serie decrescenti per ammortamenti
- **Market cycles**: serie periodiche per andamenti ciclici

---

# 5. Italiano

## 5.1. Positivismo e Naturalismo (Fine 800)

### 5.1.1 Il Positivismo

**Contesto Storico-Culturale**

- Seconda metà dell'800: rivoluzione industriale, progresso scientifico
- Fiducia nella scienza e nel metodo sperimentale
- Ottimismo per il progresso umano e sociale

**Fondamenti Filosofici**

- **Auguste Comte**: fondatore del Positivismo
- **Metodo scientifico**: osservazione, sperimentazione, leggi generali
- **Determinismo**: tutto è governato da leggi naturali
- **Evoluzionismo**: Darwin e la selezione naturale

**Principi Fondamentali**

- Rifiuto della metafisica e dell'idealismo
- Solo la scienza può spiegare la realtà
- Progresso come miglioramento continuo dell'umanità
- Applicazione del metodo scientifico ai fenomeni sociali

### 5.1.2 Il Naturalismo Francese

**Caratteristiche Generali**

- Applicazione del metodo scientifico alla letteratura
- **Romanzo sperimentale**: Émile Zola
- Narratore oggettivo e impersonale
- Determinismo ambientale e sociale

**Émile Zola (1840-1902)**

- Teorico del Naturalismo
- Ciclo dei **Rougon-Macquart**: studio scientifico di una famiglia
- **Il romanzo sperimentale** (1880): manifesto teorico
- Temi: ereditarietà, ambiente sociale, istinti

**Tecniche Narrative**

- **Impersonalità**: scomparsa dell'autore
- **Oggettività**: descrizione scientifica della realtà
- **Documentazione**: ricerca sociale diretta
- **Linguaggio**: registro medio-basso, dialettale

---

## 5.2. Il Verismo Italiano

### 5.2.1 Caratteristiche del Verismo

**Principi Ideologici**

- Rappresentazione **vera** della realtà sociale
- Focus sulle classi popolari e marginalizzate
- **Pessimismo**: visione disincantata della condizione umana
- **Fatalismo**: rassegnazione alle leggi economiche e sociali

**Differenze con il Naturalismo**

- **Pessimismo** vs. fiducia nel progresso
- **Rassegnazione** vs. impegno sociale
- **Sud arretrato** vs. industrializzazione francese
- **Conservatorismo** vs. ideologie progressiste

**Tecniche Stilistiche**

- **Regressione**: adozione del punto di vista dei personaggi
- **Straniamento**: presentazione dei fatti senza commento
- **Discorso indiretto libero**: fusione narratore-personaggio
- **Linguaggio regionale**: mimesi linguistica dell'ambiente

### 5.2.2 Giovanni Verga (1840-1922)

**Biografia e Formazione**

- Nato a Catania da famiglia benestante
- Formazione risorgimentale e romantica
- Trasferimento a Milano: contatto con Scapigliatura
- Conversione al Verismo (1878-80)

**Evoluzione Letteraria**

1. **Fase romantica**: _Una peccatrice_, _Storia di una capinera_
2. **Fase scapigliata**: _Eva_, _Tigre reale_
3. **Fase verista**: _Vita dei campi_, _I Malavoglia_

**Pensiero e Visione del Mondo**

- **Darwinismo sociale**: lotta per la sopravvivenza
- **Pessimismo**: immutabilità delle condizioni sociali
- **Ideale dell'ostrica**: attaccamento alle proprie origini
- **Religione della famiglia**: valori tradizionali

### 5.2.3 Le Opere Principali

**Vita dei campi (1880)**

- Prima raccolta verista
- Protagonisti: contadini, pescatori, minatori siciliani
- Temi: lavoro, povertà, superstizione, morte

**Novelle rusticane (1883)**

- Continuazione tematica di _Vita dei campi_
- Focus sulla società rurale siciliana
- Critica al progresso che sconvolge equilibri tradizionali

**I Malavoglia (1881)**

- Primo romanzo del ciclo dei "Vinti"
- **Trama**: declino di una famiglia di pescatori di Aci Trezza
- **Struttura**: romanzo corale, tecnica dell'impersonalità
- **Temi**: tradizione vs. modernità, famiglia, lavoro, destino

**Mastro-don Gesualdo (1889)**

- Secondo romanzo del ciclo dei "Vinti"
- Protagonista: muratore arricchito che aspira alla nobiltà
- Tema centrale: impossibilità di cambiare classe sociale

### 5.2.4 Analisi Testi Fondamentali

**"Fantasticheria" - L'ideale dell'ostrica**

- Manifesto della poetica verghiana
- Metafora dell'ostrica: attaccamento alle proprie radici
- Critica all'irrequietezza moderna

**"Rosso Malpelo"**

- Protagonista: ragazzo maltrattato per il colore dei capelli
- Ambiente: cava di sabbia (inferno sociale)
- Determinismo: carattere influenzato dall'ambiente

**"Prefazione ai Malavoglia"**

- Dichiarazione di poetica
- Metodo dell'impersonalità
- Studio del "vero" nella letteratura

---

## 5.3. Il Decadentismo

### 5.3.1 Contesto Culturale

**Crisi del Positivismo**

- Fine del XIX secolo: crisi delle certezze scientifiche
- Scoperte scientifiche che relativizzano la realtà
- **Filosofie irrazionaliste**: Bergson, Nietzsche, Freud

**Origini e Diffusione**

- Francia: Baudelaire, Verlaine, Mallarmé
- **Simbolismo**: poesia come rivelazione dell'assoluto
- Diffusione in Europa: estetismo, decadentismo

**Caratteristiche Generali**

- **Irrazionalismo**: rifiuto della ragione positivista
- **Soggettivismo**: primato dell'io e dell'intuizione
- **Estetismo**: arte come valore supremo
- **Simbolismo**: realtà come sistema di corrispondenze

### 5.3.2 Temi e Figure del Decadentismo

**Tematiche Principali**

- **Crisi dell'io**: frantumazione dell'identità
- **Malattia e morte**: fascinazione per il morboso
- **Fuga dalla realtà**: esotismo, passato, sogno
- **Panismo**: fusione con la natura
- **Superomismo**: mito dell'individuo eccezionale

**Figure Tipiche**

- **L'esteta**: culto della bellezza (D'Annunzio)
- **Il veggente**: poeta come profeta (Pascoli)
- **L'inetto**: inadattato alla vita moderna (Svevo)
- **Il superuomo**: individuo superiore (D'Annunzio)

---

## 5.4. Giovanni Pascoli

### 5.4.1 Biografia e Formazione

**Eventi Biografici Fondamentali**

- **1867**: assassinio del padre Ruggero
- **1871-73**: morti della madre, della sorella e dei fratelli
- **Nido familiare**: ossessione per la famiglia distrutta
- **Carriera**: docente universitario, poeta laureato

**Ideologia Politica**

- **Socialismo umanitario** giovanile
- **Nazionalismo** maturo: "La grande proletaria si è mossa"
- **Antimilitarismo** vs. **colonialismo**

### 5.4.2 Poetica e Opere

**La Teoria del Fanciullino (1897)**

- **Fanciullino**: bambino che vive nell'uomo adulto
- **Intuizione poetica**: conoscenza irrazionale e immediata
- **Linguaggio poetico**: spontaneo, analogico, simbolico
- **Funzione sociale**: poeta come consolatore dell'umanità

**Myricae (1891-1911)**

- **Titolo**: "tamerici" (Virgilio, Bucoliche)
- **Temi**: natura, morte, famiglia, campagna romagnola
- **Stile**: impressionismo, simbolismo, fonosimbolismo
- **Metrica**: tradizionale ma rinnovata

**Canti di Castelvecchio (1903)**

- Evoluzione di _Myricae_
- **Temi**: vita agreste, stagioni, tradizioni popolari
- **Tecnica**: sperimentazione metrica e linguistica

### 5.4.3 Analisi Testi

**"X Agosto"**

- **Tema**: parallelismo tra morte del padre e uccisione di una rondine
- **Struttura**: narrativa (fatto di cronaca) + simbolica (cosmica)
- **Stile**: impressionismo, analogie, simboli

**"Novembre"**

- **Tema**: illusione di una falsa primavera
- **Simbolo**: autunno = disillusione esistenziale
- **Stile**: sinestesie, analogie, simbolismo

**"Temporale" / "Il lampo"**

- **Dittico**: descrizione impressionistica di un temporale
- **Tecnica**: fonosimbolismo, onomatopee
- **Essenzialità**: sintesi estrema dell'immagine

---

## 5.5.1 Gabriele D'Annunzio

### 5.5.1 Biografia e Personalità

**Formazione e Esordi**

- Abruzzese di famiglia borghese
- **Primo Vere** (1879): precocità poetica
- **Roma bizantina**: vita mondana e letteraria

**L'Esteta e il Superuomo**

- **Estetismo**: vita come opera d'arte
- **Superomismo**: mito nietzschiano dell'eccezionalità
- **Vita inimitabile**: scandali, amori, imprese

**Impegno Politico e Bellico**

- **Interventismo**: per l'entrata in guerra (1915)
- **Imprese militari**: volo su Vienna, beffa di Buccari
- **Fiume**: occupazione e Reggenza del Carnaro

### 5.5.2 L'Estetismo

**Il Piacere (1889)**

- **Protagonista**: Andrea Sperelli, esteta decadente
- **Trama**: triangolo amoroso, conflitto sensualità/spiritualità
- **Temi**: arte vs. vita, raffinatezza vs. volgarità borghese
- **Stile**: prosa d'arte, preziosismo linguistico

**"Il ritratto di un esteta"**

- **Autoritratto**: D'Annunzio attraverso Sperelli
- **Ideologia estetica**: culto della bellezza assoluta
- **Critica**: ambiguità tra fascinazione e condanna

### 5.5.3 Il Periodo "Superomico"

**Alcyone (1903)**

- Terzo libro delle _Laudi_
- **Tema**: panismo, fusione io-natura
- **Estate**: tempo della pienezza vitale
- **Metro**: verso libero, sperimentazione

**"La pioggia nel pineto"**

- **Tema**: metamorfosi panica, fusione uomo-natura
- **Struttura**: dialogo con Ermione, progressiva trasformazione
- **Stile**: musicalità, analogie, sinestesie

---

## 5.6. Il Futurismo

### 5.6.1 Concetto di Avanguardia

**Definizione**

- **Rottura**: con tradizione e convenzioni artistiche
- **Sperimentazione**: nuovi linguaggi e forme espressive
- **Provocazione**: scandalizzare il pubblico borghese
- **Modernità**: esaltazione del progresso e della tecnologia

**Avanguardie Europee**

- **Espressionismo** (Germania): deformazione espressiva
- **Cubismo** (Francia): scomposizione prospettica
- **Dadaismo** (Svizzera): nonsense e provocazione
- **Surrealismo** (Francia): automatismo e inconscio

### 5.6.2 Il Futurismo Italiano

**Filippo Tommaso Marinetti (1876-1944)**

- **Manifesto del Futurismo** (1909): nascita del movimento
- **Paroliberismo**: rivoluzione del linguaggio poetico
- **Performance**: serate futuriste, provocazioni

**Principi Ideologici**

- **Velocità**: mito della macchina e della modernità
- **Dinamismo**: movimento vs. staticità
- **Aggressività**: guerra come "igiene del mondo"
- **Nazionalismo**: esaltazione dell'Italia moderna

**Tecniche Espressive**

- **Parole in libertà**: distruzione della sintassi
- **Analogie**: accostamenti inediti e audaci
- **Onomatopee**: imitazione dei rumori moderni
- **Tipografia**: rivoluzione grafica del testo

### 5.6.3 "Zang Tumb Tumb"

- **Soggetto**: assedio di Adrianopoli (1912)
- **Tecnica**: parole in libertà, onomatopee belliche
- **Innovazione**: poesia come spartito musicale-visivo
- **Significato**: esaltazione della guerra moderna

---
## 5.7. Italo Svevo

### 5.7.1 Biografia e Formazione

**Identità Culturale**

- **Nome vero**: Aron Hector Schmitz
- **Trieste**: crocevia culturale mitteleuropeo
- **Trilingue**: italiano, tedesco, dialetto triestino
- **Formazione commerciale**: vs. vocazione letteraria

**Incontro con la Psicoanalisi**

- **Freud**: conoscenza diretta delle teorie psicanalitiche
- **Dr. Weiss**: cognato psicanalista
- **Influenza letteraria**: analisi dell'inconscio nei romanzi

### 5.7.2 La Figura dell'Inetto

**Caratteristiche dell'Inetto Sveviano**

- **Inadeguatezza**: incapacità di vivere attivamente
- **Autoanalisi**: introversione morbosa
- **Ironia**: distacco critico da se stesso
- **Modernità**: anticipazione dell'uomo contemporaneo

**Evoluzione del Personaggio**

1. **Alfonso Nitti** (_Una vita_): inetto puro, suicidio
2. **Emilio Brentani** (_Senilità_): inetto che si illude
3. **Zeno Cosini** (_La coscienza di Zeno_): inetto consapevole

### 5.7.3 I Romanzi

**Una vita (1892)**

- **Protagonista**: Alfonso Nitti, impiegato di banca
- **Trama**: fallimento sentimentale e sociale
- **Finale**: suicidio come unica via d'uscita
- **Tecniche**: narratore onnisciente, analisi psicologica

**Senilità (1898)**

- **Protagonista**: Emilio Brentani, scrittore fallito
- **Trama**: amore per Angiolina, autoillusione
- **Tema**: vecchiaia precoce, rinuncia alla vita
- **Stile**: focalizzazione interna, monologo interiore

**La coscienza di Zeno (1923)**

- **Innovazione**: romanzo psicoanalitico
- **Struttura**: memorie di Zeno per la terapia
- **Tecnica**: tempo misto, stream of consciousness
- **Ironia**: autoanalisi critica del protagonista
- **Temi**: malattia, famiglia, affari, guerra

---

## 5.8. Luigi Pirandello

### 5.8.1 Pensiero e Poetica

**Filosofia Pirandelliana**

- **Relativismo**: impossibilità di una verità assoluta
- **Maschera vs. volto**: apparenza sociale vs. autenticità
- **Umorismo**: "sentimento del contrario"
- **Teatro nel teatro**: metateatro e autoriflessività

**L'Umorismo (1908)**

- **Distinzione**: comicità vs. umorismo
- **Comicità**: "avvertimento del contrario" (riso)
- **Umorismo**: "sentimento del contrario" (riflessione)
- **Tecnica**: scomposizione della realtà apparente

### 5.8.2 Novelle e Romanzi

**Novelle per un anno**

- **Progetto**: 365 novelle (24 raccolte)
- **Temi**: follia, identità, famiglia, società
- **Stile**: ironia, paradosso, straniamento

**"Il treno ha fischiato"**

- **Protagonista**: Belluca, impiegato oppresso
- **Trama**: evasione mentale attraverso il sogno
- **Tema**: fuga dalla realtà vs. prigionia sociale

**Il fu Mattia Pascal (1904)**

- **Trama**: Mattia finge la propria morte e diventa Adriano Meis
- **Tema**: impossibilità di cambiare identità
- **Significato**: critica all'ipocrisia sociale
- **Tecnica**: narratore autodiegetico, metalessi

**Uno, nessuno e centomila (1926)**

- **Protagonista**: Vitangelo Moscarda
- **Trama**: scoperta della relatività dell'identità
- **Filosofia**: frantumazione dell'io
- **Finale**: follia come liberazione

### 5.8.3 Il Teatro

**Innovazioni Teatrali**

- **Metateatro**: teatro che riflette su se stesso
- **Rottura della quarta parete**: coinvolgimento del pubblico
- **Personaggi-autori**: autonomia dei personaggi
- **Teatro dello specchio**: riflesso della condizione umana

**Sei personaggi in cerca d'autore (1921)**

- **Trama**: sei personaggi interrompono una prova teatrale
- **Tema**: arte vs. vita, verità vs. finzione
- **Innovazione**: personaggi più reali degli attori
- **Significato**: autonomia dell'arte dall'artista

---

## 5.9. Giuseppe Ungaretti

### 5.9.1 Biografia e Formazione

**Origini Cosmopolite**

- **Nascita**: Alessandria d'Egitto (comunità italiana)
- **Formazione**: Parigi, contatto con avanguardie
- **Guerra**: esperienza del Carso (1915-18)
- **Maturità**: Roma, cattedra universitaria

**Evoluzione Poetica**

1. **Prima fase**: sperimentalismo, analogismo
2. **Seconda fase**: recupero della tradizione
3. **Terza fase**: sintesi tra innovazione e tradizione

### 5.9.2 L'Allegria (1931)

**Caratteristiche Generali**

- **Titolo originale**: _Il porto sepolto_ (1916)
- **Tema centrale**: guerra come rivelazione esistenziale
- **Stile**: frantumazione del verso, analogismo
- **Poetica**: "parola scavata nel silenzio"

**Innovazioni Metriche**

- **Verso libero**: abbandono della metrica tradizionale
- **Parola isolata**: valore assoluto del termine
- **Spazi bianchi**: significato del silenzio
- **Brevità**: concentrazione massima dell'espressione

### 5.9.3 Analisi Testi

**"Veglia"**

- **Situazione**: notte di guerra accanto a un compagno morto
- **Tema**: vita e morte, fraternità bellica
- **Stile**: linguaggio essenziale, contrasti

**"Fratelli"**

- **Tema**: solidarietà umana nella guerra
- **Parola-chiave**: "fratelli" come riconoscimento reciproco
- **Stile**: estrema concentrazione espressiva

**"San Martino del Carso"**

- **Tema**: distruzione della guerra
- **Analogia**: paese distrutto = cuore del poeta
- **Stile**: parallelismo, immagini essenziali

**"Mattina"**

- **Brevità estrema**: due versi
- **Tema**: rivelazione panica, fusione con l'universo
- **Stile**: sintesi assoluta dell'esperienza poetica

**"Soldati"**

- **Metafora**: foglie d'autunno = fragilità umana
- **Tema**: precarietà dell'esistenza
- **Stile**: analogia immediata, essenzialità

---

## 5.10. Eugenio Montale

### 5.10.1 Poetica e Visione del Mondo

**Pessimismo Esistenziale**

- **"Male di vivere"**: condizione esistenziale moderna
- **Crisi delle certezze**: impossibilità di una visione unitaria
- **Poetica dell'oggetto**: correlativo oggettivo delle emozioni
- **Antieloquenza**: rifiuto della retorica tradizionale

**Evoluzione Poetica**

1. **Ossi di seppia**: pessimismo esistenziale
2. **Le occasioni**: poetica dell'oggetto, donna salvifica
3. **La bufera**: storia e metastoria
4. **Satura**: ironia, prosaicismo

### 5.10.2 Ossi di seppia (1925)

**Tematiche Principali**

- **Paesaggio ligure**: metafora dell'esistenza arida
- **Impossibilità di certezze**: "ciò che non siamo, ciò che non vogliamo"
- **Ricerca di varchi**: possibilità di salvezza
- **Memoria**: recupero del passato

### 5.10.3 Analisi Testi

**"I limoni"**

- **Poetica**: manifesto antipasseiano e antidannunziano
- **Simboli**: limoni vs. allori (semplicità vs. retorica)
- **Tema**: rivelazione nelle cose umili
- **Stile**: linguaggio prosastico, antiletterario

**"Meriggiare pallido e assorto"**

- **Tema**: aridità esistenziale, spleen mediterraneo
- **Paesaggio**: campagna ligure sotto il sole
- **Simboli**: muro, spiragli, vita come prigione
- **Stile**: endecasillabi, linguaggio prezioso ma antiornamentale

**"Spesso il male di vivere ho incontrato"**

- **Tema**: dichiarazione pessimistica sull'esistenza
- **Correlativi oggettivi**: ruscello, foglia, cavallo
- **Contrasto**: male di vivere vs. "divina indifferenza"
- **Stile**: sonetto irregolare, linguaggio filosofico

**"Ho sceso, dandoti il braccio, almeno un milione di scale"**

- **Tema**: amore coniugale, invecchiamento insieme
- **Tono**: colloquiale, domestico
- **Tecnica**: linguaggio prosastico della maturità
- **Significato**: poesia come cronaca affettiva

---
# 5.11 - Collegamenti Italiano
## **STORIA**

### Positivismo e Naturalismo

- **Seconda Rivoluzione Industriale**: fiducia nel progresso vs. realtà delle condizioni operaie
- **Questione meridionale**: Verismo documenta arretratezza del Sud post-unitario
- **Darwinismo sociale**: influenza su determinismo verista e teorizzazioni razziali

### Decadentismo e Primo Novecento

- **Belle Époque**: estetismo dannunziano vs. contraddizioni sociali
- **Crisi di fine secolo**: irrazionalismo vs. certezze positiviste
- **Prima Guerra Mondiale**: esperienza bellica in Ungaretti, interventismo dannunziano
- **Ascesa del fascismo**: superomismo e retorica nazionalista

### Avanguardie e Modernità

- **Futurismo**: esaltazione guerra = "igiene del mondo"
- **Società di massa**: alienazione moderna in Pirandello e Svevo
- **Psicanalisi freudiana**: influenza su Svevo e analisi dell'inconscio

## **INGLESE**

### Tecniche Narrative e Modernismo

- **Stream of consciousness**: Svevo anticipa Joyce e Woolf
- **Modernismo europeo**: Pirandello e metateatro vs. Beckett e Ionesco
- **Psicanalisi letteraria**: "coscienza" in Svevo vs. psychological novel inglese

### Linguaggi e Comunicazione

- **Sperimentazione linguistica**: parole in libertà futuriste vs. avanguardie europee
- **Multilinguismo**: Svevo (italiano-tedesco-triestino) vs. letterature postcoloniali
- **Traduzione culturale**: adattamento concetti europei in contesto italiano

### Tematiche Universali

- **Alienazione moderna**: Pirandello vs. teatro dell'assurdo
- **Crisi identità**: frammentazione dell'io vs. modernismo anglosassone
- **Guerra e trauma**: Ungaretti vs. war poets inglesi (Owen, Sassoon)

## **MATEMATICA**

### Precisione e Metodo Scientifico

- **Verismo**: applicazione metodo scientifico alla letteratura
- **Determinismo**: leggi matematiche della natura vs. determinismo sociale verista
- **Oggettività**: impersonalità narrativa come "neutralità" scientifica

### Frammentazione e Infinito

- **Decadentismo**: frantumazione dell'io vs. calcolo infinitesimale
- **Ungaretti**: verso libero come "derivata" della poesia tradizionale
- **Pirandello**: relativismo vs. geometrie non euclidee

### Modelli e Rappresentazione

- **Realismo verista**: modellizzazione matematica della realtà sociale
- **Simbolismo**: corrispondenze poetiche vs. funzioni matematiche
- **Analogismo**: rapporti poetici vs. proporzionalità matematiche

## **INFORMATICA**

### Strutture Dati e Narrative

- **Database relazionale**: organizzazione sistematica come schedatura verista
- **Ipertesto**: collegamenti tematici vs. montaggio cinematografico futurista
- **Algoritmi narrativi**: tecniche compositive come procedure informatiche

### Linguaggi e Protocolli

- **Linguaggi di programmazione**: sperimentazione futurista vs. sintassi informatica
- **Standardizzazione**: lingua nazionale vs. protocolli di comunicazione
- **Debugging**: revisione letteraria vs. correzione errori codice

### Intelligenza Artificiale

- **Machine learning**: analisi automatica stile vs. critica letteraria tradizionale
- **Natural Language Processing**: comprensione automatica vs. interpretazione umana
- **Creatività artificiale**: generazione automatica testi vs. ispirazione poetica

## **SISTEMI E RETI**

### Comunicazione e Protocolli

- **Reti di comunicazione**: diffusione cultura nazionale vs. reti informatiche
- **Standardizzazione linguistica**: italiano standard vs. protocolli di rete
- **Censura**: controllo informazione vs. firewall e filtri digitali

### Architetture Distribuite

- **Sistema letterario**: autori, editori, pubblico vs. architetture client-server
- **Diffusione opere**: dalle stampe ai media digitali
- **Preservation**: conservazione patrimonio culturale vs. backup digitali

---

# 6. Storia

## 6.1. Politica ed economia nel secondo 800
### L'Italia Post-Unitaria

- **Destra Storica** (1861-1876)
    
    - Accentramento vs decentramento amministrativo
    - Liberalismo politico e liberismo economico
    - Pareggio di bilancio e tassa sul macinato
    - Brigantaggio meridionale
    - Terza Guerra d'Indipendenza (1866)
    - Presa di Roma (1870)
- **Sinistra Storica** (1876-1896)
    
    - Allargamento del suffragio
    - Protezionismo economico
    - Inizio dell'avventura coloniale (Eritrea, Somalia)
    - Disfatta di Adua (1896)

---

## 6.2. La Belle Epoque (1896-1914)

### Crisi di Fine Secolo e Svolta Autoritaria

- **Governo Crispi**: autoritarismo e repressione
- **Bava Beccaris**: eccidio di Milano (1898)
- **Assassinio di Umberto I** (1900)

### L'Età Giolittiana (1901-1914)

- **Trasformismo** e metodo giolittiano
- **Questione meridionale**: dualismo Nord-Sud
- **Politica sociale**: rapporti con socialisti e cattolici
- **Suffragio universale maschile** (1912)
- **Guerra di Libia** (1911-1912)

### Fenomeni Socio-Culturali

- **Antisemitismo** e complottismo
- **Sionismo** e questione ebraica
- **Movimenti di massa**: partiti e sindacati
- **Suffragette** e questione femminile
- **Nazionalismo** e razzismo

---

## 6.3. La Prima Guerra Mondiale (1914-1918)

### Cause e Scoppio del Conflitto

- **Sistema delle alleanze**: Triplice Alleanza vs Triplice Intesa
- **Attentato di Sarajevo** (28 giugno 1914)
- **Luglio di fuoco** e dichiarazioni di guerra

### Fasi del Conflitto

- **1914-1915**: guerra di movimento → guerra di posizione
- **Neutralità italiana**: interventisti vs neutralisti
- **Patto di Londra** (26 aprile 1915) ed entrata in guerra
- **1917: anno della svolta**
    - Rivoluzione russa e uscita dalla guerra
    - Entrata USA nel conflitto
    - **Disfatta di Caporetto** (ottobre 1917)
- **1918**: offensiva finale e vittoria dell'Intesa

### Caratteristiche del Conflitto

- **Guerra totale**: economia di guerra
- **Vita nelle trincee** e condizioni dei soldati
- **Nuove armi**: gas, aviazione, carri armati
- **Genocidio armeno** (1915-1916)
- **Nemico interno** e disfattismo

### Conseguenze

- **Trattati di pace** e nuovo assetto europeo
- **Crollo degli imperi centrali**
- **Rivoluzione russa**

---

## 6.4. La Rivoluzione Russa (1917-1924)

### Premesse

- **Russia zarista**: arretratezza economica e sociale
- **Rivoluzione del 1905** e costituzione della Duma
- **Rasputin** e crisi della monarchia

### Le Due Rivoluzioni del 1917

- **Rivoluzione di Febbraio**: abdicazione dello zar
- **Governo provvisorio** e diarchia col Soviet
- **Tesi di Aprile** di Lenin
- **Rivoluzione d'Ottobre**: presa del potere bolscevico

### Consolidamento del Potere Sovietico

- **Dittatura del proletariato**
- **Guerra civile** (1918-1921)
- **Comunismo di guerra** e NEP
- **Morte di Lenin** (1924) e ascesa di Stalin
- **Stalinismo** ed economia pianificata

---

## 6.5. Il Fascismo Italiano (1919-1943)

### Crisi del Dopoguerra

- **Biennio rosso** (1919-1920)
- **Questione di Fiume** e D'Annunzio
- **Vittoria mutilata** e nazionalismo

### Ascesa del Fascismo

- **Nascita dei Fasci** (1919) e squadrismo
- **Marcia su Roma** (28 ottobre 1922)
- **Governo Mussolini** e fase legalitaria

### Costruzione della Dittatura

- **Leggi fascistissime** (1925-1926)
- **Stato totalitario** e controllo sociale
- **Creazione del consenso**: propaganda e organizzazioni di massa
- **Patti Lateranensi** (1929)

### Politica Economica e Sociale

- **Battaglia del grano** e autarchia
- **Protezionismo economico**
- **Corporativismo**
- **Impero** e guerra d'Etiopia (1935-1936)

---

## 6.6. IL NAZISMO TEDESCO (1918-1945)

### Premesse: Germania Post-Bellica

- **Repubblica di Weimar** (1919-1933)
- **Trattato di Versailles** e sue conseguenze
- **Crisi del 1929** e ripercussioni in Germania

### Ascesa di Hitler

- **Putsch di Monaco** (1923)
- **Mein Kampf** e ideologia nazista
- **Elezioni del 1932** e nomina a Cancelliere (1933)

### Il Regime Nazista

- **Gleichschaltung**: coordinamento totalitario
- **Ideologia razziale** e antisemitismo
- **Leggi di Norimberga** (1935)
- **Notte dei cristalli** (1938)

### Politica Estera Aggressiva

- **Espansionismo tedesco**: Renania, Austria, Sudeti
- **Conferenza di Monaco** (1938)
- **Patto d'acciaio** con l'Italia
- **Asse Roma-Berlino-Tokyo**

---

## 6.7. La Seconda Guerra Mondiale (1939-1945)

### Fasi del Conflitto

- **1939-1940**: "guerra lampo" tedesca
    - Invasione Polonia e scoppio del conflitto
    - Campagna di Francia e Battaglia d'Inghilterra
- **1941**: globalizzazione del conflitto
    - Operazione Barbarossa (attacco URSS)
    - Pearl Harbor ed entrata USA
- **1942-1943**: la svolta
    - Stalingrado ed El Alamein
    - Sbarco in Sicilia
- **1944-1945**: vittoria degli Alleati
    - Sbarco in Normandia
    - Liberazione dell'Europa
    - Bomba atomica e resa del Giappone

### La Guerra in Italia (1943-1945)

- **25 luglio 1943**: caduta di Mussolini
- **8 settembre 1943**: armistizio e sbandamento
- **Resistenza italiana**: CLN e guerra civile
- **Repubblica Sociale Italiana**
- **Liberazione** (25 aprile 1945)

### Collaborazionismo e Resistenza

- **Governi collaborazionisti** in Europa
- **Movimenti di resistenza**: maquis, partigiani
- **Shoah**: genocidio ebraico
- **Crimini di guerra** e tribunali

---

## 8. Guerra Fredda - Inizi (1945-1947)

### Conferenze di Pace

- **Yalta** (febbraio 1945)
- **Potsdam** (luglio-agosto 1945)
- **Divisione della Germania**

### Origini della Guerra Fredda

- **Cortina di ferro** e blocchi contrapposti
- **Dottrina Truman** (1947)
- **Piano Marshall** (1947)
- **Cominform** e risposta sovietica

### Il Mondo Bipolare

- **NATO** vs **Patto di Varsavia**
- **Equilibrio del terrore** nucleare
- **Decolonizzazione** e Terzo Mondo

# 6.5 - Collegamenti Storia
## LINGUA E LETTERATURA ITALIANA

**Verismo e Questione Meridionale**

- Verga e la rappresentazione del Sud post-unitario
- Brigantaggio e "Rosso Malpelo": sfruttamento sociale

**Decadentismo e Belle Époque**

- D'Annunzio: estetismo, superomismo e interventismo
- Pascoli: socialismo umanitario e nazionalismo ("La Grande Proletaria")

**Futurismo e Prima Guerra Mondiale**

- Marinetti: esaltazione della guerra e della modernità tecnologica
- Ungaretti: esperienza bellica sul Carso

**Letteratura e Totalitarismi**

- Pirandello: crisi dell'identità e relativismo (crisi delle certezze post-1918)
- Svevo: inetto e inadeguatezza dell'individuo moderno
- Montale: "male di vivere" e contesto storico del '900

## INGLESE

**Rivoluzione Industriale 4.0**

- Confronto con innovazioni tecnologiche del primo '900
- Intelligenza Artificiale: parallelismo con automazione bellica

**Cybersecurity e Totalitarismi**

- Controllo delle informazioni nei regimi fascista e nazista
- Propaganda vs disinformazione digitale

**George Orwell e Totalitarismi**

- "1984": parallelismo con controllo sociale fascista/nazista
- "Animal Farm": allegoria della Rivoluzione Russa

## MATEMATICA

**Serie Numeriche e Demografia Bellica**

- Calcolo delle perdite umane nelle guerre mondiali
- Progressioni geometriche nella produzione industriale bellica

**Statistica e Propaganda**

- Manipolazione dei dati nei regimi totalitari
- Analisi quantitativa degli effetti economici delle guerre

## SISTEMI E RETI

**Comunicazioni Militari**

- Evoluzione delle telecomunicazioni durante le guerre mondiali
- Crittografia bellica vs crittografia moderna

**Reti di Resistenza**

- Organizzazione clandestina partigiana come "rete"
- Paralleli con sicurezza informatica e protezione dati

## TPS

**Innovazioni Tecnologiche Belliche**

- Sviluppo radar, radio, computer durante WWII
- Progetto Manhattan: precursore della ricerca tecnologica moderna

**Controllo Qualità e Produzione Industriale**

- Economia di guerra e standardizzazione produttiva
- Fordismo e organizzazione scientifica del lavoro

## INFORMATICA

**Database e Censimenti**

- Schedatura razziale nazista come precursore dei database
- IBM e macchine perforatrici per gestione dati durante WWII

**Intelligenza Artificiale e Controllo Sociale**

- Sistemi di sorveglianza totalitari vs AI moderna
- Etica dell'automazione: da Taylorismo a Industry 4.0

## GESTIONE PROGETTO

**Project Management Bellico**

- Pianificazione delle operazioni militari (Sbarco in Normandia)
- Gestione risorse nell'economia di guerra

**Analisi Costi-Benefici**

- Decisioni strategiche nei conflitti mondiali
- Piano Marshall come progetto di ricostruzione economica

---
# 7 - Inglese

## 7.1 - Computer e Informatica

### Fondamenti dell'Informatica

- **Definizione di Informatica**
    
    - Concetti base e applicazioni
    - Ruolo nella società moderna
- **Digital Literacy (Alfabetizzazione Digitale)**
    
    - Significato e importanza
    - Applicazioni nel contesto educativo
    - Competenze digitali essenziali

### Evoluzione dei Computer

- **Storia dei Computer: Le Quattro Generazioni**
    - **Prima generazione** (1940-1956): valvole termoioniche
    - **Seconda generazione** (1956-1963): transistor
    - **Terza generazione** (1964-1971): circuiti integrati
    - **Quarta generazione** (1971-presente): microprocessori

### Tipologie di Computer

- **Mainframe**: grandi sistemi per elaborazioni massive
- **Minicomputer**: sistemi di media grandezza
- **Personal Computer**: computer individuali
- **Dispositivi Mobili**: smartphone, tablet, wearables

### Linguaggi di Programmazione

- **Classificazione per Livello**
    
    - **Linguaggi di basso livello**: Assembly, linguaggio macchina
    - **Linguaggi di alto livello**: più vicini al linguaggio umano
- **Tipologie Specifiche**
    
    - **Linguaggi di markup**: HTML, XML
    - **Linguaggi orientati agli oggetti**: Java, C++
    - **Linguaggi visuali**: interfacce grafiche
- **Confronto Linguaggi Naturali vs Informatici**
    
    - Differenze strutturali e funzionali
    - Precisione vs ambiguità
- **Panoramica Linguaggi Specifici**
    
    - **C**: linguaggio procedurale
    - **HTML**: markup per web

### Grammatica Inglese - Base

- **Present Simple**: azioni abituali e verità generali
- **Present Continuous**: azioni in corso
- **Past Simple**: azioni passate completate

---

## 7.2 - Linguaggi e SO

### Linguaggi di Programmazione Moderni

- **Java**: linguaggio object-oriented, platform-independent
- **Python**: linguaggio versatile, sintassi semplice
- **PHP**: linguaggio per sviluppo web server-side

### Sistemi Operativi

- **Funzioni Principali**
    
    - Gestione hardware e software
    - Interfaccia utente-sistema
    - Multitasking e gestione memoria
- **Interfacce Utente**
    
    - **CLI** (Command Line Interface)
    - **GUI** (Graphical User Interface)
    - **Touch Interface**
- **Sistemi Operativi Principali**
    
    - **Linux**: open-source, server e desktop
    - **Android**: mobile, basato su Linux
    - **Windows**: Microsoft, desktop e server
    - **macOS**: Apple, ecosystem integrato

### Tecnologie Emergenti

- **Industria 4.0**
    
    - Internet of Things (IoT)
    - Automazione intelligente
    - Big Data e Analytics
    - Cloud Computing
- **Tecnologia in Medicina**
    
    - Telemedicina e e-health
    - Dispositivi medici intelligenti
    - AI per diagnosi e trattamenti

### Intelligenza Artificiale

- **Storia dell'AI**
    
    - Dalle origini agli sviluppi moderni
    - Milestone principali
- **Tipologie di AI**
    
    - **Narrow AI**: specializzata in compiti specifici
    - **General AI**: intelligenza umana artificiale
    - **Super AI**: oltre le capacità umane
- **Funzionamento e Applicazioni**
    
    - Machine Learning e Deep Learning
    - Applicazioni pratiche: riconoscimento vocale, visione artificiale

### Robotica

- **Confronto con il Corpo Umano**
    
    - Sensori vs organi di senso
    - Attuatori vs muscoli
    - Processori vs cervello
- **Tipologie di Robot**
    
    - Robot industriali
    - Robot di servizio
    - Robot domestici
    - Robot medici

### Internet e Reti

- **Storia di Internet**
    
    - Da ARPANET al World Wide Web
    - Protocolli TCP/IP
- **Tipologie di Rete**
    
    - **LAN** (Local Area Network): rete locale
    - **Internet**: rete globale
    - **Intranet**: rete aziendale privata

### Educazione Civica: Letteratura e Tecnologia

- **"The Fun They Had" di Isaac Asimov**
    - Riflessioni sull'educazione digitale
    - Impatto dell'AI sull'apprendimento

### Grammatica Inglese - Intermedio

- **Present Perfect**: azioni passate con rilevanza presente
- **Comparativi**: confronti tra elementi
- **Preposizioni**: di luogo, tempo, movimento

---

## 7.3 Sicurezza

### Sicurezza Informatica

- **Minacce Informatiche Principali**
    
    - **Malware**: software dannoso generico
    - **Spam**: messaggi indesiderati
    - **Bug**: errori di programmazione
- **Tipologie di Virus**
    
    - **Worm**: si replica autonomamente
    - **Rogue Security**: falsi antivirus
    - **Trojan**: nascosti in software apparentemente utili
- **Crimeware e Cybercrime**
    
    - **Keylogger**: registra digitazioni
    - **Phishing**: furto credenziali via email
    - **Spyware**: software spia
    - **Furto di identità**: appropriazione dati personali

### Protezione e Sicurezza

- **Strumenti di Protezione**
    
    - **Antivirus**: rilevamento e rimozione malware
    - **Firewall**: controllo traffico di rete
    - **Backup**: copie di sicurezza
- **Buone Pratiche**
    
    - Password sicure e autenticazione
    - Aggiornamenti software
    - Navigazione sicura
- **Sicurezza di Rete**
    
    - Crittografia e protocolli sicuri
    - VPN e connessioni protette

### Proprietà Intellettuale Digitale

- **Copyright**: diritti d'autore tradizionali
- **Copyleft**: licenze aperte (Creative Commons, GPL)
- **Fair Use**: uso legittimo di contenuti protetti

### Orientamento Professionale

- **Competenze Professionali**
    - Redazione CV in inglese
    - Lettera di presentazione (Cover Letter)
    - Simulazione colloqui di lavoro

### Educazione Civica e Approfondimenti

- **Personaggi della Tecnologia**
    
    - **Steve Jobs**: innovazione e design Apple
    - **Alan Turing**: padre dell'informatica, AI e crittografia
- **Letteratura Distopica**
    
    - **George Orwell**: biografia e opere
    - **"1984"**: sorveglianza e controllo totalitario
    - **"Animal Farm"**: allegoria politica
- **Tematiche Contemporanee** (Articoli NY Times)
    
    - Impatto delle ricerche Google sulla privacy
    - Intelligenza Artificiale e futuro del lavoro
    - Smart working vs lavoro in presenza
    - Inquinamento acustico e qualità della vita

### Grammatica Inglese - Avanzato

- **Future Tenses**
    
    - **Will**: decisioni spontanee e previsioni
    - **Going to**: intenzioni e piani
- **Modal Verbs**
    
    - **Can/Could**: abilità e richieste
    - **May/Might**: possibilità
    - **Would**: condizionale e richieste cortesi
    - **Must/Have to**: obbligo e necessità

---
# 7.4 - Collegamenti Inglese
## STORIA

**Evoluzione Tecnologica e Contesto Storico**

- Sviluppo dei computer durante WWII: macchine Enigma, computer per calcoli balistici
- Guerra Fredda e nascita di Internet: ARPANET come progetto militare USA
- Steve Jobs e Alan Turing: figure storiche dell'innovazione tecnologica

**George Orwell e Totalitarismi**

- "1984": parallelismo con sorveglianza nazista e staliniana
- "Animal Farm": allegoria della Rivoluzione Russa e ascesa di Stalin
- Controllo dell'informazione: propaganda fascista vs controllo digitale moderno

**Industria 4.0 e Rivoluzioni Industriali**

- Confronto con le precedenti rivoluzioni industriali storiche
- Impatto sociale delle innovazioni tecnologiche

## ITALIANO

**Letteratura e Tecnologia**

- Futurismo di Marinetti: esaltazione della tecnologia moderna
- "The Fun They Had" di Asimov vs concezione pascoliana del "fanciullino"
- Distopia orwelliana vs "inetto" sveviano: inadeguatezza dell'individuo moderno

**Evoluzione della Comunicazione**

- Linguaggi naturali vs linguaggi informatici
- Crisi del linguaggio nel Decadentismo vs precisione dei linguaggi di programmazione

## MATEMATICA

**Logica e Algoritmi**

- Linguaggi di programmazione e strutture logiche matematiche
- Serie numeriche e calcolo computazionale
- Alan Turing: macchina di Turing e fondamenti matematici dell'informatica

**Crittografia e Sicurezza**

- Algoritmi matematici per protezione dati
- Crittografia RSA e teoria dei numeri

## SISTEMI E RETI

**Architetture di Rete**

- Tipi di rete (LAN, Internet, Intranet) approfonditi tecnicamente
- Protocolli TCP/IP e architetture client-server
- Storia di Internet: da ARPANET al Web moderno

**Sicurezza Informatica**

- Malware, virus, crimeware: aspetti tecnici della protezione
- Firewall, antivirus, crittografia: implementazione pratica
- Ethical hacking e penetration testing

## TPS

**Linguaggi di Programmazione**

- C, HTML, Java, Python, PHP: programmazione pratica
- Paradigmi di programmazione: procedurale vs object-oriented
- Sviluppo web e applicazioni client-server

**Intelligenza Artificiale e Robotica**

- Machine Learning e Deep Learning: implementazione algoritmica
- Robotica industriale e Industria 4.0
- IoT e sistemi embedded

## INFORMATICA

**Database e Gestione Dati**

- Protezione dati e privacy (GDPR)
- Big Data e Analytics nell'era digitale
- Backup e disaster recovery

**Sviluppo Software**

- Metodologie di sviluppo software
- Testing e debugging (bug informatici)
- Version control e collaborative coding

## GESTIONE PROGETTO

**Project Management ICT**

- Sviluppo software come gestione progetto
- Metodologie Agile e Scrum
- Steve Jobs: management e leadership nell'innovazione

**Orientamento Professionale**

- CV e colloqui: competenze per settore ICT
- Soft skills per il mondo del lavoro tecnologico
- Startup e imprenditorialità digitale

---
