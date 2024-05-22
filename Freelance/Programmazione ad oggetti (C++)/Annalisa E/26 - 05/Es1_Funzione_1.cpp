#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>

template <class T>
std::list<T*> compare(std::vector<T*>& v, std::vector<T*>& w) {
    std::list<T*> result;

    if (v.size() != w.size()) {
        throw std::string();
    }

    for (size_t i = 0; i < v.size(); ++i) {
        std::fstream* v_fstream = dynamic_cast<std::fstream*>(v[i]);
        std::stringstream* w_stringstream = dynamic_cast<std::stringstream*>(w[i]);

        if (v_fstream && typeid(*v[i]) == typeid(*w[i])) {
            result.push_back(v[i]);
            v.erase(v.begin() + i);
            w.erase(w.begin() + i);
            --i;
        }
        else if (w_stringstream && w_stringstream->good() && typeid(*v[i]) != typeid(*w[i])) {
            result.push_back(w[i]);
        }
    }

    return result;
}

int main() {
    std::vector<std::fstream*> v;
    std::vector<std::stringstream*> w;

    v.push_back(new std::fstream("file1.txt"));
    v.push_back(new std::fstream("file2.txt"));
    v.push_back(new std::fstream("file3.txt"));

    w.push_back(new std::stringstream("string1"));
    w.push_back(new std::stringstream("string2"));
    w.push_back(new std::fstream("file3.txt"));

    try {
        std::list<void*> result = compare(v, w);

        std::cout << "Puntatori nella lista ritornata:" << std::endl;
        for (auto ptr : result) {
            std::cout << ptr << std::endl;
        }

        std::cout << "Puntatori rimasti in v:" << std::endl;
        for (auto ptr : v) {
            std::cout << ptr << std::endl;
        }

        std::cout << "Puntatori rimasti in w:" << std::endl;
        for (auto ptr : w) {
            std::cout << ptr << std::endl;
        }
    }
    catch (const std::string& e) {
        std::cout << "Eccezione: i vettori hanno lunghezze diverse" << std::endl;
    }

    // Liberare la memoria allocata
    for (auto ptr : v) {
        delete ptr;
    }
    for (auto ptr : w) {
        delete ptr;
    }

    return 0;
}