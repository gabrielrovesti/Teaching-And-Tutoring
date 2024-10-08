public class Palindroma{

    // caso commentato
    boolean isPalindrome(String parola){
        // caso base - stringa vuota o di un carattere
        if(parola.length() == 0 || parola.length() == 1) return true;
        //"" o "aaa"
    
        // caso ricorsivo

        // primo e ultimo carattere
        char first = parola.charAt(0);
        char last = parola.charAt(parola.length());

        if(first == last){
            // riduci la lunghezza della stringa
            String remainingSubstring = str.substring(1, str.length() - 1);
            return isPalindrome(remainingSubstring); // continui a controllare
        }
        else
            return false;

    }
    
    // anna = palindroma
    
    // francesco = non palindroma

    // Funzione in classe

    boolean palindromaPist(String pal){
        boolean b = false;

        // primo e ultimo carattere
        String inizio = pal.substring(0,1);
        String fine = pal.substring(pal.length()-1, pal.length());

        // caso base - stringa vuota o di un carattere
        if(pal.length()<=1){
            System.out.print("Palindroma");
            b = true;
        }
        else if(inizio.compareTo(fine)){ // continui a controllare inizio con fine
            // riduci la lunghezza della stringa
            pal.substring(pal, pal.length()-1);
        }
    }
}

