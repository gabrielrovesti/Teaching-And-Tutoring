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
    Z=x.F(y); // (1) COMPILA PERCHÈ Z NON È COSTANTE
    v.F(y); // (2) NON COMPILA PERCHÈ V È COSTANTE MA F NON HA LA MARCATURA CONST --- QUINDI SERVIREBBE DEFINIRE IL METODO CONST O TOGLIERLO IN FASE DI DEFINIZIONE
    V.G(y); // {3) COMPILA
    (v.G(y)).F(x); // (4) COMPILA
    (v. G(y)).G(x); // (5) COMPILA
    x.H(v); // (6) NON COMPILA PERCHÈ H PRENDE COME PARAMETRO UN RIFERIMENTO A C, MA V È UN CONST, QUINDI SERVIREBBE UN CONST C
    x.H(z.G(y)); // (7) NON COMPILA PERCHÈ H PRENDE COME PARAMETRO UN RIFERIMENTO A C, MA STIAMO FACENDO RIFERIMENTO AD UNA VARIABILE DEALLOCATA TEMPORANEA,
                 // PERCHE IL RETURN INVOCA IL COSTRUTTORE COPIA CHE VA A CREARE UNA VARIABILE TEMPORANEA E PASSERÀ L'ELEMENTO
    x.I(z.G(y)); // (8) COMPILA A DIFFERENZA DELLA 7 PER LA PRESENZA DEL CONST
    x.J(z.G(y)); // (9) COMPILA PERCHE C'È IL CONST NELLA FUNZIONE MA IL DATO NON VIENE MODIFICATO
    v.J(z.G(y)); // (10) COMPILA
}