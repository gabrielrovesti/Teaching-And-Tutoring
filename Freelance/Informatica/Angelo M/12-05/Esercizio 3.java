public class Person {
    private String name;
    private int birthYear;

    public Person(String name, int birthYear) {
        this.name = name;
        this.birthYear = birthYear;
    }

    public String getName() {
        return name;
    }

    public int getBirthYear() {
        return birthYear;
    }

    @Override
    public String toString() {
        return "Nome: " + name + ", Anno di nascita: " + birthYear;
    }
}

public class Student extends Person {
    private String major;

    public Student(String name, int birthYear, String major) {
        super(name, birthYear);
        this.major = major;
    }

    public String getMajor() {
        return major;
    }

    @Override
    public String toString() {
        return super.toString() + ", Disciplina di specializzazione: " + major;
    }
}

public class Instructor extends Person {
    private double salary;

    public Instructor(String name, int birthYear, double salary) {
        super(name, birthYear);
        this.salary = salary;
    }

    public double getSalary() {
        return salary;
    }

    @Override
    public String toString() {
        return super.toString() + ", Salario: " + salary;
    }
}

public class PersonTester {
    public static void main(String[] args) {
        Person person1 = new Person("John Doe", 1990);
        System.out.println(person1);

        Student student1 = new Student("Jane Smith", 1995, "Computer Science");
        System.out.println(student1);

        Instructor instructor1 = new Instructor("Robert Johnson", 1980, 75000.0);
        System.out.println(instructor1);
    }
}