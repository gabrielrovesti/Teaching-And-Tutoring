#include "IntMod.h"

// struttura richiamo metodi

// tipo NomeClasse::nomeMetodo(parametri) eventuale const

int IntMod::getmodulo(){
    return n;
}

int IntMod::operator+(int a) const{
    return abs(a + n);
}

int IntMod::operator*(int a) const{
    return abs(a * n);
}

IntMod::operator int() const{
    return n;
}

// meglio usare riferimenti costanti (vedrai) per evitare di sprecare memoria
void IntMod::setmodulo(const IntMod& x){
    n = x.n;
}

