#include <iostream>
#include <vector>
// 1.(a)
class File{
    private:
        float size;
        bool isAccessible;
    public:
    // Information hiding = nascondiamo i campi privati
    // Rendiamo disponibili "fuori" i getter
        float getSize() const{
            return size;
        }
        bool getAccessible() const{
            return isAccessible;
        }

    // Costruttore (di default = tutti i campi)
    File(float sz, bool isA): size(sz), isAccessible(isA) {};

    // Costruttore di copia
    File(const File& f) {};

    // Rendiamo la classe "base" polimorfa = occhio (distruttore virtuale)
    virtual ~File();
};

// 1.(b)

class Photo: public File{
    private:
        bool isLossy;
    public:
        // Chiamo il costruttore della base per costruire "i suoi" campi + i campi che ho io sotto (= Photo aggiunge isLossy)
        Photo(float sz, bool isA, bool isL): File(sz, isA), isLossy(isL) {};

        bool getIsLossy() const {
            return isLossy;
        }
};

// 1.(c)

class Video: public File{
    private:
        float framerate;
    public:
        Video(); 

        Video(float sz, bool isA, float f): File(sz, isA), framerate(f) {};

        float getFramerate() const {
            return framerate;
        }
        
        // Parametri attuali e formali
        
        // Formali = dentro le tonde (firma)
        Video(double f){
            // Attuali = dentro le funzioni (variabili temporanee)
            if(f < 0) framerate = 0;
            else framerate = f;
        }
};

// 2

class PAODrive{
    private:
        std::vector<File*> v;
        float maxSize;
    public:
        double uploadFile(const File& f){
            if(f.getSize() < maxSize){
                v.push_back(const_cast<File*>(&f));
            }
            else{
                return -1.0;
            }
            return maxSize - f.getSize();
        }

        std::vector<const File*> copy(double x){
            std::vector<const File*> vez;

            for(auto it = v.begin(); it != v.end(); ++it){
                const Video *v = dynamic_cast<const Video*>(*it);

                if(v && v->getAccessible() && v->getFramerate() >= x){
                    vez.push_back(v);
                }

                const Photo *p = dynamic_cast<const Photo*>(*it);

                if(p && !p->getIsLossy() && p->getSize() < 2){
                    vez.push_back(p);
                }
            }

            return vez;
        }
};