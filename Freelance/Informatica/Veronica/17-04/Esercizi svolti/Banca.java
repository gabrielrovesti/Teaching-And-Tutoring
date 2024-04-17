import java.util.ArrayList;

public class Banca {
    // oggetti della classe padre

    private ArrayList<ContoCorrente> listaConti;
    private String nome;

    public Banca(){
        this.nome = "";
        this.listaConti = new ArrayList<ContoCorrente>();
    }

    public Banca(String nome){
        this(); // come se richiamasse il costruttore vuoto
        this.nome = nome;
    }

    public void inserisciConto(ContoCorrente c){
        this.listaConti.add(c);
    }

    public void inserisciConto(String IBAN, double saldo, int movimenti){
        this.listaConti.add(new ContoCorrente(IBAN, saldo, movimenti));
    }

    public void cancellaConto(String IBAN){
        for(ContoCorrente c: listaConti){
            if (c.getIban.equals(IBAN)){
                this.listaConti.remove(c);
            }
        }
    }

    public ContoCorrente modificaConto(String IBAN){
        for(ContoCorrente c: listaConti){
            if (c.getIban.equals(IBAN)){
                return c;
            }
            return null;
        }
    }

    public boolean cercaConto(String _IBAN){
        for(ContoCorrente c: listaConti){
            return c.getIban.equals(IBAN);
        }
    }

    //Overloading
    public boolean cercaConto(String _cognome, String _nome){
        for(ContoCorrente c: listaConti){
            if(c instanceof ContoCorrentePrivato){
                if(c.getNome().equals(_nome) && c.getCognome().equals(_cognome)){
                    return true;
                }
            }
        }
        return false;
    }
}
