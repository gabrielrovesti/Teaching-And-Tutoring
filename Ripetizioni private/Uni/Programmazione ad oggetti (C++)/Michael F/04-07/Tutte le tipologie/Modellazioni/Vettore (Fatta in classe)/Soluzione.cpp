#include <iostream>
using namespace std;
class Vettore{
    private:
        int *a;
        unsigned int size;
    public:
        Vettore(unsigned int dim =0, int val =0){
            size = dim; 
            a = new int[size];
            for(unsigned int i=0; i<size; i++)
                a[i] = val;  
        }
        
        Vettore& operator=(const Vettore& v){
            if(this != &v){ 
                delete[] a;
                size = v.size; 
                a = size == 0 ? nullptr : new int[size];
                for(unsigned int i=0; i<size; i++){
                    a[i] = v.a[i];
                }
            }
            return *this;
        }

		~Vettore(){
           // Se esiste l'array "a", cancellalo tutto
           if(a) delete[] a;
        }
        
        Vettore& append(const Vettore& v){
            // Prima cosa: vettore non nullo
            if(v.size !=0){
            
                int* aux = new int[size + v.size];

                for(unsigned int i=0; i<size; i++){
                    aux[i] = a[i];
                }
                
                for(unsigned int i=0; i<v.size; i++){
                    aux[i+size] = v.a[i];
                }

				delete[] a;
                a = aux;
                size += v.size;
            }
            return *this;
        }

		unsigned int getSize() const{
            return size;
        }

		Vettore(const Vettore& v){
            size = v.size; // Copiare la size del vettore
            // Se "size" = 0, "a" è nullptr 
            // altrimenti crea un vettore di dimensione "size"
            a = size == 0 ? nullptr : new int[size];
            // Assegna elemento per elemento
            for(unsigned int i=0; i<size; i++){
                a[i] = v.a[i];
            }
        }

		int& operator[](unsigned int i){
            return a[i];
        }
        
        Vettore operator+(const Vettore& v) const{
            Vettore aux(*this);
            aux.append(v);
            return aux;
        }
        
        friend ostream& operator<<(ostream& os, const Vettore& v){
            // Stampa: [1 2 3 4 5]
            os << "[";
            for(unsigned int i=0; i<v.size; i++){
                os << v.a[i] << " ";
            }
            os << "]";
            return os;
        }

        bool operator==(const Vettore& v) const{
            if(this == &v) return true;
            if(size != v.size) return false;
            for(unsigned int i=0; i<size; i++){
                // Usciamo dal ciclo sse (iff)
                // abbiamo trovato un elemento diverso
                if(a[i] != v.a[i]) return false;
            }
            return true; 
        }
};

int main(){
    Vettore v1(4), v2(3, 2), v3(5, -3);
    v1=v2+v3;
    v2.append(v2);
    v3.append(v1).append(v3);
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;
    return 0;
}