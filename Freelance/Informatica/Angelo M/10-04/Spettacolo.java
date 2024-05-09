public class Spettacolo{
    private String nome;
    private Cliente[] prenotazioni;
    private int nroPrenotazioni;
    private int maxPrenotazioni;

    public Spettacolo(String nome, Cliente[] prenotazioni, int nP, int mP){
        this.nome = nome;
        this.prenotazioni = new Cliente[mP];
        this.nroPrenotazioni = nP;
        this.maxPrenotazioni = mP;
    }

    public Spettacolo(String nome, int nP){
        this.nome = nome;
        this.prenotazioni = new Cliente[nP];
        this.nroPrenotazioni = nP;
        this.maxPrenotazioni = nP;
    }

    public boolean postiLiberi(){
        // Occhio che possiamo usare i campi
        if(nroPrenotazioni < maxPrenotazioni)
            return true;    
            // if/for/while di una sola istruzione = può non avere le graffe
        else
            return false; 
    }

    public int trova(String nome, String telefono){
        for(int i = 0; i < nroPrenotazioni; i++){
            if(prenotazioni[i].getNome().equals(nome) && prenotazioni[i].getTelefono().equals(telefono))
                return i;
        }
        return -1;
    }

    public boolean prenota(String nome, String telefono){
        if(postiLiberi()) // uguale a fare postiLiberi() == true 
        // if(!postiLiberi) // uguale a fare postiLiberi() == false
        {
            if(trova(nome, telefono) == -1){
                prenotazioni[nroPrenotazioni++] = new Cliente(nome, telefono);

                return true;
            }
        }
        return false;
    }

    public Cliente disdici(String nome, String telefono){
        int indice = trova(nome, telefono);
        if(indice != -1){
            Cliente clienteEliminato = prenotazioni[indice];
            // cliente da restituire perché è stato cancellato in posizione "indice"

            // ciclo che considera da posizione "indice" per spostare tutti gli elementi dopo la cancellazione
            for(int i = indice; i < nroPrenotazioni; i++) {
                prenotazioni[i] =  prenotazioni[i+1];
            }

            /*
            Alternativa: (non uscire dai limiti dell'array se alla fine)

            for (int i = index; i < nroPrenotazioni - 1; i++) {
                prenotazioni[i] = prenotazioni[i + 1];
            }
            prenotazioni[--nroPrenotazioni] = null;


            */
            
            return clienteEliminato;
        }
        return null;
    }

    public boolean prenota(Cliente cliente){
        return prenota(cliente.getNome(), cliente.getTelefono());

        // questo già ritorna "true" o "false"

        /*
        Completamente:

        if(postiLiberi()) 
        {
            if(trova(cliente.getNome(), cliente.getTelefono()) == -1){
                prenotazioni[nroPrenotazioni++] = new Cliente("", "");

                return true;
            }
        }
        return false;

        */
    }
}