<?php
    
    if(isset($_GET['a'])){ // isset = is set = è stato impostato il valore...
                            // in questo caso = è stato impostato il valore di "a" preso con metodo GET dal form

        $x = $_GET['a'];      // $ = usato per tutto (serve per dire "mi riferisco al valore di 'x' ")
        // se "a" non è nullo, dai il suo valore ad x
        $p = 1;
        for($i = 2; $i <= $x; $i++) // 5! = 1 * 2 * 3 * 4 * 5 = 120
            $p = $p * $i;

        echo "Il fattoriale di $x &egrave; $p"; // il valore di $x va al posto di x (segnaposto)
        
    }   // 5! = 5 * 4 * 3 * 2 * 1 = fattoriale di 5 se vado all'indietro

        
    else
        // Form = Modulo (input e bottone per inviare dati)ù

        // Input type = text --> casellina di testo
        // La chiamo "a" per sapere da dove pigliarmi il valore 
        // Required = richiesto (obbligatorio) -> il campo mi serve per inviare il form

        // Input type = submit --> Bottone di invio (con value che è il testo che sta sopra il bottone)
        echo"
        <form action=\"#\" method=\"GET\">             
            <input type=\"text\" name=\"a\" required/>
            <input type=\"submit\" value=\"Calcola\"/>
        </form>
        ";
        // action = Serve per chiamare un file esterno .php che esegue
        // method -> GET/POST
            // GET = ottenere un risultato (calcolatrice = "dammi il risultato di 3 + 2")
            // POST = invio dei dati in modo sicuro (es. file/mail, etc. )


?>