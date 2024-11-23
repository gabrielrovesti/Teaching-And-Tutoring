// Gerarchia

/*

        Auto        
    /           \
Utilitaria      SUV
    |
    Mini

*/

// TS (prima dell'uguale) - TD (dopo l'uguale) (RTTI)

Auto *a = new Mini(); // possiamo andare sotto

// static_cast
// dynamic_cast (safe downcasting) - da una classe superiore vado giù

Utilitaria *u = dynamic_cast<Utilitaria*>(a);

// Mini = sottooggetto = costruito con il tipo padre = Auto/Utilitaria


// Quesito 2 - Esame 2016 (Gerarchia)

class A{
    private:
        int x;
    public:
        int method(); 
};

class B: public A{
    public:
        virtual int method();
        // virtual int method() override;
        // override = annotazione per ricordarti di stare sovrascrivendo un metodo con l'ereditarietà (come virtual)

};

//      A
//   /     \
//  B       C
//    \    /
//      D

// Multiple inheritance = ereditarietà multipla = da chi derivo da B e c (problema del diamante)

// polimorfismo = virtual

class A{
    public:
    // distruttore virtuale polimorfo
    virtual ~A(); 
    // default
};

// virtual 
// concreto
// astratto = virtual tipo nome() = 0;
class B: public A{
    public:
        virtual int method() = 0;
        // "contratto" polimorfo = astrazione garantisce che qualcuno lo implementi = vogliamo che le sottoclassi implementino metodi/cose, ma non noi (lo lasciamo fare agli altri - ecco perché "contratto")

        // astratto = non scriviamo il corpo qui
};
// classe astratta = ha almeno un metodo astratto

class C: public B{
    public:
        virtual int method(){
            return 5;
        }
};
// classe concreta = implementa un metodo astratto (overriding usando il metodo)

// C per contratto implementa il metodo astratto di B

class D: virtual public B, virtual public C{}{
    private:
        int x;
    protected:
        // chi è all'esterno non vede, ma le sottoclassi si = solamente i sottooggetti di D ma non permette la costruzione pubblica all'esterno della gerarchia
        D(int num): x(num) {};
};

// EXAMPLES

/*
        A
    B       C
        D
*/

class A{};
class B: public A{};
class C: public A{};
class D: public B, public C{};

// problema: da chi deriviamo? (diamante)

// soluzione: usiamo virtual!


class A{};
class B: public A{};
class C: public A{};
class D: virtual public B, virtual public C{};

/*
        A
    /       \
    B       C
    \      /
      \  /
        D
        |
        E
Legenda:
Ereditarietà multipla (a trattini)
Ereditarietà "normale" (un trattino dritto)
*/

// costruzione (da sinistra) costruendo una volta sola

// A (classe base)
// B (prima classe da sx)
// C (seconda classe da dx)
// D (lui stesso)

// static_cast = assicura che se ho un sottotipo, posso tornare almeno ai tipi statici (se sono D, posso tornare "safe" su C e su B)

// COMING BACK TO THE EXERCISE....

/*

        A
    /       \
    B       C
    \      /
      \  /
        D
        |
        E

*/
class E: public D{
    // assegnazione ridefinita con comportamento standard
    E operator=(const E& e){
        D::operator(e); // assicuriamo che i sottooggetti siano costruiti almeno con tutti i costruttori delle classi dirette (E è almeno D)

        x = e.x;    // assegno i campi

        return *this;
        // rif. esercizi "Ridefinizioni standard

    }

    // class E: public C, public D
    // E operator=(){
    // C::operator(e), D::operator(e)}
    // Usiamo SOLO le classi dirette
};

// Funzione 1/2/2022

// vector = container più efficiente
// iterator = scorre il vector puntando (*) a quello che c'è dentro il vector
// const_iterator = scorre il vector puntando (*) all'oggetto costante (const tipo* )

// push_back/push_front = metodi di inserimento

// uso pratico tipo template = dire che tipo hanno i vector (container)
vector<QWidget> fun(const vector<const QPaintDevice*>& v){

    // per ogni puntatore p contenuto nel vector v:
    for(auto it = v.begin(); it != v.end(); ++it){
        // – se p punta ad un oggetto che e un ` QWidget con altezza > 50 pixel allora lancia una eccezione di tipo QString che rappresenta la stringa “TooBig”;

        // dynamic_cast al tipo costante (1)
        QWidget* w = dynamic_cast<const QWidget*>(*it);
        // togliere il const -> const_cast
        QWidget* w = dynamic_cast<QWidget*>(const_cast<QPaintDevice*>(*it));
        // QPaintDevice è la classe padre: const_cast assicura che, convertendo al tipo statico, la conversione sotto (dynamic_cast) funzioni

        if(w && w->height() > 50){  // un metodo che trova l'altezza = leggo la gerarchia e trovo height();
            throw QString("TooBig");    // lancia eccezione = throw
        }

        // – se p punta ad un oggetto obj che e un ` QWidget con altezza ≤ 50 pixel che detiene il keyboard focus allora toglie il keyboard focus a obj;
        if(w && w->height() <= 50){
            // un metodo che trova l'altezza = leggo la gerarchia e trovo clearFocus();
            w->clearFocus();
        }

        // – se p punta ad un oggetto obj che e un ` QAbstractButton allora setta l’etichetta testuale di obj alla stringa “Pulsante”.

        QAbstractButton* qab = dynamic_cast<QAbstractButton*>(const_cast<QPaintDevice*>(*it));
        // conversione ad QAbstractButton
        if(qab) qab->setText("Pulsante");
    }
    // for (auto it: v){} - range-based / alternativa
    
    // soluzione completa - scorrimento
    for(const vector<const QPaintDevice*>::const_iterator cit = v.begin(); cit != v.end(); ++cit) // masochismo!

    // vector()::iterator oppure vector()::const_iterator
}