# Inizializzazione delle variabili
numero_studenti = int(input("Inserisci il numero di studenti nella classe: "))
numero_materie = int(input("Inserisci il numero di materie: "))

# Inizializzazione delle liste per i voti degli studenti
voti_studenti = [[] for _ in range(numero_studenti)]

# Acquisizione dei voti per ciascuno studente e ciascuna materia
for studente in range(numero_studenti):
    print(f"\nInserimento voti per lo studente {studente + 1}:")
    for materia in range(numero_materie):
        voto = float(input(f"Inserisci il voto per la materia {materia + 1} dello studente {studente + 1}: "))
        voti_studenti[studente].append(voto)

# Calcolo della media dei voti per ciascuno studente
media_studenti = [sum(voti) / len(voti) for voti in voti_studenti]

# Stampa della media dei voti per ciascuno studente
print("\nMedia dei voti per ciascuno studente:")
for studente, media in enumerate(media_studenti):
    print(f"Studente {studente + 1}: {media}")

# Calcolo della media della classe per ciascuna materia
media_materie = []
for materia in range(numero_materie):
    voti_materia = [voti[materia] for voti in voti_studenti]
    media_materia = sum(voti_materia) / numero_studenti
    media_materie.append(media_materia)

# Stampa della media della classe per ciascuna materia
print("\nMedia della classe per ciascuna materia:")
for materia, media in enumerate(media_materie):
    print(f"Materia {materia + 1}: {media}")
