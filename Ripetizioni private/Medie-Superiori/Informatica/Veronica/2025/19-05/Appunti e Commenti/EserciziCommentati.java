import java.util.*;

public class EserciziCommentati{
    
    /*
    Ordinare le macchine in un certo modo seguendo l'ordine per la strada e il viale.

    Lineare -> ArrayList / LinkedList (n) -> array

    Logaritmico -> Strada / Viale
        Sottoinsiemi su cui ragioniamo con dei criteri "if"

    Deque -> First / Last / Logaritmica
    Alternativa: Coda circolare / Stack

    Stack -> ArrayList -> O(n)
    Coda circolare -> O(log(n)
    Deque -> O(log(n)) -> Buona perché punta a tutto.
    */

    public static void main(String[] args) {
        // Menù di richiamo
        // Stampa generica applicazione +
        // 1. Aggiungi macchina in parcheggio
        // 2. Toglila 
    }
}

public interface Contenitore{
	boolean isEmpty();
	int size();
    boolean isFull();
}

public class CodaCircolare extends Contenitore{
	private ArrayList<T> elements;
	private int first;
	private int last;
	private int capacity;
	
	// Metodi di accesso
	void parking(T element); // add()
	T leaveParking(); // remove()
}

public class CodaCircolareParcheggio extends CodaDoppia<T> {
    @Override 
    void parking(T car){
        // Se abbastanza spazio -> size() allora aggiungi macchina, altrimenti eccezione
        if(isFull()){
            throw new IllegalArgumentException("Parcheggio pieno");
        }
        
        // con first/last -> c'è un solo elemento o non ci sono -> addFirst / addLast

        // altrimenti aggiungi dopo in pos. generica
        elements.add(car);
    }

    @Override 
    void removeCar(T car){
        // Se abbastanza spazio -> size() allora aggiungi macchina, altrimenti eccezione
        if(isEmpty()){
            throw new IllegalArgumentException("Parcheggio vuoto");
        }
        // con first/last -> c'è un solo elemento o non ci sono -> removeFirst / removeLast

        // altrimenti remove dopo in pos. generica
        elements.remove(car);
    }
}