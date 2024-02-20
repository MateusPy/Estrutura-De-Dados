#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula *p = l3;
    l3->prox = NULL;
    l1 = l1->prox;
    l2 = l2->prox;
    while(l1 != NULL && l2 != NULL){

        if(l1->dado < l2->dado){
            p->prox = l1;
            l1 = l1->prox;
        }else{
            p->prox = l2;
            l2 = l2->prox;
        }
        p = p->prox;
    }

    
    if(l1 != NULL) p->prox = l1;
    else p->prox = l2;
}

