class Giocatore {
    private String nome;
    private String classe;
    private int puntiVita;
    private int puntiMana;

    public String getNome() {
        return nome;
    }

    public String getClasse() {
        return classe;
    }

    public int getPuntiVita() {
        return puntiVita;
    }

    public int getPuntiMana() {
        return puntiMana;
    }

    public Giocatore(String nome, String classe, int puntiVita, int puntiMana) {
        this.nome = nome;
        this.classe = classe;
        this.puntiVita = puntiVita;
        this.puntiMana = puntiMana;
    }

    public void attacca(Mostro avversario, int danno) {
        avversario.subisciDanno(danno);
    }

    public void difendi(int danno) {
        puntiVita -= danno;
    }

    public void stampaStato() {
        System.out.println("Nome: " + nome);
        System.out.println("Classe: " + classe);
        System.out.println("Punti Vita: " + puntiVita);
        System.out.println("Punti Mana: " + puntiMana);
    }
}


