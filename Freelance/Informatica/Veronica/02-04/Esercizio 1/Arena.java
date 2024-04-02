class Arena {
    public void combatti(Giocatore giocatore, Mostro mostro) {
        int turno = 1;
        while (giocatore.getPuntiVita() > 0 && mostro.getPuntiVita() > 0) {
            System.out.println("Turno " + turno);
            if (turno % 2 != 0) {
                System.out.println(giocatore.getNome() + " attacca " + mostro.getNome());
                giocatore.attacca(mostro, 10); // Esempio di attacco con 10 di danno
                mostro.stampaStato();
            } else {
                System.out.println(mostro.getNome() + " attacca " + giocatore.getNome());
                mostro.attacca(giocatore, 5); // Esempio di attacco con 5 di danno
                giocatore.stampaStato();
            }
            turno++;
        }
        if (giocatore.getPuntiVita() <= 0) {
            System.out.println("Il mostro " + mostro.getNome() + " ha vinto!");
        } else {
            System.out.println("Il giocatore " + giocatore.getNome() + " ha vinto!");
        }
    }
}
