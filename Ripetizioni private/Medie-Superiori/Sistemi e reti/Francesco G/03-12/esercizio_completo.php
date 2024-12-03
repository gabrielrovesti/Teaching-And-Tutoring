

<?php 
    // Connessione al database (mysqli_connect)
    $connessione = mysqli_connect('localhost', 'root', '', 'scuola');

    // Query

    $query = "SELECT  Studente.idstudente, Studente.classe, AVG(Voto.voto) AS votomedio
          FROM    Studente INNER JOIN Voto
                  ON Studente.idstudente=Voto.studenteid
          WHERE   Studente.nome=\"Mario\"
          GROUP BY Studente.idstudente, Studente.classe
          ORDER BY Studente.idstudente";

    // Esecuzione della query
    $risultato = mysqli_query($connessione, $query);

    // Database (tabelle): Materie, Studenti, Voti

    // Query: Visualizzare idstudente, classe e voto medio di ogni studente di nome "Mario" (ordine crescente per idstudente)

    // Lo mettiamo in una tabella 
    echo"
        <table border=1>
            <tr>
                <td>Id Studente</td>
                <td>Classe</td>
                <td>Voto Medio</td>
            </tr>
    ";

    // Vettore = Dati in forma associativa: ("idstudente" => 1, "classe" => "1A", "votomedio" => 7.5)
    // Es. dati dal DB {"idstudente": 1, "classe": "1A", "votomedio": 7.5} (dopo la query)
    while($vettore = mysqli_fetch_array($risultato, MYSQLI_ASSOC)){
        // MYSQLI_ASSOC: Array associativo (nome campo => valore)
        // Es. "idstudente" è associato a 1, "classe" è associato a "1A", "votomedio" è associato a 7.5
        echo"
            <tr>
                <td>$vettore[idstudente]</td>
                <td>$vettore[classe]</td>
                <td>$vettore[votomedio]</td>
            </tr>";
        // Stampa: idstudente - classe - votomedio (come HTML)
    }

    echo"
        </table>
    ";

    // Chiusura della connessione
    mysqli_close($connessione);

?>