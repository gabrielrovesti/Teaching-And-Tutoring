/*
Definire un template di classe i cui oggetti rappresentano una struttura dati "array ridimensionabile" di elementi di uno stesso tipo T. 
Si ricorda che in un array ridimensionabile la sua dimensione (cioè il numero di elementi correntemente contenuti) è sempre < alla sua capacità (cioè il numero di elementi che può contenere senza dover ridimensionarsi), e quando si inserisce un nuovo elemento in un 
array con dimensione uguale alla capacità, l'array viene ridimensionato raddoppiandone la capacità. Il template deve soddisfare i seguenti vincoli: 
1. Ovviamente, non può usare i contenitori STL o Qt come campi dati (inclusi puntatori e riferimenti a contenitori STL o Qt). 
2. Deve essere disponibile un costruttore Array (int k = 0, const T& t = T () ) che costruisce un array contenente k copie di t quando k > O, mentre se k = 0 costruisce un array vuoto. 
3. Gestione della memoria senza condivisione. 
4. Deve essere disponibile un metodo void pushBack (const T&) con il seguente comportamento: a. pushBack (t) inserisce l'elemento t alla fine dell'array a dopo il suo ultimo elemento corrente; 
ciò provoca quindi il ridimensionamento di a se e solo se la dimensione di a è uguale alla sua capacità. 
5. Deve essere disponibile un metodo T popBack () con il seguente comportamento: se l'array a non è vuoto, a.popBack () rimuove l'ultimo elemento corrente di a e quindi lo ritorna; se invece a è vuoto allora solleva una eccezione di tipo Empty (una opportuna classe di eccezioni di cui è richiesta la definizione). 
6. Opportuno overloading dell'operatore di uguaglianza. 
7. Opportuno overloading dell'operatore di output. 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Empty{
    private:
    string msg;
    public:
    Empty(string s = "Empty") : msg(s) {}
};

template <class T>
class Array{
    private:
        int dim;
        int cap;
        T* arr;
    public:
        Array(int k = 0, const T& t = T()) : dim(k), cap(k*2), arr(new T[k*2]){
            for(int i = 0; i < k; i++){
                arr[i] = t;
            }
        }

        Array(const Array& a) : dim(a.dim), cap(a.cap), arr(new T[a.cap]){
            for(int i = 0; i < dim; i++){
                arr[i] = a.arr[i];
            }
        }

        Array& operator=(const Array& a){
            if(this != &a){
                if(cap != a.cap){
                    delete[] arr;
                    arr = new T[a.cap];
                    cap = a.cap;
                }
                dim = a.dim;
                for(int i = 0; i < dim; i++){
                    arr[i] = a.arr[i];
                }
            }
            return *this;
        }

        ~Array(){
            delete[] arr;
        }

        void pushBack(const T& t){
            if(dim == cap){
                T* tmp = new T[cap*2];
                for(int i = 0; i < dim; i++){
                    tmp[i] = arr[i];
                }
                delete[] arr;
                arr = tmp;
                cap *= 2;
            }
            arr[dim] = t;
            dim++;
        }

        T popBack(){
            if(dim == 0){
                throw Empty("Error: array is empty");
            }
            dim--;
            return arr[dim];
        }

        friend ostream& operator<<(ostream& os, const Array& a){
            for(int i = 0; i < a.dim; i++){
                os << a.arr[i] << " ";
            }
            return os;
        }
};