<?php

    // Prendiamo valore dal form
    $x = $_GET("x");
    $y = $_GET("y");

    // Connessione = mysqli_connect

    // Indirizzo -> localhost (stesso PC)
    $connessione = mysqli_connect("localhost", "Studente", "root", "");
    // Parametri (tra le tonde): Indirizzo / Database / Utente / Password

    // Alternativamente
    // include('connessione.php'); - lo metti in un file a parte

    // Connessione non aperta
    if(!$connessione)
        // Echo = Stampa
        echo "Server non raggiunto";
    else{
        // Connessione aperta

        // Query = SQL

        // Visualizzare idstudente, classe e voto medio di ogni studente di nome “Mario” presente nel Database precedente (organizzare in modo CRESCENTE per idstudente)

        $query = "SELECT idstudente, classe, AVG(Voti.Voti) AS Voto_Medio
        FROM Studenti
        INNER JOIN Voti ON Voti.Studenteid = Studente.IdStudente
        WHERE Nome="Mario"
        GROUP BY idstudente, classe
        ORDER BY idstudente
        "

        // Ordinamento = ORDER BY

        // Eseguire query e ottengo il risultato finché sono connesso

        $risultato = mysqli_query($connessione, $query);

        // Visualizzare il risultato
        // Insieme di campi -> for/while (risultato = array)

        // Fetch = Recupero
        
        // MYSQLI_ASSOC -> ("1", 1500, "Ciao"); -> tu vuoi una tabella
        // Array associativo -> Associa il campo alla colonna SQL

        // Scorrere il vettore -> for/while
        while($vettore = mysqli_fetch_array($risultato, MYSQLI_ASSOC)){
            echo"
                    $vettore[Nome] - $vettore[Matricola] - $vettore[VotoM] <br/>
                ";
        }
    }
    // Chiudere la connessione
    mysqli_close($connessione);
?>