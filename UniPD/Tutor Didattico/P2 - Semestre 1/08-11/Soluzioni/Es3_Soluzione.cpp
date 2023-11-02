/*
Definire una classe Matrice che rappresenta una matrice di interi NxM. La classe deve avere:

- Un costruttore di default che inizializza una matrice 3x3 a 0
- Un costruttore che accetta come parametri N e M e inizializza una matrice NxM a 0
- Un metodo per stampare la matrice
- Operatori per l'accesso in lettura e scrittura tramite indici (i,j)
- Operatore di uguaglianza per il confronto tra matrici
- Costruttore di copia "profonda"
- Overload dell'operatore = per assegnazione "profonda"
*/

#include <iostream>

class Matrice {
private:
  int** elem;
  int righe;
  int colonne;

public:

  Matrice() {
    righe = 3;
    colonne = 3;
    elem = new int*[righe];
    for(int i=0; i<righe; i++) {
      elem[i] = new int[colonne];
    }
    
    for(int i=0; i<righe; i++) {
      for(int j=0; j<colonne; j++) {
        elem[i][j] = 0;  
      }
    }
  }

  Matrice(int n, int m) {
    righe = n;
    colonne = m;
    elem = new int*[righe];
    for(int i=0; i<righe; i++) {
      elem[i] = new int[colonne]; 
    }
    
    for(int i=0; i<righe; i++) {
      for(int j=0; j<colonne; j++) {
        elem[i][j] = 0;
      }
    }
  }

  void stampa() {
    for(int i=0; i<righe; i++) {
      for(int j=0; j<colonne; j++) {
        std::cout << elem[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  int operator()(int i, int j) {
    return elem[i][j];
  }

  int& operator()(int i, int j) {
    return elem[i][j];
  }

  bool operator==(const Matrice& m) {
    if(righe != m.righe || colonne != m.colonne) {
      return false;
    }
    for(int i=0; i<righe; i++) {
      for(int j=0; j<colonne; j++) {
        if(elem[i][j] != m.elem[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
  
  Matrice(const Matrice& m) {
    righe = m.righe;
    colonne = m.colonne;
    elem = new int*[righe];
    for(int i=0; i<righe; i++) {
      elem[i] = new int[colonne];
    }
    for(int i=0; i<righe; i++) {
      for(int j=0; j<colonne; j++) {
        elem[i][j] = m.elem[i][j];
      }
    }
  }

  Matrice& operator=(const Matrice& m) {
    if(this != &m) {
      for(int i=0; i<righe; i++) {
        delete[] elem[i];
      }
      delete[] elem;

      righe = m.righe;
      colonne = m.colonne;

      elem = new int*[righe];
      for(int i=0; i<righe; i++) {
        elem[i] = new int[colonne];
      }

      for(int i=0; i<righe; i++) {
        for(int j=0; j<colonne; j++) {
          elem[i][j] = m.elem[i][j];
        }
      }
    }
    return *this;
  }

};

int main() {

  Matrice m1(2,3);
  m1(0,1) = 5;
  m1(1,2) = 10;

  Matrice m2 = m1;
  
  Matrice m3(2,3);
  m3 = m1;

  if(m1 == m3) {
    std::cout << "m1 e m3 sono uguali" << std::endl;
  }

  m1.stampa();

  return 0;
}