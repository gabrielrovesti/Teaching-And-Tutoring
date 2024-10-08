public class ContoCorrente{
    private String iban;
    private double saldo;
    private double conteggioMovimenti;

    public ContoCorrente(string i, double s, string cm){
        this.iban = i;
        this.saldo = s;
        this.conteggioMovimenti = cm;
    }
    // Overloading
    public ContoCorrente(string i){
        this.iban = i;
        this.saldo = 0.0;
        this.conteggioMovimenti = 0.0;
    }

    public void versamento(ContoCorrente c1, double importo){
        if(saldo > 0 && c1.iban != ""){
            this.saldo -= importo;
            this.conteggioMovimenti++;
            c1.saldo += importo;
            c1.conteggioMovimenti++;
        }
    }

    public void prelievo(ContoCorrente c1, double importo){
        if(saldo > 0 && c1.iban != ""){
            this.saldo += importo;
            this.conteggioMovimenti++;
            c1.saldo -= importo;
            c1.conteggioMovimenti++;
        }
    }

    public String getIban(){
        return iban;
    }

    
    public double getSaldo(){
        return saldo;
    }

    public double getConteggioMovimenti(){
        return conteggioMovimenti;
    }

    @Override
    public String toString(){
        System.out.println("|--------------INFO CONTO-----------------|");
        System.out.println("| IBAN: " + this.getIBAN());
        System.out.println("| Saldo: " + this.getSaldo());
        System.out.println("| #Movimenti:" + this.getConteggioMovimenti());
        System.out.println("|-----------------------------------------|");
        System.out.println();
    }
}