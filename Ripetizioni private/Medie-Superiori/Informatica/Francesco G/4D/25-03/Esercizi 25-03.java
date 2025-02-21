/*
    Creami una classe Dipendente che contiene nome, cognome, ruolo e stipendio
    dotata di costruttore e dell'overloading del metodo toString
*/
import java.util.Date; // libreria = "inserisco altre funzionalità" - es. data

public static void main(String[] args){
    // Uso degli oggetti creati in altre classi

    // new = crea un oggetto "dinamicamente"
    Dipendente mario = new Dipendente("Mario", "Rossi");

    // Uso dei metodi della classe
    System.out.println(mario.toString()); 

}

public class Dipendente{
    // attributi = caratteristiche di una classe
    private static int numeroDipendenti = 0; // static = una sola istanza durante tutto l'arco del programma
    // incapsulamento = information hiding

    private String nome;
    private String cognome;
    private String ruolo;
    private double stipendio;

    // costruttore = serve a dare valore a (tutti gli) attributi
    public Dipendente(String n, String c, String r, double s){
        // this = puntatore al tipo di contesto
        // this = Dipendente
        this.numeroDipendenti++;
        // unico oggetto di tipo dipendente
        this.nome = n;
        this.cognome = c;
        this.stipendio = s;
        // this = riferimento "al tipo attuale"
        // non creo una nuova variabile, ma uso quelle locali
        // esistenti per "usarne i valori"
        // Uso classico = dentro i costruttori
    }

    /*
    Per farti capire come funziona "this"

    public int qualcosa(){
        this // int
    }

    this // Dipendente
    /// globalmente qua dentro vale come dipendente
    /// essendo "la sua classe"

    public double qualcosaltro{
        this // double
    }
    */

    // Overloading = stesso nome/cambiano i parametri
    // (si può fare)
    // public Dipendente(String nome, String cognome, String ruolo){
    //    
    // }

    // public Dipendente(String nome, String cognome){
    //    
    // }
    
    // Funzione = caratteristica di una classe
    // Visibilità - tipo di ritorno - nome
    // Parametri (numero1, numero2)
    public int somma(int numero1, int numero2){
        return numero1 + numero2;
    }

    // toString = "stampami i campi della classe"
    
    public String toString(){
        return "Dipendente: " + "id: " + id + "stipendio: " + stipendio + "ruolo: " + ruolo + "nome: " + nome + "cognome: " + cognome;
    }

    // equals = "voglio vedere se gli oggetti del tipo classe sono uguali tra di loro o meno"
    // Esempio d'uso:
    // Dipendente luca;
    // Dipendente mario;
    // if (luca.equals(mario))
    public boolean equals(Operaio operaio){
        boolean ris = false;
        if (this == operaio) // è tutto uguale 
        return true;
        if(this.stipendio == stipendio && this.ruolo == ruolo){
            super.equals(operaio); // super = eredita da sopra
            ris = true;
        }
        return ris;
    }

    // Metodo di calcolo dello stipendio, dando come input un dipendente, sulla base di fasce di stipendio
    // (sotto una certa soglia ) --> 1200
    // (uguale ad una certa soglia fissata) --> 1500 * 15% (0.15)
    // e lo ritorniamo
    // Funzionalità "globale" = vista sempre

    public static double calcoloStipendio(Dipendente dip){
        double stip = 0;
        if(this.stipendio < 1200){
            stip = 1200;
        }
        else stip = 1500 * 0.15;

        return stip;
    }
}

// Ereditarietà = hai almeno gli attributi della classe
// e aggiungi tu del significato
public class Operaio extends Dipendente{
    private String settore; // aggiungiamo come "significato" il campo "settore"

    // Struttura "classica" classi:
    // equals
    // toString
    // suoi metodi
}

// Vettore - array

// Ogni classe ha il nome del file
// Camel Case = nome con maiuscole intorno
class ArrayInteri{
    // attributi

    // attraversamento
    for(int i=0; i<10; i++){
        System.out.println("Elemento in posizione: " + i + "con valore: " + ArrayInteri[i]),
    }

    // ricerca lineare
    void ricerca(int[] arr, int k){
        for(int i=0; i<n; i++){
            if(k == arr[i]) // lo trovo in mezzo
            return "Trovato";
        }
    }

    // modifica

    void modifica(int[] arr, int k){
        for(int i=0; i<n; i++){
            if(k == arr[i]) // lo trovo in mezzo
            arr[i] = 5; // modifica l'elemento i-esimo
        }
    }
    // eliminazione
    void eliminazione(int[] arr, int k){
        for(int i=0; i<n; i++){
            if(k == arr[i]) // lo trovo in mezzo
            arr[i] = 0; // modo "safe" di cancellare
        }
    }
}
