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
    C x, y (1), z(2); const C v(2);
    Z=x.F(y);
    v.F(y);
    V.G(y);
    (v.G(y)).F(x);
    (v. G(y)).G(x);
    x.H(v);
    x.H(z.G(y));
    x.I(z.G(y));
    x.J(z.G(y));
    v.J(z.G(y));
}