#include <vector>

class File{
    private:
        double dimensione; //information hiding
        bool accessibile;
    public:
        // best practice - get
        double getDimensione() const{
            return dimensione;
        }
        bool getAccessibile() const{
            return accessibile;
        }
        // costruttore di default
        File(double d, bool a): dimensione(d), accessibile(a) {};

        // For the sake of exercising...

        // costruttore di copia
        File(const File& f);
        // operatore di assegnazione
        File& operator=(const File& f);
        // distruttore (polimorfo)
        virtual ~File() = 0;
};

class Photo: public File{
    private:
        bool isLossy;
    public:
        // getter
        bool getLossy() const{
            return isLossy;
        }
        // costruttori
        Photo(double d, bool a, bool isL): File(d, a), isLossy(isL) {};
        // costruzione standard (richiamo classi base)
};

class Video: public File{
    private:
        double framerate;
    public:
        // getter
        double getFPS() const{
            return framerate;
        }
        // costruttori
        Video(double d, bool a, double f): File(d, a){
            if(f < 0){
                framerate = 0;
            }
            else{
                framerate = f;
            }
        }

        // operatore ternario
        // condizione ? vero : falso
};

class PaODrive{
    private:
        std::vector<const File*> v;
        double max;
    public:
        double uploadFile(const File& f){
            if(f.getDimensione() > max) return -1.0;
            else{
                v.push_back(&f);
                max -= f.getDimensione();
                return max;
            }
        }
        std::vector<const File&> copy(double x){
            for(auto it = v.begin(); it != v.end(); ++it){
                Video *vi = dynamic_cast<Video*>(const_cast<File*>(*it));
                if(vi->getAccessibile() && vi->getFPS() >= x){
                    v.push_back(vi);
                }
                Photo *f = dynamic_cast<Photo*>(const_cast<File*>(*it));
                if(!f->getLossy() && f->getDimensione() < 2){
                    v.push_back(f);
                }
            }
        }
};