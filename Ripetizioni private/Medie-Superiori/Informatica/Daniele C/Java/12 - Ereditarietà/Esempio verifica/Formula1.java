/** Studente:
 *  classe  :
 *  data    :
 */
import java.util.ArrayList;
public class Formula1 {
    public static void main(String[] args) {
        /* VERSIONE SEMPLICE  (array paralleli)
         * Ipotizza che i seguenti array (a parità di indice) rappresentano il pilota, la relative scuderia e il punteggio attuale in campionato .  
         * Ogni signolo pilotà andrà costruito per gareggiare in gara.
         * L'ordine con cui vengono proposti rappresenta la griglia di partenza (per intenderci, Leclerc della Ferrari è in pole position)
         * */
         
        //~ final String[] piloti      = {"Leclerc","Hamilton","Schumacher","Alonso","Stroll"      ,"Verstappen","Giovinazzi"};
        //~ final String[] scuderie    = {"Ferrari","Mercedes","Haas"      ,"Alpine","Aston Martin","Red Bull"  ,"Alfa Romeo"};
        //~ final int[] punti               ={ 25,10,0,5,6,1,0};
        
         //~ ArrayList<Pilota> pilotiQualificati = new ArrayList<Pilota>();
         //~ for (int i=0;i<piloti.length;i++)
			//~ pilotiQualificati.add( new Pilota(piloti[i],scuderie[i],punti[i]) );
        
        /* VERSIONE CON SAX 
         * Completa la classe GestoreBolidiF1 (che parserizza il file "BolidiF1.xml" che rappresenta la griglia di partenza del gran premio) .
         * Costruisci un oggetto gestore appartenente alla classe GestoreBolidiF1
         * Invoca su gestore il metodo getListaPiloti() per ottenere i piloti qualificati ( la griglia di partenza)
         * */
        
        GestoreBolidiF1 gestore = new GestoreBolidiF1("qualifiche.xml");
        ArrayList<Pilota> pilotiQualificati = gestore.pippo();
        
        
        for (Pilota p:pilotiQualificati)
			System.out.println(p);
        
        //~ Gara monza = new Gara("Gran Premio d'Italia");
        //~ monza.grigliaDiPartenza(pilotiQualificati);
		//~ monza.start();
	
        
        //~ for (int giri=1;giri<=5;giri++)
        //~ {
            //~ switch(giri){
                //~ case 1: /* completa */
                        //~ break;
                //~ case 2: /* completa */
                        //~ break;
                //~ case 3: /* completa */
                        //~ break;
                //~ case 4: /* completa */
                        //~ break;
                //~ case 5: /* completa */
                        //~ break;
            //~ }
            //~ System.out.println("Classifica dopo il "+giri+"° giro ");
            //~ /* completa */
        //~ }
        //~ monza.stop();
		/* completa */
    
    } /* fine metodo main */
    
} /* fine class Formula1 */ 


/*

	//~ Gara monza = new Gara("Gran Premio d'Italia");
	//~ monza.grigliaDiPartenza(pilotiQualificati);
	//~ monza.start();
	
	class Gara{
	private String tipo;
	
	public Gara(String tipo){
		this.tipo = tipo;
	}
	
	public String getTipo(){
		return tipo;
	}
	
	// grigliaDiPartenza -> void
	// Mi fa vedere la lista di tutti i piloti
	
	public void grigliaDiPartenza(Pilota pilotiQualificati){
		for(int i = 0; i < pilotiQualificati.size(); i++){
			System.out.println("Pilota: " + pilotiQualificati.get(i).toString());
		}
					
	}
}

class GaraElettrica extends Gara{
	private int ngiri;
	public Gara(String tipo, int ngiri){
		super(tipo);
		this.ngiri = ngiri;
	}
}

*/
