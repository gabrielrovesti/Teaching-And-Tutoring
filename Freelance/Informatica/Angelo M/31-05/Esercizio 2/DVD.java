public class DVD extends LibraryItem {
    private String director;
    private int duration;
    private String format;

    public DVD(String title, String author, int year, String id, String director, int duration, String format) {
        super(title, author, year, id);
        this.director = director;
        this.duration = duration;
        this.format = format;
    }

    public String getDVDDetails() {
        return String.format("Director: %s, Duration: %d minutes, Format: %s", director, duration, format);
    }

    public String getDVDInfo() {
        return String.format("%s, %s", super.getItemInfo(), getDVDDetails());
    }
}
