public class Cliente{ 
private String nome; 
private String telefono; 
public Cliente(String n, String t){ 
nome=n; 
telefono=t; 
} 
public String getNome(){ 
return nome; 
} 
public String getTelefono(){ 
return telefono; 
} 
public String toString(){ 
return "Cliente \nnome e cognome: "+nome+"\ntelefono: "+telefono; 
} 
} 
********************************************************************************************************* public class Spettacolo{ 
private String nome; 
private Cliente[] prenotazioni; 
private int nroPrenotazioni; 
private int …………….; 
public Spettacolo(String n, int nP){ 
nome=.......; (1) 
………………………..=nP; (2) 
prenotazioni=new Cliente[.........]; (3) 
………….=0; (4) 
} 
//Scrivere un metodo libero che ritorni true se ci sono ancora posti liberi, false altrimenti. (5) 
//Scrivere un metodo trova che restituisce 0 se nell’elenco dei prenotati c’è un cliente con dato nome e numero di telefono di un cliente. (6) 
//Scrivere un metodo che prenota lo spettacolo per un cliente dati nome e numero di telefono. (7) 
//Scrivere un metodo disdici che, assegnati nome e numero di telefono, elimina dall’elenco dei prenotati il cliente corrispondente, se e solo se questo cliente è presente in elenco. Il metodo deve restituire le info del cliente eliminato. (8) 
//Scrivere il metodo prenota in overloading (riceve come parametro un oggetto di tipo….) (9) //Scrivere gli enunciati che permettano di testare i metodi libero, prenota, disdici. (10