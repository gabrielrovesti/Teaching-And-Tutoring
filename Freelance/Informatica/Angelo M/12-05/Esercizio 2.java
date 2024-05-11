import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

// Classe base Employee
abstract class Employee {
    protected String firstName;
    protected String lastName;
    protected LocalDate hireDate;

    public Employee(String firstName, String lastName, LocalDate hireDate) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.hireDate = hireDate;
    }

    public abstract double calculatePay();

    public String getFullName() {
        return firstName + " " + lastName;
    }
}

// Dipendente a tempo pieno
class FullTimeEmployee extends Employee {
    private double annualSalary;
    private double annualBonus;

    public FullTimeEmployee(String firstName, String lastName, LocalDate hireDate, double annualSalary) {
        super(firstName, lastName, hireDate);
        this.annualSalary = annualSalary;
    }

    public void setAnnualBonus(double annualBonus) {
        this.annualBonus = annualBonus;
    }

    @Override
    public double calculatePay() {
        return (annualSalary + annualBonus) / 12;
    }

    @Override
    public String toString() {
        return "Dipendente a tempo pieno: " + getFullName() + ", Stipendio annuale: " + annualSalary + ", Bonus annuale: " + annualBonus;
    }
}

// Dipendente part-time
class PartTimeEmployee extends Employee {
    private double hourlyRate;
    private int weeklyHours;
    private double overtimeRate;

    public PartTimeEmployee(String firstName, String lastName, LocalDate hireDate, double hourlyRate, double overtimeRate) {
        super(firstName, lastName, hireDate);
        this.hourlyRate = hourlyRate;
        this.overtimeRate = overtimeRate;
    }

    public void setWeeklyHours(int weeklyHours) {
        this.weeklyHours = weeklyHours;
    }

    @Override
    public double calculatePay() {
        int regularHours = Math.min(weeklyHours, 40);
        int overtimeHours = Math.max(weeklyHours - 40, 0);
        double regularPay = regularHours * hourlyRate;
        double overtimePay = overtimeHours * hourlyRate * overtimeRate;
        return regularPay + overtimePay;
    }

    @Override
    public String toString() {
        return "Dipendente part-time: " + getFullName() + ", Paga oraria: " + hourlyRate + ", Ore settimanali: " + weeklyHours + ", Maggiorazione straordinario: " + overtimeRate;
    }
}

// Dirigente
class Manager extends FullTimeEmployee {
    private double companyPerformanceBonus;
    private String companyCarModel;
    private double stockOptionValue;

    public Manager(String firstName, String lastName, LocalDate hireDate, double annualSalary, double companyPerformanceBonus, String companyCarModel, double stockOptionValue) {
        super(firstName, lastName, hireDate, annualSalary);
        this.companyPerformanceBonus = companyPerformanceBonus;
        this.companyCarModel = companyCarModel;
        this.stockOptionValue = stockOptionValue;
    }

    @Override
    public double calculatePay() {
        return super.calculatePay() + companyPerformanceBonus / 12;
    }

    @Override
    public String toString() {
        return "Dirigente: " + getFullName() + ", " + super.toString() + ", Bonus performance aziendale: " + companyPerformanceBonus + ", Auto aziendale: " + companyCarModel + ", Valore stock option: " + stockOptionValue;
    }
}

// Consulente esterno
class Contractor extends Employee {
    private double dailyRate;
    private int workingDays;
    private int maxWorkingDays;

    public Contractor(String firstName, String lastName, LocalDate hireDate, double dailyRate, int maxWorkingDays) {
        super(firstName, lastName, hireDate);
        this.dailyRate = dailyRate;
        this.maxWorkingDays = maxWorkingDays;
    }

    public void setWorkingDays(int workingDays) {
        this.workingDays = Math.min(workingDays, maxWorkingDays);
    }

    @Override
    public double calculatePay() {
        return dailyRate * workingDays;
    }

    @Override
    public String toString() {
        return "Consulente esterno: " + getFullName() + ", Tariffa giornaliera: " + dailyRate + ", Giorni lavorativi: " + workingDays + ", Limite massimo giorni: " + maxWorkingDays;
    }
}

// Stagista
class Intern extends Employee {
    private double monthlyStipend;
    private int internshipDuration; // In mesi

    public Intern(String firstName, String lastName, LocalDate hireDate, double monthlyStipend, int internshipDuration) {
        super(firstName, lastName, hireDate);
        this.monthlyStipend = monthlyStipend;
        this.internshipDuration = internshipDuration;
    }

    @Override
    public double calculatePay() {
        return monthlyStipend * internshipDuration;
    }

    @Override
    public String toString() {
        return "Stagista: " + getFullName() + ", Indennità mensile: " + monthlyStipend + ", Durata stage: " + internshipDuration + " mesi";
    }
}

// Classe principale per la gestione delle risorse umane
class HumanResourcesSystem {
    private List<Employee> employees;

    public HumanResourcesSystem() {
        employees = new ArrayList<>();
    }

    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    public void removeEmployee(Employee employee) {
        employees.remove(employee);
    }

    public double calculateTotalPayroll() {
        double totalPayroll = 0;
        for (Employee employee : employees) {
            totalPayroll += employee.calculatePay();
        }
        return totalPayroll;
    }

    public void displayEmployeeInfo() {
        for (Employee employee : employees) {
            System.out.println(employee);
        }
    }
}

// Classe principale
public class Main {
    public static void main(String[] args) {
        HumanResourcesSystem hrs = new HumanResourcesSystem();

        // Aggiunta di dipendenti
        FullTimeEmployee fte1 = new FullTimeEmployee("John", "Doe", LocalDate.of(2020, 1, 1), 60000);
        fte1.setAnnualBonus(5000);
        hrs.addEmployee(fte1);

        PartTimeEmployee pte1 = new PartTimeEmployee("Jane", "Smith", LocalDate.of(2022, 3, 15), 20, 1.5);
        pte1.setWeeklyHours(30);
        hrs.addEmployee(pte1);

        Manager manager1 = new Manager("Bob", "Johnson", LocalDate.of(2018, 6, 1), 100000, 20000, "BMW X5", 50000);
        hrs.addEmployee(manager1);

        Contractor contractor1 = new Contractor("Alice", "Williams", LocalDate.of(2023, 2, 1), 500, 200);
        contractor1.setWorkingDays(150);
        hrs.addEmployee(contractor1);

        Intern intern1 = new Intern("Michael", "Brown", LocalDate.of(2023, 5, 1), 1000, 6);
        hrs.addEmployee(intern1);

    // Visualizzazione delle informazioni dei dipendenti
    System.out.println("\nInformazioni dei dipendenti:");
    hrs.displayEmployeeInfo();

    // Calcolo della spesa salariale totale
    double totalPayroll = hrs.calculateTotalPayroll();
    System.out.println("\nSpesa salariale totale: $" + totalPayroll);
    }  
}