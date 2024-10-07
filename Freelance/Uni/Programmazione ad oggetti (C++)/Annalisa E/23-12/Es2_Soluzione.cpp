class NoButton{};

Button** Fun(const Container& c){
    vector <Component*> v = c.getComponents();
    int cont = 0;

    for(int i = 0; i < v.size(); i++){
        if(dynamic_cast<Button*>(v[i]) != nullptr)
            cont++;
    }
    if (cont == 0)
        throw NoButton();
    
    Button** b = new Button*[cont];
    cont = 0;
    for(int i = 0; i < v.size(); i++){
        if(dynamic_cast<Button*>(v[i]) != nullptr){
           MenuItem *m = dynamic_cast<MenuItem*>(v[i]);
          
           if(mi && mi->getContainers().size() > 1) mi->setEnabled(false);
           
           b[cont++] = dynamic_cast<Button*>(v[i]);  
        }
    }
    return b;
}