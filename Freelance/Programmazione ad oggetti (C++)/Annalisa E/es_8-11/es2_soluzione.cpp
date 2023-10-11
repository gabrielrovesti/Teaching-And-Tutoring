//Cosa stampa?

#include <iostream>
using namespace std;
class C {
 public:
   C(int x=6): k(x) {cout << k << " C01 ";}
   C(const C& x): k(x.k) {cout << k << " Cc ";}
   C& operator=(const C& x) {return *this; cout << "C= ";}
   int k;
 };
 class D {
 public:
   D(): z2(8) {cout << "D0 ";}
   D(const D& x): z1(x.z1.k) {cout << "Dc ";}
   D& operator=(const D& x) {z1=x.z1; z2=x.z2; return *this; cout << "D= ";}
   C* getUno() {return &z1;}
   C z1, z2;
 };
 class E {
 public:
   E(D x) {y=x; cout << "E(D) ";}
   E(const E& x) {cout << "Ec ";}
   E& operator=(const E& x) {cout << "E= ";return *this;}
   D y;
   static C x;
};
C E::x = 9;
 int main() {
   cout << "**1\n"; // 9 C01 9 Cc-> Costruito oggetto anonimo (r.7), poi viene chiamato il
   // costruttore di copia (r.8) e assegnato ad x (r.28)
   C c(7); cout << "**2\n"; // 7 C01 -> Chiamata espl. al costruttore C
   D d; cout << "**3\n"; // 6 C01 8 C01 D0 -> Creo un D (r.14), inizializza prima z1 poi z2 (r.18)
   // con il costruttore D (r.7)
   c = *(d.getUno()); cout << "**4\n"; // "" -> richiama getUno (r.17) ritornando z1 per rif.,
   // poi lo deferenzia e fa assegnazione a c. NB tutto ciò che sta dopo il return non viene considerato
   c = d.z1.k; cout << "**5\n"; // 6 C01 -> Viene preso il valore k attraverso il costruttore di C (r.7),
   // creando il nuovo oggetto avremmo assegnato 6
   E e1(d); cout << "**6\n"; // 6 C01 6 C01 Dc 6 C01 8 C01 D0 E(D) ->Viene richiamato il costruttore E (r.22), 
   prende un parametro per valore, quindi chiama costruttore di copia D (r.15)
   // costruendo z1 con il parametro x che è a sua volta il valore d(=6), poi costruisce z2, chiamando il
    costruttore C; ora si creano tutti i campi dati della classe E
    
   // non statici, chiamando costruttore D (r.25), arrivando al corpo del costruttore E
   E e2 = e1; cout << "**7\n"; // 6 C01 8 C01 D0 Ec -> Chiamato costruttore copia di E (r.23) e creato oggetto y, poi richiamati
   // i costruttori di C e D
   e2 = e1; cout << "**8"; // E= -> Chiamato operatore E& (r.24)
}
