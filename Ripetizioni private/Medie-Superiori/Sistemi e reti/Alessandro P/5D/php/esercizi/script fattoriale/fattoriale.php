<?php
    
    if(isset($_GET['a'])){
        $x=$_GET['a'];
        $p=1;
        for($i=2;$i<=$x;$i++)
            $p=$p*$i;

        echo"Il fattoriale di $x &egrave; $p";
    }
    else
        echo"
    <form action=\"#\" method=\"GET\">
        <input type=\"text\" name=\"a\" required/>
        <input type=\"submit\" value=\"Calcola\"/>
    </form>
    ";

?>