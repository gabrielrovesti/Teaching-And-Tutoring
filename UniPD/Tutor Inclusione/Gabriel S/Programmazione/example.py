# Dati di input
studenti = [(101, "Alice"), (102, "Bob"), (103, "Charlie")]
voti = {"Matematica": "A","Italiano": "B","Informatica": "C"}

# Parte 1: Convertire voti da lettera a numero usando un dizionario di conversione
conversione_voti = {"A": 4, "B": 3, "C": 2, "D": 1, "F": 0}

# Creare una funzione che converte un voto da lettera a numero
def converti_voto(voto):
    return conversione_voti.get(voto, 0)

# list comprehension per convertire tutti i voti degli studenti da lettera a numero
voti_numerici = [converti_voto(voto) for voto in voti.values()]
print(voti_numerici)

# Media dei voti con matricole pari

# Determino se le matricole sono pari
def matricola_pari(matricola):
    return matricola % 2 == 0

# list comprehension per selezionare le matricole pari
matricole_pari = [matricola for matricola, nome in studenti if matricola_pari(matricola)]
print(matricole_pari)

# calcolo della media
media_pari = sum(voti_numerici) / len(matricole_pari)
print(media_pari)

# Versione ottimizzata
media_pari = sum(voti_numerici[::2]) / len(voti_numerici[::2])
