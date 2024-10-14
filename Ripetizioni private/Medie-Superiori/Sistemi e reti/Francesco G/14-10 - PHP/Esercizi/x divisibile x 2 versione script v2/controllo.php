<?php
    $x = isset($_GET['x']) ? $_GET['x'] : NULL;
    // Uguale a dire
    /* 
    if (isset($_GET['x']))
        $x = $_GET['x']; ? = caso "positivo"
    else
        $x = NULL;      : = caso "negativo"
    */

    if($x == NULL)   /*if($_GET['x']=="")*/
    // NULL = non ha nessun valore
        echo"
        <h2>Inserisci un valore numerico</h2>
        <br/>
        <form action=\"controllo.php\" method=\"GET\">
            <input type=\"text\" name=\"x\" required/>
            <input type=\"submit\" value=\"Invia\" />
        </form>
        ";

        // Crea direttamente il form usando PHP che chiama HTML
/*
    echo"
    <h2>Inserisci un valore numerico</h2>
    <br/>
    <form action='controllo.php' method='GET'>
        <input type='text' name='x' required/>
        <input type='submit' value='Invia' />
    </form>
    ";
*/  
    else{
        if($x % 2 == 0) 
            echo"IL numero ".$x." &egrave; divisibile per 2";
        else
            echo"IL numero ".$x." non &egrave; divisibile per 2";

        echo"<br/>fine programma";
    }
?>