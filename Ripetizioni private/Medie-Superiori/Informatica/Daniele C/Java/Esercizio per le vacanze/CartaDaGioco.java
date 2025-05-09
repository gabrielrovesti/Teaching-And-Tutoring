public class CartaDaGioco{
		//variabili d'esemplare
		private String seme;
		private String nome;
		private int valore;
		
		//costruttore
		public CartaDaGioco(String s, String n, int v)
		{
			seme=s;
			nome=n;
			valore=v;
		}
		
		//get 
		
		public String getSeme(){
			return seme;
		}
		
		public String getNome(){
			return nome;
		}
		
		public int getValore(){
			return valore;
		}
		
		//
		public boolean stessoSeme(CartaDaGioco carta)
		{
			if(seme.equals(carta.seme)){ // equals (solo per stringhe)
				return true;
			}
			return false;
		}
		//
		public boolean stessoNome(CartaDaGioco carta)
		{
			if(nome.equals(carta.nome)){
				return true;
			}
			return false;
		}
		//
		public boolean stessoValore(CartaDaGioco carta)
		{
			if(valore == carta.valore){
				return true;
			}
			return false;
		}
		//conviene associare dei numeri al seme per fare i confronti più facilmente: cuori=4; quadri=3; fiori=2; picche=1
		public int associaSeme()
		{
			if(seme.equals("picche"))
				return 4;
			if(seme.equals("quadri"))
				return 3;
			if(seme.equals("fiori"))
				return 2;
			if(seme.equals("cuori"))
				return 1;
		}
		
		public String toString() // stampa tutte le info del tipo classe
		{
			return "La carta ha: \n Nome: " + getNome()+ "\n Seme: " + getSeme() + " \n Valore:  "+ getValore();
		}
}
