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

    public int getId() {
        return id;
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public String getNominativo() {
        return nominativo;
    }

    public String getDataNascita() {
        return dataNascita;
    }

    public String getComuneResidenza() {
        return comuneResidenza;
    }

    public void setComuneResidenza(String comuneResidenza) {
        this.comuneResidenza = comuneResidenza;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "ID: " + id + ", Codice Fiscale: " + codiceFiscale + ", Nominativo: " + nominativo
                + ", Data di Nascita: " + dataNascita + ", Comune di Residenza: " + comuneResidenza
                + ", Email: " + email;
    }
}

class ClasseScolastica {
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

    public void modificaComuneA1unno(int id, String nuovoComune) {
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
        ArrayList<ClasseScolastica> classi = new ArrayList<>();

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
            scanner.nextLine();

            switch (scelta) {
                case 1:
                    System.out.print("Inserisci il numero della classe (1-" + classi.size() + "): ");
                    int numeroClasse1 = scanner.nextInt() - 1;
                    if (numeroClasse1 >= 0 && numeroClasse1 < classi.size()) {
                        System.out.println(classi.get(numeroClasse1).listaAlunni());
                    } else {
                        System.out.println("Classe non valida.");
                    }
                    break;
                case 2:
                    System.out.print("Inserisci il numero della classe (1-" + classi.size() + "): ");
                    int numeroClasse2 = scanner.nextInt() - 1;
                    scanner.nextLine();
                    if (numeroClasse2 >= 0 && numeroClasse2 < classi.size()) {
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
                        classi.get(numeroClasse2).inserisciAlunno(nuovoAlunno);
                        System.out.println("Alunno inserito con successo!");
                    } else {
                        System.out.println("Classe non valida.");
                    }
                    break;
                case 3:
                    System.out.print("Inserisci il numero della classe (1-" + classi.size() + "): ");
                    int numeroClasse3 = scanner.nextInt() - 1;
                    if (numeroClasse3 >= 0 && numeroClasse3 < classi.size()) {
                        System.out.print("Inserisci l'ID dell'alunno da rimuovere: ");
                        int idRimuovi = scanner.nextInt();
                        classi.get(numeroClasse3).getAlunni().removeIf(alunno -> alunno.getId() == idRimuovi);
                    } else {
                        System.out.println("Classe non valida.");
                    }
                    break;
                case 4:
                    System.out.print("Inserisci il numero della classe (1-" + classi.size() + "): ");
                    int numeroClasse4 = scanner.nextInt() - 1;
                    scanner.nextLine(); 
                    if (numeroClasse4 >= 0 && numeroClasse4 < classi.size()) {
                        System.out.print("Inserisci il codice fiscale dell'alunno da cercare: ");
                        String cfCerca = scanner.nextLine();
                        Alunno alunnoCercato = classi.get(numeroClasse4).ricercaAlunnoDaCodiceFiscale(cfCerca);
                        if (alunnoCercato != null) {
                            System.out.println(alunnoCercato.toString());
                        } else {
                            System.out.println("Alunno non trovato.");
                        }
                    } else {
                        System.out.println("Classe non valida.");
                    }
                    break;
                case 5:
                    System.out.print("Inserisci il numero della classe (1-" + classi.size() + "): ");
                    int numeroClasse5 = scanner.nextInt() - 1;
                    scanner.nextLine(); 
                    if (numeroClasse5 >= 0 && numeroClasse5 < classi.size()) {
                        System.out.print("Inserisci l'ID dell'alunno da modificare: ");
                        int idModifica = scanner.nextInt();
                        scanner.nextLine(); 
                        System.out.print("Inserisci il nuovo comune di residenza: ");
                        String nuovoComune = scanner.nextLine();
                        classi.get(numeroClasse5).modificaComuneA1unno(idModifica, nuovoComune);
                        System.out.println("Comune modificato con successo!");
                    } else {
                        System.out.println("Classe non valida.");
                    }
                    break;
                case 0:
                    System.out.println("Programma terminato.");
                    break;
                default:
                    System.out.println("Scelta non valida. Riprova.");
            }
        } while (scelta != 0);
    }
}
