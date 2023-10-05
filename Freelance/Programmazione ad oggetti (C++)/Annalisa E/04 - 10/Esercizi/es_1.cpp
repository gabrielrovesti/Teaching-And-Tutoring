// QUALI CHIAMATE A FUNZIONE NEL MAIN COMPILANO E QUALI NO:
class C {
    private:
        int x;
    public:
        C(int n = 0) { x = n; }
        C F(C obj) {C r; r.x = obj.x + x; return r;}
        C G(C obj) const {C r; r.x = obj.x + x; return r;}
        C H(C& obj) {obj.x += x; return obj;}
        C I(const C& obj) {C r; r.x = obj.x + x; return r:}
        C J(const C& obj) const {C r; r.x = obj.x + x; return r;}
};
int main() {
    C x, y(1), z(2); const C v(2);

    Z=x.F(y); // Compila perché Z è un oggetto non costante e fa match col parametro C
    v.F(y); // Non compila perché è costante
    V.G(y); // Compila
    (v.G(y)).F(x); // Compila
    (v.G(y)).G(x); // Compila
    x.H(v);
    x.H(z.G(y));
    x.I(z.G(y));
    x.J(z.G(y));
    v.J(z.G(y));
}