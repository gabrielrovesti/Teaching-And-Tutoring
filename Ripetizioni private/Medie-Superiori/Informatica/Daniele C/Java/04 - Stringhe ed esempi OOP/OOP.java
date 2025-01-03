public class OOP{
    // OOP = Object Oriented Programming - Programmazione ad oggetti

    // tipo definito dall'utente = OOP
}

/*

public class Shape{
    private:
        int width;      // larghezza
        int height;     // altezza
    public:

        // costruttore
        
        Inizializza i parametri del tipo Classe 
        Ha lo stesso nome della classe e cambiano i parametri (overloading)

        Shape(int width, int height){
            this.width = width;
            this.height = height;

            // this = puntatore all'oggetto/al tipo che sei ora

            // Qui, this = Shape come tipo

            Sarebbe come fare:
            Shape c;
            c.width = width;
            ...
        }

        // Overloading -> stesso nome/diversi parametri
        Shape ();
        Shape (int width);
        Shape (int width, int height)
}

public class Triangle extends Shape{
    private:
        int perimeter;  // information hiding = incapsulamento = nascondo i dati privati
    public:
        int getPerimeter(){ // lo prendo dall'esterno
            return perimeter;
        }
}

public class Square extends Shape{

}

main(){
    Shape c = new Triangle(); // polimorfismo -> più forme con varie caratteristiche

    Il triangolo è una forma; ne eredita altezza e larghezza e aggiunge il perimetro
}

Ereditarietà (inheritance):

        Shape
    /           \
Triangle        Square

*/