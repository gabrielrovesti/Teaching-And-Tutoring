public class Product {
    private String name;
    private String description;
    private double price;
    private int quantity;

    public Product(String name, String description, double price, int quantity) {
        this.name = name;
        this.description = description;
        this.price = price;
        this.quantity = quantity;
    }

    public double calculateTotalPrice() {
        return price * quantity;
    }

    public String getProductInfo() {
        return String.format("Name: %s, Description: %s, Price: %.2f, Quantity: %d", 
                              name, description, price, quantity);
    }
}
