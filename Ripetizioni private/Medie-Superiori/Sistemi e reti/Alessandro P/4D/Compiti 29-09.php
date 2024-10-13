<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ordinamento di tre numeri</title>
</head>
<body>
    <h2>Inserisci tre numeri</h2>
    <form method="post" action="">
        <label for="num1">Numero 1:</label>
        <input type="number" id="num1" name="num1" required>        
        
        <label for="num2">Numero 2:</label>
        <input type="number" id="num2" name="num2" required><br><br>
        
        <label for="num3">Numero 3:</label>
        <input type="number" id="num3" name="num3" required><br><br>
        
        <input type="submit" value="Ordina">

    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $a = $_POST["num1"];
        $b = $_POST["num2"];
        $c = $_POST["num3"];

        $numeri = [$a, $b, $c];
        sort($numeri);

        $minore = $numeri[0];
        $centrale = $numeri[1];
        $maggiore = $numeri[2];

        echo "<h3>Risultato:</h3>";
        echo "A=$a, B=$b, C=$c<br>";
        echo "Maggiore = $maggiore<br>";
        echo "Centrale = $centrale<br>";
        echo "Minore = $minore";
    }
    ?>
</body>
</html>

<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Prodotto come Somma in Serie</title>
</head>
<body>
    <h2>Inserisci due numeri per il prodotto</h2>
    <form method="post" action="">
        <label for="num1">Numero 1:</label>
        <input type="number" id="num1" name="num1" required><br><br>
        
        <label for="num2">Numero 2:</label>
        <input type="number" id="num2" name="num2" required><br><br>
        
        <input type="submit" value="Calcola">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $num1 = abs((int)$_POST["num1"]); // Usiamo il valore assoluto per semplificare
        $num2 = abs((int)$_POST["num2"]); // Usiamo il valore assoluto per semplificare

        $prodotto = $num1 * $num2;

        echo "<h3>Risultato:</h3>";
        echo "$num1 × $num2 = $prodotto<br>";
        echo "Rappresentato come somma in serie:<br>";

        // Visualizza il prodotto come somma
        echo "$num1 ";
        for ($i = 1; $i < $num2; $i++) {
            echo "+ $num1 ";
        }
        echo "= $prodotto<br><br>";

        // Visualizza il processo passo dopo passo
        echo "Processo passo dopo passo:<br>";
        $somma_parziale = 0;
        for ($i = 1; $i <= $num2; $i++) {
            $somma_parziale += $num1;
            echo "Passo $i: $somma_parziale<br>";
        }
    }
    ?>
</body>
</html>