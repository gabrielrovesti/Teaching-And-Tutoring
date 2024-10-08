/*
Definire int Fun(const vector<B*> & v) con il comportamento:
- v non vuoto e T* il tipo dinamico di v[0];
- allora Fun(v) ritorna il num. di elementi di "v" che hanno un 
tipo dinamico esattamente diverso a T1* (cioè it)
tale che T1 è un sottotipo di C diverso da T;
- se "v" è vuoto, deve quindi ritornare 0
*/

int Fun(const vector<B*> & v){
    int tot = 0;

    for(auto it = v.begin(); it != v.end(); ++it){
        if(**v && typeid(**v) != typeid(**it) && dynamic_cast<C*>(*it)) ++tot;
    }

    return tot; 
}