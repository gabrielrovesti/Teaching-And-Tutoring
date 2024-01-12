public class Lista {

    // Lista
    // [info]-[next] --> [info]-[next] --> [...]

    private Nodo testa; // Punto all'inizio della lista

    public class Nodo {
        int info; // Informazione
        Nodo next; // Nodo successivo

        Nodo(int info) {
            this.info = info;
            this.next = null;
        }
    }

    // Operazioni
    // Aggiunta di un elemento
    // Rimozione di un elemento

    void aggiungiElemento(int elemento) {
        Nodo nuovoNodo = new Nodo(elemento); // Creiamo un nuovo nodo con l'elemento
        if (testa == null) {
            testa = nuovoNodo; // Se la lista è vuota, il nuovo nodo diventa la testa
        } else {
            Nodo nodoCorrente = testa;
            // Scorrere fino alla fine della lista
            while (nodoCorrente.next != null) {
                nodoCorrente = nodoCorrente.next;
            }
            nodoCorrente.next = nuovoNodo; // Aggiungi il nuovo nodo alla fine della lista
        }
    }

    // Metodo per stampare gli elementi della lista
    void stampaLista() {
        Nodo nodoCorrente = testa;
        while (nodoCorrente != null) {
            System.out.println(nodoCorrente.info);
            nodoCorrente = nodoCorrente.next;
        }
    }

    public static void main(String[] args) {
        // Creazione di una lista
        Lista listaNumeri = new Lista();

        // Aggiunta di elementi alla lista
        listaNumeri.aggiungiElemento(10);
        listaNumeri.aggiungiElemento(20);
        listaNumeri.aggiungiElemento(30);
        listaNumeri.aggiungiElemento(40);

        // Stampa degli elementi della lista
        System.out.println("Elementi della lista:");
        listaNumeri.stampaLista();
    }
}
