public class Animale {
    private String nome;
    private int eta;

    public Animale(String nome, int eta){
        this.nome = nome;
        this.eta = eta;
    }

    public String Suono(){
        return "il verso dell'animale è: ";
    }

    public String toString(){
        return "nome: " + nome + " eta: " + eta;
    }
}
