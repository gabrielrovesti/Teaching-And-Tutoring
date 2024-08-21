import java.util.*;

import java.util.LocalDateTime; // tipo data = LocalDateTime
// sia data che ora

// Interfaccia 
interface Notifica(){
    void invia();
    String getDestinatario();
    int getPriorita();
}

// Interfaccia definisce operazioni (per contratto)
// Classe astratta implementa (implements)
// Sottoclasse classica estende (extends)

abstract class NotificaBase implements Notifica{
    // timestamp: 2024-10-12 10:00:20

    // protected = attributo visto solo dalle sottoclassi
    // information hiding
    protected String destinatario;
    protected String contenuto;
    protected LocalDateTime timestamp;
    protected int priorita;

    // costruttore
    public NotificaBase(String destinatario, String contenuto, int priorita){
        this.destinatario = destinatario;
        this.timestamp = LocalDateTime.now();
        this.contenuto = contenuto;
        this.priorita = priorita;
    }

    // set/get
    // annotazione = Indicazione interna
    @Override
    // overriding = definizione metodo con diversi parametri in una classe specifica
    public String getDestinatario(){
        return destinatario;
    }
}

// Classe concreta = implementa la classe astratta estendendone i metodi

class NotificaEmail extends NotificaBase{
    private String oggetto;
    private List<String> allegati;

    // costruttore
    public NotificaBase(String destinatario, String contenuto, int priorita, String oggetto){
        super(destinatario, priorita, contenuto);
        this.oggetto = oggetto;
        this.allegati = new List<>();
    }
}

// instanceOf = polimorfismo = verifica che il tipo classe sia quello

// se sei una notifica, sei il tipo NotificaBase

// In tutti i lingauggi, si chiama "cast" = verifico convertendo al tipo che sia lui

public static void main(String[] args){

}