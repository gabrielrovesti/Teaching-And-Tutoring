
import java.util.Arrays;

public class Test {
	
	public static void main (String[] args) {
		/*calcola il punteggio finale del quiz scartando 
		 * il punteggio più basso e trovando la somma di tutti 
		 * i punteggi rimanenti.*/
		 int[] quiz = {29, 50, 37, 25, 3, 20, 50, 35};
		 System.out.println(Arrays.toString(quiz));
		 int min= quiz[0];
		 int pos = 0;
		 for(int i=0; i<quiz.length; i++){
			if(min>quiz[i]){
				min=quiz[i];
				pos=i;
			}
		}
		int temp=quiz[quiz.length-1];
		quiz[pos]=temp;
		int sizeCorrente=quiz.length-1;
		System.out.println(Arrays.toString(quiz));
		int somma=0;
		for(int i=0; i<sizeCorrente; i++){
			somma+=quiz[i];
		}
		System.out.println("Somma "+ somma);

	}
}

