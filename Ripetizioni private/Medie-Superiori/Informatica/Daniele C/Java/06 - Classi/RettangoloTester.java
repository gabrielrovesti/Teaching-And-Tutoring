public class RettangoloTester {
	
	public static void main (String[] args) {
		double base=4;
		double altezza=3;
		Rettangolo rettangolo1 = new Rettangolo(base,altezza);
		Rettangolo rettangolo3 = new Rettangolo(3,35);
		Rettangolo rettangolo2= new Rettangolo();
		
		double b = rettangolo1.getBase();
		System.out.println("la base del rettangolo 1 e': " + b);
		
		rettangolo1.setBase(8.85);
		System.out.println("la base del rettangolo 1 e': " + rettangolo1.getBase());
		System.out.println("area del rettangolo 1 " + rettangolo1.calcoloArea());
		System.out.println("perimetro del rettangolo 1 " + rettangolo1.calcoloPerimetro());
		System.out.println("diagonale del rettangolo 1 " + rettangolo1.diagonale());
	}
}

