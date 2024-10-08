#include <iostream>
#include <vector>

using namespace std;

class File{
    private:
        double dimensione;
        bool accessibile;
    public:
        File(double d, bool a):
        dimensione(d), accessibile(a) {}

        virtual ~File() {}

        double getDimensione() const{
            return dimensione;
        }

        bool getAccessibile() const{
            return accessibile;
        }

        virtual File* clone() = 0;
};

class Photo: public File{
    private:
        bool lossy;
    public:
        Photo(double d, bool p, bool l):
        File(d, p), lossy(l) {}

        bool isLossy() const{
            return lossy;
        }

        //metodo clonazione polimorfa

        virtual Photo* clone(){
            return new Photo(*this);
        }
};

class Video: public File{
    private:
        double framerate;
    public:
        Video(double d, bool p, double f):
        File(d, p), (f < 0) ? framerate(0) : framerate(f) {}

        Video(double dim, bool pub, double fr): File(dim, pub){
            if(fr < 0)
                framerate = 0;
            else
                framerate = fr;
        }

        double getFramerate() const{
            return framerate;
        }

        virtual Video* clone(){
                return new Video(*this);
        }
};

class PaoDrive{
    private:
        vector<const File*> files;
        double capacity;
    public:
        double uploadFile(const File& f){
            if(f.getDimensione() <= capacity){
                files.push_back(&f);
                return capacity - f.getDimensione();
            }else{
                return -1.0;
            }
        }
        vector<const File*> copy(double d){
            vector<const File*> vez;
            for(auto it = files.begin();
            it != files.end(); ++it) {
                Video* v = dynamic_cast<Video*>(const_cast<File*>(*it));
                Photo* p = dynamic_cast<Photo*>(const_cast<File*>(*it));

                if(v && v->getAccessibile() && v->getFramerate()){
                    vez.push_back(v);
                }
                if(p && !p->isLossy() && p->getDimensione() < 2){
                    vez.push_back(p);
                }
            }
            return vez;
        }
};