import java.util.Scanner;
public class ContoBancarioTester {
	
	public static void main (String[] args) {
		Scanner tast = new Scanner(System.in);
		System.out.println("Conto 1----");
		System.out.println("Dimmi il codice: ");
		String codice = tast.nextLine();
		System.out.println("Dimmi il saldo: ");
		double saldo = tast.nextDouble();
		tast.nextLine();
		ContoBancario conto1= new ContoBancario(codice,saldo);
		
		System.out.println("Conto 2----");
		System.out.println("Dimmi il codice: ");
		String codice2 = tast.nextLine();
	
		ContoBancario conto2= new ContoBancario(codice2);
		
		System.out.println(conto1);
		System.out.println(conto2);

		boolean flag;
		do{
			System.out.println("quanto vuoi prelevare?");
			double soldi = tast.nextDouble();
			flag = true;
			if(conto1.prelievo(soldi)){
					System.out.println("Hai prelevato " + soldi );
					flag=false;
			} else{
				System.out.println("Non puoi prelevare questi soldi: " + soldi );
			}
		}while(flag);


		
		conto2.deposito(2000);
		conto1.prelievo(1000);
		
		System.out.println(conto1);
		System.out.println(conto2);
		
		boolean bonifico;
		do{
			System.out.println("quanto vuoi trasferire?");
			double soldi = tast.nextDouble();
			bonifico = true;
			if(conto1.bonificoA(conto2, soldi)){
					System.out.println("Hai trasferito " + soldi );
					bonifico=false;
			} else{
				System.out.println("Non puoi trasferire questi soldi: " + soldi );
			}
		}while(bonifico);
		
		
		
		conto1.bonificoA(conto2, 200);
		
		System.out.println(conto1);
		System.out.println(conto2);
		
		
		
		
	}
}

