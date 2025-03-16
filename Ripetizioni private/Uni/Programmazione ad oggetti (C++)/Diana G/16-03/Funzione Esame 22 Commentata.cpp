vector<QWidget> fun(const vector<const QPaintDevice*>& v){
    vector<QWidget> ret;

    for(auto it = v.begin(); it != v.end(); ++it){
        
        // Punto (1)
        
        QWidget *qw = dynamic_cast<QWidget*>(const_cast<QPaintDevice*>(*it));
        // (1) Converto da const QPaintDevice a QWidget (cosa più semplice = togliere il const)

        // const QWidget *qw = dynamic_cast<const QWidget*>(*it);
        // (2) Converto da const QPaintDevice a const QWidget

        if(qw && qw->height() > 50){ // (a)
            throw QString("TooBig");
        }
        if(qw && qw->height() <= 50 && qw->hasFocus()){ // (b)
              qw->clearFocus();      
        }
        // (c)
        QAbstractButton *qab = dynamic_cast<QAbstractButton*>(const_cast<QPaintDevice*>(*it));
        //  Converto da const QPaintDevice a QAbstractButton 

        if(qab)
            qab->setText("Pulsante");

        // Inserimento in un container (list / vector)
        // push_back / push_front
        // Inserimento (casuale) in coda oppure in testa (di solito usiamo sempre push_back)

        // Punto (2)
        if(qw && !qab){
            ret.push_back(*qw);
            // Qui va messo *qw e non qw perché hai vector<QWidget> e non vector<QWidget*> (avresti messo solo qw)
        }
    }

    return ret;
}

/*

vector / list

iterator -> vector<Tipo*>
const_iterator -> vector<const Tipo*>

Conversioni:
- dynamic_cast -> Safe downcasting
Per es. da A passo a C (uso tipico)
OPPURE passare a classi dello stesso livello

Supertipo* p;
Sottotipo* s = dynamic_cast<Sottotipo*>(*p);

- const_cast -> Togliere il const da un puntatore

Supertipo* p;
Sottotipo* s = dynamic_cast<Sottotipo*>(const_cast<Supertipo*>(*p));

*/