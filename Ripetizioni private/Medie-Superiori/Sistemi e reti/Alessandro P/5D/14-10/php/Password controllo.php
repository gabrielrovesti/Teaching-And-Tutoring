Es. svolto =
Autenticazione (nome utente e password) su una pagina web con controllo dei dati

/*
HTML

    <form action="file.php" method="POST">
        <label name = "Nome utente">
        <input type="text" name="user" required>
        <br/>
        <label name = "Password">
        <input type="text" name="psw" required>
        <br/>
        <input type="submit" value="Invia">
    </form>

*/

/*
PHP

$user = $_POST["user"];
$psw = $_POST["psw"];

/// Controllo dati = 
    - password che ha più di 8 e meno di 16 caratteri
    - user che non ha una mail (input diverso da "@gmail.com")

if($psw >=8 && $psw<=16){
    if(isset($user) && str_contains(@gmail.com)){
        echo "Utente e password validi - puoi entrare";
    }
}


*/