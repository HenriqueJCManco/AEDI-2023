#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TEXTO 100000
#define MAX_PALAVRA 5

typedef unsigned char* palavra;
typedef unsigned char* texto;

int trivial(palavra a, int m, texto b, int n) {
    int k, r, bolado;
    bolado = 0;
    for (k = 0; k <= n - m; k++) {
        r = 0;
        while (r < m && tolower(a[r]) == tolower(b[k + r]))
            r += 1;
        if (r >= m)
            bolado += 1;
    }
    return bolado;
}


int main() {
    int resultado;
    char palavra_chave[MAX_PALAVRA] = "zelda";
    
    unsigned char texto_carta[MAX_TEXTO + 1];
    
    fgets(texto_carta, MAX_TEXTO, stdin);
    texto_carta[strcspn(texto_carta, "\n")] = '\0'; // Remover o caractere de nova linha, se presente

    resultado = trivial(palavra_chave, MAX_PALAVRA, texto_carta, strlen(texto_carta));

    if (resultado) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }

    return 0;
}
