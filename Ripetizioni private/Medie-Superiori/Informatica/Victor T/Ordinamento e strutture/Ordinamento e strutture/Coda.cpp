#include <iostream>
using namespace std;
void push(int v[], int n,int& i, int valore);
int pop(int v[],int& i);
void stampaCoda(int v[],int i);
int main(){
	int n=10;
	int v[n];
	int i = 0;
	stampaCoda(v,i);
	push(v,n,i,12);
	stampaCoda(v,i);
	push(v,n,i,9);
	stampaCoda(v,i);
	pop(v,i);
	stampaCoda(v,i);
	return 0;
}
void push(int v[], int n,int& i, int valore){
	if(i<n){
		v[i]=valore;
		i++;
	}	
}
int pop(int v[],int& i){
	int ris = -1;
	if(i>0){
		ris = v[0];
		for(int j=0; j<i-1;j++){
			v[j]=v[j+1];	
		}
		i--;
	}
	return ris;
}
void stampaCoda(int v[],int i){
	cout<<"Vettore: ";
	for(int j=0; j<i; j++){
		cout<<v[j]<<" ";
	}
	cout<<endl;
}
