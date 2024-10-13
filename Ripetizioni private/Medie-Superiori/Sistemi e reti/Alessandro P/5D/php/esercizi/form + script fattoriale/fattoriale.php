<html>
    <head>
        <link rel="stylesheet" href="s.css" />
    </head>
    <body>
        <?php
            $x=$_GET['a'];
            $p=1;
            for($i=2;$i<=$x;$i++)
                $p=$p*$i;

            echo"Il fattoriale di $x &egrave; $p";
        ?>
  
        <br/>    
        <a href="fattoriale.html">Torna alla pagina di inserimento dei valori</a>
    
    </body>
</html>