public class Bicicletta {

    private int id;
    private TipoBicicletta tipo;
    private Date dataOraParcheggio;
    private Date dataOraInizioNoleggio;

    public Bicicletta(int id, TipoBicicletta tipo) {
        this.id = id;
        this.tipo = tipo;
        this.dataOraParcheggio = null;
        this.dataOraInizioNoleggio = null;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public TipoBicicletta getTipo() {
        return tipo;
    }

    public void setTipo(TipoBicicletta tipo) {
        this.tipo = tipo;
    }

    public Date getDataOraParcheggio() {
        return dataOraParcheggio;
    }

    public void setDataOraParcheggio(Date dataOraParcheggio) {
        this.dataOraParcheggio = dataOraParcheggio;
    }

    public Date getDataOraInizioNoleggio() {
        return dataOraInizioNoleggio;
    }

    public void setDataOraInizioNoleggio(Date dataOraInizioNoleggio) {
        this.dataOraInizioNoleggio = dataOraInizioNoleggio;
    }

    public boolean isNoleggiata() {
        return dataOraInizioNoleggio != null;
    }

    public boolean isRientrata() {
        return dataOraParcheggio != null && dataOraInizioNoleggio != null;
    }

    public double calcolaCostoNoleggio() {
        if (isNoleggiata()) {
            long differenzaMinuti = (new Date().getTime() - dataOraInizioNoleggio.getTime()) / (60 * 1000);
            return differenzaMinuti * getTariffaNoleggio();
        } else {
            return 0;
        }
    }

    public String toString() {
        if (isNoleggiata()) {
            return "Bicicletta [id=" + id + ", tipo=" + tipo + ", dataOraParcheggio=" + dataOraParcheggio + ", dataOraInizioNoleggio=" + dataOraInizioNoleggio + ", in noleggio]";
        } else if (isRientrata()) {
            return "Bicicletta [id=" + id + ", tipo=" + tipo + ", dataOraParcheggio=" + dataOraParcheggio + ", dataOraInizioNoleggio=" + dataOraInizioNoleggio + ", rientrata]";
        } else {
            return "Bicicletta [id=" + id + ", tipo=" + tipo + ", dataOraParcheggio=" + dataOraParcheggio + ", dataOraInizioNoleggio=" + dataOraInizioNoleggio + ", nuova]";
        }
    }
}

enum TipoBicicletta {
    NORMALE,
    ASSISTITA,
    ELETTRICA
}

LocalDate date = LocalDate.of(2109, 03, 28);
LocalTime time = LocalTime.of(10, 34);	


// Esempio main()

import java.util.Date;

public class Main {
    public static void main(String[] args) {
        // Creazione di un'istanza di bicicletta
        Bicicletta bicicletta = new Bicicletta(1, TipoBicicletta.NORMALE);

        // Visualizzazione delle informazioni sulla bicicletta (in stato "nuova")
        System.out.println(bicicletta.toString());

        // Parcheggio della bicicletta
        bicicletta.setDataOraParcheggio(new Date());
        System.out.println(bicicletta.toString());

        // Inizio del noleggio della bicicletta
        bicicletta.setDataOraInizioNoleggio(new Date());
        System.out.println(bicicletta.toString());

        // Calcolo del costo del noleggio
        System.out.println("Costo del noleggio: " + bicicletta.calcolaCostoNoleggio() + " cent");

        // Visualizzazione delle informazioni sulla bicicletta (in stato "in noleggio")
        System.out.println(bicicletta.toString());

        // Rientro della bicicletta
        bicicletta.setDataOraParcheggio(new Date());
        System.out.println(bicicletta.toString());

        // Visualizzazione delle informazioni sulla bicicletta (in stato "rientrata")
        System.out.println(bicicletta.toString());
    }
}