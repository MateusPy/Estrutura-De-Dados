#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100010
#define MAX_M 100010

int n, m;
long long int raios[MAX_N];

int buscaBinaria(long long int valor);

int main() {
    long long int total = 0;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &raios[i]);
        raios[i] *= raios[i]; 
    }

    for (int i = 1; i <= m; i++) {
        long long int x, y;
        scanf("%lld %lld", &x, &y);
        total += buscaBinaria(x * x + y * y); 
    }

    printf("%lld\n", total);

    return 0;
}

int buscaBinaria(long long int valor) {
    int baixo = 1;
    int alto = n;
    int contagem = 0;

    while (baixo <= alto) {
        int meio = baixo + (alto - baixo) / 2;

        if (raios[meio] >= valor) {
            contagem = n - meio + 1;
            alto = meio - 1;
        } else {
            baixo = meio + 1;
        }
    }

    return contagem;
}






