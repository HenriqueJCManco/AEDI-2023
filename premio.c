#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 20

typedef struct node {
  char name[50];
  struct node *prox;
} Node;

void adicionar(Node **head, char name[]) {
  Node *newNo = (Node *)malloc(sizeof(Node));
  strcpy(newNo->name, name);
  newNo->prox = NULL;

  if (*head == NULL) {
    *head = newNo;
  } else {
    Node *noAtual = *head;
    Node *noAnterior = NULL;

    while (noAtual != NULL && strcmp(noAtual->name, name) < 0) {
      noAnterior = noAtual;
      noAtual = noAtual->prox;
    }

    if (noAnterior == NULL) {
      newNo->prox = *head;
      *head = newNo;
    } else {
      noAnterior->prox = newNo;
      newNo->prox = noAtual;
    }
  }
}

int main() {
  int K, N, i = 0, j = 1;
  Node *head = NULL;
  char name[MAX_NOME];
  scanf("%d %d", &N, &K);
  while (i < N) {
    scanf("%s", name);
    adicionar(&head, name);
    ++i;
  }
  // imprimir o no
  Node *noAtual = head;
  while (noAtual != NULL && j < K) {
    noAtual = noAtual->prox;
    j++;
  }
  printf("%s\n", noAtual->name);
  return 0;
}
