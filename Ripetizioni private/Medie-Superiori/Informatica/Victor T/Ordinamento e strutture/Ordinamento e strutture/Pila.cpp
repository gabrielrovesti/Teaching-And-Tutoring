#include <iostream>
using namespace std;
void push(int v, int n);
void pop(int v, int n);
int main(){
      int n=10;
      int v[n];
      int e=0;
      int index=0;
      while(true){
            if(index<=10){
            cout<<"Inserisci un numero: ";
            cin>>e;
            if(e<0){
				if(index<=9){
                	v[index]=e;
            }
            	else
                	v[index-1]=e;
                	
           		for(int i=0; i<index; i++)
                	cout<<v[i]<<" ";
            	
				cout<<endl;
			}
			else{
				if(index<=9){
                	v[index]=e;
                	index=index+1;
	            }
	            	else
	                	v[index-1]=e;
	           		for(int i=0; i<index; i++)
	                	cout<<v[i]<<" ";
	            	cout<<endl;
			}
		}
    } 
    return 0; 
}  
