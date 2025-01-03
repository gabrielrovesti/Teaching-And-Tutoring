public class Rettangolo{
	//attributi
	private double base;
	private double altezza;
	//metodo costruttore
	public Rettangolo(double b, double a){
		base = base;
		altezza = a;		
	}
	
	public Rettangolo(){
		base = 0;
		altezza = 0;
	}
	//metodi
	public double getBase(){
		return base;
	}
	public void setBase(double b){
		base=b;
	}
	
	public double getAltezza(){
		return altezza;
	}
	public void setAltezza(double a){
		altezza=a;
	}
	
	public double calcoloArea(){
		return base*altezza;
	}
	
	public double calcoloPerimetro(){
		return 2*(base+altezza);
	}
	
	public double diagonale(){
		return Math.sqrt(base*base + altezza*altezza);
	}
	public String toString(){
		 return "Il rettangolo ha base " + base + "e altezza " + altezza;
	}
	
	
	
}
