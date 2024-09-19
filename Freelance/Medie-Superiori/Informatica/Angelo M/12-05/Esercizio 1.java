import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

// Classe base Employee
class Employee {
    protected String firstName;
    protected String lastName;
    protected LocalDate hireDate;
    protected double annualSalary;

    public Employee(String firstName, String lastName, LocalDate hireDate, double annualSalary) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.hireDate = hireDate;
        this.annualSalary = annualSalary;
    }

    public double calculateAnnualSalary() {
        return annualSalary;
    }

    public String getEmployeeInfo() {
        return "Nome: " + firstName + " " + lastName + ", Data di assunzione: " + hireDate + ", Stipendio annuale: " + annualSalary;
    }
}

// Classe Manager che eredita da Employee
class Manager extends Employee {
    private String department;
    private double annualBonus;

    public Manager(String firstName, String lastName, LocalDate hireDate, double annualSalary, String department, double annualBonus) {
        super(firstName, lastName, hireDate, annualSalary);
        this.department = department;
        this.annualBonus = annualBonus;
    }

    @Override
    public double calculateAnnualSalary() {
        return super.calculateAnnualSalary() + annualBonus;
    }

    public String getManagerInfo() {
        return super.getEmployeeInfo() + ", Reparto: " + department + ", Bonus annuale: " + annualBonus;
    }
}

// Classe Executive che eredita da Manager
class Executive extends Manager {
    private String companyCarModel;
    private double stockOptionValue;

    public Executive(String firstName, String lastName, LocalDate hireDate, double annualSalary, String department, double annualBonus, String companyCarModel, double stockOptionValue) {
        super(firstName, lastName, hireDate, annualSalary, department, annualBonus);
        this.companyCarModel = companyCarModel;
        this.stockOptionValue = stockOptionValue;
    }

    @Override
    public double calculateAnnualSalary() {
        return super.calculateAnnualSalary() + stockOptionValue;
    }

    public String getExecutiveInfo() {
        return super.getManagerInfo() + ", Auto aziendale: " + companyCarModel + ", Valore stock option: " + stockOptionValue;
    }
}

// Classe Contractor
class Contractor extends Employee {
    private double hourlyRate;
    private int monthlyHours;

    public Contractor(String firstName, String lastName, LocalDate hireDate, double hourlyRate, int monthlyHours) {
        super(firstName, lastName, hireDate, 0);
        this.hourlyRate = hourlyRate;
        this.monthlyHours = monthlyHours;
    }

    @Override
    public double calculateAnnualSalary() {
        return hourlyRate * monthlyHours * 12;
    }

    public String getContractorInfo() {
        return super.getEmployeeInfo() + ", Compenso orario: " + hourlyRate + ", Ore lavorate al mese: " + monthlyHours + ", Compenso annuale: " + calculateAnnualSalary();
    }
}

// Classe Intern
class Intern extends Employee {
    private int internshipDuration; // In mesi
    private double monthlyStipend;

    public Intern(String firstName, String lastName, LocalDate hireDate, int internshipDuration, double monthlyStipend) {
        super(firstName, lastName, hireDate, 0);
        this.internshipDuration = internshipDuration;
        this.monthlyStipend = monthlyStipend;
    }

    @Override
    public double calculateAnnualSalary() {
        return monthlyStipend * internshipDuration;
    }

    public String getInternInfo() {
        return super.getEmployeeInfo() + ", Durata stage: " + internshipDuration + " mesi, Indennità mensile: " + monthlyStipend + ", Indennità annuale: " + calculateAnnualSalary();
    }
}

// Classe Company
class Company {
    private List<Employee> employees;

    public Company() {
        employees = new ArrayList<>();
    }

    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    public void removeEmployee(Employee employee) {
        employees.remove(employee);
    }

    public double calculateTotalAnnualSalary() {
        double totalSalary = 0;
        for (Employee employee : employees) {
            totalSalary += employee.calculateAnnualSalary();
        }
        return totalSalary;
    }

    public void displayEmployeeInfo() {
        for (Employee employee : employees) {
            if (employee instanceof Executive) {
                System.out.println(((Executive) employee).getExecutiveInfo());
            } else if (employee instanceof Manager) {
                System.out.println(((Manager) employee).getManagerInfo());
            } else if (employee instanceof Contractor) {
                System.out.println(((Contractor) employee).getContractorInfo());
            } else if (employee instanceof Intern) {
                System.out.println(((Intern) employee).getInternInfo());
            } else {
                System.out.println(employee.getEmployeeInfo());
            }
        }
    }
}

// Classe principale
public class Main {
    public static void main(String[] args) {
        Company company = new Company();

        // Aggiungi dipendenti
        company.addEmployee(new Employee("John", "Doe", LocalDate.of(2015, 3, 1), 50000));
        company.addEmployee(new Manager("Jane", "Smith", LocalDate.of(2018, 7, 15), 70000, "Marketing", 10000));
        company.addEmployee(new Executive("Bob", "Johnson", LocalDate.of(2020, 1, 1), 100000, "Vendite", 20000, "BMW X5", 50000));
        company.addEmployee(new Contractor("Alice", "Williams", LocalDate.of(2022, 5, 1), 75, 160));
        company.addEmployee(new Intern("Michael", "Brown", LocalDate.of(2023, 9, 1), 6, 1200));

        // Rimuovi un dipendente
        company.removeEmployee(company.employees.get(2)); // Rimuovi Bob Johnson

        // Stampa le informazioni dei dipendenti
        company.displayEmployeeInfo();

        // Calcola la spesa salariale annuale totale
        double totalAnnualSalary = company.calculateTotalAnnualSalary();
        System.out.println("Spesa salariale annuale totale: " + totalAnnualSalary);
    }
}