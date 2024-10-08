<?php
  
    $x=$_GET['x']; //<-- inizializzo la variabile X il tipo di dato viene acquisito dal contenuto

    // Il segno del dollaro è un segnaposto: vuol dire quindi che ci prendiamo l'oggetto che si chiama GET

    // Essendo che GET fa parte dei metodi di PHP (di sistema), allora usiamo l'underscore (_) (trattino basso)

    $variabile = "Ciao";

    // $x = $_variabile;

    // Noi qui NON mettiamo il trattino basso, non essendo già parte del linguaggio PHP

    // Si usa _ SOLO per GET e POST

    /*
    GET = schiaccio INVIA e salta fuori qualcosa = ottengo degli output

    POST = schiaccio INVIA e mando in modo sicuro dei dati
    */

    if($x % 2 == 0) echo "Il numero $x &egrave; divisibile per 2";
    else        echo "Il numero $x non &egrave; divisibile per 2";
    
?>