<?php
    $menu=isset($_GET['s'])?$_GET['s']:"";
?>
<!DocType html>
<html>
    <head>
        <title>Unione Europea</title>
        <link rel="stylesheet" href="ue.css" />
        <meta charset="UTF-8"/>
    </head>
    <body>
        <div id="ext">
            <div id="sx">
                <a href="index.php?s="><h3>Unione Europea</h3></a>
                <br/>
                <ul>
                    <li>Paesi Membri</li>
                    <ul>    
                        <li><a href="index.php?s=ita">Italia</a></li> 
                        <li>Francia</li> 
                        <li>Germania</li> 
                        <li>Austria</li> 
                        <li>Altri</li> 
                    </ul>
                    <li>Paesi Membri dal 1/5/2004 </li>
                    <ul>
                        <li>Polonia</li> 
                        <li>Ungheria</li> 
                        <li>Lettonia</li> 
                        <li>Altri</li> 
                    </ul>    
                    <li>Paesi Candidati</li>
                    <ul>
                        <li>Romania</li> 
                        <li>Bulgaria</li> 
                        <li>Turchia</li>
                    </ul>
                </ul>
                <br/>
                <a href="index.php?s=cb">Cartine e Bandiere</a>    
            </div>
            <div id="dx">
                <?php
                if($menu=="")
                    include('mappa.php');              
                if($menu=="ita")
                    include('italia.php');
                if($menu=="cb")
                    include('carban.php');//visualizza la porzione di codice dentro il file incluso                
                ?>
            </div>
        </div> 
    </body>
</html>