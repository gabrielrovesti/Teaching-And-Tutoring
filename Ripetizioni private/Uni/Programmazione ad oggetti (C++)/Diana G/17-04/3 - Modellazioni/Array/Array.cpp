#include <iostream>
#include <vector>
#include <string>

class Empty{
    private:
        std::string msg;
    public:
        Empty(std::string s = "Empty") : msg(s) {}
};

template<class T>
class Array{
    // Intro e punto 1
    private:
        int dim = 0;
        T* arr;
        int cap = 0;
    public:  
    // Punto 2 - Costruttore default ridefinito
    Array(int k = 0, const T& t = T()):
    dim(k), cap(2 * k), arr(new T[2 * k]){
        for(int i = 0; i < k; i++){
            arr[i] = t;
        }
    }
    // Punto 3
    // No condivisione memoria = Copia (profonda) = Rif. di tipo costante
    Array(const Array& a): dim(a.dim), cap(a.cap), arr(new T[a.cap]){
        for(int i = 0; i < dim; i++){
            arr[i] = a.arr[i];
        }   
    }

    // Assegnazione profonda
    Array& operator=(const Array& a){
        // Controllo se aliasing (=stessa posizione in memoria)
        if(this != &a){ // In tutti i casi in cui ci sia assegnazione (non da standard), questo va sempre fatto!
            if(cap != a.cap){
                // Deallocazione dei vecchi puntatori
                delete[] arr;
                arr = new T[a.cap];
                cap = a.cap;
            }
            dim = a.dim;
            // Assegnazione da zero di tutto il contenuto
            for(int i = 0; i < dim; i++){
                arr[i] = a.arr[i];
            } 
        }
        return *this;
        // Return
    }

    // Distruzione profonda
    ~Array(){
        delete[] arr;
    }

    // Punto 4
    void pushBack(const T& t){
        // se dim == cap, crea e raddoppia
        if(dim == cap){
            // Crea nuovo array "arr"
            // con nuova capacità (doppia)
            T* tmp = new T[cap * 2];
            // Copia in "tmp" tutti i campi di "arr"
            for(int i = 0; i < dim; i++){
                tmp[i] = arr[i];
            }
            // Deallocare "arr" e poi raddoppiare la capacità
            delete[] arr;
            arr = tmp;
            cap *= 2;
        }
        // altrimenti inserisci (alla fine)
        arr[dim] = t;
        dim++;
    }

    // Punto 5
    T popBack(){
        if(dim == 0){
            throw Empty("Array cannot be empty!");
        }
        dim--; // toglie fisicamente la size = togliere l'elemento
        return arr[dim];
    }

    // Punto 6
    // Operatore di uguaglianza
    bool operator==(const Array &a1,){
        if(this == &a) return true;
        else return false;
    }

    // Punto 7 
    // Operatore di output = Overloading = Modifica operatore di stampa per adeguarla ai nostri utilizzi
    std::ostream& operator<<(std::ostream& os, const Array& a){
        for(int i = 0; i < a.dim; i++){
            os << a.arr[i] << " ";
        }
        return os;
    }
};

int main(){
    return 0;
}