#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int valido(double L[3]) {
    return (L[0] + L[1] > L[2]) && (L[1] + L[2] > L[0]) && (L[0] + L[2] > L[1]);
}

int main(void) {
    double L[3] = {0, 0, 0};
    double A[3] = {0, 0, 0};
    const char *nomi_lati[3] = {"AB", "BC", "AC"};
    const char *nomi_angoli[3] = {"C", "A", "B"};

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
        return 1;
    }

    double perimetro = L[0] + L[1] + L[2];
    double semiper   = perimetro / 2.0;
    double area      = sqrt(semiper * (semiper - L[0]) * (semiper - L[1]) * (semiper - L[2]));

    for (int x = 0; x < 3; x++) {
        double coseno = (L[(x+1)%3]*L[(x+1)%3] + L[(x+2)%3]*L[(x+2)%3] - L[x]*L[x])
                        / (2.0 * L[(x+1)%3] * L[(x+2)%3]);
        A[x] = acos(coseno) * 180.0 / PI;
    }

    printf("\nLati: AB = %g, BC = %g, AC = %g\n", L[0], L[1], L[2]);
    printf("Perimetro: %g\n", perimetro);
    printf("Area: %g\n", area);
    for (int x = 0; x < 3; x++)
        printf("%s = %g\n", nomi_angoli[x], A[x]);

    return 0;
}