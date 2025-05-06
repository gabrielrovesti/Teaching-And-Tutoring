#include <iostream>
using namespace std;
struct vettore{
	int v[10];	
	int n;
};
int main(){
	vettore b;
	vettore l;
	b.v[0]=12;
	b.n=10;
	cout<<b.v[0];
	return 0;
}
