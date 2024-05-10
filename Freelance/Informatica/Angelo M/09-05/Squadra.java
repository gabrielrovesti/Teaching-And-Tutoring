import java.util.ArrayList;
public class Squadra {
    private String nome;
    private int anno;
    private ArrayList<Calciatore> rosa;

    public Squadra(){
        this.rosa = new ArrayList<>();
    }

    public void inserisciCalciatore(Calciatore c){
        if(c != null) rosa.add(c);
        // this.rosa.add(c); // puntatore al tipo Calciatore
    }

    public int cerca(String nome){
        for(int i = 0; i < rosa.size(); i++){
            if(rosa.get(i).getNome() == nome){
                return i;
            }
        }

        for(Calciatore c: rosa){
            if(rosa.contains(c)){
                if(c.getNome() == nome)
                   return rosa.indexOf(c);
            }
        }
    }

    public void stampaRosa(){
        for(int i = 0; i < rosa.size(); i++){
            if(rosa.get(i) instanceof Portiere){
                // toString()
            }
        }
    }

    // instanceOf
    // polimorfismo --> controlla se oggetto è di tipo X
    // Calciatore - Portiere

    // Controllo massimo
    // max
    // if num > max
    // max = num

    public Calciatore calciatoreConPiuGol()
    {
        Calciatore max = null;

        for(int i=0; i < rosa.size(); i++)
        {
            if (rosa.get(i).getGolSegnati() > max.getGolSegnati())
            {
                max = rosa.get(i);
            }
        }

        return max;
    }
}
