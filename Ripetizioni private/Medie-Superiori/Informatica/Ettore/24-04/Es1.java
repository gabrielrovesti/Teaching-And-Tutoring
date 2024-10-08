import java.util.Scanner;
public class Es1 {
    public static void main(String[] args) {
        int numero, somma;
        Scanner input = new Scanner(System.in);
        System.out.println("Inserisci il numero: ");
        numero = input.nextInt();

        if(numero % 2 == 0){
            int i = 2;
            while(i <= n){
                somma += i;
                i += 2;
            }
        }
        if(numero % 2 == 1){
            int i = 1;
            while(i <= n){
                somma += i;
                i += 2;
            }
        }
    System.out.println("La somma è: " + somma);
    }
}
