public class Gatto extends Animale{
    private String nome;
    private int eta;
    private String colorePelo;

    public Gatto(String nome, int eta, String colorePelo){
        super(nome, eta);
        this.colorePelo = colorePelo;
    }

    public String Suono(){
        return super.Suono() + "Miao!";
    }

    public String toString(){
        return super.toString() + " colorePelo: " + colorePelo;
    }
}
