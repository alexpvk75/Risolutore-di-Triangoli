#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int valido(double L[3]) {
    return (L[0] + L[1] > L[2]) && (L[1] + L[2] > L[0]) && (L[0] + L[2] > L[1]);
}

char leggi_char() {
    char c = getchar();
    while (c == '\n') c = getchar();
    while (getchar() != '\n');
    return c;
}

int main(void) {
    while(1) {
        printf("\n");
        double L[3] = {0, 0, 0};
        double A[3] = {0, 0, 0};
        double H[3] = {0, 0, 0};
        const char *nomi_lati[3] = {"AB", "BC", "AC"};

        for (int i = 0; i < 3; i++) {
            while (1) {
                printf("Inserisci il valore del lato %s: ", nomi_lati[i]);
                if (scanf("%lf", &L[i]) == 1 && L[i] > 0) break;
                printf("Inserisci un numero valido e maggiore di 0\n");
                while (getchar() != '\n');
            }
        }
        if (!valido(L)) {
            printf("I valori inseriti non possono fornire un triangolo valido.\n");
            continue;
        }
        double perimetro = L[0] + L[1] + L[2];
        double semiper   = perimetro / 2.0;
        double area      = sqrt(semiper * (semiper - L[0]) * (semiper - L[1]) * (semiper - L[2]));

        for (int x = 0; x < 3; x++) {
            double coseno = (L[(x+1)%3]*L[(x+1)%3] + L[(x+2)%3]*L[(x+2)%3] - L[x]*L[x]) / (2.0 * L[(x+1)%3] * L[(x+2)%3]);
            A[x] = acos(coseno) * 180.0 / PI;
            H[x] = (2 * area) / L[x];
        }

        printf("\n");
        for (int x = 0; x < 3; x++) 
            printf("Angolo relativo al lato %s = %g\n", nomi_lati[x], A[x]);
        for (int x = 0; x < 3; x++) 
            printf("Altezza relativa al lato %s = %g\n", nomi_lati[x], H[x]);
        printf("\nClassificazione del triangolo\n");
        printf("In base ai lati: ");
        if (L[0] == L[1] && L[1] == L[2]) 
            printf("equilatero\n");
        else if (L[0] == L[1] || L[0] == L[2] || L[1] == L[2]) 
            printf("isoscele\n");
        else 
            printf("scaleno\n");
        printf("In base agli angoli: ");
        if (A[0] == 90 || A[1] == 90 || A[2] == 90) 
            printf("rettangolo\n");
        else if (A[0] > 90 || A[1] > 90 || A[2] > 90) 
            printf("ottusangolo\n");
        else if (A[0] == A[1] && A[1] == A[2]) 
            printf("equiangolo\n");
        else 
            printf("acutangolo\n");
        
        printf("\nPerimetro: %g\n", perimetro);
        printf("Area: %g\n", area);
        while (1) {
            printf("\nVuoi eseguire un'altra computazione?(s/n): ");
            char risposta = leggi_char();
            if (risposta == 's' || risposta == 'S') break;
            else if (risposta == 'n' || risposta == 'N') { printf("Arrivederci!\n"); return 0;} 
            else printf("Risposta non valida\n");
        }
    }
}