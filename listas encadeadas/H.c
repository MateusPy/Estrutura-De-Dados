#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;

typedef struct No {
    Item *dado;
    struct No *anterior, *proximo;
} No;

typedef struct Fila {
    No *inicio, *fim;
} Fila;

int criarFila(Fila *fila);
int enfileirar(Fila *fila, Item *elemento);
Item *desenfileirar(Fila *fila);
Item *frente(Fila *fila);
void imprimirFila(Fila *fila);

int main() {
    Fila fila, fila_final;
    criarFila(&fila);

    while (1) {
        Item *elemento = malloc(sizeof(Item) * 27);
        if (scanf("%s", elemento) == EOF)
            break;
        enfileirar(&fila, elemento);
    }

    criarFila(&fila_final);
    No *atual = fila.inicio;

    while (atual) {
        int ultimoCaracter = strlen(atual->dado) - 1;

        if (atual->anterior && atual->anterior->dado[0] == atual->dado[ultimoCaracter] - 32) {
            enfileirar(&fila_final, desenfileirar(&fila));
            enfileirar(&fila, desenfileirar(&fila));
        } else {
            enfileirar(&fila_final, desenfileirar(&fila));
        }
        atual = fila.inicio;
    }

    imprimirFila(&fila_final);
    return 0;
}

int criarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    return 1;
}

int enfileirar(Fila *fila, Item *elemento) {
    if (fila->inicio == NULL) {
        fila->inicio = fila->fim = malloc(sizeof(No));
        if (fila->inicio == NULL)
            return 0;
        fila->inicio->dado = elemento;
        fila->inicio->anterior = fila->inicio->proximo = NULL;
        return 1;
    }

    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL)
        return 0;
    novoNo->dado = elemento;
    novoNo->anterior = NULL;
    novoNo->proximo = fila->fim;
    fila->fim->anterior = novoNo;
    fila->fim = novoNo;
    return 1;
}

Item *desenfileirar(Fila *fila) {
    No *aRemover = fila->inicio;

    if (fila->fim == fila->inicio)
        fila->fim = NULL;

    fila->inicio = fila->inicio->anterior;

    if (fila->inicio)
        fila->inicio->proximo = NULL;

    Item *ret = aRemover->dado;
    free(aRemover);
    return ret;
}

Item *frente(Fila *fila) {
    return fila->inicio->dado;
}

void imprimirFila(Fila *fila) {
    No *atual = fila->inicio;

    while (atual) {
        printf("%s\n", atual->dado);
        atual = atual->anterior;
    }
}

















