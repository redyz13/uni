/* Scrivere un programma che riceve da riga di comando 
 * una successione di numeri e ne effettui l’ordinamento 
 * attraverso una funzione void ordina(int*) con uno degli 
 * algoritmi di ordinamento implementati al corso. 
 * Il risultato va mostrato su standard output
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bubble sort
void ordina(int *a, int lenght);
int *crea_array(int n, char **numeri);

int main(int argc, char **argv) {
    int *array, i;

    if(argc < 2) {
        printf("Utilizzo: <%s numero1 numero2 ...>\n", argv[0]);
    }
    else {
        array = crea_array(argc - 1, argv + 1);

        printf("Numeri inseriti:\n");

        for(i = 0; i < argc - 1; i++) {
            printf("%d ", array[i]);
        }

        printf("\n\nNumeri ordinati:\n");

        ordina(array, argc - 1);

        for(i = 0; i < argc - 1; i++) {
            printf("%d ", array[i]);
        }

        putchar('\n');
    }

    return 0;
}

int *crea_array(int n, char **numeri) {
    int *array;
    int i;

    array = malloc(sizeof(int) * n);

    if(!array) {
        exit(-1);
    }

    for(i = 0; i < n; i++) {
        array[i] = atoi(numeri[i]);
    }

    return array;
}

// Bubble sort
void ordina(int *a, int lenght) {
    int i, j;
    int tmp;

    for(i = 0; i < lenght; i++) {
        for(j = 0; (j < lenght - 1 - i); j++) {
            if(a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}
