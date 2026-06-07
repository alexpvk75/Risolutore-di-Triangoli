import math

def valido(L):
    return (L[0]+L[1] > L[2]) and (L[1]+L[2] > L[0]) and (L[0]+L[2] > L[1])

def main():
    while True:
        print("", end="\n")
        L = [0.0, 0.0, 0.0]
        A = [0.0, 0.0, 0.0]
        H = [0.0, 0.0, 0.0]
        lati = ["AB", "BC", "AC"]

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

        if not valido(L):
            print("I valori inseriti non possono fornire un triangolo valido.")
            continue
        perimetro = L[0] + L[1] + L[2]
        semiper   = perimetro / 2
        area      = math.sqrt(semiper * (semiper-L[0]) * (semiper-L[1]) * (semiper-L[2]))

        for x in range(3):
            cos = (L[(x+1)%3]**2 + L[(x+2)%3]**2 - L[x]**2) / (2 * L[(x+1)%3] * L[(x+2)%3])
            A[x] = math.degrees(math.acos(cos))
            H[x] = (2 * area) / L[x]
        print("", end="\n")
        for x in range(3):
            print(f"Angolo relativo al lato {lati[x]} = {A[x]:g}")
        for x in range(3):
            print(f"Altezza relativa al lato {lati[x]} = {H[x]:g}")
        
        print("\nClassificazione del triangolo")
        print("In base ai lati:", end =" ")
        if (L[0] == L[1] and L[1] == L[2]):
            print("equilatero")
        elif (L[0] == L[1] or L[0] == L[2] or L[1] == L[2]):
            print("isoscele")
        else:
            print("scaleno")
        print("In base agli angoli:", end =" ")
        if (A[0] == 90 or A[1] == 90 or A[2] == 90):
            print("rettangolo")
        elif (A[0] > 90 or A[1] > 90 or A[2] > 90):
            print("ottusangolo")
        elif (A[0] == A[1] and A[1] == A[2]):
            print("equiangolo")
        else:
            print("acutangolo")
        
        print(f"\nPerimetro: {perimetro:g}")
        print(f"Area: {area:g}")
        while True:
            risposta = input("\nVuoi eseguire un'altra computazione? (s/n): ").strip().lower()
            if risposta == 's':
                break
            elif risposta == 'n':
                print("Arrivederci!")
                return
            else:
                print("Risposta non valida.")

if __name__ == "__main__":
    main()