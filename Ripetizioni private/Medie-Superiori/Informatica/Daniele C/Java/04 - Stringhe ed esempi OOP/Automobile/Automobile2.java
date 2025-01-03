
public class Automobile2 {
	
	
	private String nomeAuto;
	private double Resa;
	private double CapienzaSerb;
	private double LitriSerb;
	

	public String getnomeAuto(){
		return nomeAuto;
	}
	public double getResa(){
		return Resa;
	}
	public double getCapienzaSerb(){
		return CapienzaSerb;
	}
	public double getLitriSerb(){
		return LitriSerb;
	}
	
	
	public void setnomeAuto(String na){
		nomeAuto = na;
	
	}
	public void setCapienzaSerb(String cb){
		CapienzaSerb = cb;
	}
	public void setResa(String rs){
		Resa = rs;
	}
	public void setLitriSerb(String ls){
		LitriSerb = ls;
	}
	

	Automobile(string nomeAuto){
		this.nomeAuto = nomeAuto;
	}
	

	Automobile(string nomeAuto,double Resa,double CapienzaSerb,double LitriSerb){
		this.nomeAuto = nomeAuto;
		this.Resa = Resa;
		this.CapienzaSerb=CapienzaSerb;
		this.LitriSerb=LitriSerb;
	}
	
	Automobile(double LitriSerb){
		this.LitriSerb=LitriSerb;
	}
	
	
	public String toString(){
		return"nomeAuto: " + nomeAuto + "Resa" + Resa + "CapienzaSerb" + CapienzaSerb + "LitriSerb" + LitriSerb;
	}
	
	public boolean isPercorribile(double distanza){
		if(Resa-distanza<0)
			return false;
		else
			return true;
	}
	
	public void percorri(double distanza){
		if(Resa>distanza)
			Resa=Resa-distanza;
		
		}
		
	
	public double autonomia(){
		 return LitriSerb * Resa;
	}
	
	public boolean inRiserva(){
		return LitriSerb <= (CapienzaSerb * 0.05);
	}
	
	public void faPieno(){
		  LitriSerb = CfapienzaSerb;
	}
	
	public boolean consumaMeno(){
		
	}
}


	



