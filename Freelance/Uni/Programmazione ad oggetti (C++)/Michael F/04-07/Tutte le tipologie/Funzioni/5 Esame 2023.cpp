#include <vector>
#include <iostream>
#include <string>
#include <list>

using namespace std;

vector<QAbstractButton*> fun(list<QWidget*>& lst, const QSize& sz, vector<const QWidget*>& w){
    vector<QAbstractButton*> v;
    for(auto i = lst.begin(); i != lst.end(); ++i){
        /**
         * @brief se p non è nulla e la dimensione raccomandata di p è uguale ad sz, inserisci in w la copia di *p (la funzoine clone() è già definita per QWidget)
         */
        if(*i != nullptr && (*i)->sizeHint() == sz){
            w.push_back((*i)->clone());
        }

        /**
         * @brief Se p non è nullo e *p non è uno Slider Widget (che deriva da QAbstractSlider) e la dimensione raccomandata di *p è uguale ad sz, rimuoivi da lst l'elemento puntato da i e dealloca *p
         */
        auto s = dynamic_cast<QAbstractSlider*>(*i);
        auto b = dynamic_cast<QAbstractButton*>(*i);
        if(*i != nullptr && !s && (*i)->sizeHint() == sz){
            delete *i;
            i = lst.erase(i);
        }

        /**
         * @brief se p non è nullo, p non è stato eliminato nel punto precedente, *p o è una QCheckBox o un QPushButton (che derivano entrambe da QAbstractButton), elimino p da lst e lo inserisco in v
         */
        else if(*i != nullptr && !b){
            v.push_back(dynamic_cast<QAbstractButton*>(*i));
            i = lst.erase(i);
        }
    return v;
}