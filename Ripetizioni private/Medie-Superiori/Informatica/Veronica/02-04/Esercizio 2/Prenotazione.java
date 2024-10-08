public class Prenotazione {
    private int id;
    private String emailCliente;
    private int idPacchetto;

    public Prenotazione(int id, String emailCliente, int idPacchetto) {
        this.id = id;
        this.emailCliente = emailCliente;
        this.idPacchetto = idPacchetto;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getEmailCliente() {
        return emailCliente;
    }

    public void setEmailCliente(String emailCliente) {
        this.emailCliente = emailCliente;
    }

    public int getIdPacchetto() {
        return idPacchetto;
    }

    public void setIdPacchetto(int idPacchetto) {
        this.idPacchetto = idPacchetto;
    }
}
