import java.util.ArrayList;

public class Ospedale {
    private ArrayList<Medico> medici;
    private ArrayList<Paziente> pazienti;

    public Ospedale() {
        this.medici = new ArrayList<>();
        this.pazienti = new ArrayList<>();
    }

    // Metodi per aggiungere medici e pazienti
    public void aggiungiMedico(Medico medico) {
        medici.add(medico);
    }

    public void aggiungiPaziente(Paziente paziente) {
        pazienti.add(paziente);
    }
}
