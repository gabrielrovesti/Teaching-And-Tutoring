#include <iostream>
#include <vector>
#include <fstream> // gestisce file = filestream

using namespace std;

class Log{
    private:
        string applicazione;
        string messaggio;
    public:
        // get
        string getApplicazione() const{
            return applicazione;
        }
        string getMessaggio() const{
            return messaggio;
        }
        // costruttore
        Log(string a, string m): applicazione(a), messaggio(m) {};
        // polimorfa
        virtual ~Log() = 0;
        // clonazione
        virtual Log* clone() const = 0;
        // se lo implementiamo, creiamo oggetto = classe non più astratta
        virtual bool operator==(const Log& l) const{
            return 
            typeid(*this) == typeid(l) &&
            applicazione == l.applicazione && messaggio == l.messaggio;
        }

        virtual string toString() const = 0;
};

class DebugLog: public Log{
    private:
        int lineNum;
    public:
        string toString() const{
            return "Applicazione: " + getApplicazione() + "\n Messaggio: " + getMessaggio() + "\n Linea" + to_string(lineNum);
        }
        Log* clone() const{
            return new DebugLog(*this);
        }
        virtual bool operator==(const Log& l){
            return Log::operator==(l) && 
            lineNum == static_cast<const DebugLog&>(l).lineNum;
        }

        int getlineNum() const{
            return lineNum;
        }
};

class AppLog: public Log{
    private:
        int criticita;
    public:
        string toString() const{
            return "Applicazione: " + getApplicazione() + "\n Messaggio: " + getMessaggio() + "\n Criticità" + to_string(criticita);
        }
        Log* clone() const{
            return new AppLog(*this);
        }
        virtual bool operator==(const Log& l){
            return Log::operator==(l) && 
            criticita == static_cast<const AppLog&>(l).criticita;
        }

        int getCriticita() const{
            return criticita;
        }
};

class LogManager{
    private:
    class Nodo{
        public:
            Log* info; // puntatore superpolimorfo (convertirlo a seconda degli usi)
            Nodo* next;
    };
    Nodo* first;

    class IteratoreApp{
        // Iteratore
        // Punta al Nodo [info, next]
        public:
        Nodo* it;
        // Normalmente, gli iteratori prevedono overloading di: 
        // ==, ++, *, & 

        // ++ prefisso
        IteratoreApp& operator++(){
            while(it){
                it = it->next;
                if(dynamic_cast<AppLog*>(it->info));
                // past-the-end (pte) = *this
                return *this;
            }
        }

        // operator==
        bool operator==(const IteratoreApp& i) const{
            // stessa area di memoria (aliasing)
            // alternativa -> this == &i
            if(*this == i){
                if(it->info == i.it->info){
                    return true;
                }
                return false;
            }
        }
        // overloading oggetto puntato
        Log* operator*() const{
            return it->info;
        }
    };

    class IteratoreDebug{
        // Iteratore
        // Punta al Nodo [info, next]
        public:
        Nodo* it;
        // Normalmente, gli iteratori prevedono overloading di: 
        // ==, ++, *, & 

        // ++ prefisso
        IteratoreDebug& operator++(){
            while(it){
                it = it->next;
                if(dynamic_cast<DebugLog*>(it->info));
                // past-the-end (pte) = *this
                return *this;
            }
        }

        // operator==
        bool operator==(const IteratoreDebug& i) const{
            // stessa area di memoria (aliasing)
            // alternativa -> this == &i
            if(*this == i){
                if(it->info == i.it->info){
                    return true;
                }
                return false;
            }
        }
        // overloading oggetto puntato
        Log* operator*() const{
            return it->info;
        }
    };

    public:

    // Iteratore (App / Debug) [Nodo -> Log / Next]

    // con modellazioni complete che prevedono iteratori, oltre all'overloading ==, *, ->, begin() ed end()

    IteratoreApp beginApp(){
        // puntiamo al primo
        // se AppLog
        // vediamo se la posizione è valida
        // la returniamo

        IteratoreApp ia;
        ia.it = first; // Assegni a it la prima posizione
        if(dynamic_cast<AppLog*>(first->info)){
            return ia;
        }
        ++ia; // non esiste il primo, viene creato 
    }

    IteratoreApp endApp(){
        IteratoreApp ia;
        //it
        ia.it = 0;
        // first ...... [end]
        return ia;
    }

    IteratoreDebug beginDebug(){
        // puntiamo al primo
        // se AppLog
        // vediamo se la posizione è valida
        // la returniamo

        IteratoreDebug ia;
        ia.it = first; // Assegni a it la prima posizione
        if(dynamic_cast<DebugLog*>(first->info)){
            return ia;
        }
        ++ia; // non esiste il primo, viene creato 
    }   

    IteratoreDebug endDebug(){
        IteratoreDebug id;
        //it
        id.it = 0;
        // first ...... [end]
        return id;
    }

    vector<Log*> messaggi(){
        vector<Log*> v;
        // punti al primo
        // li copi tutti (polimorfo)
        // return
        Nodo* aux = first;
        while(aux->next){
            v.push_back(aux->info()->clone());
            aux = aux->next;
        }
        return v;
    }

    void save(){
        // creiamo file
        ofstream file("messages.txt");
        Nodo* aux = first;

        while(aux){
            if(dynamic_cast<AppLog*>(aux->info)){
                file << "App: " << aux->info->getApplicazione() << "\n Messaggio: " << aux->info->getMessaggio() << "\n Criticita: " << aux->info->getCriticita();
            }
            if(dynamic_cast<DebugLog*>(aux->info)){
                file << "App: " << aux->info->getApplicazione() << "\n Messaggio: " << aux->info->getMessaggio() << "\n Numero di linea: " << aux->info->getLineNum();
            }
            aux = aux->next;
        }
        
    }
};

