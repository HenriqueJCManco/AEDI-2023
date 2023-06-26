#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Lista {
    No* primeiro;
    No* ultimo;
} Lista;

void insere(Lista* hash, int chave, int tamanho) {
    int resto;
    No* novoNo = (No*) malloc(sizeof(No));
    resto = chave % tamanho;

    if (hash[resto].primeiro) {
        hash[resto].ultimo->prox = novoNo;
    } else {
        hash[resto].primeiro = novoNo;
    }

    hash[resto].ultimo = novoNo;
    novoNo->prox = NULL;
    novoNo->valor = chave;
}

int main() {
    int quantidade, caso, tamanho, elementos;
    int i, valor;

    scanf("%d", &quantidade);

    for (caso = 0; caso < quantidade; ++caso) {
        scanf("%d %d", &tamanho, &elementos);
        Lista* hash = (Lista*) malloc(tamanho * sizeof(Lista));

        for (i = 0; i < tamanho; ++i) {
            hash[i].primeiro = NULL;
            hash[i].ultimo = NULL;
        }

        for (i = 0; i < elementos; ++i) {
            scanf("%d", &valor);
            insere(hash, valor, tamanho);
        }

        for (i = 0; i < tamanho; ++i) {
            printf("%d -> ", i);
            No* no = hash[i].primeiro;

            while (no) {
                printf("%d -> ", no->valor);
                no = no->prox;
            }

            printf("\\\n");
        }

        free(hash);

        if (caso < quantidade - 1) {
            printf("\n");
        }
    }

    return 0;
}
