# Inizializzazione
import math
def valido(L):
    return (L[0] + L[1] > L[2]) and (L[1] + L[2] > L[0]) and (L[0] + L[2] > L[1])
def calc_angolo(x, L):
    cos = (L[(x+1)%3]**2 + L[(x+2)%3]**2 - L[x]**2) / (2 * L[(x+1)%3] * L[(x+2)%3])
    return math.degrees(math.acos(cos))
def calc_area(L, A):
    index = 2 if A[2]>=A[1] else 1
    H = L[2] * math.sin(math.radians(A[1])) if index == 1 else L[1] * math.sin(math.radians(A[2]))
    return 0.5*L[0]*H
def fmt(num, cifre=2):
    if num % 1 == 0:
        return f'{int(num)}'
    else:
        return f"{num:.{cifre}f}"
def main():
    L = [0, 0, 0] # Lati del triangolo (AB, BC, AC)
    A = [0, 0, 0] # Angoli del triangolo (C, A, B)
    perimetro = 0
    area = 0
    # Fase Input
    for i in range(3):
        tentativi = 0
        while tentativi <= 3:
            tentativi +=1
            insert = input(f"Inserisci il valore del lato {["AB", "BC", "AC"][i]} (tentativo n. {tentativi}/3): ")
            try:
                valore = float(insert)
            except ValueError:
                print("Errore: assicurati di inserire valori numerici validi (es. 3, 5.7)")
                continue
            if valore <= 0:
                print("Errore: tutti i lati del triangolo devono avere lunghezze positive")
                continue
            L[i] = valore
            perimetro += L[i]
            break
        else:
            print("Limite tentativi superato. Fine programma.")
            exit()
    if(not valido(L)):
        print("Errore: le lunghezze fornite non possono formare un triangolo (Disuguaglianza triangolare)")
    else:
        # Fase Elaborazione
        perimetro = (L[0] + L[1] + L[2])
        for x in range(3):
            A[x] = calc_angolo(x, L)
        area = calc_area(L, A)
        # Fase Output
        print(f'\nPerimetro: {fmt(perimetro)}\nArea: {fmt(area)}\n')
if __name__ == "__main__":
    main()