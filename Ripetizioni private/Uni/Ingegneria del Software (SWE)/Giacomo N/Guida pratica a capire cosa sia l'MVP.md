> Made by grovesti (so sempre mi)
## 1. Cos'è l'MVP: Definizione e Concetti

### 1.1 Definizione di MVP

> **Il Minimum Viable Product (MVP) è una versione preliminare del prodotto atteso dotata di funzionalità sufficienti per:**
> 
> - Valutare la bontà della visione iniziale
> - Consentire adeguato uso esplorativo
> - Permettere futuri avanzamenti

### 1.2 Caratteristiche Fondamentali dell'MVP

L'MVP è caratterizzato da:

- **✅ Prodotto reale**: Non è una demo o prototipo, è software utilizzabile
- **🎯 Funzionalità minime ma sufficienti**: Core features implementate completamente
- **💰 Costo contenuto**: Sviluppato con risorse limitate ma con qualità
- **⏱️ Tempo di realizzazione breve**: Time-to-market accelerato
- **👥 Utilizzabile dagli utenti**: Sistema operabile dall'utente finale
- **📊 Validabile**: Le funzionalità sono verificate e validate

### 1.3 MVP nel Contesto Accademico SWE

Nel progetto didattico di Ingegneria del Software:

```
MVP = Prodotto dimostrabile per Product Baseline (PB)
```

**Obiettivo**: Dimostrare che il team è in grado di:

1. **Progettare** un'architettura solida e scalabile
2. **Realizzare** codice di qualità production-ready
3. **Verificare** che il sistema soddisfi i requisiti
4. **Validare** il prodotto con stakeholder

### 1.4 Principio "Minimum" vs "Viable"

**MINIMUM** significa:

- ❌ NON "il meno possibile"
- ❌ NON "funzionalità incomplete"
- ✅ "Insieme minimo di funzionalità COMPLETE che rendono il prodotto UTILE"

**VIABLE** significa:

- ✅ Prodotto utilizzabile nella realtà
- ✅ Valore tangibile per gli utenti
- ✅ Base solida per evoluzioni future

**Esempio pratico**:

```
Sistema di e-commerce MVP:
✅ VIABLE: Catalogo prodotti + Carrello + Checkout + Pagamento
❌ NON VIABLE: Solo catalogo prodotti (manca funzionalità core)
❌ NON MINIMUM: Catalogo + Carrello + Checkout + Pagamento + 
                 Wishlist + Reviews + Raccomandazioni AI + 
                 Chat support + Loyalty program
                 (troppo ambizioso per MVP)
```

---

## 2. La Product Baseline (PB)

### 2.1 Cos'è la Product Baseline

La **Product Baseline** è la seconda revisione obbligatoria del progetto didattico. Rappresenta:

- **Milestone "Usable"** secondo SEMAT: sistema utilizzabile con caratteristiche desiderate
- **Baseline architetturale matura**: design definitivo consolidato
- **Avanzamento sostanziale di codifica**: prodotto funzionante e dimostrabile
- **Base per rilascio**: versione da cui non si può retrocedere

### 2.2 Stati SEMAT e Collocazione PB

Secondo il modello **SEMAT**, la PB si colloca tra "Usable" e "Ready":

```
┌─────────────────────────────────────────────────────┐
│ SEMAT States - Software System                     │
├─────────────────────────────────────────────────────┤
│ 1. Architecture Selected                            │
│    └─> Selezione architettura e tecnologie          │
│                                                      │
│ 2. Demonstrable ← PoC (RTB)                         │
│    └─> Principali caratteristiche dimostrate        │
│                                                      │
│ 3. Usable ← MVP/PB INIZIA QUI                       │
│    ├─> Sistema utilizzabile                         │
│    ├─> Operabile dagli utenti                       │
│    ├─> Funzionalità verificate e validate           │
│    └─> Difetti residui accettabili                  │
│                                                      │
│ 4. Ready ← MVP/PB TERMINA QUI (ideale per CA)       │
│    ├─> Documentazione utente pronta                 │
│    ├─> Stakeholder accettano prodotto               │
│    └─> Pronto per diventare operativo               │
│                                                      │
│ 5. Operational                                       │
│ 6. Retired                                           │
└─────────────────────────────────────────────────────┘
```

**Nota critica**: La PB si colloca **TRA** Usable e Ready, non esattamente in uno dei due stati. L'MVP per la PB deve essere Usable, mentre per la CA (opzionale) deve tendere a Ready.

### 2.3 Artefatti della PB

Per superare la PB sono necessari:

|Artefatto|Versione|Contenuto Principale|
|---|---|---|
|**Norme di Progetto**|v2.0.0|Way of working consolidato, aggiornamenti processi|
|**Piano di Progetto**|v2.0.0|Pianificazione aggiornata, consuntivi, preventivo a finire|
|**Piano di Qualifica**|v2.0.0|Test eseguiti, metriche raccolte, qualità misurata|
|**Analisi dei Requisiti**|v2.0.0|Requisiti raffinati post-RTB (se necessario)|
|**Specifica Tecnica**|v1.0.0|**NUOVO: Architettura logica del sistema**|
|**MVP (codice)**|-|**Prodotto funzionante con core features**|

### 2.4 Specifica Tecnica vs Definizione di Prodotto

Nel progetto SWE UniPD, la Product Baseline include la **Specifica Tecnica**, NON la Definizione di Prodotto:

|Documento|Livello|Contenuto|Revisione|
|---|---|---|---|
|**Specifica Tecnica (ST)**|Architettura logica (alto livello)|Componenti principali, interfacce, design pattern architetturali|**PB**|
|**Definizione di Prodotto (DP)**|Architettura di dettaglio (basso livello)|Classi, metodi, moduli terminali, diagrammi classi completi|RQ (Revisione Qualifica)|

**Per la PB serve la Specifica Tecnica**, che descrive l'architettura **LOGICA** senza scendere nei dettagli implementativi di ogni classe.

### 2.5 Processo di Approvazione PB

La PB segue un processo in 2 fasi identico alla RTB:

```
┌─────────────────────────────────────────────────────────┐
│  FASE 1: Valutazione MVP con Cardin (BLOCCANTE)         │
├─────────────────────────────────────────────────────────┤
│  • Prenotazione entro finestre di opportunità           │
│  • Dimostrazione MVP funzionante                        │
│  • Discussione architettura e qualità codice            │
│  • Revisione Specifica Tecnica                          │
│  • Esito: SEMAFORO VERDE / ROSSO                        │
└─────────────────────────────────────────────────────────┘
                            ↓ (solo se verde)
┌─────────────────────────────────────────────────────────┐
│  FASE 2: Presentazione PB a Vardanega                   │
├─────────────────────────────────────────────────────────┤
│  • Presentazione formale con documenti v2.0.0 + ST v1.0.0│
│  • Discussione design e qualità prodotto                │
│  • Esame grado raggiungimento obiettivi                 │
│  • Esito: APPROVAZIONE / RICHIESTA MODIFICHE            │
└─────────────────────────────────────────────────────────┘
```

**ATTENZIONE**: Senza semaforo verde da Cardin, NON si può procedere alla presentazione PB con Vardanega.

---

## 3. MVP vs PoC: Differenze Critiche

### 3.1 Tabella Comparativa Completa

|Aspetto|PoC (Proof of Concept)|MVP (Minimum Viable Product)|
|---|---|---|
|**Scopo primario**|Validare fattibilità tecnologica|Dimostrare valore al cliente|
|**Target audience**|Team di sviluppo, technical stakeholders|Utenti finali, stakeholders|
|**Qualità codice**|Esplorativo, può avere rough edges|Production-ready, mantenibile|
|**Architettura**|Concettuale, può essere usa-e-getta|Definitiva, base per evoluzione|
|**Testing**|Minimale, solo fattibilità|Completo: unit, integration, system|
|**Documentazione**|Tecnica (tecnologie, API)|Tecnica + Utente (manuale)|
|**Copertura requisiti**|20-30% (core critici)|60-80% (requisiti obbligatori)|
|**Design patterns**|Opzionali, se utili|Obbligatori, parte dell'architettura|
|**Gestione errori**|Semplificata|Completa e robusta|
|**Performance**|Accettabili|Verificate contro requisiti non-funzionali|
|**Scalabilità**|Non prioritaria|Considerata nell'architettura|
|**UI/UX**|Minimale funzionale|Usabile, segue standard|
|**Versioning**|Singolo snapshot|Baseline versionata (Git tags)|
|**Milestone SEMAT**|Demonstrable|Usable|
|**Revisione**|RTB|PB|
|**Reusable?**|Raramente|Sì, è la base del prodotto finale|

### 3.2 Evoluzione dal PoC all'MVP

**Percorso consigliato**:

```
┌──────────────┐
│     PoC      │  RTB: Dimostrazione fattibilità
│  (Dimostra)  │  - Tecnologie validate
└──────┬───────┘  - Rischi identificati
       │          - Architettura concettuale
       ↓
┌──────────────┐
│   Refactor   │  Post-RTB: Riprogettazione
│   & Rewrite  │  - Architettura definitiva
└──────┬───────┘  - Design patterns applicati
       │          - Codice production-ready
       ↓
┌──────────────┐
│     MVP      │  PB: Prodotto utilizzabile
│  (Funziona)  │  - Core features complete
└──────┬───────┘  - Testing completo
       │          - Documentazione estesa
       ↓
┌──────────────┐
│   Product    │  Post-PB / CA: Prodotto completo
│  (Completo)  │  - Tutte le features
└──────────────┘  - Production deployment
```

**IMPORTANTE**: L'MVP NON è "PoC + features". È una **riprogettazione** basata sulle lezioni apprese dal PoC.

### 3.3 Errori Comuni nella Transizione PoC → MVP

❌ **Errore #1: "Basta aggiungere features al PoC"**

```
Approccio sbagliato:
PoC (codice esplorativo) 
  → Aggiunta features
  → Patch gestione errori
  → MVP raffazzonato

Risultato: Debito tecnico, architettura fragile
```

✅ **Approccio corretto**:

```
PoC (lezioni apprese)
  → Design architettura definitiva
  → Implementazione clean da zero
  → MVP solido

Risultato: Codice mantenibile, architettura scalabile
```

❌ **Errore #2: "MVP = Tutti i requisiti implementati"**

L'MVP deve includere SOLO i requisiti **obbligatori** e alcuni **desiderabili** critici. I requisiti opzionali si aggiungono post-PB.

❌ **Errore #3: "L'architettura si raffina dopo"**

L'architettura deve essere **definitiva** alla PB. Raffinamenti OK, ma cambiamenti strutturali NO.

---

## 4. Scopo e Obiettivi della PB

### 4.1 Obiettivi Primari della PB

La Product Baseline ha **quattro obiettivi fondamentali**:

1. **🏗️ Vagliare maturità baseline architetturale**
    
    - L'architettura è solida, scalabile, mantenibile?
    - I design pattern sono applicati correttamente?
    - Le componenti sono ben definite e disaccoppiate?
2. **📐 Presentare design definitivo**
    
    - Coerente con il PoC ma migliorativo
    - Decisioni architetturali motivate
    - Trade-off documentati
3. **💻 Dimostrare avanzamento sostanziale di codifica**
    
    - Prodotto funzionante, non solo scheletro
    - Core features completamente implementate
    - Codice verificato e testato
4. **📋 Documentare architettura tecnica**
    
    - Specifica Tecnica completa
    - Diagrammi UML (classi, sequenza, package, deployment)
    - Tracciamento requisiti → componenti → test

### 4.2 Cosa Valutano i Committenti

**Cardin valuta** (focus tecnico):

- Qualità dell'architettura software
- Applicazione corretta design patterns
- Qualità del codice (leggibilità, manutenibilità)
- Copertura testing (unit, integration, system)
- Gestione errori e robustezza

**Vardanega valuta** (focus gestionale e prodotto):

- Raggiungimento obiettivi pianificati
- Soddisfacimento requisiti obbligatori
- Qualità documentazione
- Gestione progetto (pianificazione, consuntivi)
- Valore consegnato al proponente

### 4.3 Criteri di Successo PB

Un'ottima PB dimostra:

✅ **Architettura**:

- Design coerente con PoC ma evoluto
- Pattern architetturali appropriati (MVC, layered, microservizi, etc.)
- Separazione concerns (presentation, business logic, data)
- Componenti riutilizzabili e testabili

✅ **Codice**:

- Almeno 60-70% dei requisiti obbligatori implementati
- Qualità production-ready (no debug code, no hardcoded values)
- Naming conventions rispettate
- Gestione errori completa

✅ **Testing**:

- Test coverage > 70% (ideale > 80%)
- Test automatizzati (unit, integration)
- Test system manuali documentati
- Bugs critici risolti

✅ **Documentazione**:

- Specifica Tecnica v1.0.0 completa
- Diagrammi UML chiari e corretti
- Manuale Utente preliminare (se richiesto per CA)
- Codice commentato appropriatamente

---

## 5. Come Realizzare un MVP: Metodologia Pratica

### 5.1 Step 1: Post-RTB Analysis

**Obiettivo**: Analizzare feedback RTB e lezioni apprese dal PoC.

**Azioni**:

1. **Review feedback Cardin/Vardanega**
    
    - Quali problemi tecnici sono emersi?
    - Quali tecnologie vanno confermate/cambiate?
    - Quali rischi architetturali sono stati identificati?
2. **Analisi retrospettiva PoC**
    
    - Cosa ha funzionato bene?
    - Cosa va riprogettato?
    - Quali pattern emergenti dal codice?
3. **Aggiornamento requisiti**
    
    - Requisiti cambiati post-RTB?
    - Nuovi requisiti emersi?
    - Prioritizzazione requisiti per MVP

**Output**:

- Documento "Lessons Learned PoC"
- Analisi dei Requisiti v2.0.0 (se necessario)
- Lista requisiti MVP (obbligatori + desiderabili critici)

### 5.2 Step 2: Architectural Design

**Obiettivo**: Progettare architettura definitiva del sistema.

**Azioni**:

1. **Scelta stile architetturale**
    
    - Layered (n-tier)?
    - Client-Server?
    - Microservizi?
    - MVC / MVP / MVVM?
    - Event-driven?
2. **Identificazione componenti principali**
    
    - Quali sono i building blocks del sistema?
    - Come comunicano tra loro?
    - Quali interfacce espongono?
3. **Applicazione design patterns**
    
    - **Creazionali**: Factory, Singleton, Builder, Prototype
    - **Strutturali**: Adapter, Decorator, Facade, Proxy, Composite
    - **Comportamentali**: Observer, Strategy, Template Method, Command, State
4. **Definizione interfacce**
    
    - API REST / GraphQL?
    - Message queues?
    - Event bus?

**Output**:

- Diagrammi architetturali (high-level, component diagram)
- Matrice design patterns → problemi risolti
- Specifica interfacce componenti

**Esempio: Architettura Layered 3-Tier**:

```
┌────────────────────────────────────────────────────────┐
│                  PRESENTATION LAYER                    │
│  ┌──────────────────────────────────────────────────┐ │
│  │  React Components (UI)                           │ │
│  │  - Views (presentational components)             │ │
│  │  - Containers (stateful components)              │ │
│  │  - State Management (Redux/Context)              │ │
│  └──────────────────────────────────────────────────┘ │
└─────────────────────┬──────────────────────────────────┘
                      │ REST API (HTTPS/JSON)
                      ↓
┌────────────────────────────────────────────────────────┐
│                   BUSINESS LAYER                       │
│  ┌──────────────────────────────────────────────────┐ │
│  │  Application Services (Node.js/Express)          │ │
│  │  - Controllers (handle requests)                 │ │
│  │  - Services (business logic)                     │ │
│  │  - DTOs (Data Transfer Objects)                  │ │
│  │  - Validators                                    │ │
│  └──────────────────────────────────────────────────┘ │
└─────────────────────┬──────────────────────────────────┘
                      │ Internal API
                      ↓
┌────────────────────────────────────────────────────────┐
│                    DATA LAYER                          │
│  ┌──────────────────────────────────────────────────┐ │
│  │  Data Access (Repositories)                      │ │
│  │  - Models (ORM entities)                         │ │
│  │  - Repositories (data operations)                │ │
│  │  - Database (PostgreSQL/DynamoDB)                │ │
│  └──────────────────────────────────────────────────┘ │
└────────────────────────────────────────────────────────┘

CROSS-CUTTING CONCERNS:
- Logging (Winston/Log4j)
- Authentication (JWT/OAuth)
- Error Handling (Middleware)
- Configuration Management
```

### 5.3 Step 3: Implementazione Incrementale

**Obiettivo**: Costruire MVP incrementalmente, layer per layer.

**Approccio consigliato: Vertical Slices per Feature**

```
Feature 1 (UC1: Gestione Utenti)
  Sprint 1: User Registration
    ├─ Backend: POST /register endpoint
    ├─ Database: Users table
    ├─ Frontend: Registration form
    └─ Testing: Unit + Integration

  Sprint 2: User Login
    ├─ Backend: POST /login + JWT
    ├─ Database: Sessions management
    ├─ Frontend: Login form
    └─ Testing: Unit + Integration + E2E

Feature 2 (UC2: Gestione Contenuti)
  Sprint 3: Create Content
    ├─ Backend: POST /content endpoint
    ├─ Database: Content table
    ├─ Frontend: Content creation UI
    └─ Testing: Unit + Integration

  Sprint 4: List/View Content
    ├─ Backend: GET /content endpoints
    ├─ Database: Query optimization
    ├─ Frontend: Content list + detail views
    └─ Testing: Unit + Integration + Performance
```

**Ogni sprint produce**:

- Codice committato e reviewed
- Test automatizzati passing
- Feature documentata
- Demo-ready slice

### 5.4 Step 4: Continuous Integration & Quality Assurance

**Obiettivo**: Mantenere alta qualità durante sviluppo.

**Pratiche essenziali**:

1. **Version Control (Git)**
    
    ```
    main (production-ready)
      ↑
    develop (integration branch)
      ↑
    feature/UC1-user-registration
    feature/UC2-content-management
    bugfix/fix-login-validation
    ```
    
2. **Code Review**
    
    - Pull Request obbligatorie
    - Almeno 1 reviewer diverso dall'autore
    - Checklist: style, tests, documentation
3. **Automated Testing**
    
    - CI pipeline (GitHub Actions, GitLab CI)
    - Test automatici ad ogni commit
    - Coverage report
4. **Quality Metrics**
    
    - Cyclomatic complexity < 10
    - Code duplication < 5%
    - Test coverage > 70%

**Esempio GitHub Actions CI**:

```yaml
name: CI Pipeline

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - name: Setup Node.js
        uses: actions/setup-node@v2
        with:
          node-version: '20'
      - name: Install dependencies
        run: npm ci
      - name: Run linter
        run: npm run lint
      - name: Run tests
        run: npm test
      - name: Check coverage
        run: npm run coverage
      - name: Build
        run: npm run build
```

### 5.5 Step 5: Documentazione Tecnica (Specifica Tecnica)

**Obiettivo**: Produrre Specifica Tecnica v1.0.0 completa.

Vedi sezione 7 per dettagli completi.

### 5.6 Step 6: User Acceptance Preparation

**Obiettivo**: Preparare MVP per validazione utente.

**Azioni**:

1. **User Testing Scenarios**
    
    - Definire scenari d'uso realistici
    - Eseguire test con utenti (proponente)
    - Raccogliere feedback
2. **Bug Fixing Sprint**
    
    - Risolvere bugs critici e high-priority
    - Migliorare UX dove necessario
    - Ottimizzare performance
3. **Deployment in ambiente simil-produzione**
    
    - Setup ambiente staging
    - Deploy MVP
    - Smoke testing

---

## 6. Architettura e Design

### 6.1 Design Patterns Essenziali per PB

I design patterns sono **OBBLIGATORI** nella PB. Ecco quelli più comuni:

#### 6.1.1 Pattern Creazionali

**Singleton**

- **Quando**: Serve una sola istanza globale (es. Database connection pool, Logger)
- **Esempio**: ConfigurationManager, AuthenticationService
- **Attenzione**: Evitare abuso (anti-pattern se usato male)

**Factory / Abstract Factory**

- **Quando**: Creazione oggetti complessa o condizionale
- **Esempio**: DocumentFactory (crea PDF/DOCX/TXT), DatabaseFactory (MySQL/PostgreSQL/DynamoDB)

**Builder**

- **Quando**: Costruzione oggetti con molti parametri opzionali
- **Esempio**: QueryBuilder, EmailBuilder, ReportBuilder

#### 6.1.2 Pattern Strutturali

**Adapter**

- **Quando**: Integrare librerie/API con interfacce incompatibili
- **Esempio**: PaymentGatewayAdapter (unifica Stripe/PayPal), StorageAdapter (S3/GCS/Azure)

**Decorator**

- **Quando**: Aggiungere funzionalità a oggetti dinamicamente
- **Esempio**: LoggingDecorator, CachingDecorator, ValidationDecorator

**Facade**

- **Quando**: Semplificare interfaccia sistema complesso
- **Esempio**: PaymentFacade (nasconde complessità payment processing), NotificationFacade

**Proxy**

- **Quando**: Controllare accesso a oggetto (lazy loading, caching, access control)
- **Esempio**: ImageProxy (lazy load immagini), CacheProxy, AuthorizationProxy

#### 6.1.3 Pattern Comportamentali

**Observer**

- **Quando**: Notificare multipli oggetti di cambiamenti stato
- **Esempio**: Event system, Real-time notifications, State synchronization

**Strategy**

- **Quando**: Algoritmi intercambiabili a runtime
- **Esempio**: SortingStrategy, CompressionStrategy, PaymentStrategy

**Template Method**

- **Quando**: Algoritmo con passi fissi ma implementazioni variabili
- **Esempio**: DataImporter (template per CSV/JSON/XML import), ReportGenerator

**Command**

- **Quando**: Incapsulare richieste come oggetti (undo/redo, queue, logging)
- **Esempio**: TextEditorCommands, TransactionCommands

**State**

- **Quando**: Comportamento oggetto cambia in base a stato interno
- **Esempio**: OrderState (pending → processing → shipped → delivered), ConnectionState

#### 6.1.4 Pattern Architetturali

**Model-View-Controller (MVC)**

- **Quando**: Separare logica business da presentazione
- **Struttura**:
    - Model: Dati e business logic
    - View: UI e presentazione
    - Controller: Coordina Model e View

**Model-View-ViewModel (MVVM)**

- **Quando**: Applicazioni con data binding (React, Angular, Vue)
- **Vantaggi**: Testabilità, separazione concerns

**Repository Pattern**

- **Quando**: Astrarre data access layer
- **Vantaggi**: Disaccoppiamento da tecnologia database, testabilità

**Dependency Injection (DI)**

- **Quando**: SEMPRE (in progetti moderni)
- **Vantaggi**: Testabilità, flessibilità, manutenibilità

### 6.2 Diagrammi UML Richiesti per PB

La Specifica Tecnica deve includere i seguenti diagrammi UML:

#### 6.2.1 Diagramma dei Package

**Scopo**: Mostrare organizzazione logica componenti ad alto livello.

```
┌─────────────────────────────────────────────────────┐
│                 presentation                         │
│  ┌───────────┐  ┌──────────┐  ┌───────────────┐   │
│  │   views   │  │controllers│  │ state-mgmt   │   │
│  └───────────┘  └──────────┘  └───────────────┘   │
└────────────┬────────────────────────────────────────┘
             │ depends on
             ↓
┌─────────────────────────────────────────────────────┐
│                  application                         │
│  ┌───────────┐  ┌──────────┐  ┌───────────────┐   │
│  │  services │  │  DTOs    │  │  validators   │   │
│  └───────────┘  └──────────┘  └───────────────┘   │
└────────────┬────────────────────────────────────────┘
             │ depends on
             ↓
┌─────────────────────────────────────────────────────┐
│                    domain                            │
│  ┌───────────┐  ┌──────────┐  ┌───────────────┐   │
│  │  entities │  │value-objs│  │  repositories │   │
│  └───────────┘  └──────────┘  └───────────────┘   │
└────────────┬────────────────────────────────────────┘
             │ depends on
             ↓
┌─────────────────────────────────────────────────────┐
│                infrastructure                        │
│  ┌───────────┐  ┌──────────┐  ┌───────────────┐   │
│  │ database  │  │   API    │  │   logging     │   │
│  └───────────┘  └──────────┘  └───────────────┘   │
└─────────────────────────────────────────────────────┘
```

#### 6.2.2 Diagramma delle Classi (Principali)

**Scopo**: Dettagliare struttura componenti principali (NON tutte le classi).

**Esempio: User Management Component**

```
┌────────────────────────────────┐
│      <<interface>>             │
│     IUserRepository            │
├────────────────────────────────┤
│ + findById(id): User           │
│ + findByEmail(email): User     │
│ + save(user): User             │
│ + delete(id): void             │
└────────────┬───────────────────┘
             △
             │ implements
             │
┌────────────┴───────────────────┐
│   UserRepositoryImpl           │
├────────────────────────────────┤
│ - db: Database                 │
├────────────────────────────────┤
│ + findById(id): User           │
│ + findByEmail(email): User     │
│ + save(user): User             │
│ + delete(id): void             │
└────────────────────────────────┘

┌────────────────────────────────┐
│          User                  │
├────────────────────────────────┤
│ - id: string                   │
│ - email: string                │
│ - password: string             │
│ - name: string                 │
│ - role: UserRole               │
│ - createdAt: Date              │
├────────────────────────────────┤
│ + validateEmail(): boolean     │
│ + hashPassword(): void         │
│ + comparePassword(plain): bool │
└────────────────────────────────┘

┌────────────────────────────────┐
│       UserService              │
├────────────────────────────────┤
│ - repository: IUserRepository  │
│ - validator: UserValidator     │
├────────────────────────────────┤
│ + register(data): User         │
│ + login(email, pwd): Token     │
│ + getProfile(id): User         │
│ + updateProfile(id, data): User│
└────────────────────────────────┘
```

**Nota**: Includere solo metodi pubblici rilevanti, NON tutti i getter/setter.

#### 6.2.3 Diagramma di Sequenza

**Scopo**: Illustrare interazioni tra componenti per scenari critici.

**Esempio: User Registration Flow**

```
Actor           Controller      Service         Repository      Database
  │                 │               │                │               │
  │ POST /register  │               │                │               │
  ├────────────────>│               │                │               │
  │                 │ register(data)│                │               │
  │                 ├──────────────>│                │               │
  │                 │               │ validate(data) │               │
  │                 │               ├───────┐        │               │
  │                 │               │       │        │               │
  │                 │               │<──────┘        │               │
  │                 │               │ findByEmail()  │               │
  │                 │               ├───────────────>│               │
  │                 │               │                │ SELECT email  │
  │                 │               │                ├──────────────>│
  │                 │               │                │<──────────────┤
  │                 │               │<───────────────┤               │
  │                 │               │ [email exists] │               │
  │                 │<──────────────┤ throw error    │               │
  │<────────────────┤               │                │               │
  │ 409 Conflict    │               │                │               │
  │                 │               │                │               │
  │                 │               │ [email unique] │               │
  │                 │               │ hashPassword() │               │
  │                 │               ├───────┐        │               │
  │                 │               │       │        │               │
  │                 │               │<──────┘        │               │
  │                 │               │ save(user)     │               │
  │                 │               ├───────────────>│               │
  │                 │               │                │ INSERT user   │
  │                 │               │                ├──────────────>│
  │                 │               │                │<──────────────┤
  │                 │               │<───────────────┤               │
  │                 │<──────────────┤                │               │
  │<────────────────┤               │                │               │
  │ 201 Created     │               │                │               │
  │ {user}          │               │                │               │
```

#### 6.2.4 Diagramma di Attività

**Scopo**: Mostrare flusso logico complesso (workflow, business process).

**Quando usare**:

- Algoritmi complessi
- Workflow multi-step
- Business process con condizioni/branch

#### 6.2.5 Diagramma di Deployment

**Scopo**: Mostrare architettura fisica (server, network, deployment).

**Esempio: Cloud Deployment**

```
┌────────────────────────────────────────────────────┐
│               AWS Cloud (Region: eu-west-1)        │
│                                                    │
│  ┌──────────────────────────────────────────────┐ │
│  │            VPC (10.0.0.0/16)                 │ │
│  │                                              │ │
│  │  ┌─────────────────────────────────────┐    │ │
│  │  │  Public Subnet (10.0.1.0/24)        │    │ │
│  │  │                                     │    │ │
│  │  │  ┌──────────────────────────────┐  │    │ │
│  │  │  │  EC2 Instance (t3.medium)    │  │    │ │
│  │  │  │  - Node.js Runtime           │  │    │ │
│  │  │  │  - Express Server            │  │    │ │
│  │  │  │  - Port: 3000                │  │    │ │
│  │  │  └──────────────────────────────┘  │    │ │
│  │  │                ↓                   │    │ │
│  │  │  ┌──────────────────────────────┐  │    │ │
│  │  │  │  Application Load Balancer   │  │    │ │
│  │  │  │  - HTTPS (443)               │  │    │ │
│  │  │  └──────────────────────────────┘  │    │ │
│  │  └─────────────────────────────────────┘    │ │
│  │                                              │ │
│  │  ┌─────────────────────────────────────┐    │ │
│  │  │  Private Subnet (10.0.2.0/24)       │    │ │
│  │  │                                     │    │ │
│  │  │  ┌──────────────────────────────┐  │    │ │
│  │  │  │  RDS PostgreSQL              │  │    │ │
│  │  │  │  - db.t3.small               │  │    │ │
│  │  │  │  - Multi-AZ                  │  │    │ │
│  │  │  └──────────────────────────────┘  │    │ │
│  │  └─────────────────────────────────────┘    │ │
│  └──────────────────────────────────────────────┘ │
│                                                    │
│  ┌──────────────────────────────────────────────┐ │
│  │  S3 Bucket (static assets)                   │ │
│  └──────────────────────────────────────────────┘ │
│                                                    │
│  ┌──────────────────────────────────────────────┐ │
│  │  CloudFront CDN                              │ │
│  └──────────────────────────────────────────────┘ │
└────────────────────────────────────────────────────┘
```

### 6.3 Tracciamento Requisiti → Componenti → Test

**Fondamentale per PB**: Dimostrare tracciabilità end-to-end.

**Matrice di tracciamento (esempio)**:

|Requisito|Componente|Classe/Modulo|Test Unit|Test Integration|Test System|
|---|---|---|---|---|---|
|RF1.1 - Registrazione utente|UserManagement|UserService|UT_US_001|IT_UM_001|ST_UC1_001|
|RF1.2 - Login utente|UserManagement|AuthService|UT_AS_001|IT_UM_002|ST_UC2_001|
|RF2.1 - Creazione contenuto|ContentManagement|ContentService|UT_CS_001|IT_CM_001|ST_UC3_001|
|RNF1 - Performance login < 500ms|UserManagement|AuthService|-|-|ST_PERF_001|
|RNF2 - Disponibilità 99.9%|Infrastructure|LoadBalancer|-|-|ST_AVAIL_001|

---

## 7. Documentazione PB: Specifica Tecnica

### 7.1 Template Specifica Tecnica v1.0.0

```
┌─────────────────────────────────────────────────────────┐
│              SPECIFICA TECNICA (ST)                     │
│                  (Versione 1.0.0)                       │
└─────────────────────────────────────────────────────────┘

├─ Frontespizio
│  ├─ Logo gruppo
│  ├─ Titolo: "Specifica Tecnica"
│  ├─ Informazioni documento:
│  │  • Redattori: [Progettisti]
│  │  • Verificatori: [Altri membri]
│  │  • Amministratore: [Nome]
│  │  • Destinatari: T. Vardanega, R. Cardin, Proponente
│  │  • Versione: 1.0.0
│  │  • Data: [gg/mm/aaaa]
│  └─ Contatto: email@gruppo.com
│
├─ Registro dei Cambiamenti
│  └─ Tabella: Versione | Data | Autore | Verificatore | Dettaglio
│
├─ 1. Introduzione
│  ├─ 1.1 Scopo del documento
│  ├─ 1.2 Scopo del prodotto
│  ├─ 1.3 Glossario
│  └─ 1.4 Riferimenti
│      • Analisi dei Requisiti v2.0.0
│      • Norme di Progetto v2.0.0
│      • Capitolato C[N]
│
├─ 2. Tecnologie Utilizzate
│  ├─ 2.1 Frontend
│  │   • Framework e librerie con versioni
│  │   • Motivazione scelte
│  │   • Pro e contro
│  ├─ 2.2 Backend
│  │   • Runtime, framework, librerie
│  │   • Motivazione scelte
│  │   • Pro e contro
│  ├─ 2.3 Database
│  │   • DBMS scelto
│  │   • Motivazione (relazionale vs NoSQL)
│  │   • Pro e contro
│  ├─ 2.4 Deployment e Infrastructure
│  │   • Cloud provider / on-premise
│  │   • CI/CD pipeline
│  │   • Monitoring e logging
│  └─ 2.5 Tools di Sviluppo
│      • IDE, linter, formatter
│      • Version control
│      • Testing frameworks
│
├─ 3. Architettura di Sistema
│  ├─ 3.1 Stile Architetturale
│  │   • Descrizione stile scelto (Layered, MVC, Microservizi, etc.)
│  │   • Motivazione scelta
│  │   • Vantaggi e svantaggi
│  ├─ 3.2 Vista Logica
│  │   • Diagramma Package (UML)
│  │   • Descrizione package e responsabilità
│  ├─ 3.3 Vista Fisica (Deployment)
│  │   • Diagramma Deployment (UML)
│  │   • Descrizione nodi e connessioni
│  ├─ 3.4 Vista Dinamica
│  │   • Diagrammi Sequenza (scenari principali)
│  │   • Diagrammi Attività (workflow complessi)
│  └─ 3.5 Vista Dati
│      • Schema ER (se database relazionale)
│      • Schema documenti (se NoSQL)
│      • Strategia migrazione/versioning schema
│
├─ 4. Design Pattern
│  ├─ 4.1 Pattern Architetturali
│  │   • MVC, Layered, Repository, etc.
│  │   • Dove applicati
│  │   • Benefici ottenuti
│  ├─ 4.2 Pattern Creazionali
│  │   • Factory, Singleton, Builder, etc.
│  │   • Contesto applicazione
│  │   • Diagrammi classi
│  ├─ 4.3 Pattern Strutturali
│  │   • Adapter, Decorator, Facade, Proxy, etc.
│  │   • Contesto applicazione
│  │   • Diagrammi classi
│  └─ 4.4 Pattern Comportamentali
│      • Observer, Strategy, Template Method, Command, State, etc.
│      • Contesto applicazione
│      • Diagrammi sequenza
│
├─ 5. Decomposizione per Componenti
│  ├─ 5.1 Componente: [Nome Componente 1]
│  │   ├─ Responsabilità
│  │   ├─ Interfacce esposte
│  │   ├─ Dipendenze
│  │   ├─ Diagramma Classi (principali)
│  │   ├─ Requisiti soddisfatti
│  │   └─ Note implementative
│  ├─ 5.2 Componente: [Nome Componente 2]
│  │   └─ [stessa struttura]
│  └─ 5.N Componente: [Nome Componente N]
│      └─ [stessa struttura]
│
├─ 6. Tracciamento
│  ├─ 6.1 Requisiti → Componenti
│  │   • Matrice tracciamento
│  │   • Copertura requisiti
│  ├─ 6.2 Componenti → Classi
│  │   • Mapping componente → implementazione
│  └─ 6.3 Componenti → Test
│      • Strategia testing per componente
│      • Test cases associati
│
├─ 7. Qualità Architetturale
│  ├─ 7.1 Metriche
│  │   • Fan-in / Fan-out
│  │   • Cyclomatic complexity
│  │   • Coupling / Cohesion
│  ├─ 7.2 Analisi
│  │   • Valori misurati
│  │   • Interpretazione
│  │   • Azioni correttive (se necessario)
│  └─ 7.3 Trade-off
│      • Decisioni architetturali con pro/contro
│      • Debito tecnico accettato (se presente)
│
├─ 8. Gestione Errori e Logging
│  ├─ 8.1 Strategia Gestione Errori
│  │   • Tipologie errori
│  │   • Handling strategy
│  │   • Error codes e messaggi
│  ├─ 8.2 Logging
│  │   • Livelli log (debug, info, warn, error)
│  │   • Formato log
│  │   • Destinazione (file, cloud, console)
│  └─ 8.3 Monitoring
│      • Metriche monitorate
│      • Alerting
│      • Dashboard
│
├─ 9. Sicurezza
│  ├─ 9.1 Autenticazione
│  │   • Meccanismo (JWT, OAuth, session-based)
│  │   • Flusso autenticazione
│  ├─ 9.2 Autorizzazione
│  │   • RBAC / ABAC
│  │   • Gestione permessi
│  ├─ 9.3 Data Protection
│  │   • Encryption at rest
│  │   • Encryption in transit (HTTPS/TLS)
│  │   • Sensitive data handling
│  └─ 9.4 Security Best Practices
│      • Input validation
│      • SQL injection prevention
│      • XSS prevention
│      • CSRF protection
│
├─ 10. Performance e Scalabilità
│  ├─ 10.1 Requisiti Performance
│  │   • Response time targets
│  │   • Throughput targets
│  │   • Concurrent users
│  ├─ 10.2 Strategie Ottimizzazione
│  │   • Caching (Redis, Memcached)
│  │   • Database indexing
│  │   • Query optimization
│  │   • CDN per static assets
│  └─ 10.3 Scalabilità
│      • Horizontal scaling strategy
│      • Load balancing
│      • Database sharding (se applicabile)
│
└─ Appendici
   ├─ A. Glossario tecnico
   ├─ B. API Reference (se estesa)
   ├─ C. Database Schema DDL
   └─ D. Diagrammi Aggiuntivi
```

### 7.2 Differenze ST vs DP

**Specifica Tecnica (PB)**:

- Architettura LOGICA
- Componenti ad alto livello
- Interfacce principali
- Pattern architetturali
- Diagrammi package, component, deployment

**Definizione di Prodotto (RQ)**:

- Architettura DI DETTAGLIO
- Classi e moduli terminali
- Tutti i metodi e attributi
- Implementazione algoritmi
- Diagrammi classi completi per ogni componente

**Livello di dettaglio**:

```
ST (PB):  Architettura a 10.000 metri di altitudine
DP (RQ):  Architettura a livello del suolo
```

---

## 8. Verifica e Testing

### 8.1 Strategia di Testing per PB

La PB richiede testing **completo e automatizzato** su più livelli:

```
┌────────────────────────────────────────────────────┐
│              PIRAMIDE DEL TESTING                  │
└────────────────────────────────────────────────────┘

                    ▲
                   ╱ ╲
                  ╱ E2E╲          ← Pochi (5-10% effort)
                 ╱ Tests╲           End-to-End / UI Tests
                ╱─────────╲
               ╱Integration╲       ← Moderati (30% effort)
              ╱    Tests    ╲        Component Integration
             ╱───────────────╲
            ╱   Unit Tests    ╲    ← Molti (60% effort)
           ╱___________________╲     Singole unità/funzioni
```

### 8.2 Unit Testing

**Obiettivo**: Testare singole unità (funzioni, metodi, classi) in isolamento.

**Coverage target**: > 80% per business logic critica

**Tool suggeriti**:

- JavaScript: Jest, Mocha, Chai
- Java: JUnit, TestNG
- Python: pytest, unittest
- .NET: xUnit, NUnit

**Esempio Jest (JavaScript)**:

```javascript
// UserService.test.js
describe('UserService', () => {
  let userService;
  let mockRepository;

  beforeEach(() => {
    mockRepository = {
      findByEmail: jest.fn(),
      save: jest.fn()
    };
    userService = new UserService(mockRepository);
  });

  describe('register', () => {
    it('should throw error if email already exists', async () => {
      // Arrange
      const userData = { email: 'test@example.com', password: 'pass123' };
      mockRepository.findByEmail.mockResolvedValue({ id: '123' });

      // Act & Assert
      await expect(userService.register(userData))
        .rejects.toThrow('Email already exists');
    });

    it('should create user if email is unique', async () => {
      // Arrange
      const userData = { email: 'new@example.com', password: 'pass123' };
      mockRepository.findByEmail.mockResolvedValue(null);
      mockRepository.save.mockResolvedValue({ id: '456', ...userData });

      // Act
      const result = await userService.register(userData);

      // Assert
      expect(result.id).toBe('456');
      expect(result.email).toBe('new@example.com');
      expect(mockRepository.save).toHaveBeenCalledTimes(1);
    });
  });
});
```

### 8.3 Integration Testing

**Obiettivo**: Testare interazione tra componenti (es. Service + Repository + Database).

**Cosa testare**:

- API endpoints (Controller + Service + Database)
- Interazioni tra moduli
- Chiamate a servizi esterni (con mock/stub)

**Tool suggeriti**:

- JavaScript: Supertest (API testing)
- Java: Spring Test, RestAssured
- Python: pytest + requests

**Esempio Supertest (API Integration)**:

```javascript
// UserAPI.integration.test.js
const request = require('supertest');
const app = require('../app');

describe('POST /api/register', () => {
  it('should register new user successfully', async () => {
    const response = await request(app)
      .post('/api/register')
      .send({
        email: 'integration@test.com',
        password: 'SecurePass123!',
        name: 'Integration Test'
      })
      .expect(201);

    expect(response.body).toHaveProperty('id');
    expect(response.body.email).toBe('integration@test.com');
  });

  it('should return 409 if email exists', async () => {
    // First registration
    await request(app)
      .post('/api/register')
      .send({
        email: 'duplicate@test.com',
        password: 'Pass123!',
        name: 'First User'
      });

    // Duplicate registration
    const response = await request(app)
      .post('/api/register')
      .send({
        email: 'duplicate@test.com',
        password: 'DifferentPass456!',
        name: 'Second User'
      })
      .expect(409);

    expect(response.body.error).toContain('already exists');
  });
});
```

### 8.4 System Testing

**Obiettivo**: Testare sistema end-to-end dal punto di vista utente.

**Tipi**:

- **Functional Testing**: Requisiti funzionali soddisfatti?
- **Performance Testing**: Response time, throughput accettabili?
- **Security Testing**: Vulnerabilità identificate?
- **Usability Testing**: Sistema usabile dall'utente finale?

**Tool suggeriti**:

- E2E: Cypress, Selenium, Playwright, Puppeteer
- Performance: JMeter, k6, Artillery
- Security: OWASP ZAP, Burp Suite

**Esempio Cypress (E2E)**:

```javascript
// user-registration.e2e.js
describe('User Registration Flow', () => {
  beforeEach(() => {
    cy.visit('/register');
  });

  it('should complete registration successfully', () => {
    cy.get('[data-testid="email-input"]')
      .type('e2e@test.com');
    
    cy.get('[data-testid="password-input"]')
      .type('SecurePassword123!');
    
    cy.get('[data-testid="name-input"]')
      .type('E2E Test User');
    
    cy.get('[data-testid="register-button"]')
      .click();
    
    cy.url().should('include', '/dashboard');
    cy.get('[data-testid="welcome-message"]')
      .should('contain', 'Welcome, E2E Test User');
  });

  it('should show validation error for invalid email', () => {
    cy.get('[data-testid="email-input"]')
      .type('invalid-email');
    
    cy.get('[data-testid="register-button"]')
      .click();
    
    cy.get('[data-testid="email-error"]')
      .should('be.visible')
      .and('contain', 'Invalid email format');
  });
});
```

### 8.5 Test Coverage e Reporting

**Obiettivi minimi PB**:

- **Unit test coverage**: > 70% (ideale > 80%)
- **Integration test coverage**: > 60%
- **System test coverage**: 100% use case obbligatori

**Tool Coverage**:

- JavaScript: Istanbul/nyc, Jest (built-in)
- Java: JaCoCo, Cobertura
- Python: Coverage.py

**Report Coverage** (esempio Jest):

```bash
npm run test:coverage

# Output:
---------------------------|---------|----------|---------|---------|
File                       | % Stmts | % Branch | % Funcs | % Lines |
---------------------------|---------|----------|---------|---------|
All files                  |   82.14 |    76.32 |   85.71 |   82.45 |
 services/                 |   88.23 |    81.25 |   90.00 |   88.50 |
  UserService.js           |   92.30 |    87.50 |   100.0 |   92.85 |
  AuthService.js           |   84.00 |    75.00 |    80.0 |   84.00 |
 repositories/             |   78.57 |    70.00 |   80.00 |   78.94 |
  UserRepository.js        |   78.57 |    70.00 |    80.0 |   78.94 |
 controllers/              |   75.00 |    66.66 |   83.33 |   75.00 |
  UserController.js        |   75.00 |    66.66 |   83.33 |   75.00 |
---------------------------|---------|----------|---------|---------|
```

### 8.6 Piano di Qualifica: Sezione Testing

Il Piano di Qualifica v2.0.0 deve includere:

1. **Strategia di testing**
    
    - Tipologie test (unit, integration, system)
    - Tool utilizzati
    - Criteri di accettazione
2. **Test cases definiti**
    
    - ID test
    - Descrizione
    - Input
    - Output atteso
    - Stato (passed/failed)
3. **Risultati test**
    
    - Coverage raggiunta
    - Test passed / total
    - Bug identificati e risolti
4. **Tracciamento Requisiti → Test**
    
    - Ogni requisito obbligatorio ha almeno 1 test
    - Matrice tracciamento aggiornata

**Esempio tabella test nel PdQ**:

|Test ID|Tipo|Requisito|Descrizione|Stato|Note|
|---|---|---|---|---|---|
|UT_US_001|Unit|RF1.1|UserService.register con email duplicata|PASSED|-|
|UT_US_002|Unit|RF1.1|UserService.register con email valida|PASSED|-|
|IT_UM_001|Integration|RF1.1|API POST /register success|PASSED|-|
|IT_UM_002|Integration|RF1.2|API POST /login success|PASSED|-|
|ST_UC1_001|System|UC1|Registrazione utente end-to-end|PASSED|-|
|ST_PERF_001|System|RNF1|Login response time < 500ms|PASSED|avg: 320ms|

---

## 9. Checklist Pre-Consegna

### 9.1 Checklist Codice MVP

- [ ] **Repository Git organizzato**
    
    - [ ] Branch strategy chiara (main, develop, feature/*)
    - [ ] Tag versione PB (es. v2.0.0-pb)
    - [ ] .gitignore configurato
    - [ ] README.md completo
- [ ] **Qualità codice**
    
    - [ ] Linter configurato e passing (ESLint, Pylint, etc.)
    - [ ] Formatter applicato (Prettier, Black, etc.)
    - [ ] No debug code / console.log in produzione
    - [ ] No hardcoded credentials / secrets
    - [ ] Commenti significativi dove necessario
- [ ] **Architettura implementata**
    
    - [ ] Design patterns applicati correttamente
    - [ ] Separazione concerns (layers/components)
    - [ ] Dependency injection utilizzata
    - [ ] Interfaces/abstractions per disaccoppiamento
- [ ] **Testing**
    
    - [ ] Unit tests > 70% coverage
    - [ ] Integration tests per API principali
    - [ ] System tests per use case obbligatori
    - [ ] CI pipeline con test automatici
- [ ] **Gestione errori**
    
    - [ ] Try-catch appropriati
    - [ ] Error handling middleware (se web app)
    - [ ] Log errori con stack trace
    - [ ] User-friendly error messages
- [ ] **Configurazione e deploy**
    
    - [ ] Environment variables (.env.example fornito)
    - [ ] Script di setup database
    - [ ] Docker/docker-compose (se applicabile)
    - [ ] Istruzioni deployment chiare

### 9.2 Checklist Documenti PB

- [ ] **Norme di Progetto v2.0.0**
    
    - [ ] Frontespizio aggiornato
    - [ ] Changelog completo
    - [ ] Way of working consolidato
    - [ ] Aggiornamenti strumenti/processi
- [ ] **Piano di Progetto v2.0.0**
    
    - [ ] Pianificazione aggiornata post-RTB
    - [ ] Consuntivi sprint/periodo
    - [ ] Preventivo a finire
    - [ ] Analisi rischi aggiornata
- [ ] **Piano di Qualifica v2.0.0**
    
    - [ ] Metriche raccolte e analizzate
    - [ ] Test definiti e risultati documentati
    - [ ] Qualità misurata (codice, processi)
    - [ ] Azioni migliorative implementate
- [ ] **Analisi dei Requisiti v2.0.0**
    
    - [ ] Requisiti raffinati se necessario
    - [ ] Tracciamento aggiornato
    - [ ] Use case modificati documentati
- [ ] **Specifica Tecnica v1.0.0**
    
    - [ ] Frontespizio completo
    - [ ] Tutte le sezioni presenti (vedi template)
    - [ ] Diagrammi UML corretti e leggibili
    - [ ] Design patterns documentati
    - [ ] Tracciamento requisiti → componenti
    - [ ] Glossario tecnico
- [ ] **Generali**
    
    - [ ] Versioning corretto (semver)
    - [ ] Revisione ortografica
    - [ ] Indici automatici funzionanti
    - [ ] Link incrociati tra documenti
    - [ ] PDF generati e compressi

### 9.3 Checklist Presentazione PB

- [ ] **Slide preparate** (max 20-25 slide):
    
    - [ ] Overview progetto e obiettivi PB
    - [ ] Architettura di sistema
    - [ ] Design patterns utilizzati
    - [ ] Demo MVP (screenshot/video)
    - [ ] Metriche qualità e testing
    - [ ] Consuntivi e pianificazione
    - [ ] Lessons learned e next steps
- [ ] **Demo preparata**
    
    - [ ] Ambiente demo funzionante
    - [ ] Scenario demo provato più volte
    - [ ] Backup plan (video registrato)
    - [ ] Dati di test realistici
- [ ] **Team preparato**
    
    - [ ] Ogni membro conosce la propria parte
    - [ ] Risposte a domande prevedibili preparate
    - [ ] Timing presentazione provato (30-40 min)

---

## 10. Valutazione con Cardin

### 10.1 Cosa Valuta Cardin per la PB

Cardin valuta la PB su questi criteri principali:

1. **Architettura Software (35%)**
    
    - Solidità e coerenza architetturale
    - Applicazione design patterns
    - Qualità decomposizione componenti
    - Scalabilità e manutenibilità
2. **Qualità Codice (30%)**
    
    - Leggibilità e organizzazione
    - Best practices linguaggio/framework
    - Gestione errori
    - Absence of code smells
3. **Testing (20%)**
    
    - Coverage adeguata
    - Qualità test cases
    - Test automatizzati funzionanti
    - Tracciamento test → requisiti
4. **Documentazione Tecnica (15%)**
    
    - Specifica Tecnica completezza
    - Diagrammi UML correttezza
    - Chiarezza e precisione

### 10.2 Domande Tipiche di Cardin per PB

**Architettura**:

- "Perché avete scelto architettura [layered/microservizi/etc]?"
- "Come gestite la comunicazione tra [componente A] e [componente B]?"
- "Dove avete applicato il pattern [X] e perché?"
- "Come scale questo sistema a 10x utenti?"

**Design Patterns**:

- "Perché usate Singleton per [X]? Non è un anti-pattern qui?"
- "Mostratemi un esempio di Dependency Injection nel codice."
- "Come implementate il pattern Repository?"

**Codice**:

- "Come gestite le transazioni database?"
- "Dove è la validazione degli input?"
- "Come prevenite SQL injection / XSS?"
- "Cosa succede se [servizio esterno] fallisce?"

**Testing**:

- "Perché coverage è solo 65% su [componente]?"
- "Come testate le interazioni con database?"
- "Avete test per gli scenari di errore?"
- "Come fate integration testing?"

**Performance**:

- "Avete misurato le performance?"
- "Come ottimizzate le query database?"
- "Gestite caching? Come?"

### 10.3 Come Rispondere Efficacemente

**DO ✅**:

- Dimostrare comprensione profonda delle scelte architetturali
- Mostrare codice concreto quando richiesto
- Ammettere limitazioni e descrivere come migliorare
- Riferire decisioni a requisiti non-funzionali
- Citare metriche misurate (coverage, performance, etc.)

**DON'T ❌**:

- Dire "abbiamo usato pattern X perché è trendy"
- Difendere scelte tecniche sbagliate
- Ignorare code smells evidenti
- Nascondere problemi architetturali
- Vantarsi di coverage 95% se test sono banali

### 10.4 Esiti Possibili

**Semaforo VERDE** 🟢:

- Architettura solida e ben documentata
- Codice di qualità con buon testing
- MVP funzionante e dimostrabile
- → Procede a presentazione Vardanega

**Semaforo GIALLO** 🟡:

- Architettura OK ma con alcuni problemi
- Codice buono ma testing insufficiente
- Richiesti miglioramenti specifici
- → Revisione rapida richiesta

**Semaforo ROSSO** 🔴:

- Architettura fragile o inconsistente
- Codice di bassa qualità
- Testing inadeguato
- → Richiesto refactoring sostanziale

---

## 11. FAQ e Domande Ricorrenti

### 11.1 Domande Generali

**Q: Quanto tempo dedicare allo sviluppo MVP?**

A: Tipicamente 6-10 settimane post-RTB:

- Settimane 1-2: Design architettura, setup progetto
- Settimane 3-7: Sviluppo iterativo features
- Settimane 8-9: Testing, bug fixing, ottimizzazione
- Settimana 10: Documentazione, preparazione presentazione

**Effort totale**: 200-300 ore gruppo (non individuo).

**Q: Quanti requisiti dobbiamo implementare?**

A: Guideline:

- 100% requisiti obbligatori (RF e RNF critici)
- 50-70% requisiti desiderabili
- 0-20% requisiti opzionali

L'MVP deve essere **utilizzabile e dimostrabile**, non completo al 100%.

**Q: Possiamo cambiare tecnologie rispetto al PoC?**

A: **Sì, ma con motivazione forte**:

- ✅ Se PoC ha rivelato limitazioni critiche
- ✅ Se proponente lo richiede esplicitamente
- ❌ Solo perché "vogliamo provare qualcosa di nuovo"

Ogni cambio va motivato nella Specifica Tecnica.

**Q: L'MVP deve essere deployato su cloud?**

A: **Dipende dal capitolato**:

- Se richiesto esplicitamente → Sì, deployment production-like
- Se opzionale → Deployment locale accettabile per PB, cloud per CA
- In ogni caso → Documentare strategia deployment in ST

### 11.2 Domande Tecniche

**Q: Serve implementare autenticazione completa?**

A: Se autenticazione è requisito obbligatorio → **Sì**, implementazione completa:

- Registrazione + Login + Logout
- Password hashing (bcrypt/argon2)
- Session management o JWT
- HTTPS in produzione

Non accettabili: "TODO auth", autenticazione mockup.

**Q: Quanto dettagliati devono essere i diagrammi UML?**

A: **Specifica Tecnica** (PB):

- Diagrammi classi: solo classi principali e interfacce pubbliche
- Metodi: solo quelli pubblici e significativi
- NO getter/setter banali
- NO dettagli implementativi

**Definizione di Prodotto** (post-PB):

- Diagrammi classi: TUTTE le classi
- TUTTI i metodi (pubblici e privati)
- Attributi con visibilità
- Dettagli implementativi

**Q: Serve Continuous Integration (CI)?**

A: **Fortemente consigliato**:

- Dimostra professionalità
- Facilita testing automatizzato
- Previene regressioni

Setup minimo: GitHub Actions con lint + test.

**Q: Quanto deve essere buono il frontend/UI?**

A: MVP richiede UI **funzionale e usabile**, NON bella esteticamente:

- ✅ Layout chiaro e navigabile
- ✅ Responsive (se requisito)
- ✅ Accessibilità base
- ❌ NON serve design perfetto pixel-perfect
- ❌ NON servono animazioni elaborate

Focus: **usabilità > estetica**.

### 11.3 Domande su Documentazione

**Q: Specifica Tecnica: quante pagine?**

A: NON c'è limite fisso:

- **Minimo**: 40-50 pagine
- **Ottimale**: 60-80 pagine
- **Massimo**: 100-120 pagine

Priorità: **completezza e chiarezza > lunghezza**.

**Q: Serve scrivere Manuale Utente per PB?**

A: **NO** per PB (a meno che sia richiesto esplicitamente).

Il Manuale Utente è richiesto per:

- Revisione di Qualifica (RQ)
- Customer Acceptance (CA) se opzionale intrapresa

Per PB: README.md con istruzioni setup è sufficiente.

**Q: Possiamo riutilizzare sezioni della Specifica Tecnica in altri documenti?**

A: **Sì**, purché:

- Si eviti copia-incolla integrale (riassumere se necessario)
- Si mantengano riferimenti incrociati (es. "vedi ST sezione X")
- Non ci siano contraddizioni tra documenti

### 11.4 Domande su Testing

**Q: I test devono essere automatizzati o manuali vanno bene?**

A: **Entrambi**, ma con priorità:

1. **Unit e Integration tests**: DEVONO essere automatizzati
2. **System tests funzionali**: Automatizzati preferibile, manuali accettabili
3. **Usability testing**: Tipicamente manuale

**Q: Coverage 70% significa 70% di tutto il codice?**

A: **NO**. Coverage si riferisce a:

- Business logic: target 80-90%
- Controllers/API layer: target 70-80%
- Models/Entities: target 60-70%
- Configuration/Boilerplate: può essere < 50%

**Priorità**: testare codice critico e complesso, non banale boilerplate.

**Q: Serve fare performance testing per PB?**

A: **Solo se ci sono requisiti non-funzionali espliciti** di performance.

Se RNF dice "response time < 500ms" → **Sì**, va misurato e documentato.

Altrimenti: performance testing opzionale per PB, più importante per CA.

---

## 12. Customer Acceptance (CA) - Opzionale

### 12.1 Cos'è la Customer Acceptance

La **Customer Acceptance (CA)** è una revisione **opzionale** che permette di:

- Ottenere **bonus** sul voto finale
- Dimostrare capacità di delivery prodotto completo
- Validare prodotto con proponente reale
- Raggiungere stato SEMAT "Ready"

**IMPORTANTE**: La CA NON è obbligatoria. Molti gruppi terminano alla PB.

### 12.2 MVP per CA vs MVP per PB

|Aspetto|MVP per PB|MVP per CA|
|---|---|---|
|**Stato SEMAT**|Usable|Ready|
|**Copertura requisiti**|60-80% obbligatori|90-100% obbligatori + desiderabili|
|**Documentazione Utente**|Opzionale|Obbligatoria (Manuale Utente v1.0.0)|
|**Deployment**|Staging/local|Production-like|
|**Acceptance Test**|Interni|Con proponente|
|**Bug critici**|Risolti|Tutti risolti + bug medio-bassi|

### 12.3 Artefatti Aggiuntivi per CA

Per la CA servono documenti aggiuntivi:

|Artefatto|Versione|Nuovo?|
|---|---|---|
|Norme di Progetto|v3.0.0|Aggiornato|
|Piano di Progetto|v3.0.0|Aggiornato (consuntivo finale)|
|Piano di Qualifica|v3.0.0|Aggiornato|
|**Manuale Utente**|v1.0.0|**SÌ - Nuovo**|
|**Manuale Sviluppatore**|v1.0.0|**Opzionale**|
|Definizione di Prodotto|v1.0.0|Opzionale (dipende da complessità)|

### 12.4 Obiettivi CA

1. **Valutare bontà visione iniziale**
    
    - Il prodotto risolve problema del proponente?
    - Le scelte architetturali erano corrette?
2. **Consentire uso esplorativo**
    
    - Proponente può usare il sistema autonomamente
    - Documentazione utente è chiara e completa
    - Sistema è stabile e affidabile
3. **Permettere futuri avanzamenti**
    
    - Codice è mantenibile
    - Architettura permette estensioni
    - Documentazione tecnica completa per nuovi sviluppatori

### 12.5 Quando Fare la CA

**Consigliato fare CA se**: ✅ Team ha tempo e risorse (+ 4-6 settimane post-PB) ✅ Proponente è disponibile per testing/feedback ✅ Obiettivo è voto > 28/30 ✅ Capitolato è interessante e si vuole prodotto completo

**NON consigliato se**: ❌ Team in ritardo o sotto stress ❌ Proponente poco disponibile ❌ Voto PB già soddisfacente ❌ Capitolato troppo ambizioso per completare bene

### 12.6 Valutazione CA

**Vardanega valuta**:

- Completezza prodotto
- Soddisfazione proponente
- Qualità manuale utente
- Usabilità sistema

**Bonus possibile**: +1 / +2 punti sul voto finale (dipende da anno/regolamento).

---

## 📚 Riferimenti e Risorse

### Documenti Ufficiali

- ISO/IEC 25010 (Software Quality)
- IEEE 1016 (Software Design Descriptions)
- SEMAT Kernel (Software Engineering Essentials)

### Materiale Didattico

- Dispense Prof. Vardanega (progettazione, architettura)
- Materiale Prof. Cardin (design patterns, qualità codice)
- Repository gruppi anni precedenti (Error-418, SWEasabi, tommasocarraro)

### Libri Consigliati

- "Design Patterns: Elements of Reusable Object-Oriented Software" (Gang of Four)
- "Clean Architecture" (Robert C. Martin)
- "Software Engineering" (Ian Sommerville)

### Risorse Online

- [Refactoring Guru - Design Patterns](https://refactoring.guru/design-patterns)
- [Martin Fowler - Enterprise Application Architecture](https://martinfowler.com/eaaCatalog/)
- [Microsoft - Architecture Patterns](https://docs.microsoft.com/en-us/azure/architecture/patterns/)

---

## 📝 Note Finali

Questa guida è stata creata per aiutare gli studenti del corso di Ingegneria del Software dell'Università di Padova a comprendere e realizzare un MVP di qualità per la Product Baseline.

**Ricordate i principi chiave**:

- L'MVP è un **prodotto reale utilizzabile**, non un prototipo
- L'architettura deve essere **definitiva e scalabile**
- La qualità del codice è **fondamentale** (production-ready)
- Il testing deve essere **completo e automatizzato**
- La documentazione tecnica deve essere **chiara e dettagliata**

**Differenza critica PoC vs MVP**:

```
PoC:  "Possiamo costruirlo?" → Dimostrazione fattibilità
MVP:  "Funziona davvero?"     → Prodotto utilizzabile
```
