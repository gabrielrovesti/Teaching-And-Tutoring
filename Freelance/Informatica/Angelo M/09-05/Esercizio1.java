// Classe astratta per le forme geometriche
abstract class FormaGeometrica {
    // Metodi astratti per calcolare l'area e il perimetro
    abstract double calcolaArea();
    abstract double calcolaPerimetro();
}

// Sottoclasse Cerchio
class Cerchio extends FormaGeometrica {
    double raggio;

    Cerchio(double raggio) {
        this.raggio = raggio;
    }

    @Override
    double calcolaArea() {
        return Math.PI * raggio * raggio;
    }

    @Override
    double calcolaPerimetro() {
        return 2 * Math.PI * raggio;
    }
}

// Sottoclasse Quadrato
class Quadrato extends FormaGeometrica {
    double lato;

    Quadrato(double lato) {
        this.lato = lato;
    }

    @Override
    double calcolaArea() {
        return lato * lato;
    }

    @Override
    double calcolaPerimetro() {
        return 4 * lato;
    }
}

// Sottoclasse Rettangolo
class Rettangolo extends FormaGeometrica {
    double base;
    double altezza;

    Rettangolo(double base, double altezza) {
        this.base = base;
        this.altezza = altezza;
    }

    @Override
    double calcolaArea() {
        return base * altezza;
    }

    @Override
    double calcolaPerimetro() {
        return 2 * (base + altezza);
    }
}

// Classe principale per testare le forme geometriche
public class Main {
    public static void main(String[] args) {
        // Creazione di diverse forme geometriche
        FormaGeometrica cerchio = new Cerchio(5);
        FormaGeometrica quadrato = new Quadrato(4);
        FormaGeometrica rettangolo = new Rettangolo(3, 6);

        // Stampa delle informazioni delle forme geometriche
        stampaInformazioni(cerchio);
        stampaInformazioni(quadrato);
        stampaInformazioni(rettangolo);
    }

    // Metodo per stampare le informazioni di una forma geometrica
    static void stampaInformazioni(FormaGeometrica forma) {
        System.out.println("Tipo di forma geometrica: " + forma.getClass().getSimpleName());
        System.out.println("Area: " + forma.calcolaArea());
        System.out.println("Perimetro: " + forma.calcolaPerimetro());
        System.out.println();
    }
}
