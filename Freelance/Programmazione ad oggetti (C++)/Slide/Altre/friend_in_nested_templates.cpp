#include<iostream>

// dichiarazione incompleta (forward declaration) di Ext<T>
template<class T> class Ext;

// dichiarazione del template di funzione fun<T> 
template<class T> void fun(const Ext<T>&);

// dichiarazione di Ext<T>
template<class T> class Ext { 
  friend void fun <T> (const Ext<T>&);
private:
  // dichiarazione incompleta di typename Ext<T>::Inner
  class Inner;
  Inner *p; 
};

// dichiarazione del template di funzione fun2 <T> 
template<class T> void fun2 (const typename Ext<T>::Inner&);

// dichiarazione di Ext<T>::Inner
template<class T>
class Ext<T>::Inner {
  // dichiarazioni di amicizia
  friend class Ext<T>;
  friend void fun <T> (const Ext<T>&);
  friend void fun2 <T> (const typename Ext<T>::Inner&);
private:
  Inner* q;
  int a;
  Inner(): a(1) {}
};

// definizione del template di funzione fun2 <T> 
template<class T> void fun2(const typename Ext<T>::Inner& i) {
  Ext<T> x;
  x.p = nullptr;
  i.a=2;
}

// definizione del template di funzione fun <T> 
template<class T> void fun(const Ext<T>& e) {
  e.p = nullptr;
  typename Ext<T>::Inner y;
  y.a=3;
  fun2<T> (y); // ATTENZIONE ad usare ist. esplicita fun2<T> 
}

int main() {
  Ext<int> x;
  fun(x);
}

