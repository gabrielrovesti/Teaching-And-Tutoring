# Albero
- Il percorso di costo minimo perché segue la catena dei predecessori
rispetto all'ultimo nodo effettivamente aggiornato (non per forza all'ultima
iterazione, ma in una qualsiasi; poi, il percorso si conclude avendo con il primo)

# Grafo
- Tutti i percorsi di costo uguale all'albero

## Semplice (per davvero)
Aka:
- se non coincidono, vuol dire che abbiamo più percorsi di costo minimo
(l'albero è uno, il grafo sono tutti)

Concretamente:
- se abbiamo un albero che ha costo 0
- il grafo comprende più percorsi di costo 0

L'albero è un sottoinsieme del grafo. 

## Spiegazione più tecnica
- Coincidono se e solo se gli archi dell'albero dei cammini minimi sono esattamente tutti gli archi per i quali il rispettivo vincolo duale è saturo(cioè per i quali l'etichetta del nodo nel quale entra l'arco é esattamente uguale alla somma tra l'etichetta del nodo dal quale esce l'arco e il costo dell'arco)
- Se ci sono altri archi, che non appartengono all'albero dei cammini minimi, il cui rispettivo vincolo duale è saturo allora il grafo dei cammini minimi comprenderà anch'essi e quindi l'insieme  degli archi nel grafo dei cammini minimi sarà un sovrainsieme  dell' insieme degli archi nell'albero(e quindi non saranno lo stesso grafo).
