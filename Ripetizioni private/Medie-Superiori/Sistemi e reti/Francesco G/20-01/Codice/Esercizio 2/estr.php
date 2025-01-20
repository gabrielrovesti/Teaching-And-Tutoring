<?php
    include('connessione.php');

    $nome=$_GET['x'];
    $cognome=$_GET['y'];

    if(!$c) echo"Server DB NON RAGGIUNTO"; //se la connessione non è riuscita stampa un errore.
    else{
        $q="SELECT Studente.Nome, Studente.Cognome, Studente.Matricola, AVG(Voto.Voto) AS VotoM
            FROM studente INNER JOIN Voto ON Studente.Matricola=Voto.Studenteid
            WHERE Nome=\"$nome\" AND Cognome=\"$cognome\"
            GROUP BY Studente.Nome, Studente.Cognome, Studente.Matricola";

            $r=mysqli_query($c,$q);

            if(!$r) echo"Non ci sono risultati disponibili";
            else
            while($v=mysqli_fetch_array($r,MYSQLI_ASSOC)) //MYSQLI_ASSOC abbina l'ID di chiave al record correlato
                echo"
                    $v[Nome] - $v[Matricola] - $v[VotoM] <br/>
                "; //".number_format('$v[VotoM]',2)." (temporaneamente rimosso poiché non mostrava VotoM su schermo)
        echo"
            </br>
            <a href=\"form.html\">Torna alla precedente</a>
        ";

    }
    mysqli_close($c);

    
?>

