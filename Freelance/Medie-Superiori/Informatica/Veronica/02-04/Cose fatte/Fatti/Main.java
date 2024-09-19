public class Main{
    public static void main(String[] args){
        Giocatore giocatore = new Giocatore("Guerriero", "Guerriero", 100, 50);
        Mostro mostro = new Mostro("Orco", 80, 50, "Fuoco");

        Arena arena = new Arena();
        arena.combatti(giocatore, mostro);
        System.out.println(arena.mostraVincitore(giocatore, mostro));
    }
}