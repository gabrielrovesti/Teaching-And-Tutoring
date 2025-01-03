
import java.util.Random;
import java.util.Arrays;
public class Matrici {
	public static int sommaMatrice(int[][] m){
		 int somma=0; 
		 for(int r=0;r<m.length; r++){ //scorro le righe
			for(int c=0;c<m[0].length; c++){ //scorre le colonne
				somma+=m[r][c];
			}
		}
		return somma;
	}
	public static int[][] creaMatrice(int riga, int colonna, int max){
		Random gen= new Random();
		//gen.nextInt(max+1);
		int[][] matrice= new int[riga][colonna];
		
		for(int r=0;r<riga; r++){
			for(int c=0;c<colonna; c++){
				matrice[r][c]=gen.nextInt(max+1);
			}
		}

		return matrice;
	}
	
	
	public static void main (String[] args) {
		int[][] matrice= creaMatrice(4,4,51);
		for(int r=0;r<matrice.length; r++){
			for(int c=0;c<matrice[0].length; c++){
				System.out.print(matrice[r][c] + ", ");
			}
			System.out.println("");
		}
		System.out.println(sommaMatrice(matrice));
		
		//System.out.println(Arrays.toString(matrice));
	}
}

