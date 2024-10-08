Siano A, B, C, D, E cinque diverse classi polimorfe.

Si considerino le seguenti definizioni:

template<class X, class Y>
const X* fun(X& r){
    const X* ptr = &r; return dynamic_cast<Y*>(ptr);
}

int main(){
    B b; C c; D d; E e;
    if (fun<A,B>(c) == nullptr) cout << "Bjarne" << endl;
    if (dynamic_cast<C*>(&b) == nullptr) cout << "Stroustrup" << endl;
    const A* p = fun<D,B>(d);
    const D* q = fun<E,B>(e);
    fun<C, D> (d);
}

Si supponga che:
- il main compili correttamente senza errori runtime/undefined behavior;
- l'esecuzione del main provochi la stampa di "Bjarne Stroustrup".

Quali delle seguenti affermazioni sono vere sulle relazioni di sottotipo T1<=T2:

A <= B 
A <= C 
A <= D
A <= E
B <= C
B <= D
B <= E
C <= D
C <= E
D <= E