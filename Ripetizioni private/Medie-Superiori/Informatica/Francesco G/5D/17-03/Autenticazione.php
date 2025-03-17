<?php

    $_user = $POST("username");
    $_psw = $POST("psw");

    // (1) Connessione al database

    $connessione = mysqli_connect("localhost", "root", "password", "database")

    // (2) Controllo se va tutto bene -> se connesso oppure no

    if(!$connessione){
        die("Connessione fallita: " + mysqli_connect_error());
    }
    else{
        // vediamo se user e psw sono vuoti oppure no -> isset (= è stato impostato?)
        if(isset($_user) && isset($_psw)){
            // (facoltativo ma utile) controllo su user e psw (no car. speciali /....)
            $username = trim($_POST['username']); // trim = "tagliare" gli spazi
            $password = trim($_POST['psw']);

            // (3) Connessione al DB e ottenere il risultato

            $query = "INSERT INTO utenti (username, password)
                  VALUES ('$username', '$password')";

            $risultato = mysqli_query($connessione , $query);
            
            while($vettore = mysqli_fetch_array($risultato, MYSQLI_ASSOC)){
                echo "<tr> <td>.... </tr>"
            }

            session_start(); // crea la sessione

            $_SESSION["username"] = $username;   
            // Quando ti autentichi, rimani connesso -> $_SESSION
        }
    }

    // Chiusura sessione (distruzione) e chiusura connessione (4)
    session_destroy();
    mysqli_close($connessione);

?>

