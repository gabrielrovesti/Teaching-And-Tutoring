/*
Si consideri il seguente modello concernente il servizio di file hosting QoogleDrive.

(A) Definire la seguente gearchia di classi.

1. Definire una classee File i cui oggetti rappresentano un generico file memorizzabile in 
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

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Exc {
public:
    Exc() {}
};

class File {
public:
    File(int dim, bool pub) : dimensione(dim), pubblico(pub) {}
    virtual ~File() {}
    int getDimensione() const { return dimensione; }
    bool getPubblico() const { return pubblico; }
    virtual File* clone() const = 0;
private:
    int dimensione;
    bool pubblico;
};

class Audio : public File {
public:
    Audio(int dim, bool pub, bool lossy) : File(dim, pub), lossy(lossy) {}
    virtual ~Audio() {}
    bool getLossy() const { return lossy; }
    virtual Audio* clone() const = 0;
private:
    bool lossy;
};

class Mp3 : public Audio {
public:
    Mp3(int dim, bool pub) : Audio(dim, pub, true) {}
    virtual ~Mp3() {}
    virtual Mp3* clone() const { return new Mp3(*this); }
};

class Video : public File {
public:
    Video(int dim, bool pub, int frame) : File(dim, pub), framerate(frame) {}
    virtual ~Video() {}
    int getFramerate() const { return framerate; }
    virtual Video* clone() const { return new Video(*this); }
private:
    int framerate;
};

class QoogleDrive {
private:
    list<const File*> files;
    int capacita;
public:
    QoogleDrive(int cap) : capacita(cap) {}
    ~QoogleDrive() {
        for (list<const File*>::const_iterator it = files.begin(); it != files.end(); ++it)
            delete *it;
    }
    Audio* uploadFile(File& f) {
        if (f.getPubblico() && f.getDimensione() <= capacita) {
            Audio* a = dynamic_cast<Audio*>(&f);
            if (a) {
                files.push_back(a->clone());
                capacita -= a->getDimensione();
                return a->clone();
            }
            else
                throw Exc();
        }
        else
            throw Exc();
    }
    list<Audio*> audioCopy() const {
        list<Audio*> l;
        for (list<const File*>::const_iterator it = files.begin(); it != files.end(); ++it) {
            const Audio* a = dynamic_cast<const Audio*>(*it);
            if (a && (a->getLossy() || dynamic_cast<const Mp3*>(a)))
                l.push_back(a->clone());
        }
        return l;
    }
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