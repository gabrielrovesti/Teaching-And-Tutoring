import java.util.ArrayList;
import java.util.List;

public class Store {
    private List<Product> products;

    public Store() {
        this.products = new ArrayList<>();
    }

    public void addProduct(Product product) {
        products.add(product);
    }

    public void removeProduct(Product product) {
        products.remove(product);
    }

    public Product searchByName(String name) {
        for (Product product : products) {
            if (product.getProductInfo().contains(name)) {
                return product;
            }
        }
        return null;
    }

    public double calculateTotalInventoryValue() {
        double totalValue = 0;
        for (Product product : products) {
            totalValue += product.calculateTotalPrice();
        }
        return totalValue;
    }

    public void displayProductInfo() {
        for (Product product : products) {
            System.out.println(product.getProductInfo());
        }
    }
}
