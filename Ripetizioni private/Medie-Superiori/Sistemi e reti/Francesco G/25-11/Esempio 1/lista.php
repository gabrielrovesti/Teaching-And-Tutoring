<?php
    // (1) Apertura connessione con il database
    $connessione = mysqli_connect('localhost', 'root', '', 'Scuola');

    // mysqli_connect = Funzione per connettersi al database 
    // Sintassi: Indirizzo di rete - Nome utente - Password - Nome del database

    // Note: localhost = Indirizzo di rete del server locale (sul tuo PC)
    //       root = Nome utente di default di MySQL
    //       '' = Password di default di MySQL
    //       Scuola = Nome del database

    // $classe = $_GET['classe']; // Recupero il valore del parametro classe

    if(!$connessione) echo"Connessione non Và"; // caso di errore 
    else{
        $classe = $_GET['classe']; // Recupero il valore del parametro classe
        // usi GET per recuperare il valore dato che il form usa GET come "method"
        
        // (2) Query per estrarre i dati degli studenti della classe
        $query="SELECT  Matricola, Cognome, Nome
                FROM    Studente
                WHERE   Classe=\"$classe\"
               ";

        // Query è una stringa che contiene il comando SQL da eseguire
        // Metti backslash prima delle virgolette per evitare errori di sintassi
        // (tenere le virgolette) 

        $risultato_query = mysqli_query($connessione, $query);
        // mysqli_query = Funzione per eseguire una query sul database
        // Sintassi: Connessione - Query
        
        // (3) Visualizzazione dei dati
        // echo = Funzione per visualizzare un testo o un valore

        // Creiamo la tabella (esempio) - questo viene fatto dall'HTML qua sotto
        // --------------------------------
        // [Matricola]  [Cognome]   [Nome]
        // [123456]     [Rossi]     [Mario]
        // [654321]     [Verdi]     [Luca]
        // --------------------------------

        // Ripasso: table = tabella, tr = riga (row), th = intestazione (header), td = cella (data)
        echo"
            <table>
                <tr>
        <th>Matricola</th><th>Cognome</th><th>Nome</th>        
                </tr>
        ";
        // Siccome potresti avere tante righe come risultato, usiamo un ciclo
        // per visualizzare tutti i dati tramite vettore (array)

        while($vettore = mysqli_fetch_array($risultato_query, MYSQLI_ASSOC))

        // mysqli_fetch_array = Funzione per estrarre una riga di dati dal risultato della query
        // Sintassi: Risultato della query - Tipo di array (associativo o numerico)
        // MYSQLI_ASSOC = Array associativo (usa il nome del campo come chiave)
        // Es. se noi abbiamo Matricola allora prende dentro il risultato della query il valore di Matricola (tutti i campi di quel tipo)

        echo"
            <tr>
                <td>$vettore[Matricola]</td><td>$vettore[Cognome]</td><td>$vettore[Nome]</td>
            </tr>
        ";
        // $vettore[Matricola] = Prende il valore del campo Matricola dal vettore
        // $vettore[Cognome] = Prende il valore del campo Cognome dal vettore
        // $vettore[Nome] = Prende il valore del campo Nome dal vettore

        echo"
            </table>
        ";

    }

    mysqli_close($connessione); // (4) Chiusura connessione con il database
    // mysqli_close = Funzione per chiudere la connessione con il database
    // Sintassi: Connessione da chiudere
?>