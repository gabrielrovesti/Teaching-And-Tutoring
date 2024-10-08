#include <iostream>
using namespace std;

class EmptyStackException{
    private:
    int e;
    EmptyStackException(int e){cout << "Eccezione: "<< e;}
};

template <class T=char, int num=100>
class stack{

    friend ostream& operator<<(ostream& os, const stack& s); //extra
    friend EmptyStackException;
    private:
        T* elem;
        int cont;
    
    public:
    stack(): elem(new T[num]), cont(0) {}

    stack(const T&t, int n): elem(new T[num]){
        if(n > num)     n=num;
        else if(n<0)    n=0;
        for(int i=0; i<cont; i++){
            elem[i]=t;
        }
    }

    bool isEmpty() const{
        if(cont==0) return true;
        return false;
    }

    bool isFull() const{
        if(cont==num) return true;
        return false;
    }

    unsigned int size() const{
        return cont;
    }

    bool push(const T& t){
        if(cont < num){
            elem[0]=t;
            size++;
        }
        else return false;
    }

    bool search(const T& t){
        bool found=false;
        for(int i=0; i<cont && !found; i++){
            if(elem[i] == t)    found=true;
        }
        return found;
    }

    void pop(){
        if(isEmpty())   throw EmptyStackException();
        else elem[--size];
    }

    /*
    Altro modo di fare la "pop"
    void remove(){
        if(isEmpty())   throw EmptyStackException();
        else{
            for(int i=0; i<cont; i++){
                elem[i]=elem[i+1];
            }
            cont--;
        }
    }
    void pop(){
        if(isEmpty())   throw EmptyStackException();
        else remove();
    }
    */

    void flush(){
        delete [] elem;
    }

    T bottom(){
        if(isEmpty())   throw EmptyStackException();
        else return elem[cont];
    }

    T top(){
        if(isEmpty())   throw EmptyStackException();
        else return elem[0];
    }

    operator int() const{
        return cont;
    }

    stack& operator+(stack& s){
        stack sum;
        while(!sum.isEmpty()){
            sum += s.pop();
            sum.pop();
        } 
        return sum;
    }

    /*
    Altre soluzioni per l'operatore +

    (1)
    stack temp;
    for(int i=0; i<cont; i++){
        temp[i]=elem[i];
    }
    for(int i=0; i<s.cont; i++){
        temp[i+cont]=s.elem[i];
    }
    return temp;

    (2)
    stack temp;
    for(int i=0; i<cont; i++){
        temp.push(elem[i]);
    }
    for(int i=0; i<s.cont; i++){
        temp.push(s.elem[i]);
    }
    return temp;

    (3)
    stack temp;
    for(int i=0; i<cont; i++){
        temp.push(elem[i]);
    }
    while(!s.isEmpty()){
        temp.push(s.pop());
    }
    return temp;
    
    (4)
    stack temp;
    for(int i=0; i<cont; i++){
        temp.push(elem[i]);
    }
    while(!s.isEmpty()){
        temp.push(s.elem[i]);
        s.pop();
    }
    return temp;
    */

    bool operator==(const stack& s){
        if(cont != s.cont)  return false;
        else{
            for(int i=0; i<cont; i++){
                if(elem[i] != s.elem[i])    return false;
            }
            return true;
        }
    }

    stack& operator=(const stack& s){
        if(this != &s){
            this=s.cont;
            for(int i=0; i<cont; i++){
                elem[i]=s.elem[i];
            }
        }
    }
    ostream& operator<<(ostream& os){
        stack s;
        for(int i=0; i<cont; i++){
            os << "Elemento: " << s[i];
        }
        return os;
    }

    ~stack(){
        delete [] elem;
    }


    //Altri possibili metodi

    //Swap = scambio di due stack
    void swap(stack& s){
        stack temp;
        temp=s;
        s=*this;
        *this=temp;
    }

    void reverse(){
        stack temp;
        for(int i=0; i<cont; i++){
            temp.push(elem[i]);
        }
        for(int i=0; i<cont; i++){
            elem[i]=temp.pop();
        }
    }
};

int main(){

}
