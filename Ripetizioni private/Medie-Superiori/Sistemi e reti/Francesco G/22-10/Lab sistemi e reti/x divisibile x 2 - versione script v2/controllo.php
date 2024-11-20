<?php
      
    echo"
    <h2>Inserisci un valore numerico</h2>
    <br/>
    <form action=\"controllo.php\" method=\"GET\">
        <input type=\"text\" name=\"x\" required/>
        <input type=\"submit\" value=\"Invia\" />
    </form>
    ";

    /*
    Il codice PHP usando "echo" (= dare in output)
    crea gli elementi HTML (in questo caso il form)
    e fa le stesse cose di prima
    */

    /*
    $x=$_GET['x']; //<-- inizializzo la variabile X il tipo di dato viene acquisito dal contenuto

    if($x%2==0) echo"Il numero $x &egrave; divisibile per 2";
    else        echo"Il numero $x non &egrave; divisibile per 2";
    */

    if($_GET['x'] % 2 == 0) 
        echo"Il numero ".$_GET['x']." &egrave; divisibile per 2";
    else
        echo"Il numero ".$_GET['x']." non &egrave; divisibile per 2";
?>