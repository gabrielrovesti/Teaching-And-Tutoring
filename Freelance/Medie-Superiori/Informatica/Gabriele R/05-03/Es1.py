#Dichiarazione delle variabili
temperatura = 0
somma = 0
massima = 0
minima = 0
giorni = 0
giorni_sopra = 0
giorni_sotto = 0
#Inserimento del mese
mese = input("Inserisci il mese: ")
#Inserimento del numero di giorni
giorni = int(input("Inserisci il numero di giorni: "))
#Inserimento delle temperature
for i in range(1, giorni + 1):
    temperatura = int(input(f"Inserisci la temperatura del giorno {i}: "))
    somma += temperatura
    if temperatura > massima:
        massima = temperatura
    if temperatura < minima:
        minima = temperatura
    if temperatura > 30:
        giorni_sopra += 1
    if temperatura < 10:
        giorni_sotto += 1
#Calcolo della temperatura media
media = somma / giorni
#Stampa dei risultati
print(f"La temperatura media di {mese} è {media}")
print(f"La temperatura massima registrata è {massima}")
print(f"La temperatura minima registrata è {minima}")
print(f"I giorni sopra i 30 gradi sono {giorni_sopra}")
print(f"I giorni sotto i 10 gradi sono {giorni_sotto}")
