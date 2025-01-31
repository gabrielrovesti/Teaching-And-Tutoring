import java.util.Random;

public class EsempioRandom {

    public static void main(String[] args) {
        // Creazione di un oggetto Random
        Random random = new Random();

        // 1. Generare un numero intero casuale (può essere positivo o negativo)
        int numeroCasuale = random.nextInt();
        System.out.println("Numero intero casuale: " + numeroCasuale);

        // 2. Generare un numero intero casuale compreso tra 0 e un valore massimo (es. 100)
        int numeroLimitato = random.nextInt(100); // Genera un numero tra 0 e 99
        System.out.println("Numero casuale tra 0 e 99: " + numeroLimitato);

        // 3. Generare un numero decimale casuale tra 0.0 e 1.0
        double numeroDecimale = random.nextDouble();
        System.out.println("Numero decimale casuale tra 0.0 e 1.0: " + numeroDecimale);

        // 4. Generare un numero decimale casuale tra 0.0 e 10.0
        double numeroDecimaleScala = random.nextDouble() * 10; // da 0 a 9.999...
        System.out.println("Numero decimale casuale tra 0.0 e 10.0: " + numeroDecimaleScala);

        // 5. Generare un numero booleano casuale (true o false)
        boolean valoreCasuale = random.nextBoolean();
        System.out.println("Valore booleano casuale: " + valoreCasuale);

        // 6. Generare un numero intero casuale in un range specifico (es. tra 50 e 100)
        int numeroInRange = random.nextInt(51) + 50; // Genera un numero tra 50 e 100
        System.out.println("Numero casuale tra 50 e 100: " + numeroInRange);
    }
}
