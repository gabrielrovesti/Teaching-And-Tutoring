public class ContoBancario{
    public static String nome;
    public static double conto = 1000;
    public static double capitale = 2000;

    // Metodo custom per togliere soldi dal conto
    public static void estrai(double capitale){
    // finché ci sono soldi estrai
    // Richiesta dell'esercizio: il conto può andare in rosso; gestisci questo comportamento eccezionale
        try {
            double capit = 1000;
            capit -= capitale;
        } catch (Exception e) {
            System.err.println(e);
        } 
    }

    public static void main(String[] args) {
        estrai(capitale);
    }
}