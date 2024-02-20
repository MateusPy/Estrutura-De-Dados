#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


void insere_inicio (celula *le, int x){
    celula *NovaCelula;
    NovaCelula = (celula*) malloc(sizeof(celula));
    if (NovaCelula == NULL) return;
    NovaCelula->dado = x;
    NovaCelula->prox = le->prox;
    le->prox = NovaCelula;
}



void insere_antes(celula *le, int x, int y) {
    celula *NovaCelula, *Aux;
    NovaCelula = (celula*)malloc(sizeof(celula));
    if (NovaCelula == NULL) return;
    Aux = le;

    if (Aux->prox == NULL) {
        NovaCelula->dado = x;
        NovaCelula->prox = NULL;
        Aux->prox = NovaCelula;
        return;
    }

    if (Aux->prox->dado == y) {
        NovaCelula->dado = x;
        NovaCelula->prox = Aux->prox;
        Aux->prox = NovaCelula;
        return;
    }

    while (Aux->prox != NULL && Aux->prox->dado != y) {
        Aux = Aux->prox;
    }

    if (Aux->prox != NULL) {
        NovaCelula->dado = x;
        NovaCelula->prox = Aux->prox;
        Aux->prox = NovaCelula;
    } else {
        NovaCelula->dado = x;
        NovaCelula->prox = NULL;
        Aux->prox = NovaCelula;
    }
}



