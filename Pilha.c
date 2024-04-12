#include <stdio.h>
#include <stdlib.h>

// empilhar

typedef struct no {
  int valor;
  struct no *proximo;
} No;
// passando o ponteiro da estrutura como um parametro, permite a função alterar
// a estrutura original na memória.

No *empilhar /* push */ (No *topo, int entrada) {
  No *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = entrada;
    // o proximo da Struct no, aponta agora para o topo da pilha
    novo->proximo = topo;
    return novo;
  } else
    printf("\nErro ao alocar memória...\n");
  return NULL;
}
// tem que ser ponteiro para ponteiro, pq a linguagem C ia copiar o valor do
// *topo e não indicar o endereço dele.
No *desempilhar /*pop*/ (No **topo) {
  // como está sendo verificado o conteúdo, pode ser apenas *topo
  if (*topo != NULL) {
    No *remover = *topo;
    // alterando o conteúdo apontado pelo ponteiro *topo
    *topo = remover->proximo;
    return remover;
  } else
    printf("\n A pilha está vazia\n");
  // sempre que não houver ponteiro para ser retornado, retorna NULL.
  return NULL;
}

void imprimir_pilha(No *topo) {
  printf("\n\t----------------PILHA----------------\n");
  while (topo) {
    printf("\t                 %d                \t\n", topo->valor);

    topo = topo->proximo;
  }
  printf("\n\t--------------FIM PILHA--------------\n");
}

int main() {
  int opcao, entrada;
  No *remover, *topo = NULL;
  do {
    printf("\n\t0 - Sair\n\t1 - Empilhar\n\t2 - Desempilhar\n\t3 - Imprimir\n");
    printf("\n> ");
    scanf("%d", &opcao);
    printf("\n");
    switch (opcao) {
    case 1:
      printf("Digite o valor a ser empilhado: ");
      scanf("%d", &entrada);
      topo = empilhar(topo, entrada);
      break;
    case 2:
      // como a função recebe de entrada um ponteiro para ponteiro, precisa do
      // endereço(&)
      remover = desempilhar(&topo);
      if (remover) {
        printf("Elemento %d removido com sucesso!", remover->valor);
      } else
        printf("\nSem nada para remover\n");
      break;
    case 3:
      imprimir_pilha(topo);
      break;
    }
  } while (opcao != 0);
}
