import java.util.Random;

public class RandomTester {
    public static void main(String[] args) {
        Random r1 = new Random(); //oggetto della classe Random

        System.out.println("HashCode: " + r1.hashCode()); // hashCode --> indirizzo di memoria
		// es. 53436268
        System.out.println("Random Object: " + r1.toString());
  
        int numeroCasuale = r1.nextInt(); // crea un numero intero (senza limiti)
        System.out.println("Numero casuale: " + numeroCasuale); 

        System.out.println("Altro numero casuale: " + r1.nextInt());

		// becchiamo tra 0 (incluso) e 6 (escluso) -> [0:5]
		// nextInt(n)  restituisce un numero intero casuale compreso fra 0 (incluso) e n (escluso);
		
        int numeroTraMeno5e5 = r1.nextInt(11) - 5;  //11 - 5 = 6
        System.out.println("Numero casuale tra -5 e 5: " + numeroTraMeno5e5);

		
        System.out.println("Cinque valori booleani casuali:");
        for (int i = 0; i < 5; i++) {
            System.out.println(r1.nextBoolean());
        }
		
		// nextDouble() restituisce un numero in virgola mobile casuale compreso fra 0 (incluso) e 1 (escluso).
        System.out.println("Dieci numeri reali tra 0.0 e 1.0:");
        for (int i = 0; i < 10; i++) {
            System.out.println(r1.nextDouble());
        }

        System.out.println("Simulazione lancio del dado:");
        boolean vinto = false;
        for (int i = 1; i <= 5; i++) {
            int lancio = r1.nextInt(6) + 1;
            System.out.println("Lancio " + i + ": " + lancio);
            if (lancio == 6) {
                vinto = true;
                System.out.println("Hai vinto");
                break;
            }
        }
        if (!vinto) {
            System.out.println("Hai perso");
        }
    }
}



