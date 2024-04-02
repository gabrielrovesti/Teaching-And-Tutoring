class Giocatore{
    // Attributi

    private String nome;
    private String classe;
    private int puntiVita;
    private int puntiMana;
    private String messaggio;

    // Getter / Setter

    public String getNome(){
        return nome;
    }

    public String getClasse(){
        return classe;
    }

    public int getPuntiVita(){
        return puntiVita;
    }

    public String getInfo(){
        return messaggio;
    }

    // Costruttore

    public Giocatore(String nome, String classe, int puntiVita, int puntiMana){
        this.nome = nome;
        this.classe = classe;
        this.puntiVita = puntiVita;
        this.puntiMana = puntiMana;
    }

    // Overloading

    public Giocatore(){
        this.nome = null;
        this.classe = null;
        this.puntiVita = 0;
        this.puntiMana = 0;
    }

    public void attacca(Mostro mostro, int danno){
        if(danno > 0){
            if (classe.equals("Guerriero")){
                mostro.subisciDanno(danno + 50);
                puntiMana += 5;
            }
            if (classe.equals("Guaritore")){
                mostro.subisciDanno(danno + 10);
                puntiMana += 10;
            }
        }
        else 
            messaggio += "Esegui un attacco!";
    }

    public void difendi(int danno){
        boolean guardia = false;
        if(danno > 0){
            if (classe.equals("Guerriero")){
                puntiVita -= 10;
            }
            if (classe.equals("Guaritore")){
                puntiVita -= 20;
                rigenera(true);
            }
        }
        else 
            messaggio += "Esegui un attacco!";
    }

    public void rigenera(boolean guard){
        if(guard) puntiVita += 15;
    }

    public String stampaStato(){
        return ("Nome: " + nome + ", punti vita: " + puntiVita);
    }
}