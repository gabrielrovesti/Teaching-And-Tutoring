formatter = ""
a = 100
b = 200
c = 300
print("{0:3d}{1:3d}{2:3d}".format(a,b,c)) #100 200 300
print("{0:4d}{1:4d}{2:4d}".format(a,b,c)) #100 200 300
print("{0:10d}{1:30d}{2:30d}".format(a,b,c)) #       100                           200                           300
# 10 - 3 del numero = 7 caratteri di spazio prima della prima stampa
# 30 - 3 del numero = 27 caratteri di spazio prima della seconda stampa
# 30 - 3 del numero = 27 caratteri di spazio prima della terza stampa

# 0/1/2 = ordine dell'elemento
# d = numero decimale
# 4d = numero delle cifre (o dei caratteri della variabile più gli spazi (padding))

print('{:10.10}'.format('Python'))
print("")
# stringa fino a 10 spazi occupati (padding) e poi separa fino a 10 spazi (truncating)
 # stringa con 6 caratteri e 4 di separazione

# Esempi con stringhe
# Primo argomento = troncamento - Secondo argomento = spazi di separazione
>>> '{:3.3}'.format('Python')
'Pyt'
>>> '{:6.2}'.format('Python')
'Py    '
>>> '{:6.3}'.format('Python')
'Pyt   '
>>> '{:6.4}'.format('Python')
'Pyth  '

# Arrotondamento dopo i due punti = tutto quello che viene dopo il numero
# fino a due decimali
"{:.2f}".format(3.1415926)
>>> '3.14'
# fino ad un solo decimale
"{:.1f}".format(8.9998)
>>> '9.0'

#  Backslash = Evita che i caratteri non vengano stampati
# = fa l'escape del carattere X ()

my_string = "This is a string with a \"quotation mark\" and a newline character \n in it"
print(my_string)
>>> This is a string with a "quotation mark\ and a newline character
in it

my_string = "This is a string with a \"quotation mark"\ and a newline character \n in it"
print(my_string)
>>> This is a string with a "quotation mark" and a newline character
in it

# Esempio di carattere speciale = carattere che viene interpretato come comando
# Nell'esempio, mettendo backslash davanti, viene stampato "Numero: {'\%d'}"
numero=150
>>> f"Numero: {'\%d'}" 

# Inserimento caratteri speciali
>>> '{:+d}'.format(24)
'+24'
>>>

numero=150
>>> f"Numero: {'\%d'}" 

# F-string = formattando la stampa

>>> "Hello, {name}! You're {age} years old.".format(name="Jane", age=25)
"Hello, Jane! You're 25 years old."

# Sostituzione di variabili
name = "Pippo"
age = "26"
>>> print{f"Hello, {name}! You're {age} years old."}
"Hello, Pippo! You're 26 years old."

# Ordine posizionale
name = "Pippo"
age = "26"
>>> print{f"Hello, {1}! You're {0} years old."}
"Hello, 26! You're Pippo years old."

# % = percentuale = "lì viene inserito il tipo X"

>>> from datetime import datetime
>>> date = datetime(2023, 9, 26)
>>> f"Date: {date:%m/%d/%Y}"
'Date: 09/26/2023'

numero=150
>>> f"Numero: {%d}" 
>>> Numero: 150

# Esempi di serie di stampe

>>> print("Il prezzo finale è{:10.1f}".format(p))
Il prezzo finale è    1200.0
>>> print("Il prezzo finale è{:10.4f}".format(p))
Il prezzo finale è 1200.0000
>>> print("Il prezzo finale è{:10.5f}".format(p))
Il prezzo finale è1200.00000
>>> print("Il prezzo finale è{:10.6f}".format(p))
Il prezzo finale è1200.000000
>>> print("Il prezzo finale è{:5.2f}".format(p))
Il prezzo finale è1200.00
>>> print("Il prezzo finale è{:6.3f}".format(p))
Il prezzo finale è1200.000
>>> print("Il prezzo finale è{:1.3f}".format(p))
Il prezzo finale è1200.000
>>> print("Il prezzo finale è{:3.3f}".format(p))
Il prezzo finale è1200.000
>>> print("Il prezzo finale è{:3.1f}".format(p))

# Spaziature
>>> print("{0:5d}{1:15d}{2:40d}".format(a, a*2, a*3))
   10             20                                      30

# Formattazioni specifiche di stringhe
>>> cognome="Verdi"
>>> nome="Giuseppe"
>>> print("{0:20}{1:45}".format(cognome, nome))
Verdi               Giuseppe
>>> print("{0:>20}{1:>^45}".format(cognome, nome))
               Verdi>>>>>>>>>>>>>>>>>>Giuseppe>>>>>>>>>>>>>>>>>>>