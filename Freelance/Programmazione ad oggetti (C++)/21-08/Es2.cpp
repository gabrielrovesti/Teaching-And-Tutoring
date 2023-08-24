#include <iostream>

using namespace std;

class Z { 
	private: 
		int x;
};

class B { 
	private:
		Z x; 
};

class D: public B { 
    private:
	    Z y; 
    public:
        
};

int main(){
	
}

