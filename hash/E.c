#include <stdio.h>
#include <stdlib.h>

int main() {
    char c, *m = malloc(sizeof(char) * (unsigned int) 1<<31);
    unsigned int s, loc = (unsigned int) 1<<31;

    if (m == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    while (scanf("%u %c", &s, &c) != EOF) {
        if (s >= (unsigned int) 1<<31) {
            printf("Erro: Índice inválido.\n");
            return 1;
        }
        m[s] = c;
        if (s < loc)
            loc = s;
    }

    while (m[loc]) {
        printf("%c", m[loc++]);
    }

    printf("\n");
    free(m);
    return 0;
}




