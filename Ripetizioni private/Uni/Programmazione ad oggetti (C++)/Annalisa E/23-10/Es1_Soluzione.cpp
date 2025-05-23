#include <iostream>
#include <string>
using namespace std;

class Data {
    private:
        int giorno, mese, anno;
        string giorno_settimana;
    public:
        Data(int g, int m, int a, string gs) {
            giorno = g;
            mese = m;
            anno = a;
            giorno_settimana = gs;
        }
        Data(int g, int m, int a) {
            giorno = g;
            mese = m;
            anno = a;
            giorno_settimana = "";
        }
        Data() {
            giorno = 0;
            mese = 0;
            anno = 0;
            giorno_settimana = "";
        }
        int getGiorno() const {
            return giorno;
        }
        int getMese() const {
            return mese;
        }
        int getAnno() const {
            return anno;
        }
        string getGiornoSettimana() const{
            return giorno_settimana;
        }
        void setGiorno(int g) {
            giorno = g;
        }
        void setMese(int m) {
            mese = m;
        }
        void setAnno(int a) {
            anno = a;
        }
        void setGiornoSettimana(string gs) {
            giorno_settimana = gs;
        }
        void aggiungi_uno() {
            if (giorno == 31 && mese == 12) {
                giorno = 1;
                mese = 1;
                anno++;
            } else if (giorno == 31 && (mese == 1 || mese == 3 || mese == 5 || mese == 7 || mese == 8 || mese == 10)) {
                giorno = 1;
                mese++;
            } else if (giorno == 30 && (mese == 4 || mese == 6 || mese == 9 || mese == 11)) {
                giorno = 1;
                mese++;
            } else if (giorno == 28 && mese == 2) {
                giorno = 1;
                mese++;
            } else {
                giorno++;
            }
        }
        bool operator==(Data d) {
            if (giorno == d.getGiorno() && mese == d.getMese() && anno == d.getAnno()) {
                return true;
            } else {
                return false;
            }
        }
        bool operator<(Data d) {
            if (anno < d.getAnno()) {
                return true;
            } else if (anno == d.getAnno() && mese < d.getMese()) {
                return true;
            } else if (anno == d.getAnno() && mese == d.getMese() && giorno < d.getGiorno()) {
                return true;
            } else {
                return false;
            }
        }
        friend ostream& operator<<(ostream& os, const Data& data) {
            os << data.getGiornoSettimana() << " " << data.getGiorno() << "/" << data.getMese() << "/" << data.getAnno();
            return os;
        }
};

// Esemplificare l'uso della classe e di tutti i suoi metodi tramite un esempio di main()
int main() {
    // Creiamo una data con giorno della settimana
    Data data1(21, 10, 2002, "lun");

    // Creiamo una data senza giorno della settimana
    Data data2(31, 1, 2002);

    // Visualizziamo le date utilizzando l'overloading dell'operatore di output
    cout << "Data 1: " << data1 << endl;
    cout << "Data 2: " << data2 << endl;

    // Verifichiamo l'uguaglianza tra due date
    if (data1 == data2) {
        cout << "Le date sono uguali." << endl;
    } else {
        cout << "Le date non sono uguali." << endl;
    }

    // Verifichiamo l'operatore relazionale "<" ignorando il giorno della settimana
    if (data1 < data2) {
        cout << "Data 1 e' precedente a Data 2." << endl;
    } else {
        cout << "Data 2 e' precedente a Data 1." << endl;
    }

    // Aggiungiamo un giorno alla data
    data1.aggiungi_uno();
    cout << "Dopo l'aggiunta di un giorno: " << data1 << endl;

    return 0;
}

