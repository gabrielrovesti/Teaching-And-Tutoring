public class Contatore{

    // 5 (numero passato)
    // 4 3 2 1 0 (quello che fa il metodo)
    // countdown finché numero !=0

    public int contatore(int i){
        // caso base
        if(i == 0) return 0;
        return contatore(i-1);
    }

    
}

