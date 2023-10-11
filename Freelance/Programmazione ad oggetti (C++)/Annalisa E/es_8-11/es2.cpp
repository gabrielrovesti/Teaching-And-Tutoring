//Cosa stampa?

#include <iostream>
using namespace std;
class C {
 public:
   C(int x=6): k(x) {cout << k << " C01 ";}
   C(const C& x): k(x.k) {cout << k << " Cc ";}
   C& operator=(const C& x) {return *this; cout << "C= ";}
   int k;
 };
 class D {
 public:
   D(): z2(8) {cout << "D0 ";}
   D(const D& x): z1(x.z1.k) {cout << "Dc ";}
   D& operator=(const D& x) {z1=x.z1; z2=x.z2; return *this; cout << "D= ";}
   C* getUno() {return &z1;}
   C z1, z2;
 };
 class E {
 public:
   E(D x) {y=x; cout << "E(D) ";}
   E(const E& x) {cout << "Ec ";}
   E& operator=(const E& x) {cout << "E= "; return *this;}
   D y;
   static C x;
};
C E::x = 9;
 main() {
   cout << "**1\n"; // 9 C01 
   C c(7); cout << "**2\n"; // 7 C01
   D d; cout << "**3\n"; // 6 C01 8 C01 D0
   c = *(d.getUno()); cout << "**4\n"; // ""
   c = d.z1.k; cout << "**5\n"; // 6 C01
   E e1(d); cout << "**6\n"; // 6 C01 6 C01 Dc 6 C01 8 C01 D0 E(D)
   E e2 = e1; cout << "**7\n"; // 6 C01 8 C01 D0 Ec
   e2 = e1; cout << "**8"; // E=
}
