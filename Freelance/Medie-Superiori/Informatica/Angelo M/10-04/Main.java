public class Main{

    public static void main(String[] args){
        Spettacolo spettacolo = new Spettacolo("Concerto", 50);
        System.out.println("Posti liberi prima della prenotazione: " + spettacolo.postiLiberi());

        spettacolo.prenota("Mario Rossi", "1234567890");

        System.out.println("Posti liberi dopo la prenotazione: " + spettacolo.postiLiberi());

        spettacolo.disdici("Mario Rossi", "1234567890");

        System.out.println("Posti liberi dopo la disdetta: " + spettacolo.postiLiberi());
    }
}


