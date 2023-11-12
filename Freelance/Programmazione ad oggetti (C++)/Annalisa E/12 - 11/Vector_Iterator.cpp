//LIBRERIA STANDARD - STL (STANDARD TEMPLATE LIBRARY)

std::vector<int> v1; // vettore di interi

// Strutture dati

- vector
- list
- stack 

// Vector is megl che il resto -> vector è migliore di tutti

// Ha un insieme di operazioni 

// Iteratori -> puntatori agli oggetti di vector

// Esempio di iteratori
int* // - fa side effects

vector<int>::iterator it; // iteratori di vector di interi
it.begin(); // puntatore al primo elemento
it.end(); // puntatore all'ultimo elemento

// Const_iterator
const int* // non fa side effects (ci sarà un tipo const*)

vector<int>::const_iterator it; // iteratori di vector di interi

// Come inserire i valori in vector

vector<int> v1; // vettore di interi
v1.push_back(1); // inserisce in coda gli elementi

// Come cancellare i valori in vector
vector<int> v2; // vettore di interi

for(int i = 0; i < 10; i++)
    v2.push_back(i);
for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    cout << *it << endl;
// it = v2.erase(it);
// v2.erase(it);

// Utilizzo

// (1) Esercizi Funzione 
// ti viene data una gerarchia e devi controllare tutti gli if
// (vector con operazioni quali push_back e poi polimorfismo)

// (2) Esercizi Modellazione
// ti viene data una gerarchia e devi implementare fisicamente la classe e tutti i metodi

// Esempio di utilizzo "verboso" di iterator
vector<QWidget> fun(const vector<const QPaintDevice*>&)

    for(vector<const QPaintDevice*>::const_iterator it = v.begin(); it != v.end(); it++)

}

// Usiamo "auto" per far capire direttamente il contesto del tipo
vector<QWidget> fun(const vector<const QPaintDevice*>&)

    for(auto it = v.begin(); it != v.end(); it++)

}

// Algoritmi (senso = alternativa per fare i for)
// #include <algorithm>
for_each(v.begin(), v.end(), [](int x) { cout << x << endl; }); // stampa tutti gli elementi

// for range-based (C++ 17) - molto ottimizzato
for(auto x : v)
    cout << x << endl;