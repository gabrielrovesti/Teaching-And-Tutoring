<?php
    include('accesso.php');
    if(!$c) echo"Errore connessione";
?>
<!DocType html>
<html>
    <head>
        <title>Estrazione dati Scuola</title>
        <link rel="stylesheet" href="ssc.css"/>
        <meta charset="UTF-8"/>
    </head>
    <body>
        <h1>Estrazione dati studente</h1>
        <br/>
        <table>
            <tr>
                <th>Matricola</th><th>Nome</th><th>Cognome</th>
                <th>Classe</th><th>Genere</th><th>Data di Nascita</th>
            </tr>
            <?php include('estrazione.php'); ?>
        </table>
    </body>
</html>
<?php
    mysqli_close($c);
?>