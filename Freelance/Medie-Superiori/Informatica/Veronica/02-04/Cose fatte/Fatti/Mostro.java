class Mostro{
    // Attributi

    private String nome;
    private int puntiVita;
    private int puntiAttacco;
    private String elemento;

    public Mostro(String n, int pv, int pa, String e){
        this.nome = n;
        this.puntiVita = pv;
        this.puntiAttacco = pa;
        this.elemento = e;
    }

    public String getNome(){
        return nome;
    }

    public int getPuntiVita(){
        return puntiVita;
    }

    public void subisciDanno(int danno) {
        puntiVita -= danno;
    }

    public String stampaStato(){
        return "Nome: " + nome + ", punti vita: " + puntiVita;
    }
}