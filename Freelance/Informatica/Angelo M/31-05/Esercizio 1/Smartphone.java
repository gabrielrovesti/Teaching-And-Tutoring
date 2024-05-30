public class Smartphone extends Electronics {
    private String operatingSystem;
    private double screenSize;
    private String camera;

    public Smartphone(String name, String description, double price, int quantity, 
                      String manufacturer, String model, String warranty, 
                      String operatingSystem, double screenSize, String camera) {
        super(name, description, price, quantity, manufacturer, model, warranty);
        this.operatingSystem = operatingSystem;
        this.screenSize = screenSize;
        this.camera = camera;
    }

    public String getSmartphoneSpecs() {
        return String.format("OS: %s, Screen Size: %.1f inches, Camera: %s", operatingSystem, screenSize, camera);
    }

    public String getSmartphoneInfo() {
        return String.format("%s, %s", super.getElectronicsInfo(), getSmartphoneSpecs());
    }
}
