#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb; 
    int M; 
    int N; 
} TH;

int hash(int chave, int M) {
    return chave % M;
}

TH* inicializaTabelaHash(int M) {
    TH *novaTabela = (TH*)malloc(sizeof(TH));
    novaTabela->M = M;
    novaTabela->N = 0;
    novaTabela->tb = (celula*)malloc(M * sizeof(celula));

    for (int i = 0; i < M; i++) {
        novaTabela->tb[i].prox = NULL;
    }

    return novaTabela;
}


void THinsere(TH *h, int ch) {
    int pos = hash(ch, h->M);

    celula *atual = h->tb[pos].prox;
    while (atual != NULL) {
        if (atual->dado == ch) {
            return;
        }
        atual = atual->prox;
    }

    celula *novaCelula = (celula*)malloc(sizeof(celula));
    novaCelula->dado = ch;
    novaCelula->prox = h->tb[pos].prox;
    h->tb[pos].prox = novaCelula;
    h->N++;
}

int THremove(TH *h, int ch) {
    int pos = hash(ch, h->M);
    celula *anterior = NULL;
    celula *atual = h->tb[pos].prox;


    while (atual != NULL) {
        if (atual->dado == ch) {
            if (anterior == NULL) {

                h->tb[pos].prox = atual->prox;
            } else {
            
                anterior->prox = atual->prox;
            }

            free(atual); 
            h->N--; 
            return 0; 
        }
        anterior = atual;
        atual = atual->prox;
    }

    return -1; 
}

int THbusca(TH *h, int ch) {
    int pos = hash(ch, h->M);
    celula *atual = h->tb[pos].prox;


    while (atual != NULL) {
        if (atual->dado == ch) {
            return 1; 
        }
        atual = atual->prox;
    }

    return 0;
}


void liberarTabelaHash(TH *h) {
    for (int i = 0; i < h->M; i++) {
        celula *atual = h->tb[i].prox;
        while (atual != NULL) {
            celula *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(h->tb);
    free(h);
}






