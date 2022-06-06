#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

#define COUNT 10

struct Node {
    Item data;
    struct Node *left;
    struct Node *right;
};

Btree newBtree(void) {
    return NULL;
}

int isEmptyBtree(Btree t) {
    return t == NULL;
}

void setItemBtree(Btree t, Item it) {
    if (t == NULL) return;

    t->data = it;
}

Item getItemBtree(Btree t) {
    if (t == NULL) return NULLITEM;

    return t->data;
}

Btree figlioSX(Btree t) {
    if (t == NULL) return NULL;

    return t->left;
}

Btree figlioDX(Btree t) {
    if (t == NULL) return NULL;

    return t->right;
}

struct Node *getRoot(Btree t) {
    return t;
}

Btree consBtree(Item it, Btree sx, Btree dx) {
    Btree new;

    new = malloc(sizeof(struct Node));
    if (new == NULL) return NULL;

    setItemBtree(new, it);

    new->left = sx;
    new->right = dx;

    return new;
}

void preorder(Btree t) {
	if (isEmptyBtree(t)) return;
	
	printItem(getItemBtree(getRoot(t)));
    putchar(' ');
	preorder(figlioSX(t));
	preorder(figlioDX(t));

}

static void print2DUtil(Btree root, int space) {
    if (root == NULL) return;
 
    space += COUNT;
 
    print2DUtil(root->right, space);
 
    printf("\n");

    for (int i = COUNT; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);
 
    print2DUtil(root->left, space);
}
 
void print2DBtree(Btree root) {
   print2DUtil(root, 0);
}
