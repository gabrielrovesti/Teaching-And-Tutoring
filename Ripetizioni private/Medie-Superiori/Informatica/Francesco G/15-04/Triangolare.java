public class Triangolare {
    public int numTriangolare(int n){
        // caso base 
        if(n == 1){
            risultato = 1;
            System.out.println("[]");
            // stampi il fatto "che sia vuoto"
        }
        else{
            risultato = n + (numTriangolare(n-1)); // triangolo che va avanti
            // a numeri "finché ha caratteri da consumare"
            // es. 10 ne stampa 10, poi 9, poi 8.... finché non arriva ad 1
            // e va sull'if fermandosi
            System.out.println(" ");
            for(int i=0; i<=n; i++)
                System.out.println(n);
        }

        return risultato;
    }
}

/* 


Output:
                        []
                        *
                    *       *   
                *       *       *
            *       *       *       *
        *       *       *       *       *
    *       *       *       *       *       *

numerotriangolare(6)

Output:
                []
(continuando....)
    *   *   *   *   *   *   *  
    *   *   *   *   *   *   *   *
*   *   *   *   *   *   *   *   *   *
numerotriangolare(10)
*/

