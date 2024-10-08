class Mostro {
    private String nome;
    private int puntiVita;

    public String getNome() {
        return nome;
    }

    public int getPuntiVita() {
        return puntiVita;
    }

    public Mostro(String nome, int puntiVita) {
        this.nome = nome;
        this.puntiVita = puntiVita;
    }

    public void attacca(Giocatore avversario, int danno) {
        avversario.difendi(danno);
    }

    public void subisciDanno(int danno) {
        puntiVita -= danno;
    }

    public void stampaStato() {
        System.out.println("Nome: " + nome);
        System.out.println("Punti Vita: " + puntiVita);
    }
}

