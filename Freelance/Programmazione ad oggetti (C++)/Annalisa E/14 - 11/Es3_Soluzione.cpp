// Cosa stampa ogni riga del Main?
#include <iostream>
using namespace std;
#include <string>
class Nodo;
 class Smart {
   friend class Lista;
 private:
   Nodo* punt;
 public:
   Smart(Nodo* p=0): punt(p) {} // costruttore di copia
    ̃Smart();
   bool operator==(const Smart& s) const {return punt==s.punt;}
   Nodo* operator->() const {return punt;}
   Smart& operator=(const Smart&);
};
 class Nodo {
   friend class Lista; friend class Smart;
 private:
   int x;
   Smart next;
 public:
   Nodo(int z =0, const Smart& n = 0): x(z), next(n) {}
   ̃Nodo() {cout << "  ̃N";} };
 Smart& Smart::operator=(const Smart& s) {
   Nodo* t = punt;
   punt = new Nodo(s->x);
   delete t;
   return *this;
 };
Smart:: ̃Smart() {if(punt) delete punt; cout << "  ̃S";}
 class Lista {
 private:
   Smart first;
 public:
   Lista() : first(0) {}
   Lista(int k): first(new Nodo(k)) {if(k>0) first->next = new Nodo(k+1);}
   void remove() {if(!(first==0)) first = first->next;}
};
 main() {
   Lista x1; cout << " **1\n"; // **1 -> Crea una lista usando il costruttore a 0 parametri, allocando "smart" (r.9) ma 
   //non stampa nulla
   
   Lista x2(5); cout << " **2\n"; // ~S ~S ~N ~S ~S ~S **2  -> "54" Apro e chiudo scope; chiama costruttore di lista con un 
   //parametro (r.35), poi chiama costruttore nodo ad un parametro (r.23)
   // poi chiamato costruttore di smart ad un intero (nello specifico ad un puntatore) (r.9) creando valore temporaneo, 
   //poi procediamo con le inizializzazioni a r.21
   //  poi entriamo nel corpo del costruttore: in first->next=... bisogna fare la conversione di tipo, quindi si 
   //richiama l'operatore smart (r.13), definito r.23-28,
   // creando un nuovo nodo che punta all'elemento corrente (r.25), poi il nodo temporaneo che puntava l'elemento corrente 
   //viene eliminato dal distruttore di Nodo(r.22), ma dato che era nullo
  //  Quando viene chiamato il distruttore di smart, chiama a sua volta il distruttore del nodo stampando ~N; quando il 
   //distruttore di una classe viene invocato, al suo termine vengono invocati
  // ricorsivamente anche i distruttori di tutti i campi che ha per valore in ordine inverso nel quale sono stati 
   //inizializzati; infine l'ultimo valore distrutto e' quello creato all'interno 
  // del costruttore di nodo come valore di default
   //~S per via del first new nodo temp. r37 ~S per via di new nodo (k+1) r.37 temp. ~N r.24 viene cancellato il nodo creato con new nodo
   // ~S distrutti i campi ridefiniti>next ~S distrutto ~S

   Lista* p = new Lista(3); cout << " **3\n"; //  ~S ~S ~N ~S ~S ~S **3 -> Stampiamo ~S perche viene creato il valore temp. 
   //all'interno di costruttore di nodo (r.21), finito first viene cancellato ; nel corpo del 
   //corpo del distruttore di lista eseguiamo l'espressione creando un nuovo nodo, causando la creazione di uno smart temp. (r.21),
   //poi esegue first->next che e' di tipo smart perche l'operatore ->
   // ritorna un * (r.12), poi viene dereferenziato ed il nodo next e' di tipo smart, dato che i 2 tipi non coincidono pero' 
   //esiste un tipo di conversione, viene chiamato r.9 con new Nodo(k+1); 
   
   delete p; cout << " **4\n"; // ~N ~N ~S ~S ~S **4 -> P punta riga con 2 nodi, cancella poi una lista, chiamando il distruttore di lista che non è ridefinito, quindi chiama quello di default (r.34), siamo in r.31, punt non e' nullo
   // cancellando punt, che esso a sua volta e' un nodo, invocando cosi il distruttore di nodo (r.24), ricorsivamente chiama i distruttori dei suoi campi in ordine inverso, quindi smart (r.31), dove punt contiene qualcosa (4)
   // cancellando nodo 4, distruttore di nodo invocato; poi chiama distruttore nextr che e' smart, che ha il valore di default, putnatore nullo; poi si torna al distruttore di smart, per finire con la chiamata implicita 
   // dell'istruttore di lista
   
   Lista x3(0); cout << " **5\n"; // ~S **5 -> creata lista con valore 0, quindi nel costruttore (r.37), viene eseguito solo first, dove crea il nuovo nodo (r.) passato come temporaneo per poi essere eliminato (r.23)
   
   x2.remove(); cout << " **6\n"; // ~S ~S ~N ~S ~S ~S **6 -> chiamato remove(r.38), confronto tra interi che non sono 
   //compatibili, quindi serve conversione di tipo, assegnando un val temporaneo da 0 in smart, effettuato il confronto che da false
   // poi viene eliminato il temp., si entra nel corpo dell'if, essendo due valori smart, non viene creato elemento temp.,
   //si entra in r.31, creato elemento temp. e distrutto successivamente; delete t causa chiamata distruttore
   // di nodo, poi chiama distruttore del suo next, a sua volta chiama distruttore del suo elemento
}