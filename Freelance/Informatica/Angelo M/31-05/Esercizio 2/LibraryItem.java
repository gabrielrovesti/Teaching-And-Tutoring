public class LibraryItem {
    private String title;
    private String author;
    private int year;
    private String id;
    private boolean isAvailable;

    public LibraryItem(String title, String author, int year, String id) {
        this.title = title;
        this.author = author;
        this.year = year;
        this.id = id;
        this.isAvailable = true;
    }

    public String getItemInfo() {
        return String.format("Title: %s, Author: %s, Year: %d, ID: %s", title, author, year, id);
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void setAvailability(boolean isAvailable) {
        this.isAvailable = isAvailable;
    }
}
