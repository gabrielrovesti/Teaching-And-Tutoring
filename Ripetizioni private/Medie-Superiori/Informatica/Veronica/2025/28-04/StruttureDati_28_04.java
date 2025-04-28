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

// Coda Circolare (Queue)
// Esempio: coda circolare specifica per interi
public class CodaCircolareArrayInteger implements Coda<Integer>{
    // Array di elementi (interi)
    private int[] elements;
    // Fronte-Testa / Retro-Coda / Size
    private int front;
    private int rear;
    private int size; // Numero elementi attualmente presenti

    // (Eventuale) Capacity (capacità) "finale" - Massimo num. elementi contenibile
    private static final int CAPACITY = 10;

    // Costruttore
    public CodaCircolareArrayInteger(int capacity){
        elements = new int[capacity];

        front = 0; // esiste solo il fronte vuoto
        rear = -1;
        size = 0;
    }

    // isFull() / isEmpty() / size()

    public boolean isFull(){
        // se size corrisponde alla lunghezza dell'array di interi 
        return size == elements.length;
    }

    @Override 
    public boolean isEmpty(){
        return size == 0;
    }

    @Override 
    public int size(){
        return size;
    }

    // Metodi di interesse 

    // enqueue = Accoda (dopo rear)
    @Override 
    public void enqueue(Integer element){
        // O la coda è piena
        if(isFull())
            throw new IllegalStateException("Coda piena");

        // Aggiungiamo elemento alla fine )(sicuri che ce ne starà un altro)
        rear = (rear + 1) % elements.length;
        // rear += 1; // accogliere elemento
        elements[rear] = element; // aggiunta
        // Aumentiamo size 
        size++;
    }

    // dequeue = Toglie dalla cima (da front) - restituendolo
    @Override 
    public Integer dequeue(){
        // O la coda è vuota
        if(isEmpty())
            throw new NoSuchElementException("Coda piena");

        // Rimuoviamo elemento dal fronte
        int value = elements[front]; // salvo
        front = (front + 1) % elements.length;
        size--; // Diminuisco size

        return value;
    }

    // Volendo: getRear() / getFront() -> return elements[rear] / return elements[front]
}

// Coda Doppia (Deque) - Fronte e retro (puntatore sia ad inizio che fine)
// Caso d'uso - PalindromeChecker (palindrome)

// ABBA - Es. palindromo 

// Libreria - Deque / ArrayDeque
import java.util.Deque;
import java.util.ArrayDeque;

public class PalindromeChecker{

    public static boolean isPalindrome(String input) {
        // input nullo 
        if(input == null) return false;

        // input non nullo e verifica con deque di caratteri
        // puntiamo ad inizio e puntiamo a fine e poi verifico match caratteri

        // sanificare input (opzionale)
        String cleanInput = input.replaceAll("[^a-zA-Z0-9]",
"").toLowerCase();

        // vuota = palindromo vero
        if (cleanInput.isEmpty())
            return true; // vuoto = palindromo a sé stesso

        // Uso della Deque gestendo gli elementi linearmente
        Deque<Character> deque = new ArrayDeque<>();

        // Inseriamo i caratteri nella deque (popolarla ad array = inseriamo dopo ultimo elemento = rear)
        for(char c: cleanInput.toCharArray()){
            deque.addLast(c);
        }
        
        // Confronto estremità
        while(deque.size() > 1){
            // primo e ultimo 
            char first = deque.removeFirst();
            char last = deque.removeLast(); 

            if(first != last) return false;
        }
        return true;
    }
    /* 
    public static void main(String[] args) {
        System.out.println("'radar' è palindromo? " +
        isPalindrome("radar"));

        System.out.println("'A man, a plan, a canal: Panama' è palindromo? "
        +
        isPalindrome("A man, a plan, a canal: Panama"));

        System.out.println("'hello' è palindromo? " +
        isPalindrome("hello"));
    }
    */
}

// Coda Prioritaria (Priority Queue)
// Gestito come coda = Coppia (inizio-fine)
// Ciascun elemento ha priorità

// Librerie Comparatore e PriorityQueue
import java.util.Comparator;
import java.util.PriorityQueue;

class Coppia{
    private String descrizione;
    private int priorita;

    public Coppia(String descrizione, int priorita) {
        this.descrizione = descrizione;
        this.priorita = priorita;
    }

    public String getDescrizione() {
        return descrizione;
    }

    public int getPriorita() {
        return priorita;
    }
}

class ComparatoreCoppia implements Comparator<Coppia>{
    // Metodo che verifica la priorità minore (più alta) - O(n log (n))
    public int compare(Coppia o1, Coppia o2){
        return o1.getPriorita() - o2.getPriorita();
    }
}

// Classe Coda di priorità = Implementa il comparatore, aggiunge coppie e ne verifica la priorità

class EsempioPriorityQueue{
    public static void main(String[] args){
        // Crea coda con comparatore di coppia <T> = <Coppia>

        PriorityQueue<Coppia> codaPrioritaria = new PriorityQueue<>(new ComparatoreCoppia());

        // Aggiunge coppie alla coda
        codaPrioritaria.add(new Coppia("Task normale", 3));

        codaPrioritaria.add(new Coppia("Task urgente", 1));

        codaPrioritaria.add(new Coppia("Task bassa priorità", 5));

        codaPrioritaria.add(new Coppia("Task alta priorità", 2));

        // Vari metodi per estrarre: poll() - estrae elemento dal fronte e verifica priorità
        // peek()

        // Estrae gli elementi in ordine di priorità
        System.out.println("Elementi in ordine di priorità:");

        while (!codaPrioritaria.isEmpty()) {
            System.out.println(codaPrioritaria.poll()); // Continuo ad estrarre l'elemento a buffer
        }
    }
}

// LinkedList
// Lista collegata = [Elemento | Puntatore al nodo successivo] <-- Nodo []
// [Nodo 1] - [Nodo 2] - [Nodo 3]
// (Volendo) Nelle liste possiamo gestire first e last (= volendo possiamo passare ad altre strutture dati)

import java.util.LinkedList;
import java.util.Iterator;

// Iterator = Oggetto che scorre in automatico

public class EsempioLinkedList{
    public static void main(String[] args) {
        // Crea la lista di Stringhe 
        LinkedList<String> lista = new LinkedList<>();

        // Aggiunge elementi alla lista
        lista.add("Primo");
        lista.add("Secondo");
        lista.add("Terzo");
        // Inserisce un elemento a un indice specifico
        lista.add(3, "Quarto");

        // Aggiunge elementi all'inizio e alla fine
        lista.addFirst("Inizio");
        lista.addLast("Fine");

        // Stampa la lista
        System.out.println("Lista completa: " + lista);

        // Accede agli elementi
        System.out.println("Primo elemento: " + lista.getFirst());
        System.out.println("Ultimo elemento: " + lista.getLast());
        System.out.println("Elemento all'indice 2: " + lista.get(2));

        // Rimuove elementi
        lista.removeFirst();
        lista.removeLast();
        lista.remove(1);
        System.out.println("Lista dopo le rimozioni: " + lista);

        // Uso di iterator (stringa) 
        System.out.println("Iterazione sulla lista:");
        Iterator<String> iterator = lista.iterator();
        // hasNext() = Continua a scorrere tutti gli elementi 
        while (iterator.hasNext()) {
            System.out.println("- " + iterator.next());
        }

        // Itera sulla lista in modo più conciso
        System.out.println("Iterazione concisa:");
        for (String elemento : lista) {
        System.out.println("- " + elemento);
        }

        // Svuota la lista
        lista.clear();
        System.out.println("La lista è vuota? " + lista.isEmpty());
    }
}

// Parentesi (Hash)
// Hash -> Valore con una chiave

// Insieme -> HashSet
// Set = Un insieme di elementi disordinato ma tutti univoci 

import java.util.HashSet;
public class EsempioHashSet{
    public static void main(String[] args) {
        // Crea un HashSet di stringhe
        HashSet<String> set = new HashSet<>();

        // Aggiunge elementi al set
        set.add("Mela");
        set.add("Banana");
        set.add("Arancia");
        set.add("Mela"); // Non verrà aggiunto perché è un duplicato - set = tutti elementi univoci!

        // Stampa il set
        System.out.println("Set: " + set);

        // Verifica la dimensione
        System.out.println("Dimensione del set: " + set.size());

        // Verifica se un elemento è presente
        System.out.println("Contiene 'Banana'? " + set.contains("Banana"));
        System.out.println("Contiene 'Pera'? " + set.contains("Pera"));

        // Rimuove un elemento
        set.remove("Banana");
        System.out.println("Set dopo la rimozione: " + set);

        // Itera sul set
        System.out.println("Elementi nel set:");
        for (String frutto : set) {
            System.out.println("- " + frutto);
        }

        // Crea HashSet 
        HashSet<String> altroSet = new HashSet<>();

        altroSet.add("Kiwi");
        altroSet.add("Mela");

        // Set -> Insieme
        // Unione (A U B) - Intersezione (A ∩ B) - Differenza (A \ B)

        // Unione - addAll
        HashSet<String> unione = new HashSet<>(set);
        unione.addAll(altroSet);
        System.out.println("Unione: " + unione);

        // Intersezione - filtra quelli da prenderti - retainAll
        HashSet<String> intersezione = new HashSet<>(set);
        intersezione.retainAll(altroSet);
        System.out.println("Intersezione: " + intersezione);

        // Differenza - removeAll
        HashSet<String> differenza = new HashSet<>(set);
        differenza.removeAll(altroSet);
        System.out.println("Differenza: " + differenza);

        // Pulizia set
        set.clear();
        System.out.println("Il set è vuoto? " + set.isEmpty());
    }
}

import java.util.HashMap;
import java.util.Map;

// Mappa -> HashMap - Esempio: ContaRicorrenze
// Mappa = Array associativo [Chiave-Valore]

public class ContaRicorrenze{
    // Data una stringa, conta le occorrenze di ciascun carattere
    public static void nRicorrenze(String s){
        // Se vuoto  
        if (s == null || s.isEmpty()) {
            System.out.println("La stringa è vuota o null");
            return;
        }

        // Se non vuoto, crea una HashMap <carattere, ricorrenza>
        HashMap<Character, Integer> ricorrenze = new HashMap<>();
        // Chiave = Carattere (alfabetico)
        // Valore = Ricorrenza (apparizioni)

        // Conta le ricorrenze di ciascun carattere
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i); // prendere il carattere ad una posizione 

            // Aggiorna il conteggio per il carattere corrente
            ricorrenze.put(c, ricorrenze.getOrDefault(c, 0) + 1);
            // put = Associa al carattere la ricorrenza specifica (default: 0) - o c'è ricorrenza o butta 0
            }
            // Stampa i risultati
            System.out.println("Ricorrenze dei caratteri in \"" + s + "\":");

            // Entry = Coppia chiave / valore = Carattere / Ricorrenza e lo gestisco come insieme (elementi univoci) + accesso lineare
            for (Map.Entry<Character, Integer> entry : ricorrenze.entrySet()) {
                System.out.println("'" + entry.getKey() + "': " +
                entry.getValue());
            }
            // Hash -> O riesco a inserire valore / Oppure collisione (non riesco a metterlo in quella posizione)
            // Voglio inserire in posizione 4 -> [1, 2, 3, 4]
            // Collisione -> Devo ricalcolare dove....
            // Set garantisce unicità!
    }
}

class StruttureDati{
    // Esempio di main che le richiama
    // Costruttori, scanner, metodi
}