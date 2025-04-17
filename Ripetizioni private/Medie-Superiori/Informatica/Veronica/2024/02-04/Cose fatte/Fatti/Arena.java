class Arena{

    public void combatti(Giocatore giocatore, Mostro mostro){
        int turno = 1;
        while(giocatore.getPuntiVita() > 0 &&
        mostro.getPuntiVita() > 0){
            
            if(turno % 2 != 0){
                System.out.println(giocatore.getNome() 
                + " attacca " + mostro.getNome());
                giocatore.attacca(mostro, 30);
                mostro.stampaStato();
            }
            else{
                System.out.println(mostro.getNome() 
                + " attacca " + giocatore.getNome());
                giocatore.attacca(mostro, 10);
                mostro.stampaStato();
            }

            turno++;
        }
    }
        
    public String mostraVincitore(Giocatore giocatore, Mostro mostro){
        if(giocatore.getPuntiVita() <= 0){
            return "Il mostro " + mostro.getNome() + " ha vinto!";
        }
        else
            return "Il mostro " + mostro.getNome() + " ha vinto!";
    }
}