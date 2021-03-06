#include <stdio.h>
#include "playlist.h"

int main(void) {
    Playlist p;

    p = newPlaylist();

    Canzone c1, c2, c3, c4;

    c1 = creaCanzone("Titolo0", "Cantante0", 120);
    c2 = creaCanzone("Titolo1", "Cantante1", 140);
    c3 = creaCanzone("Titolo2", "Cantante0", 160);
    c4 = creaCanzone("Titolo3", "Cantante2", 180);

    enqueue(p, c1);
    enqueue(p, c2);
    enqueue(p, c3);
    enqueue(p, c4);

    // removeCanzone(p, 3);

    printPlaylist(p);

    forward(p, 2);

    printf("Lista dopo il forward:\n");

    printPlaylist(p);

    printf("\nCanzoni del cantante Cantante0:\n");

    Playlist s = canzoniCantante(p, "Cantante0");

    printPlaylist(s);

    freeCanzone(c1);
    freeCanzone(c2);
    freeCanzone(c3);
    freeCanzone(c4);
    freePlaylist(s);
    freePlaylist(p);

    return 0;
}
