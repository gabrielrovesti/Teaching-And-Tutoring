import java.util.ArrayList;

public class ArrayList {
	
	public static void main (String[] args) {
		
		// array a 1 dimensione
		int[] array = new int [100];
		
		/*
		1 2 3 4 5 6
		*/
		
		// scorrimento
		for(int i = 0; i < 6; i++){
			array[i] += 1;
		}
		
		
		// array a 2 dimensione - matrice
		int[][] matrice = new int[2][6]; // 2 righe (i) e 6 colonne (j)
		/*
		1 2 3 4 5 6
		7 8 9 10 11 12
		*/
		
		// scorrimento
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 6; j++){
				matrice[i][j] += 1;
			}
		}
		
		// creazione arraylist
		// sintassi: ArrayList<Tipo> nome = new ArrayList<Tipo>();
		ArrayList<String> al = new ArrayList<String>();
		
		// es. oggetto di tipo scanner
		// sintassi: Scanner nome = new Scanner(libreria di input)
		Scanner scanner = new Scanner(System.in);
		
		// logica creazione oggetti --> dove tonde = costruttori
		Carte c1; 		// Costruttore --> Carte();
		Carte c2(c1); 	// Costruttore di copia --> Carte(Carta c2) { c1 = c2 };
		
		// metodi
		
		// 1 - Aggiunta oggetti - add
		
		// aggiunta "normale"
		al.add("ciao");		// ciao
		al.add("mondo");	// ciao mondo
		// aggiunta in coda - concatenazione
		
		// aggiunta in posizione "x"
		al.add(3, "siamo noi");
		
		// 2 - Rimozione oggetti - remove
		
		// rimozione "normale"
		al.remove("ciao");	// mondo
		al.add("mondo");	// ""
		
		// for esteso (range-based) - 
		// ti basi sull'intervallo di valori piuttosto che le posizioni
		
		// for(int i=0; i<n; i++); con int n = 100;
		// equivalente
		
		//for(int i: n){	
		//}
		
		ArrayList<String> names = new ArrayList<String>();
		for (String name : names){
			System.out.println(name);
		}
		// Equivalente
		for (int i = 0; i < names.size(); i++){
			String name = names.get(i);
			System.out.println(name);
		}
		// size() = dimensione dell'arraylist
		
		// ArrayList = si aggiusta dinamicamente in base agli elementi
		// Perché gli array sono immutabili
	}
}

