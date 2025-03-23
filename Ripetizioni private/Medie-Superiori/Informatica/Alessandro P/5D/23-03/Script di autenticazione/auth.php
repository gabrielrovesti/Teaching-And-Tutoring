<?php
    include('connect.php');

    if(!$c) echo"Server DB non raggiungibile";
    else{
        $q="SELECT Nome, Cognome FROM Utente WHERE email=\"$_POST[usr]\" AND Psw=\"$_POST[aut]\"";

        $r=mysqli_query($c,$q);/*Controllo se ho estratto almeno un RECORD 
                                    -se vero procedo con lo script attuale
                                    -se falso creo un form di REGISTRAZIONE utente (INSERT INTO...)

                                    utilizzare come condizione di if-else la funzione mysqli_num_rows()
                               */
        if(mysqli_num_rows($r)>0){
            $v=mysqli_fetch_array($r,MYSQLI_ASSOC);

            echo" 
                Benvenuto $v[Nome] $v[Cognome]
                <br/>
                index della pagina
                <br/>
            ";
        }
        else{
            echo"
                <h2>Non sei registrato</h2>
                <br/> 
            ";
            header('url=;refresh:3;');//funzione di re-indirizzamento automatica
        }
    }
?>