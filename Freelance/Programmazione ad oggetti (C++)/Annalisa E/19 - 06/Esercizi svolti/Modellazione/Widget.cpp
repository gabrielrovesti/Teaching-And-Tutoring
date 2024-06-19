#include <list>
#include <vector>
#include <iostream>

using namespace std;

class Widget{
    private:
        int width;
        int height;
    public:

        virtual void setStandardSize() = 0;

        // costruttore di copia
        Widget(int w, int h): width(w), height(h) {}

        Widget(int w, int h){
            width = w;
            height = h;
        }

        Widget(){
            width = 0;
            height = 0;
        }

        // assegnazione profonda

        /*
        Widget& operator=(const Widget& w){
            if (this != &w){
                w.width = width;
                w.height = height;
            }
        }
        */

       virtual ~Widget(){ // = rende la classe polimorfa
            /* Comportamento classico
            if(punt) delete punt;
            punt;
            */
       }

       int getWidth() const{
            return width;
       }

       int height() const{
            return height;
       }
};

class AbstractButton: public Widget{
    private:
        string label;
    public:
        AbstractButton(int w, int h, string l): Widget(w, h), label(l) {};

        string getLabel() const{
            return label;
        }
};

class PushButton: public AbstractButton{
    private:
        // potremmo mettere unsigned = rimangono positive
        static int height;
        static int width;
    public:
        // void setStandardSize() override { setSize(standardW,standardH); } 

        // override = per "segnalarsi" il fatto che ridefinisce il metodo

        // setSize() = metodo di comodo per ridefinire entrambe

        virtual void setStandardSize(){
            height = 80;
            width = 20;
        }

        PushButton(int w, int h, string l): AbstractButton(w, h, l) {};
};

int PushButton::width = 80;
int PushButton::height = 20;

class CheckBox: public AbstractButton{
    private:
        bool checked;
        int height;
        int width;

        int* a;
    public:
        CheckBox(bool c, int w, int h, string l, int* a1): checked(c), AbstractButton(w, h, l), a(new int(*a1)) {};

        bool isChecked() const{
            return checked;
        }

        virtual void setStandardSize(){
            height = 5;
            width = 5;
        }

        /*
        CheckBox(bool c, int w, int h, string l, int* a1): checked(c), AbstractButton(w, h, l) {
            if(a1 == nullptr)   a = nullptr;
            else a = new int(*a1);
        };
        */
};

class Gui{
    private:
        vector <const Widget*> NoButtons;
        list <const AbstractButton*> Buttons;
    public:
        void insert(Widget* p){
            if(!p) throw string("NoInsert");

            if(!dynamic_cast<AbstractButton*>(p))
                NoButtons.push_back(dynamic_cast<const Widget*>(p));
            else 
                Buttons.push_back(static_cast<AbstractButton*>(p));
        }

    void insert(unsigned int pos, PushButton& pb){
        if(pos > Buttons.size()) throw string("NoInsert");
        else {
            auto it = Buttons.begin();
            for(int k=0; k < pos; ++it, ++k);
            Buttons.insert(it,&pb);
        }
    }

    vector<AbstractButton*> removeUnchecked() {
        vector<AbstractButton*> v;

        for(auto it = Buttons.begin(); it != Buttons.end(); ++it){
            CheckBox* c = dynamic_cast<CheckBox*>(const_cast<AbstractButton*>(*it));

            if(c && !c->isChecked()){
                it = Buttons.erase(it);
                v.push_back(c);
                delete c;
            }
            else{
                it++;
            }
        }

        return v;
    }

    void setStandardPushButton(){
        for(auto it = Buttons.begin(); it != Buttons.end(); ++it){
            PushButton* p = dynamic_cast<PushButton*>(const_cast<AbstractButton*>(*it));
            
            if(p->getLabel() != ""){
                p->setStandardSize();
            }

            // (*it)->getLabel(); - se devo usare direttamente l'iteratore
        }
    }
};

int main(){

}