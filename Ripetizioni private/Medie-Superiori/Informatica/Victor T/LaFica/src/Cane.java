public class Cane extends Animale{
    private String nome;
    private int eta;
    private String razza;

    public Cane(String nome, int eta, String razza){
        super(nome, eta);
        this.razza = razza;
    }

    public String Suono(){
        return super.Suono() + "Bau!";
    }

    public String toString(){
        return super.toString() + " razza: " + razza;
    }
}
