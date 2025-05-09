ds /* La classe Pietanza definisce una pietanza da mangiare al ristorante
 * 
*/ 
public class Pietanza {
	private String nome;
	private double prezzo;
	private String tipologia;
	/*avrà un nome, un prezzo e una tipologia di tipo String ma verrà inserito nel contruttore con un tipo char
	 * P: primo
	 * s: secondo
	 * b bibite
	 * d dessert
	 * c contorno
	 */ 
    
    public Pietanza (char tipo,String nome,double prezzo){
		switch (tipo){
			case 'P' : tipologia="PRIMO";
				break;
			case 'S' : tipologia="SECoNDO";
				break;
			case 'B' : tipologia="BIBITE";
				break;
			case 'D' : tipologia="DESSERT";
				break;
			case 'C' : tipologia="CONTORNO";
				break;
		}
	}
    
    //get
    
    public String getNome(){
		return nome;
	}
	
	 public double getPrezzo(){
		return prezzo;
	}
	
	 public String getTipologia(){
		return tipologia;
	}
    //toString
    
    public String toString(){
		return " il nome e' " + nome +" con prezzo: " + prezzo + " di tipo: " + tipologia;
	}
} /* Fine classe Pietanza */
            
    

