// Assegnazione standard
// utilizzare l'assegnazione della superclasse diretta
// /delle superclassi diretta

class Z
{
private:
    int x;
};

class B
{
private:
    Z x;
};

class C
{
private:
    Z z;
};

class D : public B, public C
{
private:
    Z y;
    int *p;

public:
    // assegnazione standard

    // assegnare tutti i campi (y)
    // e controllare di non fare interferenza

    D &operator=(const D &d)
    {
        // chiamiamo l'assegnazione della (B) o delle (C, B)
        B::operator=(d);
        C::operator=(d);
        // assegno i sottocampi
        y = d.y;
        p = d.p;
        return *this;
    }

    // copia standard

    // costruisco di copia un sottooggetto classe(variabile)
    // poi i campi variabile(riferimento.variabile)
    D(const D &d) : B(d), C(d), y(d.y), p(d.p) {}
};