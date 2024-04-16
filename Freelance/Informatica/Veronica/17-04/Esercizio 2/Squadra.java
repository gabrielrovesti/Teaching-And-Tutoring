import java.util.ArrayList;

public class Squadra
{
    private String nome;
    private int annoFondazione;
    private ArrayList<Calciatore> rosa;

    public Squadra()
    {
        this.rosa = new ArrayList<Calciatore>();
    }

    public Squadra(String nome, int annoFondazione)
    {
        this();
        this.nome = nome;
        this.annoFondazione = annoFondazione;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAnnoFondazione() {
        return annoFondazione;
    }

    public void setAnnoFondazione(int annoFondazione) {
        this.annoFondazione = annoFondazione;
    }

    //METODI ACCESSORI
    public void inserisciCalciatore(Calciatore c)
    {
        if (c != null)
        {
            this.rosa.add(c);
        }
    }

    public int cerca(String _nome)
    {
        for(int i=0; i < this.rosa.size(); i++)
        {
            if (this.rosa.get(i).getNome() == _nome)
            {
                return i;   //restituisce l'indice del calciatore trovato
            }
        }

        return -1;
    }

    public Calciatore modifica(String _nome)
    {
        for(int i=0; i < this.rosa.size(); i++)
        {
            if (this.rosa.get(i).getNome() == _nome)
            {
                return this.rosa.get(i);
            }
        }

        return null;
    }

    public void rimuoviCalciatore(int index)
    {
        this.rosa.remove(index);
    }

    public void rimuoviCalciatore(String _nome)
    {
        for(int i=0; i < this.rosa.size(); i++)
        {
            if (this.rosa.get(i).getNome() == _nome)
            {
                this.rosa.remove(i);
            }
        }

    }

    public void stampaRosa()
    {
        for(int i=0; i < this.rosa.size(); i++)
        {
            if (this.rosa.get(i) instanceof Portiere)
            {
                Portiere p = (Portiere)this.rosa.get(i);
                p.stampaInfo();
            }
            else
                this.rosa.get(i).stampaInfo();
            System.out.println();
        }
    }

    public long valoreInEuroSquadra()
    {
        long valore = 0;
        for(int i=0; i < this.rosa.size(); i++)
        {
            valore += this.rosa.get(i).getValoreinEuro();
        }

        return valore;
    }

    public Calciatore calciatoreConPiuGol()
    {
        Calciatore max = null;

        for(int i=0; i < this.rosa.size(); i++)
        {
            if (this.rosa.get(i).getGolSegnati() > max.getGolSegnati())
            {
                max = this.rosa.get(i);
            }
        }

        return max;
    }
}
