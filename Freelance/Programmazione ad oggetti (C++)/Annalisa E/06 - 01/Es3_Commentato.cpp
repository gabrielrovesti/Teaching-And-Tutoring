list<const D* const> fun(const vector<const B*> &v){
    list<const D* const> res;

    int count = 0;
    for(auto q = v.begin(); q != v.end(); ++q){
        if(*q != nullptr && typeid(**q) == typeid(C)){
            v.erase(q);
            //q = v.erase(q);
            count++;
            if(count > 2){
                throw C();
            }
        }
        A* ptr = (*q)->f(); //invochiamo la funzione virtuale pura sul punt. di tipo A*
        if(ptr == nullptr){
            throw std::string("nullptr");
        }
        if(dynamic_cast<D*>(const_cast<B*>(ptr)) &&
        dynamic_cast<E*>(const_cast<B*>(ptr))){
            res.push_back(dynamic_cast<const D* const>(ptr));
        }

        /*
        if(dynamic_cast<const D* const>(ptr)) &&
        (dynamic_cast<const E* const>(ptr)){

        }
        */

    }

    return res;
}