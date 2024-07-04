/*
Definire, separando interfaccia ed implementazione, una classe Data i cui oggetti rappresentano una data 
con giorno della settimana (lun-mar-...-dom). La classe deve includere: 
• opportuni costruttori 
• metodi di selezione per ottenere giorno della settimana, giorno, mese, anno di una data 
• l'overloading dell'operatore di output esternamente alla classe 
• l'overloading dell'operatore di uguaglianza 
• l'overloading dell'operatore relazionale < che ignori il giorno della settimana 
• un metodo aggiungi_uno() che avanza di un giorno la data di invocazione. Esempi: lun 21/10/2002 => mar 22/10/2002; gio 31/1/2002 => ven 1/2/2002; mar 31/12/2002 => mer 1/1/2003. 
Ignorare gli anni bisestili 

Esemplificare l'uso della classe e di tutti i suoi metodi tramite un esempio di main(). 

*/

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
        int getGiorno() {
            return giorno;
        }
        int getMese() {
            return mese;
        }
        int getAnno() {
            return anno;
        }
        string getGiornoSettimana() {
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
};