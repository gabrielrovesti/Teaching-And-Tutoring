import java.util.*;

public class Es14_9 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Inserisci un numero intero: ");
        int numero = input.nextInt();
        
        // Creazione pila per memorizzazione cifre in ordine inverso (LIFO)
        // Push = Inserimento
        // Pop = Rimozione
        Stack<Integer> pila = new Stack<>();
        
        // Casi da gestire (particolari)
        // (1). Zero -> Push subito
        // (2). Negativo -> Assoluto (gestire come positivo)
       
        if(numero == 0) {
            pila.push(0);
        } else {
            // Gestione numeri negativi
            boolean negativo = numero < 0;
            if(negativo) numero = -numero;
            
            // Scomposizione numero
            while(numero > 0) {
                int cifra = numero % 10;
                pila.push(cifra);
                numero /= 10;
            }
            
            // Se il numero era negativo, aggiungiamo il segno
            if (negativo) {
                System.out.print("-");
            }
            
            // Visualizzazione cifre separate da spazi
            while(!pila.isEmpty()) {
                System.out.print(pila.pop() + " ");
            }
        }
        
        input.close();
    }
}

// Funzionava già correttamente

// For example, when you input 1729:
// 
// It pushes 9, 2, 7, 1 onto the stack (in that order)
// Then pops and prints them, resulting in "1 7 2 9"
// 
// The key points about your stack implementation:
// 
// You're using it correctly for LIFO (Last In, First Out) behavior