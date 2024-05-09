public class Main
{
    public static void main(String[] args)
    {
        /*** PARTE 1 ***/
        Calciatore c1 = new Calciatore("Gabriel Batistuta", 200,95,20000000);
        Portiere p1 = new Portiere("Sebastiano Rossi", 345,0,7000000,145,50,42);

        c1.stampaInfo();
        System.out.println();
        p1.stampaInfo();
        System.out.println();

        if (c1.getPartiteGiocate() > p1.getPartiteGiocate())
        {
            System.out.print(c1.getNome() + " ha giocato più partite di "+ p1.getNome());
        }
        else
        {
            System.out.print(p1.getNome() + " ha giocato più partite di "+ c1.getNome());
        }

        System.out.println();

        if (p1.getRigoriParati() >= p1.getRigoriSubiti()/2)
        {
            System.out.print("Ottimo! " + p1.getNome() + " ha parato più rigori di quanti subiti");
        }

        /*** PARTE 2 ***/
        Squadra milan = new Squadra("Milan", 1899);
        milan.inserisciCalciatore(c1);
        milan.inserisciCalciatore(p1);
        milan.inserisciCalciatore(new Calciatore("Zlatan Ibrahimovic",23,8,4000000 ));
        milan.inserisciCalciatore(new Portiere("Dida",21,0,12000000,12,10,12));
        System.out.println();

        int posizione = milan.cerca("Zlatan Ibrahimovic");
        if (posizione > 0)
        {
            System.out.println("Zlatan Ibrahimovic trovato in posizione "+ posizione);
        }
        else
        {
            System.out.println("Zlatan Ibrahimovic non trovato");
        }

        System.out.println();
        milan.stampaRosa();
        System.out.println();

        System.out.println("Cancella Batistuta e Dida e ristampa la rosa");
        milan.rimuoviCalciatore(0);
        milan.rimuoviCalciatore("Dida");

        System.out.println();
        milan.stampaRosa();
        System.out.println();
    }
}