#include <stdio.h>

/*
Scrivere un programma che calcoli il minimo comune multiplo tra tre numeri n1, n2, n3 > 0.
Il minimo comune multiplo può essere ottenuto facendo la scomposizione in fattori primi dei tre numeri
e poi moltiplicando tra loro tutti i fattori dei tre numeri, sia quelli comuni che quelli non comuni.
Attenzione:
1) Ogni fattore deve essere moltiplicato dopo essere stato elevato al massimo esponente apparso nella
scomposizione in fattori primi. Per esempio: se n1=6=2*3, n2=12=2*2*3 e n3=24=2*2*2*3 allora il fattore
2 deve essere moltiplicato elevato alla terza potenza (2*2*2).
2) Ogni fattore comune va moltiplicato una sola volta, nell'esempio precedente il fattore 2 va prima elevato
alla terza potenza e poi moltiplicato una unica volta per raggiungere il risultato.
*/

/*
Una strategia che potete adottare è la seguente:
Per ogni numero primo p minore di n1, n2, n3, recuperate gli esponenti e1, e2, e3 t.c. p^e1 è fattore primo di n1,
p^e2 è fattore primo di n2, e poi moltiplicate il vostro risultato per il massimo tra questi tre valori.
Dividete n1 per p^e1, n2 per p^e2 e n3 per p^e3 e procedete fino a che n1, n2, n3 diventano tutti e tre uguali a 1.
*/

// Restituisce l'esponente e massimo per cui f^e divide n.
// Se f non divide n ritorna 0
// Pre: n >=0, f > 1
int fattore_primo(int n, int f);

// Se il numero n è primo ritorna 1 (true), altrimenti ritorna 0 (false)
// Pre: n > 0
int verifica_primo(int n);

// Restituisce il valore massimo tra n1, n2, n3
int max(int n1, int n2, int n3);

// Restituisce il numero base elevato alla potenza indicata da esponente
// Pre: esponente >= 0
int potenza(int base, int esponente);

// Restituisce il minimo comune multiplo tra i numeri n1, n2, n3
int mcm(int n1, int n2, int n3);

int main () {
  int res = mcm(18, 84, 360);
  printf("%d\n", res);
}

int fattore_primo(int n, int f) {
  int e = 0;
  while (n % f == 0) {
    e++;
    n = n / f;
  }
  return e;
}

int max(int n1, int n2, int n3) {
  int max = 0;
  if (n1 > max) max = n1;
  if (n2 > max) max = n2;
  if (n3 > max) max = n3;

  return max;
}

int verifica_primo(int n) {
  int primo = 1;

  if (n > 1) {
    int f = 2;
    while (f < n && primo) {
      if (n % f == 0) primo = 0;
      f++;
    }
  }

  return primo;
}

int potenza(int base, int esponente) {
  int risultato = 1;
  for (int i = 0; i < esponente; i++) {
    risultato = risultato * base;
  }
  return risultato;
}

int mcm(int n1, int n2, int n3) {
  int risultato = 1;
  int f = 2;

  while (n1 > 1 || n2 > 1 || n3 > 1) {
    if (verifica_primo(f)) {
      int e_n1 = fattore_primo(n1, f);
      n1 = n1 / potenza(f, e_n1);
      int e_n2 = fattore_primo(n2, f);
      n2 = n2 / potenza(f, e_n2);
      int e_n3 = fattore_primo(n3, f);
      n3 = n3 / potenza(f, e_n3);

      int max_e = max(e_n1, e_n2, e_n3);
      risultato = risultato * (potenza(f, max_e));
    }

    f++;
  }

  return risultato;
}