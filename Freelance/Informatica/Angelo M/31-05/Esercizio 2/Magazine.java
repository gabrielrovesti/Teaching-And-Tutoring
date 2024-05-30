public class Magazine extends LibraryItem {
    private int issueNumber;
    private String frequency;

    public Magazine(String title, String author, int year, String id, int issueNumber, String frequency) {
        super(title, author, year, id);
        this.issueNumber = issueNumber;
        this.frequency = frequency;
    }

    public String getMagazineDetails() {
        return String.format("Issue Number: %d, Frequency: %s", issueNumber, frequency);
    }

    public String getMagazineInfo() {
        return String.format("%s, %s", super.getItemInfo(), getMagazineDetails());
    }
}
