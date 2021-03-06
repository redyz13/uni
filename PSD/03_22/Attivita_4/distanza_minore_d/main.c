#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int calcolo_distanze(punto *p, int n, int d);

int main(int argc, char *argv[]) {
    int i, j;
    int n = 0, m = 0;
    float d = 0;
    float ascissa = 0, ordinata = 0;
    punto *p;

    // Carica tutto l'input: coppie e distanza
    if(argc < 4 || (argc % 2 != 0)) {
        fprintf(stderr, "formato: <%s, distanza, coppie...>\n", argv[0]);
        return -1;
    }

    n = (argc - 2) / 2;

    p = malloc(sizeof(punto) * n);

    if(!p) return -1;

    d = atof(argv[1]);

    j = 0;

    for(i = 2; i < argc; i += 2) {
        ascissa = atof(argv[i]);
        ordinata = atof(argv[i+1]);

        p[j] = creapunto(ascissa, ordinata);

        stampa(p[j]);

        j++;
    }

    // Calcola le distanze a coppie e controlla che siano minori di d
    m = calcolo_distanze(p, n, d);

    printf("Le coppie di punti a distanza minore di %.2f sono %d\n", d, m);

    return 0;
}

int calcolo_distanze(punto *p, int n, int d) {
    float tmp;
    int i, k;
    int m = 0;

    for(i = 0; i < n; i++) {
        for(k = i + 1; k < n; k++) {
            tmp = distanza(p[i], p[k]);

            if(tmp < d) {
                m++;
            }
        }
    }

    return m;
}
