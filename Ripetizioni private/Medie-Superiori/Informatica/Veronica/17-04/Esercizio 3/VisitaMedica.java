import java.util.ArrayList;

public class Paziente extends Persona {
    private String diagnosi;
    private ArrayList<VisitaMedica> visiteMediche;

    public Paziente(String nome, String cognome, String CF, String diagnosi) {
        super(nome, cognome, CF);
        this.diagnosi = diagnosi;
        this.visiteMediche = new ArrayList<>();
    }

    // Metodi per gestire le visite mediche
    public void aggiungiVisita(VisitaMedica visita) {
        visiteMediche.add(visita);
    }

    public void visualizzaCartellaClinica() {
        for (VisitaMedica visita : visiteMediche) {
            System.out.println(visita.getInfo());
        }
    }
}
