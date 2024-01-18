import java.util.ArrayList;
import java.util.Scanner;

class Alunno {
    private static int counter = 1;

    private int id;
    private String codiceFiscale;
    private String nominativo;
    private String dataNascita;
    private String comuneResidenza;
    private String email;

    public Alunno(String codiceFiscale, String nominativo, String dataNascita, String comuneResidenza, String email) {
        this.id = counter++;
        this.codiceFiscale = codiceFiscale;
        this.nominativo = nominativo;
        this.dataNascita = dataNascita;
        this.comuneResidenza = comuneResidenza;
        this.email = email;
    }

    // Getters and setters...

    @Override
    public String toString() {
        return "ID: " + id + ", Codice Fiscale: " + codiceFiscale + ", Nominativo: " + nominativo
                + ", Data di Nascita: " + dataNascita + ", Comune di Residenza: " + comuneResidenza
                + ", Email: " + email;
    }
}

class Scuola {
    private ArrayList<Alunno> alunni = new ArrayList<>();

    public void inserisciAlunno(Alunno alunno) {
        alunni.add(alunno);
    }

    public Alunno ricercaAlunnoDaCodiceFiscale(String codiceFiscale) {
        for (Alunno alunno : alunni) {
            if (alunno.getCodiceFiscale().equals(codiceFiscale)) {
                return alunno;
            }
        }
        return null;
    }

    public void rimuoviAlunnoDaCodiceFiscale(String codiceFiscale) {
        alunni.removeIf(alunno -> alunno.getCodiceFiscale().equals(codiceFiscale));
    }

    public ArrayList<Alunno> getAlunni() {
        return new ArrayList<>(alunni);
    }

    public ArrayList<Alunno> ricercaAlunniPerComune(String comune) {
        ArrayList<Alunno> result = new ArrayList<>();
        for (Alunno alunno : alunni) {
            if (alunno.getComuneResidenza().equals(comune)) {
                result.add(alunno);
            }
        }
        return result;
    }

    public void modificaComuneAlunno(int id, String nuovoComune) {
        for (Alunno alunno : alunni) {
            if (alunno.getId() == id) {
                alunno.setComuneResidenza(nuovoComune);
                break;
            }
        }
    }

    public String listaAlunni() {
        StringBuilder result = new StringBuilder();
        for (Alunno alunno : alunni) {
            result.append(alunno.toString()).append("\n");
        }
        return result.toString();
    }
}

public class Principale {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Scuola scuola = new Scuola();

        int scelta;
        do {
            System.out.println("1) Visualizza alunno");
            System.out.println("2) Inserisci alunno");
            System.out.println("3) Rimuovi alunno dato ID");
            System.out.println("4) Ricerca alunno dato codice fiscale");
            System.out.println("5) Modifica comune alunno");
            System.out.println("0) ESCI");
            System.out.print("Inserisci la tua scelta: ");
            scelta = scanner.nextInt();
            scanner.nextLine(); // Consuma la new line

            switch (scelta) {
                case 1:
                    System.out.println(scuola.listaAlunni());
                    break;
                case 2:
                    System.out.print("Inserisci il codice fiscale: ");
                    String cf = scanner.nextLine();
                    System.out.print("Inserisci il nominativo: ");
                    String nominativo = scanner.nextLine();
                    System.out.print("Inserisci la data di nascita: ");
                    String dataNascita = scanner.nextLine();
                    System.out.print("Inserisci il comune di residenza: ");
                    String comune = scanner.nextLine();
                    System.out.print("Inserisci l'email: ");
                    String email = scanner.nextLine();

                    Alunno nuovoAlunno = new Alunno(cf, nominativo, dataNascita, comune, email);
                    scuola.inserisciAlunno(nuovoAlunno);
                    System.out.println("Alunno inserito con successo!");
                    break;
                case 3:
                    System.out.print("Inserisci l'ID dell'alunno da rimuovere: ");
                    int idRimuovi = scanner.nextInt();
                    scuola.getAlunni().removeIf(alunno -> alunno.getId() == idRimuovi);
                    break;
                case 4:
                    System.out.print("Inserisci il codice fiscale dell'alunno da cercare: ");
                    String cfRicerca = scanner.nextLine();
                    Alunno alunnoRicerca = scuola.ricercaAlunnoDaCodiceFiscale(cfRicerca);
                    if (alunnoRicerca != null) {
                        System.out.println(alunnoRicerca.toString());
                    } else {
                        System.out.println("Alunno non trovato.");
                    }
                    break;
                case 5:
                    System.out.print("Inserisci l'ID dell'alunno da modificare: ");
                    int idModifica = scanner.nextInt();
                    scanner.nextLine(); // Consuma la new line
                    System.out.print("Inserisci il nuovo comune di residenza: ");
                    String nuovoComune = scanner.nextLine();
                    scuola.modificaComuneAlunno(idModifica, nuovoComune);
                    break;
                case 0:
                    System.out.println("Uscita dal programma.");
                    break;
                default:
                    System.out.println("Scelta non valida. Riprova.");
                    break;
            }
        } while (scelta != 0);
    }
}
