public class Negozio{
	public static void main(String args[]){
		Fiore f1=new Fiore();
		Fiore f2=new Fiore("r",10,7.5);
		Fiore f3=new Fiore("g",8,16.3);
		Fioriera l=new Fioriera(5);
		System.out.println(l);
		System.out.println(f1);
		System.out.println(f2);
		System.out.println(f3);
		l.add(f1);
		l.add(f2);
		l.add(f3);
		System.out.println(l);
	}
}
