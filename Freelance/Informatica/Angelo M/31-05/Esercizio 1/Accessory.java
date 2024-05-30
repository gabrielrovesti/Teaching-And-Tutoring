public class Accessory extends Product {
    private String type;

    public Accessory(String name, String description, double price, int quantity, String type) {
        super(name, description, price, quantity);
        this.type = type;
    }

    public String getAccessoryType() {
        return type;
    }

    public String getAccessoryInfo() {
        return String.format("%s, Type: %s", super.getProductInfo(), type);
    }
}
