# 11. [misura]
print("Programma per il calcolo dell'incertezza nella misura del tempo di oscillazione di un pendolo")

num_esperimenti = int(input("Inserisci il numero di esperimenti da effettuare: "))
risultati = []

for esperimento in range(num_esperimenti):
    print(f"\nEsperimento {esperimento + 1}")
    num_misure = int(input("Inserisci il numero di misure da effettuare per questo esperimento: "))
    tempi = []

    for i in range(num_misure):
        tempo = float(input(f"Inserisci il tempo di oscillazione {i + 1} (in secondi): "))
        tempi.append(tempo)

    tmin = min(tempi)
    tmax = max(tempi)
    tmedio = sum(tempi) / num_misure
    incertezza = (tmax - tmin) / 2

    risultati.append((tmedio, incertezza))

print("\nRisultati degli esperimenti:")
for i, (tmedio, incertezza) in enumerate(risultati):
    print(f"Esperimento {i + 1}: ({tmedio:.2f} ± {incertezza:.2f}) s")

# 12. [giudizio]
print("Programma per il calcolo della media dei voti e del giudizio finale")

num_studenti = int(input("Inserisci il numero di studenti: "))
giudizi = []

for studente in range(num_studenti):
    print(f"\nStudente {studente + 1}")
    num_verifiche = int(input("Inserisci il numero di verifiche effettuate: "))
    voti = []

    for i in range(num_verifiche):
        voto = int(input(f"Inserisci il voto della verifica {i + 1}: "))
        voti.append(voto)

    media = sum(voti) / num_verifiche

    if media < 4.5:
        giudizio = "Gravemente insufficiente"
    elif media < 6.0:
        giudizio = "Insufficiente"
    elif media < 7.5:
        giudizio = "Sufficiente"
    else:
        giudizio = "Buono"

    giudizi.append((studente + 1, media, giudizio))

print("\nRisultati degli studenti:")
for studente, media, giudizio in giudizi:
    print(f"Studente {studente}: media {media:.2f}, giudizio {giudizio}")

# 13. [gita]
print("Programma per l'organizzazione delle gite scolastiche")

num_scuole = int(input("Inserisci il numero di scuole: "))
destinazioni = []

for scuola in range(num_scuole):
    print(f"\nScuola {scuola + 1}")
    num_classi = int(input("Inserisci il numero di classi di questa scuola: "))

    for i in range(num_classi):
        classe = input(f"Inserisci la classe {i + 1} (es. 1A, 2B, 3C, ...): ")
        anno = int(classe[0])
        sezione = classe[1]

        if anno == 1:
            destinazione = "Il museo egizio di Torino"
        elif anno == 2:
            if sezione == "A":
                destinazione = "il Duomo di Milano"
            else:
                destinazione = "il Castello Sforzesco di Milano"
        elif anno == 3:
            destinazione = "le Gallerie degli Uffizi di Firenze"
        elif anno == 4:
            if sezione == "B":
                destinazione = "il Colosseo a Roma"
            elif sezione == "C":
                destinazione = "il Pantheon a Roma"
            else:
                destinazione = "i Musei Vaticani"
        else:
            destinazione = "il Cern di Ginevra"

        destinazioni.append((scuola + 1, classe, destinazione))

print("\nDestinazioni delle gite:")
for scuola, classe, destinazione in destinazioni:
    print(f"Scuola {scuola}, classe {classe}: {destinazione}")