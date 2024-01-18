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
