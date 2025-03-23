vector<fstream*> Fun(const vector<const ios*>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        // const ios !
        //    |
        // istream
        istream* i = dynamic_cast<istream*>(const_cast<ios*>(*it));
        // const ios !
        //    |
        // ostream
        ostream* o = dynamic_cast<ostream*>(const_cast<ios*>(*it));
        if(i && i->tellg() > o->tellp()){
            i->setstate(2);
        }
        // const ios !
        //    |
        // fstream
        fstream* f = dynamic_cast<fstream*>(const_cast<ios*>(*it));

        if(f && f->rdstate() == 0 && f->isopen()){
            f->close();
        }
        else{
            throw std::exception();
        }
    }
}

// Possono esserci i tipi non const, ma noi dobbiamo per forza toglierlo in caso di cancellazioni.

vector<fstream*> Fun(const vector<const ios*>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        // const ios !
        //    |
        // const istream
        const istream* i = dynamic_cast<istream*>(*it);
        // const ios !
        //    |
        // ostream
        const ostream* o = dynamic_cast<ostream*>(*it);
        if(i && i->tellg() > o->tellp()){
            i->setstate(2);
        }
        ...

        // Se const in questo caso (=convertire al sottotipo const, va bene uguale)
    }
}

// Alternativa (più lunga) = ciclo for con "i" -> v[i] <--> (*v)+i

vector<fstream*> Fun(const vector<const ios*>& v){
    for(int i = 0; i < v.size(); ++i){
        istream* i = dynamic_cast<istream*>(const_cast<ios*>(v[i]));
        ostream* o = dynamic_cast<istream*>(const_cast<ios*>(v[i]));
        if(i && i->tellg() > o->tellp()){
            i->setstate(2);
        }
    }
}