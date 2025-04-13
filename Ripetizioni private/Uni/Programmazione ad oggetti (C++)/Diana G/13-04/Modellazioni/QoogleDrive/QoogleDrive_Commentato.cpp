#include <iostream>
#include <vector>
#include <list>

class File{
    private:
        int dim;    // unsigned int (sempre sicuramente positivo! - Ranzy-like)
        bool isAccessible;
    public:
        int getDim() const{
            return dim;
        }
        bool getAccessibility() const{
            return isAccessible;
        }
        
        // costruttore di default
        File(int d, bool isA): dim(d), isAccessible(isA) {};

        // costruttore di copia (profondo)
        File(const File &f) {};

        // assegnazione profonda
        File& operator=(const File &f){};

        // rendere la classe polimorfa
        virtual ~File() {};

        // clonazione polimorfa 
        virtual File* clone(){
            return new File(*this);
        }
};

class Audio: public File{
    private:
        bool isLossy;
    public:
        Audio(int d, bool isA, bool isL): File(d, isA), isLossy(isL) {};

        bool getLossy() const{
            return isLossy;
        }
};

class Mp3: public Audio{
    public:
        Mp3(int d, bool isA, bool isL): Audio(d, isA, isL = true) {};
};


class Video: public File{
    private:
        unsigned int framerate;
    public:
        Video(int d, bool isA, unsigned int f): File(d, isA), framerate(f) {};

        unsigned int getFramerate() const{
            return framerate;
        }
};

class QoogleDrive{
    private:
        std::vector<const File*> files;
        unsigned int capacity;
    public:
        Audio uploadFile(File& f) {
            if(f.getAccessibility() && capacity - f.getDim() >= 0){
                files.push_back(&f);
                return static_cast<Audio&>(f); // correttezza perché la gerarchia assicura che Audio sia File 
            }
            else{
                throw Exc("File non idoneo");
            }
        }
        std::list<Audio*> audioCopy() {
            std::list<Audio*> l;

            for(auto it = files.begin(); it != files.end(); ++it){
                // files = const File*
                const Audio* a = dynamic_cast<const Audio*>(*it);
                if(a && a->getLossy() && dynamic_cast<const Mp3*>(*it)){
                    // dynamic_cast<Mp3*>(const_cast<Audio*>(*it)) - alternativa
                    l.push_back(const_cast<Audio*>(a));
                }
            }

            return l;
        }
        Video* minVideo(unsigned int fr) {
            int min = 0;
            for(auto it = files.begin(); it != files.end(); ++it){
                const Video* v = dynamic_cast<const Video*>(*it);
                if(v->getFramerate() > fr && v->getDim() < min){
                    min = v->getDim();
                }
            }

            for(auto it = files.begin(); it != files.end(); ++it){
                const Video* v = dynamic_cast<const Video*>(*it);
                if(v->getFramerate() == min){
                    return &v;
                }
                else{
                    throw Exc("Video non trovato");
                }
            }
        }
};

// classe ad-hoc eccezione
class Exc{
    private:    
        std::string msg;
    public:
        Exc(std::string messaggio): msg(messaggio) {};
};

int main(){

    return 0;
}