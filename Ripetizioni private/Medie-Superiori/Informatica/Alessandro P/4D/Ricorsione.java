public int fib(int n){
    int f = 1;
    // Caso base
    if (n==1) f = 1;
    else f * fib(f-1); // caso ricorsivo
}

public boolean parolaPalindromaIt(String parola){
    // Caso base (iterativo)
    if(parola.length == 0 || parola.length == 1)
        return true;
    // Caso induttivo (iterativo)
        for(i = 0; i < parola.length; i++){
            if(parola.charAt(i) == parola.charAt(parola.length))
            {
                i += 1;
                length -= 1;
            }
        }
}

    public boolean parolaPalindromaRic(String parola){
        // Caso base
        if(parola.length() == 0 || parola.length() == 1)
            return true; 
        // Caso ricorsivo
        if(parola.charAt(0) == parola.charAt(s.length()-1))
            return parolaPalindromaRic(parola.substring(1, parola.length()-1));

        return false;
    }


public static void main(String[] args){

    //Anna
    //Alessandro

    // ""
    // a
}