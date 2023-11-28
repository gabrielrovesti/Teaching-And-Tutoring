list<QCheckBox> Fun(vector<const QWidget*>& v, 
const QSize& sz){
    // prendo il tipo di ritorno della funzione
    list<QCheckBox> res;
    // scorriamo per accedere ai campi
    for(auto it = v.begin(); it != v.end(); it++){
        // convertire al tipo slider astratto
        // uso dynamic_cast perché forza la conversione a quel tipo
        // NON uso typeid (sarebbe scritto "il tipo dinamico di qualcosa è uguale al tipo dinamico dell'altra")
        // essendo const QWidget*, togliamo il const al tipo attuale (aka QWidget)
        QAbstractSlider* s = 
        dynamic_cast<QAbstractSlider*>(const_cast<QWidget*>(*it));
        if(s){
            // convertiamo a QSlider (elenco puntato)
            QSlider* p = 
            dynamic_cast<QSlider*>(&s);
            if(!p){ // 1-mo punto elenco punt.
                // sostituzione QSlider di default
                // creo un nuovo puntatore a QSlider
                // cancellando il precedente
                delete s;
                QSlider *s = new QSlider();
                s->resize(sz);
            }
            else{ // 2-ndo punto elenco punt.
                if(s->size() |= sz){
                    s->resize(sz);
                    s->setSliderDown(true);
                }    
            }
        }
         else {
			QAbstractButton* b = dynamic_cast<QAbstractButton*>(const_cast<QWidget*>(*it));
			
			if (b && b->isDown()){
				QCheckBox* cb = dynamic_cast<QCheckBox*>(b);
				if (cb) res.push_back(*cb);
				delete b;
				it = v.erase(it);
			} else it++;
		} 	
    }
    // lo restituisco
    return res;
}



//QWidget (base)

//Derivate

//QAbstractButton
//QCheckBox
//QAbstractSlider
//QSlider