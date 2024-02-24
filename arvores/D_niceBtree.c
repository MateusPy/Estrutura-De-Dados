#include <stdio.h>

// Função para calcular a profundidade da árvore binária "nice"
int profundidade_da_arvore_binaria_nice(char **preordem) {
    char atual = **preordem;
    (*preordem)++;

    if (atual == '\0') {
        return 0;
    }

    if (atual == 'l') {
        return 0;
    }

    // Para 'n', calcula a profundidade recursivamente para as subárvores esquerda e direita
    int profundidade_esquerda = profundidade_da_arvore_binaria_nice(preordem);
    int profundidade_direita = profundidade_da_arvore_binaria_nice(preordem);

    // A profundidade do nó atual é a profundidade máxima de suas subárvores + 1
    return (profundidade_esquerda > profundidade_direita) ? (profundidade_esquerda + 1) : (profundidade_direita + 1);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        char preordem[10001];
        scanf("%s", preordem);

        // Inicializa um ponteiro para o início da string
        char *ptr = preordem;

        int resultado = profundidade_da_arvore_binaria_nice(&ptr);
        printf("%d\n", resultado);
    }

    return 0;
}


