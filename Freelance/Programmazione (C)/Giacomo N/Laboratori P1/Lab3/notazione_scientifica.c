#include <stdio.h>

/*
	Calcolo notazione scientifica di un numero reale
*/

float notazione_scientifica(float x, int *n);

int main (void) {

	float x;
	int n;
	scanf("%f", &x);

	// INVOCARE QUA LA VOSTRA FUNZIONE (non modificare il main in altro modo)
	x = notazione_scientifica(x, &n);

	printf("x=%f,n=%d\n", x, n);

}


/* 
	PRE: 
	POST: restituisce x' e modifica *n in modo che 1<=x'<10 e x=x'*10^(*n). 
*/
float notazione_scientifica(float x, int *n) {

	*n=0;
	while (x<1 || x>=10) {
		if(x<1) {
			x*=10.0;
			*n+=1;
		} else {
			x/=10.0;
			*n+=-1;
		}
	}
	return x;
}
