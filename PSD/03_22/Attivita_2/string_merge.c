/* Creare una funzione char *merge(char *, char *) che prende in
 * input il nome e il cognome e produca una nuova stringa che è il
 * risultato della concatenazione delle due date in input
 *
 * Una funzione char *incastona(char *, char *) che produce una nuova
 * stringa secondo la seguente regola: la più piccola delle due va
 * incastonata nella più lunga sostituendo i caratteri di questa ultima
 * Esempio: a = "fabio" b = "narducci" restituirà in output la stringa
 * c = "nfabioci" (nota. quando la stringa più lunga ha un numero pari di
 * caratteri, la stringa più corta viene incastonata al centro a meno di un
 * carattere a sx o dx)
 *
 * Una funzione void ordina(char *) che ordini i caratteri del nome e del
 * cognome con un algoritmo a scelta tra InsertionSort o BubbleSort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
void copia_stringa(char *s1, const char *s2);
char *merge(const char *s1, const char *s2);

int main(void) {
    char *nome, *cognome;
    char *concat;

    printf("Inserire il proprio nome: ");
    nome = leggi_stringa(25);

    printf("Inserire il proprio cognome: ");
    cognome = leggi_stringa(25);

    printf("\nNome inserito: %s", nome);
    printf("\nCognome inserito: %s", cognome);

    concat = merge(nome, cognome);

    printf("\nConcatenazione di nome e cognome: %s", concat);

    return 0;
}

char *leggi_stringa(int buff) {
    char *s;
    char tmp[buff+1];
    int lun;
    int ch, i = 0;

    while((ch = getchar()) != '\n') {
        if(i < buff) {
            tmp[i++] = ch;
        }
    }

    tmp[i] = '\0';

    lun = strlen(tmp);

    s = malloc(lun + 1);

    if(!s) {
        return NULL;
    }

    strcpy(s, tmp);

    return s;
}

void copia_stringa(char *s1, const char *s2) {
    char *pi = s1;

    while(*s2) {
        *pi++ = *s2++;
    }

    *pi = '\0';
}

char *merge(const char *s1, const char *s2) {
    char *p;
    char *pi;

    // Alloco una dimensione sufficiente per concatenare le stringhe
    p = malloc(strlen(s1) + strlen(s2) + 1);

    if(!p) {
        return NULL;
    }

    // Utilizzo un altro puntatore per mantenere intatto l'indirizzo di base
    pi = p;

    // Copio la prima stringa nella nuova stringa
    copia_stringa(pi, s1);

    // Scorro la stringa fino a trovare il carattere terminatore
    while(*pi)
        pi++;

    /* Inizio a copiare i caratteri dal terminatore della prima stringa
    *  fino all'ultimo carattere della seconda
    */
    copia_stringa(pi, s2);

    return p;
}
