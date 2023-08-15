#include <iostream>

using namespace std;

class Z { private: int x;
};

class B { private:
	Z x; };

class D: public B { private:
	Z y; public:
	// ridefinizione di operator= in modo che il suo comportamento coincida con quello dell'assegnazione standard di D
	D& operator=(const D& d){
		if(this != &d){
			B::operator=(d);
			y = d.y;
		}
		return *this;
	}
};


int main(){
	return 0;
}

