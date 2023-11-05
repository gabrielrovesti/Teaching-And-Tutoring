// Cosa stampa ogni riga del Main?

class Nodo;
 class Smart {
    friend class Lista;
    private:
        Nodo* punt;
    public:
        Smart(Nodo* p=0): punt(p) {}
        ~Smart();
        bool operator==(const Smart& s) const {return punt==s.punt;}
        Nodo* operator->() const {return punt;}
        Smart& operator=(const Smart&);
};
 class Nodo {
   friend class Lista; friend class Smart;
 private:
   int x;
   Smart next;
 public:
   Nodo(int z =0, const Smart& n = 0): x(z), next(n) {}
   ~Nodo() {cout << "  ~N";} };
 Smart& Smart::operator=(const Smart& s) {
   Nodo* t = punt;
   punt = new Nodo(s->x);
   delete t;
   return *this;
 };
Smart:: ̃~Smart() {if(punt) delete punt; cout << " ~S";}
 class Lista {
 private:
   Smart first;
 public:
   Lista() : first(0) {}
   Lista(int k): first(new Nodo(k)) {
    if(k>0) first->next = new Nodo(k+1);
    }
   void remove() 
   {if(!(first==0)) first = first->next;
   }
};
int main() {
   Lista x1; cout << " **1\n";
   Lista x2(5); cout << " **2\n";
   Lista* p = new Lista(3); cout << " **3\n";
   delete p; cout << " **4\n";
   Lista x3(0); cout << " **5\n";
   x2.remove(); cout << " **6\n";
}