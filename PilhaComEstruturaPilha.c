#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia, mes, ano;
} Data;

typedef struct {
  char nome[50];
  Data data;
} Pessoa;


typedef struct no {
  Pessoa p;
  struct no *proximo;

} No;

typedef struct{
  No *topo;
  int tam;
}Pilha;

void criar_pilha(Pilha *p){
  p->topo = NULL;
  p->tam = 0;
}

Pessoa ler_pessoa() {
  Pessoa p;

  printf("\n Digite o nome, data de nascimento dd mm aaaa: \n");
  scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
  return p;
}

void imprimir_pessoa(Pessoa p) {
  printf("\n Nome : %s\n Data: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes,
         p.data.ano);
}
// funcao push recebe um ponteiro para o topo
void empilhar(Pilha *p) {
  No *novo = malloc(sizeof(No));
  if (novo) {
    novo->p = ler_pessoa();
    novo->proximo = p->topo;
    p->tam++;
  
  } else
    printf("Erro ao alocar memória!");

}

// funcao pop recebe um ponteiro para ponteiro
No *desempilhar(Pilha *p) {
  if (p->topo) {
    No *remover = p->topo;
    p->topo = remover->proximo;
    return remover;
    p->tam--;
  } else
    printf("Pilha vazia!");
  return NULL;
}

// funcao imprimir rece ponteiro para o topo
void imprimir_pilha(Pilha *p) {
  No *aux = p->topo;
  printf("\n------------- PILHA -------------\n");
  while (aux) {
    imprimir_pessoa(aux->p);
    aux = aux->proximo;
  }
  printf("\n----------- FIM PILHA -----------\n");
}

int main() {
  No  *remover;
  Pilha p;
  int opcao;
  criar_pilha(&p);
  do {
    printf("\n 0 - sair \n1 = empilhar\n2 = desempilhar\n3 = imprimir\n");
    scanf("%d", &opcao);
    getchar();
    printf("\n opcao = %d", opcao);

    switch (opcao) {
    case 1:
      empilhar(&p);
      break;
    case 2:
      remover = desempilhar(&p);
      if (remover) {
        printf("\nElemento removido com sucesso!\n");
        imprimir_pessoa(remover->p);

        free(remover);
      } else
        printf("\nSem no a remover\n");
      break;
    case 3:
      imprimir_pilha(&p);
      break;
    default:
      if (opcao != 0) {
        printf("\n opcao invalida\n");
      }
    }
  } while (opcao != 0);

  return 0;
}
