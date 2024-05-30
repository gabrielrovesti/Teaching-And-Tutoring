#include <iostream>
using namespace std;

int getIndex(int v[],int n, int x);
void shiftVett(int v[],int n, int s, int e);
void insertionSort(int v[],int n);

int main(){
	int vett[10]={1,4,6,7,9,11,20,21,26,30};
	insertionSort(vett,10);
	for(int i=0; i<10;i++)
		cout<<vett[i]<<" ";
	return 0;
}

void insertionSort(int v[],int n){
	for(int i=0; i<n;i++){
		int valore = v[i];
		int indice = getIndex(v,i,valore);
		cout<<"valore:"<<valore<<" indice:"<<indice<<endl;
		shiftVett(v,n,indice,i);
		v[indice]=valore;
	}
}

//PRE: Sia v un vettore ordinato di interi,
//    la cui dimensione è n. x è un intero.
int getIndex(int v[],int n, int x){
	for(int i=0;i<n;i++){
		if(v[i]>=x){
			return i;
		}
	}
	return n;	
}
//POST: Viene ritornato un valore che rappresenta
// l'indice in cui tutti gli elementi precedenti 
// sono minori di x e tutti gli elementi sucessivi
// sono superiori o uguali a x. Il vettore v rimane 
// invariato

//PRE: Sia v un vettore di interi,la cui 
// dimensione è n. s e e sono interi minori
// di n. s<e.
void shiftVett(int v[],int n, int s, int e){
	if(e+1<n){
		for(int i=e; i>=s; i--){
			v[i+1]=v[i];

		}
	}
}
//POST: Gli elementi compresi tra gli indici s e e
// di v sono spostati di una cella a destra.
// Se non c'è sufficiente spazio l'operazione non
// modifica il vettore.
