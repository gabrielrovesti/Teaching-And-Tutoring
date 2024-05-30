public class Electronics extends Product {
    private String manufacturer;
    private String model;
    private String warranty;

    public Electronics(String name, String description, double price, int quantity, 
                       String manufacturer, String model, String warranty) {
        super(name, description, price, quantity);
        this.manufacturer = manufacturer;
        this.model = model;
        this.warranty = warranty;
    }

    public String getWarrantyInfo() {
        return warranty;
    }

    public String getElectronicsInfo() {
        return String.format("%s, Manufacturer: %s, Model: %s, Warranty: %s", 
                             super.getProductInfo(), manufacturer, model, warranty);
    }
}
