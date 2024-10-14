<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ricerca Google</title>
</head>
<body>
    <h1>Ricerca su Google</h1>
    <form action="" method="POST">
        <input type="text" name="search" placeholder="Inserisci il termine di ricerca" required>
        <input type="submit" value="Cerca">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $search = urlencode($_POST["search"]);
        $url = "https://www.google.com/search?q=" . $search;
        echo "<p>Clicca <a href='$url' target='_blank'>qui</a> per vedere i risultati della ricerca su Google.</p>";
    }
    ?>
</body>
</html>