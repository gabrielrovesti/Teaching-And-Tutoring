public class Main
{
    public static void main(String[] args)
    {
        Banca intesa = new Banca("Intesa San Paolo");
        intesa.inserisciConto(new ContoCorrentePrivato("IT99C1234567890123456789012",
                                                        0,
                                               0,
                                                        "alfredo",
                                                      "centinaro",
                                                    "CNTLRD82A02L103V"));
        intesa.inserisciConto(new ContoCorrenteGiuridico("IT88C1234567890123456789012",
                0,
                0,
                "Alfredo SPA",
                "1234567"));

        intesa.modificaConto("IT99C1234567890123456789012")
                .versamento(1000);
        intesa.modificaConto("IT99C1234567890123456789012")
                .prelievo(200);


        intesa.stampaInfoConti();

        if(intesa.cercaConto("IT99C1234567890123456789012"))
            System.out.println("Trovato IT99C1234567890123456789012");
        else
            System.out.println("Non Trovato IT99C1234567890123456789012");

        System.out.println("Ho creato #"+ContoCorrente.quanticontiHocreato +" conti");
    }
}
