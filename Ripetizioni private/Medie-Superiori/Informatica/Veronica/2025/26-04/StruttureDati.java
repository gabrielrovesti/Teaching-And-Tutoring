// Tutte le strutture dati che noi consideriamo sono contenitori

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.NoSuchElementException;

// Interfaccia = Esegue solo operazioni (contratto)
public interface Contenitore{
    // Se vuoto
    boolean isEmpty();
    // Size elementi
    int size();
}

// Esempio struttura dati = Pila (LIFO)

public interface Pila<T> extends Contenitore{
    // Push = Inserire elemento in cima alla pila
    void push(T elem);
    // Pop = Rimuovere elemento in cima
    T pop();
    // Top = Bottom = Prendi l'elemento in cima / in fondo
    T top();
    T bottom();
}
/*
    T removeFirst() {}
    T removeLast() {}

    Uguali a pop e push, ma di base vuol dire che stai implementando (es.coda) la tua struttura in qualche altro modo (es.array)
    [TOP][][][][][BOTTOM]
 */

// Esempio implementazione Pila -> PilaArrayList<T>
// ArrayList -> forEach, get, remove, size (estendibile) = Override

public class PilaArrayList<T> implements Pila<T>{
    // Gestiamo un insieme di elementi
    private ArrayList<T> elements;

    // Costruttore
    public PilaArrayList(){
        elements = new ArrayList<>();
    }

    // Size() = Parte di contenitore = Override
    @Override
    public int size(){
        return elements.size();
    }

    // Push() = Parte di Pila = Override
    @Override
    public void push(T elem){
        elements.add(elem);
    }

    // Pop() = Se c'è l'elemento, rimuoverlo e restituire l'elemento in cima, altrimenti lancio eccezione
    public T pop(){
        if(isEmpty())
            throw EmptyStackException();
            // IllegalArgumentException
        return elements.remove(elements.size()-1);
    }

    // Top() = Restituisce in cima senza rimuoverlo
    public T top(){
        if(isEmpty())
            throw EmptyStackException();
            // IllegalArgumentException
        return elements.get(elements.size()-1);
    }

    // toString = Rappresentazione testuale stack/pila

    public String toString(){
        // StringBuilder = append

        // Creiamo costruttore di stringhe
        StringBuilder sb = new StringBuilder();
        sb.append("Stack: [");

        for (int i = 0; i < elements.size(); i++) {

            sb.append(elements.get(i)); // prendo i singoli elementi ArrayList

            if (i < elements.size() - 1) {
                sb.append(", ");
            }
            // Ognuno separato da comma / virgola
        }

        sb.append("] <- cima");
        return sb.toString();
    }
}


// Esempio struttura dati = Coda (FIFO)

public interface Coda<T> extends Contenitore{
    // Enqueue = Accodare elemento (in coda)
    void enqueue(T elem);

    // Dequeue = Rimuovere elemento (dalla testa)
    T dequeue();

    // Prendiamo singolo elemento in testa
    T getFront();
}

public class PilaArrayList<T> implements Pila<T>{
    private ArrayList<T> elements;

    // Costruttore
    public PilaArrayList(){
        elements = new ArrayList<>();
    }

    // Pila vuota
    @Override
    public boolean isEmpty(){
        return elements.isEmpty();
    }

    // Accodo
    @Override
    public void enqueue(T elem){
        elements.add(elem);
    }

    // Rimuovo dal fronte -> NoSuchElementException
    public T dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("La coda è vuota");
        }
        return elements.remove(0); // dal fronte (0)
    }

    // Get dal fronte
    @Override
    public T getFront() {
        if (isEmpty()) {
            throw new NoSuchElementException("La coda è vuota");
        }
        return elements.get(0);
    }

    //toString

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Coda: [");

        for (int i = 0; i < elements.size(); i++) {
            sb.append(elements.get(i));

            if (i < elements.size() - 1) {
                sb.append(", ");
            }
        }

        sb.append("] <- fine");
        return sb.toString();
    }
}

// CodaArrayListEstremoFissoLiberato
// Coda che usa ArrayList ottimizzato per operazioni in tempo costante
// Puntatore al fronte -> Cancellazioni di elementi (compact)
// Ottimizzazione delle stesse operazioni di sopra
public class CodaArrayListEstremoFissoLiberato<T> implements Coda<T> {
    private ArrayList<T> elements;
    private int front; // Indice elemento frontale

    // Costruttore
    public CodaArrayListEstremoFissoLiberato(){
        elements = new ArrayList<>();
        front = 0;
    }
    // isEmpty -> Verifica se la coda è vuota = Esiste ancora il puntatore frontale 
    @Override 
    public boolean isEmpty(){
        return front >= elements.size();
    }

    // size = N. elem. in coda = Size() - front
    @Override 
    public int size(){
        return elements.size() - front;
    }

    // Add della coda -> enqueue
    @Override 
    public void enqueue(T elem){
        elements.add(elem);
        // Posizioni vuote in mezzo -> Dequeue su più elementi = Compact
        if(front > elements.size() / 2 && front > 10){
            compact();
        }
    }
    // Remove della coda -> dequeue
    @Override 
    public T dequeue(){
        if(isEmpty())
            throw NoSuchElementException("Coda vuota");
        
        // Garbage collection = Gestione degli elementi in memoria 
        // Questa viene resa efficiente
        // Ci prendiamo l'elemento in coda e poi ripartiamo da front

        T value = elements.get(front); // O(1)
        elements.set(front, null); // O(1)
        front++; // front = front + 1; // O(1)
        
        return value;
    }

    // getFront
    @Override 
    public T getFront(){
        if(isEmpty())
            throw NoSuchElementException("Coda vuota");

        return(elements.get(front));
    }

    // Compact = Rimuovo gli elementi nulli all'inizio
    private void compact(){
        int size = elements.size();

        for(int i = 0; i < size - front; i++){ // O(n)
            elements.set(i, elements.get(i + front)); // O(1) aiutati dal puntatore frontale
        }

        for(int i = size - front; i < size; i++){
            elements.remove(size - front); // da front rimuovo elementi nulli
        }

        front = 0;
    }

    @Override
    public String toString() {
        if (isEmpty()) {
            return "Coda: []";
        }

        StringBuilder sb = new StringBuilder();
        sb.append("Coda: [");

        for (int i = front; i < elements.size(); i++) {
            sb.append(elements.get(i));
            
            if (i < elements.size() - 1) {
                sb.append(", ");
            }
        }

        sb.append("] <- fine");
        return sb.toString();
    }

    // toString
}

class StruttureDati{
    // Esempio di main che le richiama
    // Costruttori, scanner, metodi
}