import java.time.LocalDate;
import java.time.Period;
import java.util.List;

abstract class Persona {
    private String nome;
    private String cognome;
    private LocalDate dataNascita;
    private String residenza;

    public Persona(String nome, String cognome, LocalDate dataNascita, String residenza) {
        this.nome = nome;
        this.cognome = cognome;
        this.dataNascita = dataNascita;
        this.residenza = residenza;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public LocalDate getDataNascita() {
        return dataNascita;
    }

    public String getResidenza() {
        return residenza;
    }

    public void setResidenza(String residenza) {
        this.residenza = residenza;
    }

    public int calcolaEta() {
        return Period.between(dataNascita, LocalDate.now()).getYears();
    }

    public boolean isResidenteIn(String citta) {
        return residenza.equalsIgnoreCase(citta);
    }

    public boolean haLoStessoCognome(Persona p) {
        return cognome.equalsIgnoreCase(p.getCognome());
    }

    public static int confrontaEta(Persona p1, Persona p2) {
        return p1.calcolaEta() - p2.calcolaEta();
    }

    @Override
    public String toString() {
        return nome + " " + cognome + ", nato il " + dataNascita + ", residente a " + residenza;
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) return true;
        if (other == null || getClass() != other.getClass()) return false;
        Persona persona = (Persona) other;
        return nome.equals(persona.nome) && cognome.equals(persona.cognome) && dataNascita.equals(persona.dataNascita) && residenza.equals(persona.residenza);
    }
}

abstract class StudenteUniversitario extends Persona {
    private int matricola;
    private int annoImmatricolazione;
    private String corsoDiLaurea;

    public StudenteUniversitario(String nome, String cognome, LocalDate dataNascita, String residenza, int matricola, int annoImmatricolazione, String corsoDiLaurea) {
        super(nome, cognome, dataNascita, residenza);
        this.matricola = matricola;
        this.annoImmatricolazione = annoImmatricolazione;
        this.corsoDiLaurea = corsoDiLaurea;
    }

    public int getMatricola() {
        return matricola;
    }

    public int getAnnoImmatricolazione() {
        return annoImmatricolazione;
    }

    public String getCorsoDiLaurea() {
        return corsoDiLaurea;
    }

    public void setCorsoDiLaurea(String corsoDiLaurea) {
        this.corsoDiLaurea = corsoDiLaurea;
    }

    public int calcolaAnniIscrizione() {
        return LocalDate.now().getYear() - annoImmatricolazione;
    }

    public boolean isImmatricolatoInCorso(String corso) {
        return corsoDiLaurea.equalsIgnoreCase(corso);
    }

    public boolean isStudenteFuoriCorso() {
        return calcolaAnniIscrizione() > 5;
    }

    public static boolean isStudenteLavoratore(Persona p) {
        return p instanceof StudenteLavoratore;
    }

    @Override
    public String toString() {
        return super.toString() + ", matricola " + matricola + ", iscritto al corso " + corsoDiLaurea + " dall'anno " + annoImmatricolazione;
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) return true;
        if (other == null || getClass() != other.getClass()) return false;
        if (!super.equals(other)) return false;
        StudenteUniversitario that = (StudenteUniversitario) other;
        return matricola == that.matricola && annoImmatricolazione == that.annoImmatricolazione && corsoDiLaurea.equals(that.corsoDiLaurea);
    }
}

class Studente extends StudenteUniversitario {
    public Studente(String nome, String cognome, LocalDate dataNascita, String residenza, int matricola, int annoImmatricolazione, String corsoDiLaurea) {
        super(nome, cognome, dataNascita, residenza, matricola, annoImmatricolazione, corsoDiLaurea);
    }

    public double calcolaTassaIscrizione() {
        return 1000.0;
    }

    public boolean isStudenteRegolare() {
        return calcolaEta() < 25 && !isStudenteFuoriCorso();
    }

    public static double calcolaTassaMedia(List<Studente> studenti) {
        double somma = 0;
        for (Studente s : studenti) {
            somma += s.calcolaTassaIscrizione();
        }
        return somma / studenti.size();
    }
}

class StudenteLavoratore extends Studente {
    private String azienda;
    private double stipendio;

    public StudenteLavoratore(String nome, String cognome, LocalDate dataNascita, String residenza, int matricola, int annoImmatricolazione, String corsoDiLaurea, String azienda, double stipendio) {
        super(nome, cognome, dataNascita, residenza, matricola, annoImmatricolazione, corsoDiLaurea);
        this.azienda = azienda;
        this.stipendio = stipendio;
    }

    public String getAzienda() {
        return azienda;
    }

    public double getStipendio() {
        return stipendio;
    }

    public void setAzienda(String azienda) {
        this.azienda = azienda;
    }

    public void setStipendio(double stipendio) {
        this.stipendio = stipendio;
    }

    public double calcolaRedditoAnnuale() {
        return stipendio * 12;
    }

    @Override
    public String toString() {
        return super.toString() + ", lavora presso " + azienda + " con uno stipendio di " + stipendio + " euro al mese";
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) return true;
        if (other == null || getClass() != other.getClass()) return false;
        if (!super.equals(other)) return false;
        StudenteLavoratore that = (StudenteLavoratore) other;
        return azienda.equals(that.azienda) && Double.compare(that.stipendio, stipendio) == 0;
    }
}

class StudenteFuoriSede extends Studente {
    private double affitto;
    private double borsa;

    public StudenteFuoriSede(String nome, String cognome, LocalDate dataNascita, String residenza, int matricola, int annoImmatricolazione, String corsoDiLaurea, double affitto, double borsa) {
        super(nome, cognome, dataNascita, residenza, matricola, annoImmatricolazione, corsoDiLaurea);
        this.affitto = affitto;
        this.borsa = borsa;
    }

    public double getAffitto() {
        return affitto;
    }

    public double getBorsa() {
        return borsa;
    }

}

public void setBorsa(double borsa) {
    this.borsa = borsa;
}

public double calcolaSpeseAnnuali() {
    return (affitto * 12) + calcolaTassaIscrizione() - borsa;
}

@Override
public String toString() {
    return super.toString() + ", affitto di " + affitto + " euro al mese" + (borsa > 0 ? ", borsa di studio di " + borsa + " euro" : "");
}

@Override
public boolean equals(Object other) {
    if (this == other) return true;
    if (other == null || getClass() != other.getClass()) return false;
    if (!super.equals(other)) return false;
    StudenteFuoriSede that = (StudenteFuoriSede) other;
    return Double.compare(that.affitto, affitto) == 0 && Double.compare(that.borsa, borsa) == 0;
}

public class Main {
public static void main(String[] args) {
    Persona p1 = new Persona("Mario", "Rossi", LocalDate.of(1990, 5, 15), "Verona");
    Studente s1 = new Studente("Luigi", "Bianchi", LocalDate.of(1998, 9, 20), "Milano", 12345, 2018, "Informatica");
    StudenteLavoratore sl1 = new StudenteLavoratore("Anna", "Verdi", LocalDate.of(1995, 3, 10), "Roma", 54321, 2015, "Ingegneria", "Acme Inc.", 2500.0);
    StudenteFuoriSede sfs1 = new StudenteFuoriSede("Carlo", "Neri", LocalDate.of(2000, 11, 5), "Napoli", 67890, 2019, "Biologia", 450.0, 3000.0);

    System.out.println(p1);
    System.out.println(s1);
    System.out.println(sl1);
    System.out.println(sfs1);

    System.out.println("Età di " + p1.getNome() + ": " + p1.calcolaEta());
    System.out.println("Anni di iscrizione di " + s1.getNome() + ": " + s1.calcolaAnniIscrizione());
    System.out.println("Reddito annuale di " + sl1.getNome() + ": " + sl1.calcolaRedditoAnnuale());
    System.out.println("Spese annuali di " + sfs1.getNome() + ": " + sfs1.calcolaSpeseAnnuali());

    System.out.println(s1.isStudenteRegolare());
    System.out.println(StudenteUniversitario.isStudenteLavoratore(sl1));
    System.out.println(Persona.confrontaEta(p1, s1));
    System.out.println(p1.haLoStessoCognome(sl1));
    System.out.println(s1.isImmatricolatoInCorso("Informatica"));
    System.out.println(Studente.calcolaTassaMedia(List.of(s1, sfs1)));
}
}