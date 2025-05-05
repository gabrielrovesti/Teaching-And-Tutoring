#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Widget{
    private:
        int width;
        int height;
        bool isVisible;
    public:
        Widget(int w, int h, bool isV): width(w), height(h), isVisible(isV) {}

        virtual ~Widget() = 0;

        int getWidth() const{
            return width;
        }
        int getHeight() const{
            return height;
        }
        bool getVisibility() const{
            return isVisible;
        }

        // setter per altezza e larghezza - alternativi i costruttori (ogni tanto)
        void setHeight(int h){
            height = h;
        }

        void setWidth(int w){
            width = w;
        }

        virtual void setStandardSize() = 0;
};

class AbstractButton: public Widget{
    private:
        string label;
    public:

        AbstractButton(int w, int h, bool isV, string l): Widget(w, h, isV), label(l) {};

        string getLabel() const{
            return label;
        }
};

class PushButton: public AbstractButton{
    public:
        virtual void setStandardSize(){
            this->setHeight(80);
            this->setWidth(20);
        }
        PushButton(int w, int h, bool isV, string l): AbstractButton(w, h, isV, l) {};
};

class CheckBox: public AbstractButton{
    private: 
        bool checked;
    public:
        virtual void setStandardSize(){
            this->setHeight(5);
            this->setWidth(5);
        }
        CheckBox(int w, int h, bool isV, string l, bool c): AbstractButton(w, h, isV, l), checked(c) {};

        bool isChecked() const{
            return isChecked;
        }
};

class Gui{
    private:
        vector<const Widget*> noButtons;
        list<const AbstractButton*> buttons;
    public:
        void insert(Widget* p){
            if(!p){
                throw string("NoInsert");
            }
            else{
                noButtons.push_back(dynamic_cast<const Widget*>(p));
            }
        }
        
        void insert(unsigned int pos, PushButton& pb){
            // Es. vettore di 10 elementi e lo vuoi mettere alla 6 -> vettore[6] = 5; 
            // vector.insert(pos, pb) meno efficiente di vector.push_back() (o push_front)
            if(pos < 0 || pos > buttons.size()) throw string("NoInsert");

            if(pos == 0) // inserimento in testa
                buttons.push_front( &pb );
            if(pos == buttons.size()) // inserimento in coda
                buttons.push_back(&pb);
            else {
                list<const AbstractButton*>::iterator it; // comincio a scorrere
                int i = 1;
                for(it = buttons.begin(); it != buttons.end(); ++it, ++i ) {
                    if(pos == i) // se la posizione è valida (accesso casuale -> gli dai la posizione)
                        buttons.insert(it, &pb);
                }
            }
        }

        vector<AbstractButton*> removeUnchecked(){
            vector<AbstractButton*> ret;
            for(auto it = buttons.begin(); it != buttons.end(); ++it){
                CheckBox* c = dynamic_cast<CheckBox*>(const_cast<AbstractButton*>(*it));
                if(c && c->isChecked() == false){
                    ret.push_back(dynamic_cast<AbstractButton*>(c));
                    // prima delete e poi erase (in caso di variabili di appoggio)
                    delete c;
                    it = buttons.erase(it);
                }
            }
            return ret;
        }

        void setStandardPushButton(){
            for(auto it = buttons.begin(); it != buttons.end(); ++it){
                AbstractButton* ab = dynamic_cast<AbstractButton*>(const_cast<AbstractButton*>(*it));

                if(ab && ab->getLabel() != ""){
                    ab->setStandardSize();
                }
            }
        }
};

int main(){
    return 0;
}