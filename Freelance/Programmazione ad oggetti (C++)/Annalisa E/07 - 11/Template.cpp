// Template = Modello "generico"

// T = tipo generico (segnaposto) che viene sostituito dalla chiamata
// Metto "class T" quando non ho il tipo
template<class T1, class T2>
T min(int a, T b){
    return a < b ? a : b;
}

int main(){
    int i; double d;
    // deduzione dell'argomento
    e = min(d,i);
}

// Uso "reale" dei template
// Modellare qualcosa che "è riutilizzabile in più contesti"

class QueueInt{
    void add(const int&);
};

class QueueString{
    void add(string);
};

// Evitare di duplicare codice creando qualcosa "che vada generalmente bene"

template<class T>
class Queue{
    void add(const T&);
}

// Inizializzazione esplicita valori template
template <int, int size = 1024>
class Esempio{};

Esempio<int, int> x;

template<class T>
class QueueItem{
    QueueItem(const T&);
    T info;
    QueueItem* next;

}

template<class T>
class Queue{
    public:
    Queue();
    ~Queue();
    private:
    QueueItem<T>* primo;
    QueueItem<T>* ultimo;
};

QueueItem<double> coda;
QueueItem q1(coda);

// friend = a una classe o ad un metodo permetto di vedere "il mio contesto"
// le variabili/i metodi, etc.
template<class T>
class C{
    private:
    T t;
    public:
    friend void method()(const T&); //amicizia associata 
}

// Associato = faccio parte del template
// Non associato = non faccio del template e non ho il permesso di entrare (friend)
    

// Ogni volta che noi abbiamo una classe o un metodo che fa parte di un template

// Conversioni
//  -> narrow (stretta) -> double verso int
//  -> wide (larga) -> int verso double

// Cast espliciti = conversioni esplicite
// Forzare una conversione

// static_cast = statico (sappiamo precisamente i tipi prima di convertire)

// Conversione stretta - cast<tipo>(variabile);
double d = 3.14;
int x = static_cast<int>(d);