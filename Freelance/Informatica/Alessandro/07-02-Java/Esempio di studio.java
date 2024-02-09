class Classe{

    private:
        int x; // Information hiding - Incapsulamento
    public:
        Classe(int x){
            this.x = x;
        }

        int getX(){ //fornire all'esterno come comportamento
            return x;
        }
        
}

class Triciclo{
    private double potenza;
    private boolean alimentazione;
    private int porte;

    public static void accendiMotore(){
        alimentazione = true;
    }
}

// Ereditarietà = extends
// Sottotipo/i che aggiunge/ono comportamento
// o che usa quanto fornisce la/le superclassi
class Ciclomotore extends Triciclo{
    private double potenza;
    private boolean alimentazione;
    private int porte;

    public static void accendiMotore(){
        alimentazione = true;
        porte = 50;
    }
};

// Astratta = non istanza oggetti e dichiara comportamento 
// implementato dagli altri

abstract class Animal {
  public abstract void animalSound(); //operazione da implementare
  public void sleep() { 
    System.out.println("Zzz");
  }
}

// Interfaccia = ha un contratto ed esegue un'operazione

public class Dog implements Animal{
    public void animalSound(){
        return;
        // this qui = void
    }
    // this qui = Dog
}

// this --> puntatore al contesto

