#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>
using namespace std;

class Widget{
    private:
        int width;
        int height;
        bool isVisible;
    public:
        virtual void setStandardSize() = 0;
        // essendo che deriva, ha bisogno del costruttore di default
        Widget(){
            width = 0;
            height = 0;
            isVisible = false;
        }
        // Widget w;

        Widget(int w, int h, bool v): width(w), height(h), isVisible(v) {}
        // Widget(50, 20, true)

        int getWidth() const{return width;}
        int getHeight() const{return height;}
        bool getVisible() const{return width;}

        //classe polimorfa
        virtual ~Widget(){}

        // anche virtuale puro virtual ~Widget() = 0 {}
        
        // void setSize(int w =0, int h =0) {width = w; height = h;} 

};
        
class AbstractButton: public Widget{
    private:
        string label;
        int* i;
    public:
        //AbstractButton(string l, int w, int h, bool v): label(l), Widget(w, h, v) {}

        // essendo che deriva, ha bisogno del costruttore di default
        AbstractButton(){
            label = "";
            i = new int(10);
        }

        AbstractButton(string l, int* i1){
            label = l;
            if(i == nullptr){
                i = 0;
            }
            else{
                i = new int(*i1);
            }
        }

        // AbstractButton(string l, int* i1): label(l), i(i1) {}

        AbstractButton(string l, int* i1, int w, int h, bool v): Widget(w, h, v) {
            label = l;
            if(i == nullptr){
                i = 0;
            }
            else{
                i = new int(*i1);
            }
        }

        string getLabel() const{
            return label;
        }
};

class PushButton: public AbstractButton{
    private:
        int standardW;
        int standardH;

        // statici = hanno valore fisso = lo sappiamo dalla consegna
        // 80 x 50

        /*
            static unsigned int standardW; --> unsigned int perché sempre positivi
            static unsigned int standardH;
        */
    public:
        PushButton(int w = 80, int h = 20){
            standardW = w;
            standardH = h;
        }

        virtual void setStandardSize(){
            standardW = 80;
            standardH = 20;
        }

        int getstandardW() const{
            return standardW;
        }

        int getstandardH() const{
            return standardH;
        }

        // override = sa di sicuro che la classe la ridefinisce
        // "un po' alla Java"
        
        // void setStandardSize() override { setSize(standardW,standardH); }    
};

/*
unsigned int PushButton::standardW = 80;
unsigned int PushButton::standardH = 20;

se comincio ad usare unsigned int, usi solo unsigned int
*/

class Checkbox: public AbstractButton{
    private:
        static int standardW;
        static int standardH;
        bool checked;
    public:

        Checkbox(bool c, int w, int h, string l, int* i): checked(c), AbstractButton(l, i){}

        bool isChecked() const{
            return checked;
        }

        virtual void setStandardSize(){
            standardW = 5;
            standardH = 5;
        }
};

int Checkbox::standardH = 5;
int Checkbox::standardW = 5;

class GUI{
    private:
        vector<const Widget*> NoButtons;
        list<const AbstractButton*> Buttons;
    public:
        void insert(Widget* p){
            if(p == nullptr) throw string("NoInsert");
            else Buttons.push_back(dynamic_cast<const AbstractButton*>(p));
        }

        /*
        "Ranzy-based"

        void insert(Widget* p) {
            if(p==nullptr) throw std::string("NoInsert");
            if(!dynamic_cast<AbstractButton*>(p)) NoButtons.push_back(p); - non è un bottone, per fare il figo lo pusho dove non sono i bottoni

            else Buttons.push_back(static_cast<AbstractButton*>(p));

        }
    */

   void insert(unsigned int pos, PushButton& pb){
        if(pos > Buttons.size()) throw string("NoInsert");
        //auto it = Buttons.begin();
        //std::advance(it, pos); // Sposta l'iteratore alla posizione corretta - non visto con Ranzato
        //Buttons.insert(it, &pb); // Inserisce il puntatore a pb nella lista

        // oppure avanzi col for
        auto it = Buttons.begin();
        for(unsigned int k=0; k < pos; ++it, ++k);
        Buttons.insert(it,&pb);
   }

    vector<AbstractButton*> removeUnchecked() {
        vector<AbstractButton*> v;
        
        // Gui = Buttons
        for(auto it = Buttons.begin(); it != Buttons.end(); ++it){
            Checkbox* c = dynamic_cast<Checkbox*>(const_cast<AbstractButton*>(*it));

            if(c && !c->isChecked()){
                v.push_back(dynamic_cast<AbstractButton*>(c));
                it = Buttons.erase(it);
                delete c;
            }            
        }

        return v;
    }

    /*
      Ranzy-based

      std::vector<AbstractButton*> removeUnchecked() {
        std::vector<AbstractButton*> v;
        auto it = Buttons.begin();
        while(it!=Buttons.end()) { 
            const CheckBox* p = dynamic_cast<const CheckBox*> (*it);
            if(p != nullptr && !(p->isChecked())) {
                v.push_back(const_cast<AbstractButton*> (*it));     
                it=Buttons.erase(it);
            }
        else ++it;
        }
        return v;
    }

    */

    void setStandardPushButton() {
        for(auto it = Buttons.begin(); it != Buttons.end(); ++it){
            Checkbox* c = dynamic_cast<Checkbox*>(const_cast<AbstractButton*>(*it));
            if(c && c->getLabel() != ""){
                c->setStandardSize();
            }
        }
    }
    /*
      void setStandardPushButton() const {
        for(auto it = Buttons.begin(); it != Buttons.end(); ++it){
        const CheckBox* p = dynamic_cast<const CheckBox*> (*it);
        if(p !=nullptr && p->getLabel() != std::string(""))
        (const_cast<CheckBox*>(p))->setStandardSize(); 
        }
    }
    */
};

int main(){
    
}