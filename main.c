#include <stdio.h>
#include <math.h>
int valido(float L[]) {
    if ((L[0]+L[1]>L[2])&&(L[0]+L[2]>L[1])&&(L[1]+L[2]>L[0])) {
        return 1;
    }
    else {
        return 0;
    }
}
float calc_angolo(int x, float L[]) {
    float cos = (L[(x+1)%3]*L[(x+1)%3] + L[(x+2)%3]*L[(x+2)%3] - L[x]*L[x]) / (2 * L[(x+1)%3] * L[(x+2)%3]);
    return acos(cos) * (180.0 / 3.14159);
}
float calc_area(float L[], float A[]) {
    int index = (A[2]>=A[1]) ? 2 : 1;
    float H = (index == 1) ? L[2] * sin(A[1] * (3.14159 / 180.0)) : L[1] * sin(A[2] * (3.14159 / 180.0));
    return 0.5 * L[0] * H;
}
int main () {
    float L [] = {0,0,0};
    float A [] = {0,0,0};
    float perimetro = 0.0f;
    float area;
    const char *lati[3] = {"AB", "BC", "AC"};

    for (int i = 0; i < 3; i++) {
        int tentativi = 0;
        int successo = 0;

        while (tentativi < 3) {
            tentativi++;
            printf("Inserisci il valore del lato %s (tentativo n. %d/3): ", lati[i], tentativi);

            if (scanf("%f", &L[i]) == 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) ;
                if (L[i] <= 0.0f) {
                    printf("Errore: tutti i lati del triangolo devono avere lunghezze positive\n");
                    continue;
                }
                perimetro += L[i];
                successo = 1;
                break;
            } else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) ;
                printf("Errore: assicurati di inserire valori numerici validi (es. 3, 5.7)\n");
            }
        }

        if (!successo) {
            printf("Limite tentativi superato. Fine programma.\n");
            return 1;
        }
    }

    if(!valido(L)) {
        printf("Errore: le lunghezze fornite non possono formare un triangolo (Disuguaglianza triangolare)\n");
        return 1;
    } else {
        for (int x = 0; x < 3; x++) {
            A[x] = calc_angolo(x, L);
        }
        area = calc_area(L, A);
        printf("il perimetro del triangolo: %.3f\n", perimetro);
        printf("l'area del triangolo: %.3f\n", area);
    }

    return 0;
}