parola = "Matematica"

# stampare 
# "tema"
# contando da 0
print(parola[2:6])

# stampare 
# "      tema"

print("{:>10}".format(parola[2:6]))
# in tutto sono 10 caratteri e sposta la parte a sx della stringa 
# = prima dei due punti
# e stampa il resto 

# stampare 
# "  tema   "

print("{:^10}".format(parola[2:6]))

stringa = "Testo Parola Musica"

for i in stringa:
    print("", end=" ")

"Testo"
"Parola"
"Musica"

x = 12
y = 18
print("{0:+d} {1:-d}".format(x,y)) #+12 18 = "+" aggiunge tanti caratteri quanti indicati
print("{0:+2d} {1: d}".format(x,y)) #12  18 = "-" toglie tanti caratteri quanti indicati
