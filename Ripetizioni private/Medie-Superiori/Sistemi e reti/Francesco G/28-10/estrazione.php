<?php        
    $q = "SELECT * FROM Studente";
    $r = mysqli_query($c,$q);
    
    while($v = mysqli_fetch_array($r,MYSQLI_ASSOC))
        echo"
            <tr>
                <td>$v[Matricola]</td> 
                <td>$v[Nome]</td>
                <td>$v[Cognome]</td> 
                <td>$v[Classe]</td>
                <td>$v[Genere]</td>
                <td>$v[DataN]</td> 
            </tr>
        ";
?>