<html>
    <head>
        <link rel="stylesheet" href="s.css" /> <!-- Inclusione del file css con stylesheet = foglio di stile-->
    </head>
    <body>
        <?php
            $x=$_GET['a'];
            $p=1;
            for($i=2;$i<=$x;$i++)
                $p=$p*$i;

            echo "Il fattoriale di $x &egrave; $p";
        ?>
  
        <br/>    
        <a href="fattoriale.html">Torna alla pagina di inserimento dei valori</a>
        <!-- Questo codice HTML spunta DOPO che ho inserito dei valori -->
    
    </body>
</html>