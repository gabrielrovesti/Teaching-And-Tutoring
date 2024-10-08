#include <iostream>

using namespace std;

struct vettore{
	int n; // numero massimo di elementi
	int v[10]; // vettore
	int i; // indice
};

void push(vettore &a, int valore);
int pop(vettore &a);
void stampaPila(vettore &a);
int main(){
	vettore pila;
	pila.n=10;
	pila.i=0;
	
	stampaPila(pila);
	push(pila,12);
	stampaPila(pila);
	push(pila,9);
	stampaPila(pila);
	pop(pila);
	stampaPila(pila);
		
	return 0;
}

void push(vettore &a, int valore){
	// inseriamo elemento in posizione
	// e spostiamo tutti gli altri
	if(a.i<a.n){ 
		a.v[a.i]=valore; //v[i++]=valore;
		a.i++;
	}
}

int pop(vettore &a){
	int ris=-1;
	// se possiamo togliere elemento
	if(a.i>0){
		ris=a.v[a.i-1]; // sposta tutti gli elementi
		a.i--;			
	}
	return ris;
}

// procedura con accesso a parametro indice
// e parametro per riferimento
void stampaPila(vettore &a){
	cout<<"Vettore: ";
	for(int j=0; j<a.i; j++){ 
		cout<<a.v[j]<<" ";
	}
	cout<<endl;
}
