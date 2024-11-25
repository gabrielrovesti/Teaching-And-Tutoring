<?php
    //funzione ISSET(parametri accettati)
    // restituisce un valore boolean true o false    

    echo"Test del valore boolean restituito da ISSET()<br/>";
    $x=NULL;

    echo ISSET($x);

    if(ISSET($x))   echo" <-- TRUE" ;
    else            echo"0 <-- FALSE";

    echo"<br/><br/>";
    //operatore ternario
    $x=ISSET($x)?"1 <-- TRUE":"0 <--FALSE";
    echo $x;
?>