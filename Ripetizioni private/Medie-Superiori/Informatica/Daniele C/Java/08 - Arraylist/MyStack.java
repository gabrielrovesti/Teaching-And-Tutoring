import java.util.*;

public class MyStack {
	private ArrayList<String> array = new ArrayList <String>();
	
	MyStack(){
		array = new ArrayList<String>();
		// inizializzazione
	}
	
	MyStack(ArrayList<String> array){
		array = this.array;
	}
	
	public ArrayList<String> getArray(){
		return array;
	}
	
	// push = inserisco valore nella pila
	
	public void push(String valore){
		for(int i = 0; i<array.size(); i++){
			if(array.size() == 0) // se pila vuota
				array.add(valore);
			// isEmpty() = la pila è vuota?
			// if(array.isEmpty()) - alternativa
			
			if(array.get(i) == null)
				array.add(valore);
		}
	}
	
	// pop = tolgo valore dalla pila
	public String pop(){
		for(int i = 0; i<array.size(); i++){
			if(array.size() == 0) // se pila vuota
				return "Pila vuota";
				// eccezione (vedrai)
				// throws IllegalArgumentException();
			
			if(array.get(i) != null)
				return array.get(i);
		}
		// equivalente - for esteso
		/*
		ArrayList<String> array;
		for(String elemento: array){
			if(array.isEmpty()) // eccezione
			
			// elemento è uguale ad array.get(i) (come dire array[i]);
			if(elemento != null)
				array.remove(valore);
		}
		*/
		return "";
	}
	
	public int getCount(){
		if (array.size() == 0)
			return 0;
		else
			return array.size();
	
		// alternativamente (ternario --> condizione ? vero : falso
		// array.size() == 0 ? return 0 : return array.size();
	}
	
	/*
	 Stack/pila vuota
	 
	 [   ]
	 [   ]
     [   ]
	 
	 MyStack stack = new MyStack();
	 stack.add(1);
	 
	 [ 1  ]
	 [    ]
     [    ]
	 
	 Pila piena
	 
	 [ 1 ]
	 [ 2 ]
     [ 3 ]
     
     Pop (tolgo) = FIFO (First In First Out)
     
	 [ "" ]
	 [ 2 ]
     [ 3 ]
     
          
     Push (metti) = FIFO (First In First Out)
     
	 [ "1" ]
	 [ 2 ]
     [ 3 ]
	 
	 */
}

