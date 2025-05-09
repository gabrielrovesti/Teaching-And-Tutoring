
 
/* 
 * La classe AlRistorente contiene il main che testerà oggetti di tipo Tavolo
 * 
 * Segui attentamente le indicazioni:
 * Avrai sicuramente capito che nel testare un oggetto appartenente alla classe restaurant.Tavolo dovrai necessariamente inserire nell'ordine n pietanze e, per ogni
 * pietanza, dovrai inserire la tipologia (PRIMO, SECONDO, DESSERT, ecc.) il nome della pietanza e il relativo prezzo. Lavoro alquanto noioso e dispendioso (in temini di tempo)
 * 
 * Al fine di "semplificarti la vita", ti vengono messi a disposizione 2 array (paralleli) ovvero hanno la stessa lunghezza e puoi accedere al loro contenuto utilizzando lo stesso indice, 
 * che ti permetteranno di creare oggetti di tipo pietanza in modo veloce e sicuro.
 * Come puoi vedere gli array sono:
 * 	tipoPietanza (contiene la tipologia della pietanza: il carattere 'P' significa Primo, la 'S' significa Secondo, la 'B' significa Bibita, la 'C' significa Contorno, la 'D' significa Dessert.
 * 	nomePietanza (contiene il nome della pietanza)
 */ 


public class AlRistorante {
	  
      public static void main(String[] args) {
   
		char[]   tipoPietanza = 	    {'P','S','P','S','S','B','D','C','C','S','D','B','B','B','S'}; 
		String[] nomePietanza = 		{ 				"SPAGHETTI",
														"COSTATA",
														"GNOCCHI",
														"HAMBURGER",
														"BISTECCA",
														"COCA COLA",
														"DOLCE",
														"PATATINE",
														"VERDURE GRIGLIATE",
														"POLLO ALLO SPIEDO",
														"SORBETTO",
														"BIRRA",
														"ACQUA",
														"VINO",
														"POLENTA E SALSICCIA"
										};
										
        
 		/* 11 - SCRIVI QUI il codice necessario per creare un oggetto tavolo1 di classe Tavolo che conterrà un ordine composto da 3 pietanze per ogni coperto
 		 * (prevedere la lettura del numero di coperti di tavolo1 da tastiera)
		 *  Le pietanze saranno prese casualmente dall'array nomePietanza (e, contestualmente, la tipologia dall'array parallelo tipoPietanza).
		 *  Il prezzo sarà generato casualmente attraverso un oggetto appartenente alla classe Random che dovrà restituire un valore casuale compreso tra 1.0 e 20.0 euro.
		 *  Suggerimento: genera in numero intero casuale compreso tra 10 e 200, poi dividilo per 10
		 */

 		/* 12 - SCRIVI QUI il codice necessario per creare un oggetto tavolo2 di classe restaurant.Tavolo che conterrà un ordine composto da tutte le pietanze presenti nell'array nomePietanza */
       
		  
 		/* 13 - SCRIVI QUI il codice necessario per visualizzare la simil-ricevuta del tavolo 1 e del tavolo 2 */
	

		
		/* 14 - SCRIVI QUI il codice necessario per confrontare il ricavo del tavolo 1 con quello di tavolo 2 */  
		   

 		/* 15 - SCRIVI QUI il codice necessario per testare almeno un'altro metodo della classe restaurant.Tavolo (diverso da quelli precedenti)*/

		  

 public Pietanza (char tipo,String nome,double prezzo){
		switch (tipo){
			case 'P' : tipologia="PRIMO";
				break;
			case 'S' : tipologia="SECoNDO";
				break;
			case 'B' : tipologia="BIBITE";
				break;
			case 'D' : tipologia="DESSERT";
				break;
			case 'C' : tipologia="CONTORNO";
				break;
		}
	}g

    } /* Fine metodo main */
} /* Fine classe AlRistorante */
        
        
        
        
                
        

