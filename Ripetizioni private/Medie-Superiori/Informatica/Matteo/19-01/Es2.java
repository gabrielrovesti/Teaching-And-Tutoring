import java.util.Random;
import java.util.Scanner;

class Punto {
    private double x;
    private double y;
    private double z;

    // Costruttore con tre parametri
    public Punto(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    // Costruttore di copia
    public Punto(Punto altroPunto) {
        this.x = altroPunto.x;
        this.y = altroPunto.y;
        this.z = altroPunto.z;
    }

    // Metodo equals
    public boolean equals(Punto altroPunto) {
        return this.x == altroPunto.x && this.y == altroPunto.y && this.z == altroPunto.z;
    }

    // Getter e setter
    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getZ() {
        return z;
    }

    public void setZ(double z) {
        this.z = z;
    }

    // Metodo distanzaOrigine
    public double distanzaOrigine() {
        return Math.sqrt(x * x + y * y + z * z);
    }

    // Metodo distanzaDaAltroPunto
    public double distanzaDaAltroPunto(Punto altroPunto) {
        double deltaX = this.x - altroPunto.x;
        double deltaY = this.y - altroPunto.y;
        double deltaZ = this.z - altroPunto.z;
        return Math.sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
    }

    // Metodo toString
    @Override
    public String toString() {
        return "[" + x + "," + y + "," + z + "]";
    }
}

public class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        // Creazione di un array di punti con dimensione 10
        Punto[] arrayDiPunti = new Punto[10];

        // Popolazione dell'array con punti casuali
        for (int i = 0; i < arrayDiPunti.length; i++) {
            double x = random.nextDouble() * 200 - 100; // Numeri compresi tra -100 e 100
            double y = random.nextDouble() * 200 - 100;
            double z = random.nextDouble() * 200 - 100;
            arrayDiPunti[i] = new Punto(x, y, z);
        }

        // Chiede all'utente di inserire due numeri da 1 a 10
        System.out.print("Inserisci il primo numero da 1 a 10: ");
        int indicePunto1 = scanner.nextInt() - 1;

        System.out.print("Inserisci il secondo numero da 1 a 10: ");
        int indicePunto2 = scanner.nextInt() - 1;

        // Stampa le coordinate dei punti selezionati nell'array
        System.out.println("Coordinate del primo punto: " + arrayDiPunti[indicePunto1].toString());
        System.out.println("Coordinate del secondo punto: " + arrayDiPunti[indicePunto2].toString());

        // Stampa la distanza tra i due punti
        double distanzaTraPunti = arrayDiPunti[indicePunto1].distanzaDaAltroPunto(arrayDiPunti[indicePunto2]);
        System.out.println("Distanza tra i due punti: " + distanzaTraPunti);

        // Stampa la distanza del primo punto e del secondo punto dall'origine
        System.out.println("Distanza del primo punto dall'origine: " + arrayDiPunti[indicePunto1].distanzaOrigine());
        System.out.println("Distanza del secondo punto dall'origine: " + arrayDiPunti[indicePunto2].distanzaOrigine());

        // Chiede all'utente di inserire altri due numeri da 1 a 10
        System.out.print("Inserisci il terzo numero da 1 a 10: ");
        int indicePunto3 = scanner.nextInt() - 1;

        System.out.print("Inserisci il quarto numero da 1 a 10: ");
        int indicePunto4 = scanner.nextInt() - 1;

        // Stampa se i due punti sono uguali o diversi
        if (arrayDiPunti[indicePunto3].equals(arrayDiPunti[indicePunto4])) {
            System.out.println("I due punti sono uguali.");
        } else {
            System.out.println("I due punti sono diversi.");
        }
    }
}
