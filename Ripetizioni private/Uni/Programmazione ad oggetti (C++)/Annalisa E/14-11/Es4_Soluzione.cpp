// Cosa stampa il Main?

class N;

class Smart {
public:
    N* p;
    Smart(N* q = 0): p(q) {if(p) p->counter++; cout << "Smart() ";}
    Smart(const Smart& x): p(x.p) {if(p) p->counter++; cout << "SmartCopy() ";}
    ̃Smart() {
    if(p) {
        p->counter--; if(p->counter==0) delete p;
    };
    cout << " ̃Smart() ";
    }
    operator bool() {return p!=0;}
    Smart& operator=(const Smart& x) {
        Smart t = *this;
        p = x.p; if(p) p->counter++;
        cout << "Smart= ";
        return *this;
    }
    N* operator->() {return p;}
    bool operator==(const Smart& x) {return p==x.p;}
    bool operator==(N* x) {return p==x;}
};

class N {
public:
    string s;
    int counter;
    Smart next;
    N(string x, const Smart& y) : s(x), counter(0), next(y) {cout << "N() ";}
    ̃N() {cout << " ̃N ";}
};

class C {
public:
    Smart punt;
    C(string s="BIANCO"): punt(new N(s,0)) {}
    void add(string s) {punt = new N(s,punt);}
    void modify() {
        if(punt && punt->next) punt->next = (punt->next)->next;
    }
    void print() {
        while(punt) { cout << punt->s << " "; punt=punt->next; }
    }
};
main() {
    C c1; cout << " **0" << endl; /* Smart() Smartcopy() N() Smart() ~Smart() ->
    Invochiamo costruttore a 0 parametri (r.40) passando valore di default, a seguire chiamiamo costruttore N con 2 parametri stringa e riferimento a 
    smart (r.33), quindi serve conversione di tipo da intero a smart, quindi chiamamo costruttore smart (r.8), stampando cosi Smart();

    Ora si entra nel costruttore di N con parametro smart temporaneo, segue la lista di inizializzazione, seguendo l'ordine nel quale appiaono 
    nella classe, che stamperà solo Smartcopy per via della chiamata del costruttore di copia next (r.9);

    Si entra nel corpo del costruttore di N e stampa N();

    Inizializzazione di punt (r.40) che e' smart (r.8) per stampare ancora Smart();

    Distrutto il valore smart temporaneo, quindi stampa ~Smart();
    */
    C c2("ROSSO"); cout << " **1" << endl; /* Smart() Smartcopy() N() Smart() ~Smart() ->
    Stesso procedimento di prima, anziche' usare parametro di default, si passa ROSSO
    */
    C c3(c2); cout << " **2" << endl; /* Smartcopy() ->
    Costruisco oggetto C partendo da un ogetto C, quindi usiamo costruttore di copia, ma dato che non c'è, viene usato quello di default dove tutti 
    i campi della classe vengono inizializzati copiando dai campi dell'oggetto passato (r.9)
    */
    c3.add("VERDE"); cout << " **3" << endl; /* Smartcopy() N() Smart() Smartcopy() Smart= ~Smart() ~Smart() ->
    Chiamato metodo add, che crea nuovo N con VERDE e come punt il punt corrente, sta aggiungendo un nuovo valore all'inizio della lista concatenata. 
    Viene chiamato il costruttore di N (r.33) dove gli passiamo uno smart, quindi no valori temporanei, quindi viene chiamato il costruttore di copia per 
    next (r.9), che stampera' Smartcopy();

    Nel corpo di N, stampiamo N(), no distruttore perche' non c'erano temp;

    Nell'assegnazione punt=new... viene richiamato l'operatore a r.17-21, e vuole un riferimento a smart in input, pero' stiamo passando un puntatore a 
    nodo, quindi verrà creato un valore temp. (r.8), dunque stamperemo Smart();

    alla r.18 chiamamiamo costruttore copia, quindi stampiamo Smartcopy();

    Alla r.20 stampiamo Smart=;

    Alla fine verra' eliminato t, quindi stampera' ~Smart();

    Viene anche eliminato l'elemento per la conversione di tipo da N a smart, quindi stampiamo ancora ~Smart();

    */
    c3.add("BLU"); cout << " **4" << endl; /* /* Smartcopy() N() Smart() Smartcopy() Smart= ~Smart() ~Smart() ->
    Stessa procedura dell'istruzione precedente
    */
    c3.modify(); cout << " **5" << endl; /* Smartcopy() Smart= ~Smart() ->
    Con l'operatore bool (r.16), se punt ed il suo elemento next esistono, tolgono l'elemento next in mezzo
    L'assegnazione punt->next=... richiama l'operatore smart (r.17), costruendo smart t e stampando Smartcopy();

    Stampiamo Smart=;

    Cancelliamo t, quindi stampa ~Smart();
    */
    c1=c3; cout << " **6" << endl; /* Smartcopy() Smart= ~Smart() ->
    Assegnazione implicita di 2 oggetti già inizializzati, quindi verra' chiamata l'assegnazione di default e non il costruttore di copia,
    quindi chiamo operatore Smart (r.17), quindi Smartcopy();

    Stampo Smart=;

    Cancello t quindi ~Smart()
    */
    c1.print(); cout << " **7" << endl; /* -> BLU Smartcopy() Smart= ~Smart() ROSSO Smartcopy() Smart= ~Smart()
    */
    c2.print(); cout << " **8" << endl; /* -> ROSSO Smartcopy() Smart= ~Smart()
    */
    c3.print(); cout << " **9" << endl; /* -> BLU Smartcopy() Smart= ~Smart() ROSSO Smartcopy() Smart= ~Smart()
    */
}
    // Al suo termine, il programma stamperà, per aver eliminato c1,c2,c3 -> ~Smart() ~Smart() ~Smart()