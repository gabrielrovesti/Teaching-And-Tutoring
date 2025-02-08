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
        f->setTitle("menu");
        v.push_back(f);
    }

    const Window* w = dynamic_cast<const Window*>(&c);
    if(w && w->hasFocus()) {
        try {
            w->hide();
        } catch(const Hidden&) {
            // Gestione finestra già nascosta
        }
    }

    const Container* co = dynamic_cast<const Container*>(&c);
    if(co && co->hasFocus()) {
        co->setHeight(3.0);
        co->setWidth(3.0);
    }
}