#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void pre_ordem(no *raiz) {
    if (raiz == NULL)
        return;

    no *pilha[100];  
    int topo = -1;

    pilha[++topo] = raiz;

    while (topo >= 0) {
        no *atual = pilha[topo--];
        printf("%d ", atual->dado);

        if (atual->dir != NULL)
            pilha[++topo] = atual->dir;

        if (atual->esq != NULL)
            pilha[++topo] = atual->esq;
    }
}
