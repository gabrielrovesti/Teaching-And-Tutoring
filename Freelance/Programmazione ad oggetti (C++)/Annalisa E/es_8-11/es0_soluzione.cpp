#include <iostream>
using namespace std;
class C {
    public:
    C() {}
    C(const C& r) {
        cout << "*";
    }
};

C f(C a) {
  C b(a);
    C c = b;
    return c;
}

int main() {
    C x;
    C y = f(f(x)); // *****
}