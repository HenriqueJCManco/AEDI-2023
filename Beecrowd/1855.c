#include <stdio.h>

#define MAX_SIZE 100

char labirinto[MAX_SIZE][MAX_SIZE];
int visitados[MAX_SIZE][MAX_SIZE];
int linhas, colunas, posX, posY, direcaoX, direcaoY;

int validaPosicao(int x, int y) {
    return x >= 0 && y >= 0 && x < linhas && y < colunas;
}

int main() {
    scanf("%d%d", &colunas, &linhas);

    for (int i = 0; i < linhas; i++) {
        scanf("%s", labirinto[i]);
    }

    while (validaPosicao(posX, posY)) {
        if (visitados[posX][posY]) {
            printf("!\n");
            return 0;
        }

        if (labirinto[posX][posY] == '*') {
            printf("*\n");
            return 0;
        }

        switch (labirinto[posX][posY]) {
            case '>':
                direcaoX = 0;
                direcaoY = 1;
                break;
            case '<':
                direcaoX = 0;
                direcaoY = -1;
                break;
            case 'v':
                direcaoX = 1;
                direcaoY = 0;
                break;
            case '^':
                direcaoX = -1;
                direcaoY = 0;
                break;
        }

        visitados[posX][posY] = 1;
        posX += direcaoX;
        posY += direcaoY;
    }

    return 0;
}
