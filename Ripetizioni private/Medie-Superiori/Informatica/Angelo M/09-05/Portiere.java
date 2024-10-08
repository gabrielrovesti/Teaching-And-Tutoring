public class Portiere extends Calciatore{
    // extends = sono una sottoclasse
    private int golSubiti;
    private int rigoriSubiti;
    private int rigoriParati;

    public Portiere(int golSubiti,
    int rigoriSubiti, int rigoriParati, String nome, int partite, int gol, double valore){
        // richiamo superclasse
        super(nome, partite, gol, valore);

        this.golSubiti = golSubiti;
        this.rigoriSubiti = rigoriSubiti;
        this.rigoriParati = rigoriParati;
    }

    public Portiere(Portiere p){
        super(p);
        this.golSubiti = p.getGolSubiti();
        this.rigoriParati = p.getRigoriParati();
        this.rigoriSubiti = p.getRigoriSubiti();
    }
    public int getGolSubiti() {
        return golSubiti;
    }

    public void setGolSubiti(int golSubiti) {
        this.golSubiti = golSubiti;
    }

    public int getRigoriSubiti() {
        return rigoriSubiti;
    }

    public void setRigoriSubiti(int rigoriSubiti) {
        this.rigoriSubiti = rigoriSubiti;
    }

    public int getRigoriParati() {
        return rigoriParati;
    }

    public void setRigoriParati(int rigoriParati) {
        this.rigoriParati = rigoriParati;
    }
}
