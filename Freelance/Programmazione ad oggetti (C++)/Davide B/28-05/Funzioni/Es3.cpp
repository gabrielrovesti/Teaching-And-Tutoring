#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>

template <class T>
std::list<const std::iostream*> compare(const std::vector<std::ostream*>& v, const std::vector<const T*>& w) {
    if (v.size() != w.size()) {
        throw std::string("");
    }

    std::list<const std::iostream*> result;

    for (size_t i = 0; i < v.size(); ++i) {
        auto* vi_fstream = dynamic_cast<std::fstream*>(v[i]);
        auto* wi_fstream = dynamic_cast<const std::fstream*>(w[i]);

        auto* wi_sstream = dynamic_cast<const std::stringstream*>(w[i]);

        if (vi_fstream && wi_fstream) {
            result.push_back(static_cast<const std::iostream*>(v[i]));
        } else if (wi_sstream && wi_sstream->good() && typeid(*v[i]) != typeid(*w[i])) {
            result.push_back(static_cast<const std::iostream*>(w[i]));
        }
    }

    return result;
}

int main(){
    return 0;
}