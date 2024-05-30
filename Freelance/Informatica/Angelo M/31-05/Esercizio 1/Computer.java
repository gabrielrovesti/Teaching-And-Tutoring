public class Computer extends Electronics {
    private String cpu;
    private int ram;
    private int storage;

    public Computer(String name, String description, double price, int quantity, 
                    String manufacturer, String model, String warranty, 
                    String cpu, int ram, int storage) {
        super(name, description, price, quantity, manufacturer, model, warranty);
        this.cpu = cpu;
        this.ram = ram;
        this.storage = storage;
    }

    public String getComputerSpecs() {
        return String.format("CPU: %s, RAM: %dGB, Storage: %dGB", cpu, ram, storage);
    }

    public String getComputerInfo() {
        return String.format("%s, %s", super.getElectronicsInfo(), getComputerSpecs());
    }
}
