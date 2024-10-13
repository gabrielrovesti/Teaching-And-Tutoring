<?php
    $x=isset($_GET['x'])?$_GET['x']:NULL;

    if($x==NULL)   /*if($_GET['x']=="")*/
        echo"
        <h2>Inserisci un valore numerico</h2>
        <br/>
        <form action=\"controllo.php\" method=\"GET\">
            <input type=\"text\" name=\"x\" required/>
            <input type=\"submit\" value=\"Invia\" />
        </form>
        ";
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
        if($x%2==0) 
            echo"IL numero ".$x." &egrave; divisibile per 2";
        else
            echo"IL numero ".$x." non &egrave; divisibile per 2";

        echo"<br/>fine programma";
    }
?>