Siano A, B, C, D, E cinque diverse classi polimorfe.

Si considerino le seguenti definizioni:

template<class C, class D>
const C* fun(C& r){
    const C* ptr = &r; return dynamic_cast<D*>(ptr);
}

int main(){
    B b; C c; D d; E e;
    if (fun<A,B>(c) == nullptr) cout << "Bjarne" << endl; // C <= A Vero, B <= A Falso, A <= C Falso, A <= B Falso
    if (dynamic_cast<C*>(&b) == nullptr) cout << "Stroustrup" << endl; // B <= C Falso
    const A* p = fun<D,B>(d);   // D <= A Vero, A <= D Falso, D <= B Vero/Possibile, A <= E Falso
    const D* q = fun<E,B>(e);   // E <= D Vero, E <= B Vero/Possibile, D <= E Falso
    fun<C,D>(d);    // C <= D Falso, B <= C Falso, B <= D Vero, B <= E Possibile, C <= E Falso

}

// Osservazioni:
// (1) TS - TD
// (2) Se vanno bene o meno i cast (bad_cast/nullptr/va bene)
    // Male: !dynamic_cast // dynamic_cast () == nullptr/0 // if(dynamic_cast) bad_cast()
// (3) Il discorso dei template (sottotipo il parametro passato tra parentesi)
// (4) Disegno della gerarchia in contemporanea

/*
    A    
    | \
    C  D  
       |
       E  B 

*/

Si supponga che:
- il main compili correttamente senza errori runtime/undefined behavior;
- l'esecuzione del main provochi la stampa di "Bjarne Stroustrup".

Quali delle seguenti affermazioni sono vere sulle relazioni di sottotipo T1<=T2:

A <= B Falso
A <= C Falso
A <= D Falso
A <= E Falso
B <= C Falso
B <= D Vero
B <= E Possibile
C <= D Falso
C <= E Falso
D <= E Falso