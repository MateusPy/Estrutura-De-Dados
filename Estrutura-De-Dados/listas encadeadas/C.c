#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;



int remove_depois (celula *p){
    if (p->prox == NULL){
        return 0;
    }
    else{
        celula *ch = p->prox;
        p->prox = ch->prox;
        free(ch);
        return 1;
    }
}


void remove_elemento(celula *le, int x){
    celula *atual = le;
    celula *ant = NULL;

    if(atual == NULL) return;
    if (atual->dado == x) {
        le = atual->prox; 
        free(atual);
        return;
    }
    while (atual != NULL && atual->dado != x) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        return; 
    }
    ant->prox = atual->prox;
    free(atual);
}


void remove_todos_elementos(celula *le, int x) {
    celula *atual = le;
    celula *ant = NULL;

    while (atual) {
        if (atual->dado == x) {
            if (ant == NULL) {
                le = atual->prox;
                free(atual);
                atual = le;
            } else {
                ant->prox = atual->prox;
                free(atual);
                atual = ant->prox;
            }
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
}


