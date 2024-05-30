public class Main {
    public static void main(String[] args) {
        Library library = new Library();

        LibraryItem b1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", 1925, "B001", "Scribner", "9780743273565", 180);
        LibraryItem m1 = new Magazine("Time", "Various Authors", 2021, "M001", 32, "Weekly");
        LibraryItem d1 = new DVD("Inception", "Christopher Nolan", 2010, "D001", "Christopher Nolan", 148, "Blu-ray");
        LibraryItem a1 = new AudioBook("Becoming", "Michelle Obama", 2018, "A001", "Michelle Obama", 1140);

        library.addItem(b1);
        library.addItem(m1);
        library.addItem(d1);
        library.addItem(a1);

        System.out.println("All Library Items:");
        library.displayAllItems();

        System.out.println("\nSearch by Title (The Great Gatsby):");
        LibraryItem searchTitle = library.searchByTitle("The Great Gatsby");
        if (searchTitle != null) {
            System.out.println(searchTitle.getItemInfo());
        } else {
            System.out.println("Item not found.");
        }

        System.out.println("\nSearch by Author (Michelle Obama):");
        List<LibraryItem> searchAuthor = library.searchByAuthor("Michelle Obama");
        for (LibraryItem item : searchAuthor) {
            System.out.println(item.getItemInfo());
        }
    }
}
