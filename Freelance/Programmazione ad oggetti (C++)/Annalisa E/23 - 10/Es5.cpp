#include <iostream>
using namespace std;

class A {
protected:
	int x;
public:
	A(int k=0) : x(k) {cout << "A("<<k<<") ";}
	~A() { cout << "~A ";}
	operator double() const { cout << "operator double() "; return x;}
};

class B : public A {
public:
	static A a;
	const A& a2;
	B(int k=3, const A &a3=0) : A(k), a2(a3) {cout << "B() ";}
	B(const B &b) : a2(b) {cout << a2 << " ";}
	~B() { cout <<"~B ";}
	A F(A a = A() ) { return a; }
};
A B::a(1);

int main() {
	
	A a(2); cout << "UNO\n";
	B b; cout << "DUE\n";
	B b2(a); cout << "TRE\n";
	B b3(a,a); cout << "QUATTRO\n";
	B b4=b3; cout << "CINQUE\n";
	b.F(); cout << "SEI\n";
	b.F(3); cout << "SETTE\n";
	return 0;
}