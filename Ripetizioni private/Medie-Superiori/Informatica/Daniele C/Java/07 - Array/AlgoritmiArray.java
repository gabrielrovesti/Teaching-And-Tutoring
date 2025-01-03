// Dichiarazione array
int[] array = new int[10];

// Lunghezza array = Length (funzione)
int lunghezza = array.length; // 10

// Scorro il vettore (cicli)

// (1) - Modo "classico" (partenza / condizione / incremento)

for(int i = 0; i < lunghezza; i++){ // altrimenti --> i < array.length
    // corpo....
}

//altrimenti

while(i < lunghezza){
    // corpo....
    i++;
}

// 0 - 9 (i = 0; i < 9) ----  1 - 10 (i = 1; i <= 10)

// (2) - Modo "compatto" - for range-based (for esteso Riferimento §7.2)
for(int i: array){
    // Operazioni

    // Somma/Differenza/Divisione/Moltiplicazione <--> Riempimento

    array[i] = i * i; // array[i] <---> accedo alla posizione i-esima 
}

// Metodi notevoli

// (1) Ricerca lineare (voglio vedere se esiste "x")

// Esempio
// x = 5 (elemento)
// {1 2 3 4 5} (array)

boolean ricercaLineareFor(int[] array, int x){
    boolean trovato = false;
    for(int i = 0; i < lunghezza; i++){
        if(x == array[i]){
            trovato = true;
        }
    }
    return trovato;
}

// § 7.3.5 - Ricerca lineare
boolean ricercaLineareWhile(int[] array, int pos, int x){
    boolean found = false;
    int pos = 0;
    while(pos < lunghezza){
        if(array[pos] == x){
            found = true;
        }
        else{
            pos++; // avanzo SOLO nel caso in cui non lo trovo
        }
    }
    return trovato;
}


// (3) Cancellazione in una posizione (pos)

/*
                    pos
                     |
    [32][54][67][29][80][115][45]
    pos = 4;

    // i = pos + 1
                    pos  i+1
                     |    |
    [32][54][67][29][80][115][45]


    pos--;
    ...

    Finale:
     [32][54][67][29][115][45]   
*/

// Es. cancella in posizione (4)
void cancella(int[] array, int pos){
    for(int i = pos + 1; i < array.length; i++){
        // compatta gli elementi
        array[i - 1] = array[i];
    }
}

