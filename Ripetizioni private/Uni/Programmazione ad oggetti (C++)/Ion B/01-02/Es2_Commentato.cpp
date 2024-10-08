#include <vector>
using namespace std;

// Gerarchia solo a titolo di esempio per modellazioni

class QString{
    private:
        string messaggio;
    public:
        QString(string msg): messaggio(msg) {}

        string getMessaggio() const{
            return messaggio;
        }
};

class QPaintDevice{
    public:
        virtual ~QPaintDevice() = 0{}
        int height() const{
            return 42;
        }
        virtual QPaintDevice* clone() const = 0;
};

class QWidget: public QPaintDevice{
    // metodo di clonazione
    virtual QWidget* clone() const{
        return new QWidget(*this);
    }
};

class QAbstractButton: public QWidget{
    virtual QAbstractButton* clone() const{
        return new QAbstractButton(*this);
    }
};

// In esame = solo la funzione

vector<QWidget> fun(const vector<const QPaintDevice*>& v) {
    vector<QWidget> v;

    //(1)
    for(auto it = v.begin(); it != v.end(); ++it){
        QWidget *q = dynamic_cast<QWidget*>(const_cast<QPaintDevice*>(*it));
        // Classe a cui converto = dynamic_cast<Classe a cui converto>(const_cast<Superclasse>(*it))

        if(q && q->height() > 50){
            throw QString("TooBig");
        }
        if(q && q->height() < 50){
            q->clearFocus();
        }

        QAbstractButton *qab = dynamic_cast<QAbstractButton*>(const_cast<QPaintDevice*>(*it));

        if(qab){
            qab->setText("Pulsante");
        }

        if(q && !qab){
            v.push_back(*w);
        }
    }

    return v;
}