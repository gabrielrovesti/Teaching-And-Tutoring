#include <iostream>
#include <vector>
#include <list>
using namespace std;

class B { 
private:
	list<double>* ptr;
	virtual void m() =0; 
};

class C: virtual public B {};

class D: virtual public B { 
private: 
	int x;
};

class E: public C, public D {
private:
	vector<int*> v; 
public:
	void m() {}

	// Buon riferimento = 2 Esame 2021 (li contiene tutti)
	// Cartella "Ridefinizioni standard"

    //copia standard

	bool operator==(const E& e){
		return v == e.v;
		if(v == e.v){
			return true;
		}
		else{
			return false;
		}
	}

	E(const E& e):
	C(e), D(e), v(e.v == nullptr ? nullptr : new E(*e.v)){};
	/*
		if(e.v == nullptr){
			e.v = nullptr;
		}
		else{
			e.v = new E();
		}
	*/


	// distruzione standard
	// ~E(){delete v; };
    
	//assegnazione standard
	E& operator=(const E& e){
		C::operator=(e);
		D::operator=(e);

		v = e.v;

		return *this;
	}

	//metodo clonazione polimorfa
	virtual E* clone() const{
		return new E(*this);
	}

	//1 Esame 2014 - assegnazione standard
	D& operator=(const D& d){
		B::operator=(d);
		//y = d.y;
		return *this;
	}

};