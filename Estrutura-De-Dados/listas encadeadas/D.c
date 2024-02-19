#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *aux;
    aux = le;
    if (aux == NULL) return NULL;
    while(aux != NULL && aux->dado != x){
        aux = aux->prox;
    }
    return aux;
}

celula *busca_rec (celula *le, int x){
    celula *aux;
    aux = le;
    if(aux == NULL) return NULL;
    if(aux->dado == x){
        return aux;
    }else{
        return busca_rec(aux->prox, x);
    }
}