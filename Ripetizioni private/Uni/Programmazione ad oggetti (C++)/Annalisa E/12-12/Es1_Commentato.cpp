/*
Si consideri il seguente modello concernente il servizio di file hosting QoogleDrive.

(A) Definire la seguente gerarchia di classi.

1. Definire una classe File i cui oggetti rappresentano un generico file memorizzabile in 
un account QoogleDrive. Ogni File è caratterizzato dalla sua dimensione (in MB) e dall'essere pubblicamente accessibile 
o meno. Dotare la classe File di opportuno/i costruttore/i.

2. Definire una classe Audio derivata da File i cui oggetti rappresentano un file audio memorizzabile in un account QoogleDrive.
Ogni file audio è caratterizzato dall'essere lossy (cioè compresso con perdita di informazione) oppure no. 
Dotare la classe Audio di opportuno/i costruttore/i.

3. Definire una classe Mp3 derivata da Audio i cui oggetti rappresentano un file audio memorizzabile in formato mp3-
Tutti i file audio in formato mp3 sono lossy. Dotare la classe Mp3 di opportuno/i costruttore/i.

4. Definire una classe Video derivata da File i cui oggetti rappresentano un file video memorizzabile in un account QoogleDrive.
Ogni video è caratterizzato dal suo framerate, cioè un intero positivo che rappresenta la frequenza in hertz.
Dotare la classe Video di opportuno/i costruttore/i.

(b) Definire una classe QoogleDrive i cui oggetti rappresentano un account QoogleDrive.
Più precisamente, un oggetto QoogleDrive è caratterizzato da tutti i file correntemente memorizzati dall'account, 
che devono essere rappresentati mediante un contenitore di puntatori al tipo File costante e dalla capacità massima
di memorizzazione (in MB) dell'account. Devono essere definite le seguenti funzionalità:

5. un metodo di istanza Audio uploadFile(File&) con il seguente comportamento:
una invocazione qd.uploadFile(f) provoca l'upload del file f nell'account qd quando: (1) f è un file audio pubblicamente 
accessibile, e (2) la memoria libera dell'account qd consente l'upload; se l'upload di f va a buon fine, allora viene
ritornata una copia del file audio f, altrimenti viene sollevata una eccezione di tipo Exc, tipo di cui è richiesta la definizione.

6. un metodo di istanza list<Audio*> audioCopy() con il seguente comportamento:
una invocazione qd.audioCopy() ritorna una lista (possibilmente vuota) contenente tutti e soli i puntatori ai file audio
memorizzati nell'account qd che: (1) o sono dei file audio lossy oppure (2) sono dei file audio in formato mp3.

7. un metodo di istanza Video* minVideo(unsigned int) con il seguente comportamento:
una invocazione qd.minVideo(f) ritorna un puntatore sempre non nullo ad un video memorizzato nell'account qd che:
(1) abbia un framerate maggiore di fr e (2) abbia dimensione minima tra tutti i video memorizzanti nell'account qd; se un tale video non dovesse
avere trovato tra i file moemorizzati nell'account qd, allora vienee sollevata una eccezione di tipo Exc.
*/


/*
Si consideri il seguente modello concernente il servizio di file hosting QoogleDrive.

(A) Definire la seguente gerarchia di classi.

1. Definire una classe File i cui oggetti rappresentano un generico file memorizzabile in 
un account QoogleDrive. Ogni File è caratterizzato dalla sua dimensione (in MB) 
e dall'essere pubblicamente accessibile 
o meno. Dotare la classe File di opportuno/i costruttore/i.
*/

#include <iostream>
#include <vector>

using namespace std;

class File{
    private:
        int dimensione;
        bool accessibile;
    public:
        // rendiamo la classe base polimorfa
        virtual ~File() {}
        // costruttore
        File(int dim, bool pub): dimensione(dim), accessibile(pub) {}
        // get
        int getDimensione() const{return dimensione;}
        bool getAccessibilita() const{return accessibile;}

        // clonazione polimorfa (può essere chiesta)
        /*
        virtual File* clone() const = 0;

        virtual Audio* clone(return new Audio*(this)); //clona l'oggetto nella sottoclasse
        */

};

/*
2. Definire una classe Audio derivata da File i cui oggetti rappresentano 
un file audio memorizzabile in un account QoogleDrive.
Ogni file audio è caratterizzato dall'essere lossy 
(cioè compresso con perdita di informazione) oppure no. 
Dotare la classe Audio di opportuno/i costruttore/i.
*/

class Audio: public File{
    private:
        bool lossy;
    public:
        // richiamo costruttore classe base + campo sottoclasse
        Audio(int dim, bool pub, bool los): File(dim, pub), lossy(los) {}
        virtual ~Audio() {}
        bool getLossy() const{ return lossy; }
        virtual Audio* clone() const = 0;
};

/*
3. Definire una classe Mp3 derivata da Audio i cui oggetti rappresentano 
un file audio memorizzabile in formato mp3.
Tutti i file audio in formato mp3 sono lossy. 
Dotare la classe Mp3 di opportuno/i costruttore/i.

4. Definire una classe Video derivata da File i cui oggetti rappresentano un file 
video memorizzabile in un account QoogleDrive.
Ogni video è caratterizzato dal suo framerate, 
cioè un intero positivo che rappresenta la frequenza in hertz.
Dotare la classe Video di opportuno/i costruttore/i.
*/

class Mp3: public Audio{
    public:
        Mp3(int dim, bool pub): Audio(dim, pub, true) {}
        virtual ~Mp3() {}
        // clonazione polimorfa
        virtual Mp3* clone() const{return new Mp3(*this);}
};

class Video: public File{
    private:
        unsigned int framerate; //intero positivo
    public:
        Video(int dim, bool pub, unsigned int fratm): File(dim, pub), framerate(fratm) {}
        virtual ~Video() {}
        int getFramerate() const { return framerate; }
};

/*
(b) Definire una classe QoogleDrive i cui oggetti rappresentano un account QoogleDrive.
Più precisamente, un oggetto QoogleDrive è caratterizzato da tutti i file correntemente 
memorizzati dall'account, 
che devono essere rappresentati mediante un contenitore di puntatori al tipo File costante 
e dalla capacità massima
di memorizzazione (in MB) dell'account. Devono essere definite le seguenti funzionalità:

5. un metodo di istanza Audio uploadFile(File&) con il seguente comportamento:
una invocazione qd.uploadFile(f) provoca l'upload del file f nell'account qd quando: (1) f è un file audio pubblicamente 
accessibile, e (2) la memoria libera dell'account qd consente l'upload; se l'upload di f va a buon fine, allora viene
ritornata una copia del file audio f, altrimenti viene sollevata una eccezione di tipo Exc, tipo di cui è richiesta la definizione.

6. un metodo di istanza list<Audio*> audioCopy() con il seguente comportamento:
una invocazione qd.audioCopy() ritorna una lista (possibilmente vuota) contenente tutti e soli i puntatori ai file audio
memorizzati nell'account qd che: (1) o sono dei file audio lossy oppure (2) sono dei file audio in formato mp3.

7. un metodo di istanza Video* minVideo(unsigned int) con il seguente comportamento:
una invocazione qd.minVideo(f) ritorna un puntatore sempre non nullo ad un video memorizzato nell'account qd che:
(1) abbia un framerate maggiore di fr e (2) abbia dimensione minima tra tutti i video memorizzanti nell'account qd; se un tale video non dovesse
avere trovato tra i file moemorizzati nell'account qd, allora vienee sollevata una eccezione di tipo Exc.

*/

/*
Definire una classe QoogleDrive i cui oggetti rappresentano un account QoogleDrive.
Più precisamente, un oggetto QoogleDrive è caratterizzato da tutti i file correntemente 
memorizzati dall'account, 
che devono essere rappresentati mediante un contenitore di puntatori al tipo File costante 
e dalla capacità massima
di memorizzazione (in MB) dell'account.
*/

class QoogleDrive{
    private:
    // const in mezzo - punto a oggetti costanti (puoi modificare la variabile ma non gli oggetti puntati)
        vector<const File*> files; //vettore punta a degli oggetti costanti
        int capacita; 
    /* 
    Chiarimenti su dove mettere il const:
    /// const all'inizio - tutto costante (non puoi modificare né la variabile né gli oggetti puntati)
    const vector<int*> v; //vettore o variabile costante

    /// const alla fine - metodo che non cambia l'oggetto
    int metodo() const; //non faccio side-effects/modifiche all'oggetto di invocazione
    */
    
    public:
    QoogleDrive(int cap): capacita(cap) {}

    /*
    5. un metodo di istanza Audio* uploadFile(File&) con il seguente comportamento:
    una invocazione qd.uploadFile(f) provoca l'upload del file f nell'account qd quando: 
    (1) f è un file audio pubblicamente 
    accessibile, e 
    (2) la memoria libera dell'account qd consente l'upload; se l'upload di f va a buon fine, 
    allora viene
    ritornata una copia del file audio f, altrimenti viene sollevata una eccezione di tipo Exc, 
    tipo di cui è richiesta la definizione.
    */

    // per lanciare un'eccezione = creo una classe apposta con un costruttore
    // throw Classe();

    class Exc{
        public:
        Exc();
        //private: string s; public: Exc(string msg): s(msg) {}
    };

    Audio* uploadFile(File& f){
        if(f.getAccessibilita() && f.getDimensione() <= capacita){
            // :-O - occhio che devi convertire al tipo Audio
            // e alla sintassi -> Sottotipo* s = dynamic_cast<Sottotipo*>(&Supertipo);
            Audio* a = dynamic_cast<Audio*>(&f); // devo converti
            if(a){
                files.push_back(a->clone());
                // di solito vai a fare contenitore.push_back(oggetto)
                // ma lui chiede una copia dell'oggetto di invocazione
                // quindi, uso clone() per quella classe
                capacita -= a->getDimensione(); // abbiamo fatto l'upload del file
                return a->clone(); 
            }
            else{
                throw Exc(); //lanco l'eccezione
                //throw Exc("Errore disagiato");
            }
        }
    }

    /*
    6. un metodo di istanza list<Audio*> audioCopy() con il seguente comportamento:
    una invocazione qd.audioCopy() ritorna una lista (possibilmente vuota) contenente 
    tutti e soli i puntatori ai file audio
    memorizzati nell'account qd che: 
    (1) o sono dei file audio lossy oppure 
    (2) sono dei file audio in formato mp3.
    */
    list<Audio*> audioCopy(){
        list<Audio*> l;
        // vector<const File*> files;
        //se siamo proprio hardcore allora dovremmo scrivere: list<const File*>::const_iterator it
        for(auto it = files.begin(); it != files.end(); ++it){
            // la rottura di questo esercizio è avere il vettore di tipo costante

            // o convertiamo al tipo Audio non costante (più easy, consigliata)
            Audio* a = dynamic_cast<Audio*>(const_cast<File*>(*it));

            // oppure convertiamo al tipo Audio costante (più masochita)
            // const Audio* a = dynamic_cast<const Audio*>(*it);
            // dato che lì ci sta const File*, togliendo il const
            // dynamic_cast<Mp3*>(const_cast<File*>(a)));
            if(a && a->getLossy() || dynamic_cast<const Mp3*>(a)){
                l.push_back(a->clone());
            }
        }
        return l;
    }

    /*
    7. un metodo di istanza Video* minVideo(unsigned int) con il seguente comportamento:
    una invocazione qd.minVideo(f) ritorna un puntatore sempre non nullo 
    ad un video memorizzato nell'account qd che:
    (1) abbia un framerate maggiore di fr e 
    (2) abbia dimensione minima tra tutti i video memorizzati nell'account qd; 
    se un tale video non dovesse
    avere trovato tra i file memorizzati nell'account qd, 
    allora viene sollevata una eccezione di tipo Exc.
    */

    Video* minVideo(unsigned int fr) const {
        Video* min = 0;
        for (list<const File*>::const_iterator it = files.begin(); it != files.end(); ++it) {
            const Video* v = dynamic_cast<const Video*>(*it);
            if (v && v->getFramerate() > fr && (!min || v->getDimensione() < min->getDimensione()))
                min = v->clone();
        }
        if (min)
            return min;
        else
            throw Exc();
    }

};