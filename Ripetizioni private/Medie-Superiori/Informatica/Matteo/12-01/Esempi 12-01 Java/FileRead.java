// Usiamo le funzionalità da file
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class FileRead{
    public static void main(String[] args){
        // Esempio apertura file

        File file = new File("testo.txt");
        BufferedReader reader = new BufferedReader(new FileReader(file));
        
        // Letto il file, andiamo fino alla file stampandone le righe
        while((line = reader.readLine()) != null){
            System.out.println(line);
        }
        reader.close(); //Aperto il file, lo chiudiamo
    }
}