import math

lati = ["AB", "BC", "AC"]

L = [0.0, 0.0, 0.0]

for i in range(3):
    while True:
        try:
            v = float(input(f"Inserisci il valore del lato {lati[i]}: "))
            if v <= 0:
                print("Inserisci un numero valido e maggiore di 0")
                continue
            L[i] = v
            break
        except ValueError:
            print("Inserisci un numero valido e maggiore di 0")

def valido(L):
    return (L[0]+L[1] > L[2]) and (L[1]+L[2] > L[0]) and (L[0]+L[2] > L[1])

if not valido(L):
    print("I valori inseriti non possono fornire un triangolo valido.")
else:
    perimetro = L[0] + L[1] + L[2]
    semiper   = perimetro / 2
    area      = math.sqrt(semiper * (semiper-L[0]) * (semiper-L[1]) * (semiper-L[2]))

    print(f"\nLati: AB = {L[0]:g}, BC = {L[1]:g}, AC = {L[2]:g}")
    print(f"Perimetro: {perimetro:g}")
    print(f"Area: {area:g}")