public class AudioBook extends LibraryItem {
    private String narrator;
    private int duration;

    public AudioBook(String title, String author, int year, String id, String narrator, int duration) {
        super(title, author, year, id);
        this.narrator = narrator;
        this.duration = duration;
    }

    public String getAudioBookDetails() {
        return String.format("Narrator: %s, Duration: %d minutes", narrator, duration);
    }

    public String getAudioBookInfo() {
        return String.format("%s, %s", super.getItemInfo(), getAudioBookDetails());
    }
}
