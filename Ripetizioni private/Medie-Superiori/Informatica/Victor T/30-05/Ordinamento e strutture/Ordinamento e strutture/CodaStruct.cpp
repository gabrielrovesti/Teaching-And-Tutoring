#include <iostream>
using namespace std;
struct vettore{
	int n;
	int v[10];
	int i;
};
void push(vettore &a, int valore);
int pop(vettore &a);
void stampaCoda(vettore &a);
int main(){
	vettore coda;
	coda.n = 10;
	coda.i = 0;
	
	stampaCoda(coda);
	push(coda,12);
	stampaCoda(coda);
	push(coda,9);
	stampaCoda(coda);
	pop(coda);
	stampaCoda(coda);
	return 0;
}
void push(vettore &a, int valore){
	if(a.i<a.n){
		a.v[a.i]=valore;
		a.i++;
	}	
}

int pop(vettore &a){
	int ris = -1;
	if(a.i>0){
		ris = a.v[0];
		for(int j=0; j<a.i-1;j++){
			a.v[j]=a.v[j+1];	
		}
		a.i--;
	}
	return ris;
}
void stampaCoda(vettore &a){
	cout<<"Vettore: ";
	for(int j=0; j<a.i; j++){
		cout<<a.v[j]<<" ";
	}
	cout<<endl;
}
