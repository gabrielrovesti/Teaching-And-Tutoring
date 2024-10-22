/*

4.	Scrivi il codice che consente, utilizzando un form di acquisizione dati, di stampare il seguente messaggio 5 volte:

Buongiorno <<La Vespa>> <<Guido>> !

 (il contenuto tra parentesi uncinate viene passato tramite variabili url; utilizzare il metodo GET)

*/

// HTML + PHP

// form di acquisizione dati = form normale = modulo con input (etichette e bottoni)

// usa il metodo GET perché serve a ottenere la stampa di Buongiorno...
// mentre "action" chiama il file esterno .php
<form method="GET" action="file.php">
    <label name="Nome">
    <input type="text" name="nome" required>     // nome - etichetta ed input

    <br/>

    <label name="Cognome">
    <input type="text" name="cognome" required>  // cognome - etichetta ed input

    <br/>

    <input type="submit" value="Invia"> // (Invia)
</form>

<?php

    $nome = $_GET("nome");
    $cognome = $_GET("cognome");

    if($isset($nome) && $isset($cognome)){   // quando entrambe sono definite
        // Buongiorno <<La Vespa>> <<Guido>> ! --> output

        echo("Buongiorno ".$cognome." ".$nome);
    }

?>

// PHP PURO --> tutto in un solo file PHP

<?php   
    if($isset($nome) && $isset($cognome)){   // quando entrambe sono definite
        // Buongiorno <<La Vespa>> <<Guido>> ! --> output

        echo("Buongiorno ".$cognome." ".$nome);
    }
    else{
        echo"
            <form method=\"GET\" action=\"\#\">
            <label name=\"Nome\">
            <input type=\"text\" name=\"nome\" required>     // nome - etichetta ed input

            <br/>

            <label name=\"Cognome\">
            <input type=\"text\" name=\"cognome\" required>  // cognome - etichetta ed input

            <br/>

            <input type=\"submit\" value=\"Invia\"> // (Invia)
        </form>
        ";
    }
?>