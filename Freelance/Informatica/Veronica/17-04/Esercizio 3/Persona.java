public class Persona {
    protected String nome;
    protected String cognome;
    protected String CF;

    public Persona(String nome, String cognome, String CF) {
        this.nome = nome;
        this.cognome = cognome;
        this.CF = CF;
    }

    // Metodi getter per i vari attributi
    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public String getCF() {
        return CF;
    }
}
