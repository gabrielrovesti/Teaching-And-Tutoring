template<class T> 
class SmartP{
    private:
        T* ptr;

    public:
    //copia profonda
    SmartP(const SmartP& s){
        if(ptr != nullptr){
            ptr = new T(*s.ptr);
        }
        else ptr = new T();
    }
    //versione stringata
    //SmartP(const SmartP& s): ptr(new T(*s.ptr)) {}

    //assegnazione profonda
    SmartP& operator=(const SmartP& s){
        if(this != &s){ //controllare che non siamo nello stesso punto in memoria
            //cancella dallo heap
            delete ptr;
            //si assegna il campo
            ptr = new T(*s.ptr);
        }
        return *this; //puntatore al contesto
    }

    //distruttore profondo
    ~SmartP(){
        if(ptr) delete ptr;
    }

    //*
    T& operator*(){
        return *ptr;
    }

    //->
    T* operator->(){
        return ptr;
        //return &ptr;
    }

    //==
    bool operator==(const SmartP& s){
        if(ptr == s.ptr){
            return true;
        }
        return false;
    }

    /*Stringato 

    bool operator==(const SmartP& s) const 
    { return ptr == s.ptr;}
    */

    //Prefisso/Postfisso
    //Si mette un int al postfisso per distinguerli
    //Quello che cambia è dire:
    //prefisso : somma e poi ritorna il campo
    //postfisso: prima mi creo il campo e poi lo sommo 
    
    SmartP& operator++(){
        ptr++;
        return *this;
    }

    SmartP& operator++(int){
        SmartP temp = *this;
        ++*this; 
        return temp;
    }

    //Operatore di stampa
    // best practice: lo definisco interno alla classe
    // (o come amico/friend ) oppure come funzionalità
    // e poi la faccio fuori
    
    ostream& operator<<(ostream&, const SmartP&)

};

template<class T>
ostream& SmartP::operator<<(ostream&, const SmartP& p){
    return os << "Campo " << p->ptr;
}
