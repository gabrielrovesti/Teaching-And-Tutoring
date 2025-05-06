#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
int findMax(int v[], int n);
int findIndexMax(int v[], int n);
int findMin(int v[], int n);
int findIndexMin(int v[], int n);
int findIndexElement(int v[], int n, int elemento);
int numberElement(int v[], int n, int elemento);
void bubbleSort(int v[], int n);
void selectionSort(int v[], int n);
void selectionSortV2(int v[], int n);
void stampa(int v[], int n);

int main(){
	srand(time(NULL));
	int n = 10;	
	int v[n];	
	for(int i=0; i<n; i++){
		v[i]= rand()%101;//numeri da 0 a 100
	}
	stampa(v,n);
	bubbleSort(v,n);
	/*		
	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
	int max = findMax(v,n);
	cout<<"Il numero massimo e': "<<max<<endl;
	
	int iMax = findIndexMax(v,n);	
	cout<<"La posizione del massimo e': "<<iMax;
	cout<<" con un valore di: "<<v[iMax]<<endl;
	
	int min = findMin(v,n);
	cout<<"Il numero minimo e': "<<min<<endl;
	
	int iMin = findIndexMin(v,n);
	cout<<"La posizione del minimo e': "<<iMin;
	cout<<" con un valore di: "<<v[iMin]<<endl;
	
	int var = 5;	
	int pos = findIndexElement(v,n,var);
	if(pos != -1){
		cout<<"Il numero "<<var<<" e' stato trovato";
		cout<<" in posizione "<<pos<<endl;
	}
	else{
		cout<<"Il numero "<<var<<" non e' presente nel vettore"<<endl;	
	}	
	
	int occorrenze = numberElement(v,n,var);
	cout<<"Il numero di occorrenze di "<<var;
	cout<<" e': "<<occorrenze<<endl;
	*/
	return 0;	
}

// Funzione ausiliaria trova elemento massimo
int findMax(int v[], int n){
	//Calcolo elemento massimo
	int max=v[0];			
	for(int i=0; i<n; i++){
		if(v[i]>max){
			max = v[i];
		}
	}
	return max;
}

// Funzione ausiliaria trova posizione elemento massimo
int findIndexMax(int v[], int n){
	//Calcolo posizione elemento massimo
	int iMax=0;			
	for(int i=0; i<n; i++){
		if(v[i]>v[iMax]){
			iMax = i;
		}
	}
	return iMax;	
}

int findMin(int v[], int n){
	//Calcolo elemento minimo
	int min=v[0];			
	for(int i=0; i<n; i++){
		if(v[i]<min){
			min = v[i];
		}
	}
	return min;
}

int findIndexMin(int v[], int n){
	//Calcolo posizione elemento minimo
	int iMin=0;			
	for(int i=0; i<n; i++){
		if(v[i]<v[iMin]){
			iMin = i;
		}
	}
	return iMin;
}

//Funzione che ritorna la posizione di 'elemento' da cercare.
//Ritorna -1 se 'elemento' non  è presente
int findIndexElement(int v[], int n, int elemento){
	int index = -1;
	for(int i=0; i<n && index==-1;i++){
		if(v[i]==elemento){
			index = i;
		}
	}
	return index;	
}
//Funzione che ritorna il numero di occorrenze 
//di 'elemento' all'interno del vettore.
int numberElement(int v[], int n, int elemento){
	int occ = 0;
	for(int i=0; i<n; i++){
		if(v[i]==elemento){
			occ++;
		}
	}
	return occ;	
}

//Calcola media

//Bubble Sort
void bubbleSort(int v[], int n){
	for(int j=0; j<n-1;j++){
		for(int i=0; i<n-1-j; i++){
			if(v[i]>v[i+1]){
				int t = v[i];
				v[i]=v[i+1];
				v[i+1]=t;
			}
		}
		stampa(v,n);
	}	
}

//Algoritmo selection sort
void selectionSort(int v[], int n){
	for(int j = n-1; j>0 ;j--){
		int iMax = 0; // indice massimo
		for(int i=0; i<=j; i++){
			if(v[i]>v[iMax]){ 
			// scambio del valore attuale
			// con l'indice massimo corrente
				iMax = i;
			}
		}
		// scambio per mettere il maggiore elemento
		// in fondo e poi ordinare la parte rimanente
		int t = v[iMax]; 
		v[iMax] = v[j]; //scambio
		v[j] = t;
	}
}

//Algoritmo selection sort v2 - chiamata funzione
void selectionSortV2(int v[], int n){
	for(int j = n-1; j > 0 ; j--){
		int iMax = findIndexMax(v,j+1);		
		int t = v[iMax];
		v[iMax] = v[j];
		v[j] = t;
	}
}

void stampa(int v[], int n){
	for(int i = 0; i < n; i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
