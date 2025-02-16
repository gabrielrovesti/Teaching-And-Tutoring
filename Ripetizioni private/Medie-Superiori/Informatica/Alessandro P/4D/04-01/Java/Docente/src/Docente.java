/*
Scrivere una classe Docente che rappresenti le seguenti informazioni:
cognome, codice ed età che contenga il costruttore parametrizzato e i metodi
getCodice, getCognome, getEta e che restituiscono codice, cognome ed età.

 */

public class Docente{
    String cognome;
    String codice;
    int età;

    public Docente(Docente docente){
        cognome = docente.getCognome();
        codice = docente.getCodice();
        età = docente.getEtà();
    }
    public Docente(String cog, String cod, int et){
        cognome = cog;
        codice = cod;
        età = et;
    }

    //Metodi get - ritornano variabili
    public String getCognome() {
        return cognome;
    }

    public String getCodice(){
        return codice;
    }

    public int getEtà(){
        return età;
    }

    //Metodi set - impostano variabili
    public void setCognome(String c){
        cognome = c;
    }

    public void setCodice(String c){
        codice = c;
    }

    public void setEtà(int e){
        età = e;
    }
}