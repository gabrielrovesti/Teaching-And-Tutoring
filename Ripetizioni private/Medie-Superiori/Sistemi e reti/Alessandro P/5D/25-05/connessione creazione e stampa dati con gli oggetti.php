<?php
// (1) Stabilire parametri di connessione
$host = "localhost"; // o l'indirizzo del tuo server DB
// host = stazione = chi si connette alla rete
$user = "tuo_username";
$password = "tua_password";
$database = "tuo_database";

// (2) Creazione della connessione
// mysqli = (i) improved = mysqli più sicuro (migliorato)
$conn = new mysqli($host, $user, $password, $database);

// (3) Controllo della connessione
// connect_error = controlla errore di connessione
if ($conn->connect_error) {
    die("Connessione al database fallita: ". $conn->connect_error);
}else{
    echo "Connessione al database riuscita!<br>";
    // Esempio di query per creare una tabella
    $create_table_query = "CREATE TABLE IF NOT EXISTS utenti (
                            id INT AUTO_INCREMENT PRIMARY KEY,
                            nome VARCHAR(100) NOT NULL,
                            email VARCHAR(100) NOT NULL
                        );";
}
// (4) Esempio esecuzione query
if ($conn->query($create_table_query) === TRUE) {
    echo "Tabella 'utenti' creata con successo!<br>";
} else {
    echo "Errore nella creazione della tabella: " . $conn->error . "<br>";
}

// Esempio di query per inserire dati
$insert_query = "INSERT INTO utenti (nome, email) VALUES ('Mario Rossi', 'mario.rossi@example.com');";

if ($conn->query($insert_query) === TRUE) {
    echo "Record inserito con successo!<br>";
} else {
    echo "Errore nell'inserimento del record: " . $conn->error . "<br>";
}

// Esempio di query per recuperare dati
$select_query = "SELECT * FROM utenti;";
$result = $conn->query($select_query);

if ($result->num_rows > 0) {
    // Stampa dei risultati
    while ($row = $result->fetch_assoc()) {
        echo "ID: " . $row["id"] . " - Nome: " . $row["nome"] . " - Email: " . $row["email"] . "<br>";
    }
} else {
    echo "Nessun record trovato.<br>";
}

// Chiusura della connessione
$conn->close();
echo "Connessione al database chiusa.";
}
?>
