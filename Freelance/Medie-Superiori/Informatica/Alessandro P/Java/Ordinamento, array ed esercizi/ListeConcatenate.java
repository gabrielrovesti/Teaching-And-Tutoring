import java.util.List;

public class ListeConcatenate {
    Nodo testa;

    public ListeConcatenate() {
        this.testa = null;
    }

    // Aggiungi un elemento in coda alla lista
    public void aggiungiElemento(int valore) {
        Nodo nuovoNodo = new Nodo(valore);
        if (testa == null) {
            testa = nuovoNodo;
        } else {
            Nodo ultimo = trovaUltimoNodo();
            ultimo.successivo = nuovoNodo;
        }
    }

    // Trova l'ultimo nodo nella lista
    private Nodo trovaUltimoNodo() {
        Nodo corrente = testa;
        while (corrente.successivo != null) {
            corrente = corrente.successivo;
        }
        return corrente;
    }

    // Stampa la lista concatenata
    public void stampaLista() {
        Nodo corrente = testa;
        while (corrente != null) {
            System.out.print(corrente.valore + " ");
            corrente = corrente.successivo;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListeConcatenate lista = new ListeConcatenate();

        lista.aggiungiElemento(1);
        lista.aggiungiElemento(2);
        lista.aggiungiElemento(3);

        System.out.println("Lista concatenata:");
        lista.stampaLista();
    }
}
