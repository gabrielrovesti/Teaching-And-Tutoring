public class Main {
    public static void main(String[] args) {
        Store store = new Store();

        Product p1 = new Product("Generic Product", "This is a generic product", 10.0, 100);
        Electronics e1 = new Electronics("TV", "4K Smart TV", 500.0, 50, "Sony", "XBR55X900F", "2 years");
        Computer c1 = new Computer("Laptop", "High-end gaming laptop", 1500.0, 20, "Dell", "G5 15", "1 year", "Intel i7", 16, 512);
        Smartphone s1 = new Smartphone("Smartphone", "Latest model smartphone", 1000.0, 30, "Apple", "iPhone 13", "1 year", "iOS", 6.1, "12MP");
        Accessory a1 = new Accessory("Phone Case", "Durable phone case", 15.0, 200, "Case");

        store.addProduct(p1);
        store.addProduct(e1);
        store.addProduct(c1);
        store.addProduct(s1);
        store.addProduct(a1);

        System.out.println("Product Info:");
        store.displayProductInfo();

        System.out.println("\nSearch Product by Name:");
        Product searchResult = store.searchByName("Laptop");
        if (searchResult != null) {
            System.out.println(searchResult.getProductInfo());
        } else {
            System.out.println("Product not found.");
        }

        System.out.println("\nTotal Inventory Value:");
        System.out.println(store.calculateTotalInventoryValue());
    }
}
