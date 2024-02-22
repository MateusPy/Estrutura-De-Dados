#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;


void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    no *pilha[100];  
    int topo = -1;
    no *atual = raiz;
    no *ultimoVisitado = NULL;

    while (atual != NULL || topo != -1) {
        while (atual != NULL) {
            pilha[++topo] = atual;
            atual = atual->esq;
        }

        atual = pilha[topo];


        if (atual->dir == NULL || atual->dir == ultimoVisitado) {
            printf("%d ", atual->dado);
            topo--;
            ultimoVisitado = atual;
            atual = NULL;  
        } else {
            atual = atual->dir;
        }
    }
}