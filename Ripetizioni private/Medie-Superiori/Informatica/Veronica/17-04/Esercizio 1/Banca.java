import java.util.ArrayList;

public class Banca
{
    private String nome;
    private ArrayList <ContoCorrente> listaConti;

    //COSTRUTTORI
    public Banca()
    {
        listaConti = new ArrayList<ContoCorrente>();
    }

    public Banca(String nome)
    {
        this(); //chiama il costruttore vuoto + aggiunge l'inizializzazione di seguito

        this.nome = nome;
    }

    //METODI DI ACCESSO SET/GET
    public String getNome()
    {
        return nome;
    }

    public void setNome(String nome)
    {
        this.nome = nome;
    }

    //METODI ACCESORI
    public void inserisciConto(ContoCorrente _c)
    {
        this.listaConti.add(_c);
    }

//overloading inserisciConto
    public void inserisciConto(String IBAN, double saldo, int movimenti)
    {
        this.listaConti.add(new ContoCorrente(IBAN, saldo, movimenti));
    }

    public void cancellaConto(String _IBAN)
    {
        for (int i=0; i < this.listaConti.size(); i++)
        {
            if (this.listaConti.get(i).getIBAN() == _IBAN)
            {
                this.listaConti.remove(i);
            }
        }
    }

    public ContoCorrente modificaConto(String _IBAN)
    {
        for (int i=0; i < this.listaConti.size(); i++)
        {
            if (this.listaConti.get(i).getIBAN() == _IBAN)
            {
                return this.listaConti.get(i);
            }
        }

        return null;
    }

    public boolean cercaConto(String _IBAN)
    {
        for (int i=0; i < this.listaConti.size(); i++)
        {
            if (this.listaConti.get(i).getIBAN() == _IBAN)
            {
                return true;
            }
        }

        return false;
    }
    
    //@Overloading
    public boolean cercaConto(String _cognome, String _nome)
    {
        for (int i=0; i < this.listaConti.size(); i++)
        {
            if (this.listaConti.get(i) instanceof ContoCorrentePrivato)
            {
                if (new ContoCorrentePrivato ((ContoCorrentePrivato) this.listaConti.get(i)).getNome() == _nome &&
                    new ContoCorrentePrivato ((ContoCorrentePrivato) this.listaConti.get(i)).getCognome() == _cognome)
                {
                    return true;
                }
            }

            if (this.listaConti.get(i) instanceof ContoCorrenteGiuridico)
            {
                if (new ContoCorrenteGiuridico ((ContoCorrenteGiuridico) this.listaConti.get(i)).getPartitaIVA() == _nome &&
                        new ContoCorrenteGiuridico ((ContoCorrenteGiuridico) this.listaConti.get(i)).getRagioneSociale() == _cognome)
                {
                    return true;
                }
            }
        }

        return false;
    }

    public double totaleSaldi()
    {
        double totale = 0;
        for (int i=0; i < this.listaConti.size(); i++)
        {
            totale += this.listaConti.get(i).getSaldo();
        }
        return totale;
    }

    public void stampaInfoConti()
    {
        for (int i=0; i < this.listaConti.size(); i++)
        {
            this.listaConti.get(i).stampaInfo();
        }
    }
}
