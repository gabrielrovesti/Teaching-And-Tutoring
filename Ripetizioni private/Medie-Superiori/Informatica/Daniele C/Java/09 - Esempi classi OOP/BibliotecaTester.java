
public class BibliotecaTester{
    public static void main(String[] args){
        Biblioteca b1=new Biblioteca("BiblioPoint","ITI Severi");
        b1.inserisciLibro(new Libro("Viaggio al centro della terra","avventura ragazzi",250,20.00),1);
        Libro x=new Libro("Il signore degli anelli","fantasy",500,31.50);
        b1.inserisciLibro(x,1);

        System.out.println(b1.toString());
        
        System.out.println("\nRimozione riuscita? "+b1.removeLibro(x));
        System.out.println(b1.toString());
        
        Libro x2=new Libro("La Divina Commedia","classico",350,27.50);
        Libro x3=new Libro("IT","horror",220,28.00);
        b1.inserisciLibro(x,1);
        b1.inserisciLibro(x2,1);
        b1.inserisciLibro(x3,1);
        System.out.println(b1.toString());
        
        System.out.println("\nNoleggio riuscito? "+b1.noleggia(x2));
        System.out.println(b1.toString());
        System.out.println("\nRimozione riuscita? "+b1.removeLibro(x2));
        System.out.println(b1.toString());
        
    }
}
