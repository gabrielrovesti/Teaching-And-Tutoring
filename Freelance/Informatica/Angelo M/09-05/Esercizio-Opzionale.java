import java.util.Scanner;

// Interfaccia per gli elementi riproducibili
interface Riproducibile {
    void play();
}

// Classe astratta per gli elementi multimediali
abstract class ElementoMultimediale {
    String titolo;

    // Costruttore
    ElementoMultimediale(String titolo) {
        this.titolo = titolo;
    }

    // Metodo per eseguire l'elemento multimediale
    abstract void esegui();

    // Metodo per regolare il volume (implementato solo per le registrazioni audio e i filmati)
    void regolaVolume(int volume) {
        System.out.println("Regolazione del volume non supportata per questo elemento.");
    }

    // Metodo per regolare la luminosità (implementato solo per i filmati e le immagini)
    void regolaLuminosita(int luminosita) {
        System.out.println("Regolazione della luminosità non supportata per questo elemento.");
    }
}

// Classe per le registrazioni audio
class RegistrazioneAudio extends ElementoMultimediale implements Riproducibile {
    int durata;
    int volume;

    // Costruttore
    RegistrazioneAudio(String titolo, int durata, int volume) {
        super(titolo);
        this.durata = durata;
        this.volume = volume;
    }

    // Metodo per riprodurre la registrazione audio
    @Override
    public void play() {
        for (int i = 0; i < durata; i++) {
            for (int j = 0; j < volume; j++) {
                System.out.print("!");
            }
            System.out.println(" " + titolo);
        }
    }

    // Metodo per regolare il volume
    @Override
    void regolaVolume(int volume) {
        this.volume = volume;
    }

    // Metodo per eseguire la registrazione audio
    @Override
    void esegui() {
        play();
    }
}

// Classe per i filmati
class Filmato extends ElementoMultimediale implements Riproducibile {
    int durata;
    int volume;
    int luminosita;

    // Costruttore
    Filmato(String titolo, int durata, int volume, int luminosita) {
        super(titolo);
        this.durata = durata;
        this.volume = volume;
        this.luminosita = luminosita;
    }

    // Metodo per riprodurre il filmato
    @Override
    public void play() {
        for (int i = 0; i < durata; i++) {
            for (int j = 0; j < volume; j++) {
                System.out.print("!");
            }
            for (int k = 0; k < luminosita; k++) {
                System.out.print("*");
            }
            System.out.println(" " + titolo);
        }
    }

    // Metodo per regolare il volume
    @Override
    void regolaVolume(int volume) {
        this.volume = volume;
    }

    // Metodo per regolare la luminosità
    @Override
    void regolaLuminosita(int luminosita) {
        this.luminosita = luminosita;
    }

    // Metodo per eseguire il filmato
    @Override
    void esegui() {
        play();
    }
}

// Classe per le immagini
class Immagine extends ElementoMultimediale {
    int luminosita;

    // Costruttore
    Immagine(String titolo, int luminosita) {
        super(titolo);
        this.luminosita = luminosita;
    }

    // Metodo per visualizzare l'immagine
    void show() {
        for (int i = 0; i < luminosita; i++) {
            System.out.print("*");
        }
        System.out.println(" " + titolo);
    }

    // Metodo per regolare la luminosità
    @Override
    void regolaLuminosita(int luminosita) {
        this.luminosita = luminosita;
    }

    // Metodo per eseguire l'immagine
    @Override
    void esegui() {
        show();
    }
}

// Classe principale per il lettore multimediale
public class LettoreMultimediale {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Creazione degli elementi multimediali
        ElementoMultimediale[] elementi = new ElementoMultimediale[5];
        for (int i = 0; i < elementi.length; i++) {
            System.out.println("Inserisci il tipo di elemento multimediale (1 = Registrazione Audio, 2 = Filmato, 3 = Immagine):");
            int tipo = scanner.nextInt();
            scanner.nextLine(); // Consuma il carattere newline

            System.out.println("Inserisci il titolo:");
            String titolo = scanner.nextLine();

            switch (tipo) {
                case 1:
                    System.out.println("Inserisci la durata:");
                    int durataAudio = scanner.nextInt();
                    System.out.println("Inserisci il volume:");
                    int volume = scanner.nextInt();
                    elementi[i] = new RegistrazioneAudio(titolo, durataAudio, volume);
                    break;
                case 2:
                    System.out.println("Inserisci la durata:");
                    int durataFilmato = scanner.nextInt();
                    System.out.println("Inserisci il volume:");
                    int volumeFilmato = scanner.nextInt();
                    System.out.println("Inserisci la luminosità:");
                    int luminosita = scanner.nextInt();
                    elementi[i] = new Filmato(titolo, durataFilmato, volumeFilmato, luminosita);
                    break;
                case 3:
                    System.out.println("Inserisci la luminosità:");
                    int luminositaImmagine = scanner.nextInt();
                    elementi[i] = new Immagine(titolo, luminositaImmagine);
                    break;
                default:
                    System.out.println("Tipo di elemento multimediale non valido.");
                    break;
            }
        }

        // Esecuzione degli elementi multimediali
        int scelta;
        do {
            System.out.println("Scegli l'elemento multimediale da eseguire (da 1 a 5, 0 per uscire):");
            scelta = scanner.nextInt();
            if (scelta >= 1 && scelta <= 5) {
                System.out.println("Elemento selezionato: " + elementi[scelta - 1].titolo);
                System.out.println("1. Regola il volume");
                if (elementi[scelta - 1] instanceof Filmato || elementi[scelta - 1] instanceof Immagine) {
                    System.out.println("2. Regola la luminosità");
                }
                int opzione = scanner.nextInt();
                switch (opzione) {
                    case 1:
                        System.out.println("Inserisci il nuovo volume:");
                        int nuovoVolume = scanner.nextInt();
                        elementi[scelta - 1].regolaVolume(nuovoVolume);
                        break;
                    case 2:
                        if (elementi[scelta - 1] instanceof Filmato) {
                            System.out.println("Inserisci la nuova luminosità:");
                            int nuovaLuminosita = scanner.nextInt();
                            ((Filmato) elementi[scelta - 1]).regolaLuminosita(nuovaLuminosita);
                        } else if (elementi[scelta - 1] instanceof Immagine) {
                            System.out.println("Inserisci la nuova luminosità:");
                            int nuovaLuminosita = scanner.nextInt();
                            ((Immagine) elementi[scelta - 1]).regolaLuminosita(nuovaLuminosita);
                        }
                        break;
                    default:
                        System.out.println("Opzione non valida.");
                        break;
                }
                elementi[scelta - 1].esegui();
            } else if (scelta != 0) {
                System.out.println("Scelta non valida.");
            }
        } while (scelta != 0);

        scanner.close();
    }
}
