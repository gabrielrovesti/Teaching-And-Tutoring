import java.time.LocalDate;
import java.util.Scanner;

/**
 * Classe tester per simulare l'acquisto di prodotti
 */
public class ProdottoDemo {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        // Creo un esempio di prodotto alimentare
        ProdottoAlimentare pa = new ProdottoAlimentare("PA1", "Yogurt", 10.00, 
                LocalDate.now().plusDays(5)); // Scadenza a 5 giorni da oggi (quindi sconto 50%)
        
        // Creo un esempio di prodotto non alimentare riciclabile
        ProdottoNonAlimentare pna = new ProdottoNonAlimentare("PNA1", "Quaderno", 20.00, "Carta");
        
        System.out.println("===== SIMULAZIONE ACQUISTO =====");
        
        System.out.println("\nProdotti disponibili:");
        System.out.println("1. " + pa);
        System.out.println("2. " + pna);
        
        System.out.println("\nPossiedi una carta fedeltà? (si/no)");
        String haCartaFedelta = input.nextLine().trim().toLowerCase();
        boolean cartaFedelta = haCartaFedelta.equals("si") || haCartaFedelta.equals("sì");
        
        System.out.println("\nSeleziona il prodotto da acquistare (1 o 2):");
        int scelta = Integer.parseInt(input.nextLine().trim());
        
        double spesaTotale = 0.0;
        
        if (scelta == 1) {
            System.out.println("\nHai scelto il prodotto alimentare: " + pa);
            
            // Applico lo sconto appropriato
            pa.applicaSconto(10); // Il parametro verrà ignorato e applicherà la logica della sottoclasse
            
            System.out.println("Prezzo dopo l'applicazione dello sconto: " + pa.getPrezzo() + " euro");
            spesaTotale = pa.getPrezzo();
            
        } else if (scelta == 2) {
            System.out.println("\nHai scelto il prodotto non alimentare: " + pna);
            
            // Applico lo sconto appropriato
            pna.applicaSconto(10); // Il parametro verrà ignorato e applicherà la logica della sottoclasse
            
            System.out.println("Prezzo dopo l'applicazione dello sconto: " + pna.getPrezzo() + " euro");
            spesaTotale = pna.getPrezzo();
            
        } else {
            System.out.println("Scelta non valida!");
            input.close();
            return;
        }
        
        // Applico sconto carta fedeltà (ipotizzo un ulteriore 10% di sconto con carta fedeltà)
        if (cartaFedelta) {
            spesaTotale = spesaTotale * 0.90; // Sconto aggiuntivo del 10%
            System.out.println("Applicato sconto carta fedeltà del 10%");
        }
        
        System.out.println("\n===== TOTALE SPESA =====");
        System.out.println("Totale da pagare: " + spesaTotale + " euro");
        
        input.close();
    }
}
