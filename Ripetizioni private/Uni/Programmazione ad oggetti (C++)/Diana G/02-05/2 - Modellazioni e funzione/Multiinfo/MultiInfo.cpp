#include <iostream>
using namespace std;

// classe C
template<class T, int size> class C;
// dichiarazione incompleta

// classe MultiInfo - amicizia associata
template<class T, int size>
class C{
    // operatore di output = friend
    friend ostream& operator<< <T, size> (ostream& os, const C<T, size>& c);
    
    class MultiInfo{
        friend class C<T, size>;
        // campi
        T informazione;
        unsigned int molteplicità; //>=0
    };
    private:
        MultiInfo m[size];
    public:
        // copia profonda
        C(const T& t, int k){
            for(int i = 0; i < size; i++){
                m[i].informazione = t;
                
                if(k >= 1) 
                    m[i].molteplicità = k;
                else 
                    m[i].molteplicità = 0;

                // ternario
                // m[i].molteplicita = k > 0 ? k : 0;
            }
        }
        // assegnazione profonda
        C& operator=(const C& c){
            // if stessa aera di memoria = aliasing
            if(this != &c){
                /*
                m = Multinfo 
                molteplicità (int) / informazione (T)
                */
                
                // deallocazione
                delete[] m;

                // assegnazione
                for(int i = 0; i < size; i++){
                    m[i].informazione = c.m[i].informazione;
                    m[i].molteplicità = c.m[i].molteplicità;
                }
            }
            return *this;
        }

        // distruzione profonda
        ~C(){
            delete[] m;
        }

        // overloading indicizzazione (subscripting)
        // Cioè, m[i]
        T* operator[] (int k){
            // se dentro indici, ritorni
            if(k >=0 && k < size) return &m[k];
            // altrimenti nullo 
            return nullptr;
        }

        int occorrenze(const T& t){
            int sum = 0;
            // m = array
            for(int i = 0; i < size; i++){
                if(m[i].informazione == t){
                    sum += m[i].molteplicità;
                }
            }
            return sum;
        }
};

// dichiaro friend l'operatore e poi lo dichiaro fuori dalla classe (siccome è parte di template, devo dirlo)
template<class T, int size>
ostream& operator<< <T, size> (ostream& os, const C<T, size>& c){
    for(int i = 0; i < size; i++) {
        os << c.m[i].informazione << " " << c.m[i].molteplicita << endl;
    }
    return os;
}

int main(){
    return 0;
}