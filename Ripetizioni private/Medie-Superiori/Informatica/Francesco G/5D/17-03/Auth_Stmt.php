<?php
    // Estensione PDO = connessione in modo sicuro alternativa a MySQLi
    $pdo = new PDO("localhost", "database", "test", "pass1234"); 

    // Esecuzione query
    $query = 'SELECT nome, prezzo FROM prodotti WHERE id = :id';

    // Preparazione query (= si può fare la query)
    $stmt = $pdo->prepare($sql_check);
    $stmt->bindParam(':u', $username, PDO::PARAM_STR); // usiamo quello username
    $stmt->execute(); // esegui la query
    $user = $stmt->fetch(PDO::FETCH_ASSOC); // prendere dal DB quello username
?>