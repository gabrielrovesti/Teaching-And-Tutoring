// Definisci le classi

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hidden {};

class Component {
public:
    virtual ~Component() {}
    virtual bool hasFocus() const = 0;
};

class Container : public Component {
public:
    virtual ~Container() {}
    virtual bool hasFocus() const = 0;
    virtual void setHeight(double) = 0;
    virtual void setWidth(double) = 0;
};

class Window : public Component {
public:
    virtual ~Window() {}
    virtual bool hasFocus() const = 0;
    virtual void hide() = 0;
};

class Frame : public Window {
public:
    virtual ~Frame() {}
    virtual bool hasFocus() const = 0;
    virtual bool hasMenu() const = 0;
    virtual void setTitle(const string&) = 0;
};

int main(){
    return 0;
}


void fun(const Component& c, vector<const Window*>& v) {
    // VERSIONE 1: usando const_cast + dynamic_cast
    Frame* f = dynamic_cast<Frame*>(const_cast<Component*>(&c));
    if(f && f->hasMenu()) {
        f->setTitle("menu");
        v.push_back(f);
    }

    Window* w = dynamic_cast<Window*>(const_cast<Component*>(&c));
    if(w && w->hasFocus()) {
        try {
            w->hide();
        } catch(const Hidden&) {
            // Gestione finestra già nascosta
        }
    }

    Container* co = dynamic_cast<Container*>(const_cast<Component*>(&c));
    if(co && co->hasFocus()) {
        co->setHeight(3.0);
        co->setWidth(3.0);
    }
}

// VERSIONE 2: usando dynamic_cast diretto su const
void fun(const Component& c, vector<const Window*>& v) {
    const Frame* f = dynamic_cast<const Frame*>(&c);
    if(f && f->hasMenu()) {
        const_cast<Frame*>(f)->setTitle("menu");
        v.push_back(f);
    }

    const Window* w = dynamic_cast<const Window*>(&c);
    if(w && w->hasFocus()) {
        try {
            const_cast<Window*>(w)->hide();
        } catch(const Hidden&) {
            // Gestione finestra già nascosta
        }
    }

    const Container* co = dynamic_cast<const Container*>(&c);
    if(co && co->hasFocus()) {
        const_cast<Container*>(co)->setHeight(3.0);
        const_cast<Container*>(co)->setWidth(3.0);
    }
}