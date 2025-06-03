public class Uccello extends Animale{
    private String nome;
    private int eta;
    private int lunghezzaAli;

    public Uccello(String nome, int eta, int lunghezzaAli){
        super(nome, eta);
        this.lunghezzaAli = lunghezzaAli;
    }

    public String Suono(){
        return super.Suono() + "Cip!";
    }

    public String toString(){
        return super.toString() + " lunghezzaAli: " + lunghezzaAli;
    }
}
