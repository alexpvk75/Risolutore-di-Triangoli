#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int valido(double L[3]) {
    return (L[0] + L[1] > L[2]) && (L[1] + L[2] > L[0]) && (L[0] + L[2] > L[1]);
}

int main(void) {
    double L[3] = {0, 0, 0};
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
        return 1;
    }

    double perimetro = L[0] + L[1] + L[2];
    double semiper   = perimetro / 2.0;
    double area      = sqrt(semiper * (semiper - L[0]) * (semiper - L[1]) * (semiper - L[2]));

    printf("\nLati: AB = %g, BC = %g, AC = %g\n", L[0], L[1], L[2]);
    printf("Perimetro: %g\n", perimetro);
    printf("Area: %g\n", area);
    return 0;
}