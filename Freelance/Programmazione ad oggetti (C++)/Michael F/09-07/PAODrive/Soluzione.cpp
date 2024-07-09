/* definisci una classe File che fappresenta i file di PaoDrive.
   I file sono caraterrizzati da una dimensione in MB e se sono pubblicamente accessibili.
   Definire opportunamente i/o costruttore/i
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class File{
private:
    double dimensione;
    bool pubblico;
public:
    File(double dim, bool pub): dimensione(dim), pubblico(pub){}
    
    virtual ~File() {} // Adding a virtual destructor to make the class polymorphic

    double getDimensione() const {return dimensione;}
    bool getPubblico() const {return pubblico;}
};



/* definisci una classe Photo che deiva da File che rappreserta una foto. 
   Ogni foto può essere lossy o meno.
   definire opportunamente i/o costruttore/i.
*/

class Photo: public File{
private:
    bool lossy;
public:
    Photo(double dim, bool pub, bool los): File(dim, pub), lossy(los){}
    bool getLossy() const {return lossy;}
};



/* definisci una classe Video che deiva da File che rappreserta un video. Ogni video ha un framerate.
   Se un valore fittizzio f di tipo double rappresenta il framerate, se f < 0, alllora imposta il framerate a 0
*/

class Video: public File{
private:
    double framerate;
public:
    Video(double dim, bool pub, double fr): File(dim, pub){
        if(fr < 0)
            framerate = 0;
        else
            framerate = fr;
    }
    double getFramerate() const {return framerate;}
};



/* la class PaODrive rappresenta un drive di PaoDrive. 
   Ogni drive ha un contenitore di puntatori a File e la dimensione massima in MB.
   Definisci una funzione double uploadFile(const File& f) che aggiunge il puntatore al file f al contenitore di puntatori a File.
   Se f < dimensioneDisco, allora esegue l'upload e ritorna lo spazio restante una volta termianto l'upload.
   Altrimenti, ritorna errore e stampa -1.0.

   Definisci una funzione vector<const File*> copy(double d) che ritona un vettore a cui vengono aggiunti:
   - I video che sono accessibili e il framerate è maggiore di d
   - Foto non sono lossy e hanno la dimensione maggiore di 2MB
   Non puoi usare l'operatore di index per accedere agli elementi del vettore.
*/

class PaODrive{
private:
    vector<const File*> files;
    double dimensioneDiscoInMB;

public:
    PaODrive(double dim): dimensioneDiscoInMB(dim){}

    double uploadFile(const File& f){
        if(f.getDimensione() < dimensioneDiscoInMB){
            files.push_back(&f);
            return dimensioneDiscoInMB - f.getDimensione();
        }else{
            cout << "Errore" << endl;
            return -1.0;
        }
    }

    vector<const File*> copy(double d) {
        vector<const File*> v;
        for (auto it = files.begin(); it != files.end(); ++it) {
            if (dynamic_cast<const Video*>(*it) && (*it)->getPubblico() && dynamic_cast<const Video*>(*it)->getFramerate() > d)
                v.push_back(*it);
            
            else if (dynamic_cast<const Photo*>(*it) && (*it)->getPubblico() && !dynamic_cast<const Photo*>(*it)->getLossy() && (*it)->getDimensione() > 2.0)
                v.push_back(*it);
        }
        return v;
    }
};