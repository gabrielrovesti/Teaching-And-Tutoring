public class Book extends LibraryItem {
    private String publisher;
    private String isbn;
    private int pages;

    public Book(String title, String author, int year, String id, String publisher, String isbn, int pages) {
        super(title, author, year, id);
        this.publisher = publisher;
        this.isbn = isbn;
        this.pages = pages;
    }

    public String getBookDetails() {
        return String.format("Publisher: %s, ISBN: %s, Pages: %d", publisher, isbn, pages);
    }

    public String getBookInfo() {
        return String.format("%s, %s", super.getItemInfo(), getBookDetails());
    }
}
