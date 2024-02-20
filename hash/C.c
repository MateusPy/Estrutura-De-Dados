#include <stdio.h>

int main() {
    int numObservacoes; 
    int corMaisFrequente = 0; 
    int frequenciaCor = 0; 

    while(1) { 
        scanf("%d", &numObservacoes);

        if (numObservacoes == 0) {
            break; 
        }

        for (int i = 0; i < numObservacoes; i++) {
            int codigoCor;
            scanf("%d", &codigoCor);

            if (frequenciaCor == 0) {
                corMaisFrequente = codigoCor;
                frequenciaCor++;
            } else {
                if (codigoCor == corMaisFrequente) {
                    frequenciaCor++;
                } else {
                    frequenciaCor--;
                }
            }

            if (frequenciaCor < 0) {
                frequenciaCor = 0;
            }
        }  
        printf("%d\n", corMaisFrequente);
    }

    return 0;
}






