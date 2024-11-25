<?php
    include('connessione.php'); // Inclusione del file di connessione

    $nome=$_GET['x']; // Recupero del parametro "x" dal form
    $cognome=$_GET['y']; // Recupero del parametro "y" dal form

    if(!$c) echo"server DB NON RAGGIUNTO"; // Controllo della connessione (se non è attiva)
    else{
        // q = query
        // Interrogazione al database (richiesta) - ricerca e prende i campi che servono

        $q="SELECT  Studente.Nome, Studente.Cognome, AVG(Voto.Voto) AS VotoM
            FROM    Studente INNER JOIN Voto
                    ON Studente.Matricola=Voto.Studenteid
            WHERE   Nome=\"$nome\" AND Cognome=\"$cognome\"
            GROUP BY Studente.Nome, Studente.Cognome";

        $r = mysqli_query($c,$q); 
        // r = risultato, esegue la query (q) sul database connesso (c)

        if(!$r) echo"Non ci sono risultati disponibili"; // Controllo della query (se è vuota = risultato (r) nullo)
        else
            while($v = mysqli_fetch_array($r, MYSQLI_ASSOC))
            // v = valore, estrae i risultati della query (r) come array associativo
            // MYSQLI_ASSOC = array associativo alle tabelle (campi) del database
            // Le stampe sono sotto forma di tabelle HTML usando PHP come linguaggio
                echo"
                    $v[Nome] - $v[Cognome] - $v[VotoM] <br/>
                ";
        echo"
            <br/>
            <a href=\"form.html\">Torna alla precedente</a>
            ";
            // Link per tornare alla pagina precedente quando ha finito di eseguire
    }

    mysqli_close($c);  // Chiusura della connessione al database
?>