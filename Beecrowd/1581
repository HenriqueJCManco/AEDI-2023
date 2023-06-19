#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        char primeiraPalavra[21];  // Supondo que o tamanho máximo da palavra seja 20 caracteres
        scanf("%s", primeiraPalavra);

        char palavraAtual[21];
        int isEnglish = 0;  // Variável para indicar se a língua é inglês

        for (int i = 1; i < N; i++) {
            scanf("%s", palavraAtual);

            if (strcmp(primeiraPalavra, palavraAtual) != 0) {
                isEnglish = 1;
            }
        }

        if (isEnglish) {
            printf("ingles\n");
        } else {
            printf("%s\n", primeiraPalavra);
        }
    }

    return 0;
}
