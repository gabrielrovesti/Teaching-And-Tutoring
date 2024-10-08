#include <stdio.h>

/*
Scrivere un programma che, dato un intero n >= 0 e un numero primo p (> 1), restituisca il numero n diviso per p^e (p elevato alla potenza e)
dove e è la potenza con cui p compare nella scomposizione in fattori primi di n.
Se p non compare nella scomposizione in fattori primi di n allora restituire n / (p^0) = n

Esempi:
- se n = (2^3) * 5 = 40 e p = 2, il programma deve restituire 5
- se n = (2^3) * 5 = 40 e p = 5, il programma deve restituire 8
- se n = (2^3) * 5 = 40 e p = 7, il programma deve restituire 40
*/

// Restituisce l'esponente e massimo per cui p^e divide n.
// Se p non divide n ritorna 0
// Pre: n >= 0, p numero primo > 1
int fattore_primo(int n, int p);

// Restituisce il numero base elevato alla potenza indicata da esponente
// Pre: esponente >= 0
int potenza(int base, int esponente);

int main () {
	int n;
  int p;
	scanf("%d %d", &n, &p);

	// INSERITE QUI IL VOSTRO CODICE (non modificate le righe sopra)
	int e = fattore_primo(n, p);
  int res = n / potenza(p, e);
  // INSERITE QUI SOPRA IL VOSTRO CODICE (non modificate le righe sotto)

	printf("%d\n", res);
}


int fattore_primo(int n, int p) {
  int e = 0;
  while (n % p == 0) {
    e+=1;
    n = n / p;
  }
  return e;
}

int potenza(int base, int esponente) {
  int risultato = 1;
  for (int i = 0; i < esponente; i++) {
    risultato = risultato * base;
  }
  return risultato;
}