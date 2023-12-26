Button **Fun(const Container& c){
    
    // creare il vettore di componenti
    // chiamando il metodo

    // fare un ciclo 
    // controllando se il tipo è Button
    // e poi contandolo (aka, cont)

    int cont = 0;

    vector<Component*> v = c.getComponents(); // Container dà tutto e crea tutti i soli componenti, da cui tutti e soli buttoni
    for(auto it = v.begin(); 
    it != v.end(); ++it){
        if(dynamic_cast<Button*>(*it)){
            cont++;
        }
    }

    // Alternativamente - si può fare con "i"
    // for(int i = 0; i < v.size(); i++){
    //     if(dynamic_cast<Button*>(v[i]));
    //     //**v 
    // }

    if(cont == 0) throw NoButton();

    //creare un array dinamico di puntatori
    //a tutti i soli pulsanti contati
    Button** b = new Button*[cont];

    for(auto it = v.begin(); 
    it != v.end(); ++it){
        if(dynamic_cast<Button*>(*it)){
            MenuItem *m = dynamic_cast<MenuItem*>(*it);

            if(m && m->getContainers().size() >= 2){
                m->setEnabled(false);
            }

            b[cont] = dynamic_cast<Button*>(*it);
            cont++;
        }
    }
    return b;
}