import java.util.ArrayList;

public class Squadra {
    private String nome;
    private int numGiocatori;
    private ArrayList<Calciatore> giocatori;
    private static final int maxSostituzioni = 3;

    public Squadra(){
        this.giocatori = new ArrayList<Calciatore>();
    }

    public void sostituisci(Calciatore c, String nome, int numero){
        for(Calciatore g: giocatori){
            if(g.getNome().equals(nome) && g.getNumero() == numero){
                if(this.maxSostituzioni < 3 && c.maxSostituzioni <=3){
                    g.modifica(c);
                }
            }
            else return;
        }
    }

    public Calciatore capoCannoniere() {
        Calciatore max = null;
        for(Calciatore g: giocatori){
            if(g.getGolSegnati() > max.getGolSegnati)
                max = g;
        }
        return max;
    }
}
