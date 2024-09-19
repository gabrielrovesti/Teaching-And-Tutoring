public class 9_2 {
    
}

public class Employee{

}

public class Manager extends Employee{

}

public class Accountant extends Employee{

}

public class SalariedEmployee extends Employee{

}

public class SlaveAccountant extends Accountant{

}

public class GoodAccountant extends Accountant{

}

        /*
         Employee   
        /       \           \
    Manager     Accountant      SalariedEmployee
            /           \
        Slave           Good  
         * 
         */

abstract class Employee{
    void weeklyPay();
    void setName();
}

class SalariedEmployee extends Employee{
    // overriding = overloading da parte di sottoclasse
    // = sovrascrivere
    @Override
    // annotazione = aggiunta informazioni al tuo codice, non obbligatoria
    void weeklyPay(){

    }

    void setName(){

    }
}

// E.g. SalariedEmployee sovrascrive la tua classe

// variabili di esemplare di un oggetto = variabili 
// di istanza = oggetti parte della classe (field/attributi)
// visibii nella stessa classe

public class HourlyEmployee extends Employee{
    private int hourSalary;

}