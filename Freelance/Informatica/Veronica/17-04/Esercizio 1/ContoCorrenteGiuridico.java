public class ContoCorrenteGiuridico extends ContoCorrente
{
    private String partitaIVA;
    private String ragioneSociale;

    public ContoCorrenteGiuridico(String partitaIVA, String ragioneSociale)
    {
        this.partitaIVA = partitaIVA;
        this.ragioneSociale = ragioneSociale;
    }

    public ContoCorrenteGiuridico(String IBAN, double saldo, int conteggioMovimenti, String partitaIVA, String ragioneSociale) {
        super(IBAN, saldo, conteggioMovimenti);
        this.partitaIVA = partitaIVA;
        this.ragioneSociale = ragioneSociale;
    }

    public ContoCorrenteGiuridico(ContoCorrenteGiuridico _c) {
        super(_c);
        this.partitaIVA = _c.getPartitaIVA();
        this.ragioneSociale = _c.getRagioneSociale();
    }

    public String getPartitaIVA() {
        return partitaIVA;
    }

    public void setPartitaIVA(String partitaIVA) {
        this.partitaIVA = partitaIVA;
    }

    public String getRagioneSociale() {
        return ragioneSociale;
    }

    public void setRagioneSociale(String ragioneSociale) {
        this.ragioneSociale = ragioneSociale;
    }


    @Override
    public void stampaInfo()
    {
        System.out.println("|--------------INFO CONTO-----------------|");
        System.out.println("| IBAN: " + this.getIBAN());
        System.out.println("| Ragione Sociale: " + this.ragioneSociale);
        System.out.println("| P. IVA: " + this.partitaIVA);
        System.out.println("| Saldo: " + this.getSaldo());
        System.out.println("| #Movimenti:" + this.getConteggioMovimenti());
        System.out.println("|-----------------------------------------|");
        System.out.println();
    }
}
