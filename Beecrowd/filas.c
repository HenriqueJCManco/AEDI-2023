#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000
#define STACK 0
#define QUEUE 1
#define PRIORITY_QUEUE 2
#define IMPOSSIVEL 3
#define NOT_SURE 4

int is_stack(int *comandos, int n){
    int top = -1; // pilha começa vazia
    int comandos_copia[n];
    memcpy(comandos_copia, comandos, n*sizeof(int)); // copia os valores do vetor original para o novo vetor
    for (int i = 0; i < n; i++){
        if(comandos_copia[i] == 1){
            top++; // empilha
        } else {
            if (top < 0 || comandos_copia[i] != top + 1){
                return 0; // erro: pilha vazia ou tentativa de desempilhar elemento diferente do esperado
            }
            top--; // desempilha
        }
    }
    return 1; // sucesso: todos os comandos foram executados corretamente
}


int is_queue(int *comandos, int n){
    int comandos_aux[MAX_N];
    memcpy(comandos_aux, comandos, n * sizeof(int));
    int head = 0, tail = -1; // fila começa vazia
    bool possible = true; // supõe que é possível ser uma fila
    for (int i = 0; i < n && possible; i++){ // verifica se ainda é possível ser uma fila
        if (comandos_aux[i] == 1){
            tail++; // insere na fila
            comandos_aux[tail] = comandos_aux[i+1];
            i++;
        } else{
            if (head > tail || comandos_aux[head] != comandos_aux[i]){
                possible = false; // não é possível ser uma fila
            }
            head++; // remove da fila
        }
    }
    if (possible && head <= tail){ // head <= tail verifica se a fila não está vazia
        return true; // sucesso: todos os comandos foram executados corretamente e é uma fila
    } else {
        return false; // erro: não é uma fila
    }
}



int is_priority_queue(int *comandos, int n) {
    int comandos_aux[MAX_N];
    memcpy(comandos_aux, comandos, n * sizeof(int));
    int sorted[MAX_N]; // vetor auxiliar que armazena elementos ordenados
    int tail = -1; // fila com prioridade começa vazia
    for (int i = 0; i < n; i++) {
        if (comandos_aux[i] == 1) {
            tail++;
            sorted[tail] = comandos_aux[i]; // insere na fila com prioridade
        } else {
            // remove o maior elemento da fila com prioridade
            int max = -1, pos = -1;
            for (int j = 0; j <= tail; j++) {
                if (sorted[j] > max) {
                    max = sorted[j];
                    pos = j;
                }
            }
            if (pos == -1 || comandos_aux[i] != max) {
                return 0; // erro: a fila com prioridade não foi construída corretamente
            }
            // remove o elemento da fila com prioridade
            for (int j = pos; j < tail; j++) {
                sorted[j] = sorted[j+1];
            }
            tail--;
        }
    }
    return 1; // sucesso: todos os comandos foram executados corretamente
}


int main() {
    int n, x, comandos[MAX_N];
    while (scanf("%d", &n) == 1){
        if (n == 0){
            break; 
        }
        int j = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &x);
            if (x == 2){
                scanf("%d", &x); // lê o valor a ser inserido/retirado da fila com prioridade
            }
            comandos[j++] = x;
        }
        int tipo = IMPOSSIVEL;
        if (is_stack(comandos, n)){
            tipo = STACK;
        } 
        if (is_queue(comandos , n)){
            tipo = QUEUE;
        } 
        if (is_priority_queue(comandos, n)){
            tipo = PRIORITY_QUEUE;
        } 
        if(tipo == QUEUE && tipo == PRIORITY_QUEUE){
        ( tipo = NOT_SURE);
        }
        switch (tipo) {
            case STACK:
                printf("stack\n");
                break;
            case QUEUE:
                printf("queue\n");
                break;
            case PRIORITY_QUEUE:
                printf("priority queue\n");
                break;
            case IMPOSSIVEL:
                printf("impossible\n");
                break;
            case NOT_SURE:
                printf("not sure\n");
                break;
        }
    }
    return 0;
}
