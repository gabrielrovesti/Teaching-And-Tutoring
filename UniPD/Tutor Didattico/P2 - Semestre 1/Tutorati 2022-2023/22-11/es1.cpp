// Cosa stampa il Main?

class N;

class Smart {
public:
    N* p;
    Smart(N* q = 0): p(q) {if(p) p->counter++; cout << "Smart() ";}
    Smart(const Smart& x): p(x.p) {if(p) p->counter++; cout << "SmartCopy() ";}
    ̃Smart() {
    if(p) {
        p->counter--; if(p->counter==0) delete p;
    };
    cout << " ̃Smart() ";
    }
    operator bool() {return p!=0;}
    Smart& operator=(const Smart& x) {
        Smart t = *this;
        p = x.p; if(p) p->counter++;
        cout << "Smart= ";
        return *this;
    }
    N* operator->() {return p;}
    bool operator==(const Smart& x) {return p==x.p;}
    bool operator==(N* x) {return p==x;}
};

class N {
public:
    string s;
    int counter;
    Smart next;
    N(string x, const Smart& y) : s(x), counter(0), next(y) {cout << "N() ";}
    ̃N() {cout << " ̃N ";}
};

class C {
public:
    Smart punt;
    C(string s="BIANCO"): punt(new N(s,0)) {}
    void add(string s) {punt = new N(s,punt);}
    void modify() {
        if(punt && punt->next) punt->next = (punt->next)->next;
    }
    void print() {
        while(punt) { cout << punt->s << " "; punt=punt->next; }
    }
};
main() {
    C c1; cout << " **0" << endl;
    C c2("ROSSO"); cout << " **1" << endl;
    C c3(c2); cout << " **2" << endl;
    c3.add("VERDE"); cout << " **3" << endl;
    c3.add("BLU"); cout << " **4" << endl;
    c3.modify(); cout << " **5" << endl;
    c1=c3; cout << " **6" << endl;
    c1.print(); cout << " **7" << endl;
    c2.print(); cout << " **8" << endl;
    c3.print(); cout << " **9" << endl;