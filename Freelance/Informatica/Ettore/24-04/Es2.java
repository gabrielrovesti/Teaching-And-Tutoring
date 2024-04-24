import java.util.Scanner;
import java.util.random.*;
public class Es2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        // Password corretta
        int p = 1234; 
        // Password dell'utente
        int pu = 0;
        do{
            if(pu != p) System.out.println("Password invalida, inseriscila correttamente");
            System.out.println("Inserisci la password numerica: ");
            pu = input.nextInt();
        } while(pu != p);
        System.out.println("Password valida");
    }
}
