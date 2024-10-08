
#include <iostream>
using namespace std;

class IntMod{
    public:
    static int n;
    static void setmodulo(const IntMod&);
    static int getmodulo();
    int operator+(int) const;
    int operator*(int) const;
    operator int() const;
};

int IntMod::n = 1;

void IntMod::setmodulo(const IntMod& x){
    n = x.n;
}

int IntMod::getmodulo(){
    return n;
}

int IntMod::operator+(int a) const{
    return abs(a + n);
}

int IntMod::operator*(int a) const{
    return abs(a * n);
}

IntMod::operator int() const{
    return n;
}

int main(){
    IntMod a;
    a.n = 5;
    IntMod::setmodulo(a);
    cout << IntMod::getmodulo() << endl;
    cout << a + 5 << endl;
    cout << a * 5 << endl;
    cout << a << endl;
    return 0;
}