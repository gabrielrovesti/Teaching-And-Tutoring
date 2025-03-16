#include <iostream>

// Modellazione / Funzione

// Ti dà la gerarchia

class A{
    // poliformismo = virtual / override
    
    // classe polimorfa (gestisce gli oggetti una sola volta)
    public:
    virtual ~A() {};
};

class B: public A{
    public:
        // astratto = virtuale puro
        virtual void method() = 0;
};

class C: public B{
    public:
    // concreto -> ridefinizione (overriding) - ridefinizione con virtual stesso nome / stessi parametri

        virtual void method() override;
        // override = rendere visibile a chi programma il polimorfismo
};

class D: virtual public C{
    private:
        int x;
    protected:
        D(int x1): x(x1) {} // costruzione dei soli sottooggetti = protected
};

class E: public D{
// classe E deriva da D
// comportamento standard dice: richiama l'assegnazione delle superclassi dirette -> in questo caso public D

// se ci fosse stato ad es. E: public B, public C
// allora chiamo sia operator= di B e di C

// :: (scoping) = Richiamo la roba pubblica di qualcun altro

    // Operatori (+, -, <<, ==, !=, =)

    // Assegnazione standard (=)
    // Uso: E e; e = f;

    E& operator=(const E& e){
        // In esame (comportamento standard)
        D::operator=(e); 
        return *this; // this = puntatore di riferimento (= qua dentro punta ad E)        
    }
};


/*

Gerarchia attuale

        A
        |
        B
        |
        C
      /  
    D
    |
    E

Ereditarietà multipla = problema del diamante
        A
    B       C
        D

Problema: D da chi deriva? Da B o da C?

Soluzione: class D: virtual public B, virtual public C

*/

