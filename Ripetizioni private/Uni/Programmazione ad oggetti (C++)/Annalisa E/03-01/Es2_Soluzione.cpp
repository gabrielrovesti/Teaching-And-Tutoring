/*
 * Soluzione
 * 
 * 01) B::g 
 * 02) NC
 * 03) B::f  C::g  B::h 
 * 04) B::m  C::g  B::h 
 * 05) ERT
 * 06) B::k  D::h  B::m  B::g  D::h 
 * 07) B::f  B::g  D::h 
 * 08) B::n  B::m  B::g  D::h 
 * 09) B::n  B::n  B::g 
 * 10) B::n  B::g 
 * 11) E::m  C::g  E::h 
 * 12) C::k  B::n 
 * 13) E::n  B::m  C::g  E::h 
 * 14) C::g 
 * 15) C::k  B::n 
 * 16) E::m  C::g  E::h
 */

#include <iostream>

using namespace std;

class B {
protected:
	virtual void h() {cout << " B::h ";}
public:
	virtual void f() {cout << " B::f "; g(); h();}
	virtual void g() const {cout << " B::g ";}
	virtual void k() {cout << " B::k "; h(); m();}
	void m() {cout << " B::m "; g(); h();}
	virtual B* n() {cout << " B::n "; return this;}
};

class C: public B {
public:
	virtual void g() const {cout << " C::g ";}
	void k() {cout << " C::k "; B::n();}
	virtual void m() {cout << " C::m "; g(); h();}
	B* n() {cout << " C::n "; return this;}
};

class D: public B {
protected:
	void h() {cout << " D::h ";}
public:
	virtual void g() {cout << " D::g ";}
	void k() const {cout << " D::k "; k();}
	void m() {cout << "D::m "; g(); h();}
};

class E: public C {
protected:
	void h() {cout << " E::h ";}
public:
	void m() {cout << " E::m "; g(); h();}
	C* n() {cout << " E::n "; return this;}
};

int main() {
	const B* p1 = new D();
	B* p2 = new C();
	B* p3 = new D();
	C* p4 = new E();
	B* p5 = new E();

	cout << endl << "01";
	p1-> g();
	cout << endl << "02";
	//(p1->n())->g();
	cout << endl << "03";
	p2->f();
	cout << endl << "04";
	p2->m();
	cout << endl << "05";
	//(static_cast<D*>(p2))->k();
	cout << endl << "06";
	p3->k();
	cout << endl << "07";
	p3->f();
	cout << endl << "08";
	(p3->n())->m();
	cout << endl << "09";
	(p3->n())->n()->g();
	cout << endl << "10";
	(static_cast<C*>(p3->n()))->g();
	cout << endl << "11";
	p4->m();
	cout << endl << "12";
	p4->k();
	cout << endl << "13";
	(p4->n())->m();
	cout << endl << "14";
	p5->g();
	cout << endl << "15";
	p5->k();
	cout << endl << "16";
	(dynamic_cast<C*>(p5))->m();
	
	return 0;
}