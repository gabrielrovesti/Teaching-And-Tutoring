public static void main(String[] args) {
        // Creo due mazzi 
        Mazzo mazzoGiocatore1 = new Mazzo();
        Mazzo mazzoGiocatore2 = new Mazzo();

        int punteggioGiocatore1 = 0;
        int punteggioGiocatore2 = 0;

        for(int i = 0; i < 26; i++){
            CartaDaGioco cartaGiocatore1 = mazzoGiocatore1.pescaPrima();
            CartaDaGioco cartaGiocatore2 = mazzoGiocatore2.pescaPrima();

            if(cartaGiocatore1.getValore() > cartaGiocatore2.getValore()){
                punteggioGiocatore1++;
            }else if (cartaGiocatore1.getValore() < cartaGiocatore2.getValore()){
                punteggioGiocatore2++;
            }
        }

        System.out.println("Punteggio Giocatore 1: " + punteggioGiocatore1);
        System.out.println("Punteggio Giocatore 2: " + punteggioGiocatore2);

        if(punteggioGiocatore1 > punteggioGiocatore2){
            System.out.println("Il vincitore è il Giocatore 1!");
        } else if (punteggioGiocatore2 > punteggioGiocatore1) {
            System.out.println("Il vincitore è il Giocatore 2!");
        }else{
            System.out.println("È un pareggio!");
        }
    }
}

 
