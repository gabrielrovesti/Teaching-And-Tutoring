#include <iostream>
#include <list>
#include <vector>

using namespace std;

class QSize {
public:
    int width, height;
    QSize(int w = 0, int h = 0) : width(w), height(h) {}
    bool isValid() const { return width > 0 && height > 0; }
    bool isEmpty() const { return width == 0 || height == 0; }
    bool operator==(const QSize &other) const {
        return width == other.width && height == other.height;
    }
};

class QWidget {
public:
    virtual ~QWidget() {}
    // Metodo sizeHint restituisce una QSize (valore fittizio per l'esempio)
    virtual QSize sizeHint() const { return QSize(100, 100); }
    // Metodo clone() per creare una copia dell'oggetto. In Qt non esiste di default.
    virtual QWidget* clone() const { return new QWidget(*this); }
};

class QAbstractButton : public QWidget {
public:
    virtual ~QAbstractButton() {}
};

class QCheckBox : public QAbstractButton {
public:
    virtual ~QCheckBox() {}
};

class QPushButton : public QAbstractButton {
public:
    virtual ~QPushButton() {}
};

class QAbstractSlider : public QWidget {
public:
    virtual ~QAbstractSlider() {}
};

vector<QAbstractButton*> fun(list<QWidget*>& lst, const QSize& sz, vector<const QWidget*>& w) {
    // Vettore risultato che conterrà i QAbstractButton come richiesto al punto (c)
    vector<QAbstractButton*> ret;
    
    // Iteriamo sulla lista di input senza ++it nel for
    for(auto it = lst.begin(); it != lst.end();) {
        cout << "\n--- Nuova iterazione ---" << endl;
        
        // Salviamo il puntatore corrente
        QWidget* p = *it;
        
        // Verifico se il puntatore è nullo 
        if(!p) {
            cout << "Puntatore nullo, passo al prossimo" << endl;
            ++it;
            continue;
        }
 
        cout << "Analizzo elemento di tipo: " << typeid(*p).name() << endl;
        cout << "SizeHint: (" << p->sizeHint().width << "," << p->sizeHint().height << ")" << endl;
        
        bool rimosso = false; // Flag per tracciare se l'elemento viene rimosso al punto (b)
        
        // Punto (a): se ha sizeHint == sz, inserisco copia in w
        if(p->sizeHint() == sz) {
            cout << "(a) SizeHint corrisponde, creo copia e inserisco in w" << endl;
            w.push_back(p->clone());
        }
        
        // Punto (b): se non è slider e ha sizeHint == sz, rimuovo e dealloco
        if(p->sizeHint() == sz && !dynamic_cast<QAbstractSlider*>(p)) {
            cout << "(b) Non è slider e SizeHint corrisponde, rimuovo e dealloco" << endl;
            delete p;
            it = lst.erase(it);
            rimosso = true;
            continue; // Vado al prossimo elemento
        }
        
        // Punto (c): se non rimosso in (b) e è CheckBox/PushButton, sposto in ret
        if(!rimosso && (dynamic_cast<QCheckBox*>(p) || dynamic_cast<QPushButton*>(p))) {
            cout << "(c) È CheckBox/PushButton, sposto nel vettore risultato" << endl;
            ret.push_back(dynamic_cast<QAbstractButton*>(p));
            it = lst.erase(it);
            // --it; Compenso il ++it del for (EQUIVALENTE A)
        }
        
        // Se non ho fatto erase, incremento manualmente
        // ++it (EQUIVALENTE al fatto che dobbiamo riposizionare l'iteratore)
    }
    
    cout << "\nFine funzione: " << ret.size() << " bottoni nel risultato" << endl;
    return ret;
 }

int main() {
    // Creiamo la lista di test con diversi tipi di widget
    list<QWidget*> lst;
    vector<const QWidget*> w;
    
    cout << "Creazione oggetti di test...\n";
    
    // Aggiungiamo vari tipi di widget
    lst.push_back(new QWidget());       // QWidget 
    lst.push_back(new QCheckBox());     // QCheckBox
    lst.push_back(new QPushButton());   // QPushButton
    lst.push_back(new QAbstractSlider()); // QSlider
    
    cout << "\nStato iniziale:";
    cout << "\n- Lista contiene: " << lst.size() << " elementi";
    
    // Creiamo una QSize uguale a quella di default (100,100)
    QSize sz(100, 100);
    
    // Chiamiamo fun
    cout << "\n\nChiamo fun()...\n";
    vector<QAbstractButton*> risultato = fun(lst, sz, w);
    
    // Verifichiamo i risultati
    cout << "\nRisultati:";
    cout << "\n- Bottoni nel vettore risultato: " << risultato.size();
    cout << "\n- Elementi rimasti nella lista: " << lst.size();
    
    // Cleanup
    cout << "\n\nPulizia memoria...\n";
    for(auto p : lst) {
        delete p;
    }
    for(auto p : risultato) {
        delete p;
    }
    
    cout << "\nTest completato.\n";
    return 0;
}