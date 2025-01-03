public class ContoBancario {
	//variabili d'esemplare
	private String codice;
	private double saldo;
	
	//costruttori
	public ContoBancario(String codice, double saldo){
		this.codice=codice;
		this.saldo=saldo;
	}
	public ContoBancario(String codice){
		this.codice=codice;
		this.saldo=0;
	}
	//metodi
	public String getCodice(){
		return codice;
	}
	public double getSaldo(){
		return saldo;
	}
	public void setSaldo(double saldo){
		this.saldo=saldo;
	}
	public void deposito(double soldi){
		if(soldi>0){
			saldo = saldo + soldi;
		}
	}
	public boolean prelievo (double soldi){
		boolean flag = true;
		if(soldi<=saldo){
			saldo = saldo - soldi;
		} else{
			flag=false;
		}
		return flag;
	}
	public String toString(){
		return "Il conto con codice: " + getCodice()+ " ha saldo: " + getSaldo();
	}
	
	public boolean bonificoA(ContoBancario altro, double soldi){
		if(this.saldo>=soldi){
			this.saldo = this.saldo - soldi;
			altro.saldo = altro.saldo + soldi;
			return true;
		} else{
			return false;
		}
	}

}
