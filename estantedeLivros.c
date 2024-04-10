/*Resolva o problema a seguir, usando lista encadeada :

Simular a organização de uma prateleira de livros na qual podem ser colocados
até 45 volumes, divididos em três categorias, conforme classificação abaixo:


- Tipo 1  -  romances;


- Tipo 2  -  policiais;


- Tipo 3  -  não ficção.


 A movimentação na prateleira ocorrerá da seguinte forma:


- código 1  -  inserção de livro na prateleira;


- código 2  -  retirada de um livro da prateleira.


Faça um programa para gerenciar vestes livros.  Para cada livro serão
registrados:  seu código, título, tipo e autor(es).  Para facilitar o
procedimento de busca de um determinado livro, devem ser organizadas três listas
sobre este vetor - uma para cada tipo de livro.  Em seguida o programa deverá
gerenciar um conjunto de inserções e retiradas. A busca de um livro para
retirada deverá ser feita analisando a lista correspondente a seu tipo. E a
inserção de um livro deverá ser feita na lista adequada. O programa deverá,
portanto, gerenciar as três listas, procurando otimizar o espaço ocupado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro {
  int codigo;
  char titulo[50];
  int tipo;
  char autor[50];
} Livro;

typedef struct no {
  Livro livro;
  struct no *prox;
} Node;

// inserir no início
void inserir_livro(Node *vetor_dos_tipos[], int c, const char *titu, int tip,
                   const char *a) {
  Node *novo_livro = (Node *)malloc(sizeof(Node));
  if (novo_livro) {
    novo_livro->livro.codigo = c;
    strcpy(novo_livro->livro.autor, a);
    strcpy(novo_livro->livro.titulo, titu);
    novo_livro->livro.tipo = tip;
    novo_livro->prox = vetor_dos_tipos[tip - 1];
    vetor_dos_tipos[tip - 1] = novo_livro;
  } else
    printf("Erro ao alocar memória");
}
// verifica o vetor do tipo e retorna os nos
void imprimirLivrosPorTipo(Node *vetor_dos_tipos[], int num_tipos) {
  for (int i = 0; i < num_tipos; i++) {
    printf("Livros do tipo %d:\n", i + 1);
    Node *atual = vetor_dos_tipos[i];
    while (atual != NULL) {
      printf("Código: %d, Título: %s, Autor: %s\n", atual->livro.codigo,
             atual->livro.titulo, atual->livro.autor);
      atual = atual->prox;
    }
    printf("\n");
  }
}

// buscar e remover. Função recebe a lista Livro, com cabeça e remove da lista
// quando achar o código
void buscar_e_remover(Node **lista, int codigo) {
  Node *aux, *remover = NULL;
  aux = *lista;
  if (aux != NULL && aux->livro.codigo == codigo) {
    *lista = aux->prox;
    free(aux);
    return;
  }
  while (aux != NULL && aux->livro.codigo != codigo) {
    remover = aux;
    aux = aux->prox;
  }
  if (aux == NULL) {
    printf("Livro não encontrado\n");
    return;
  }
  remover->prox = aux->prox;
  free(aux);
}

// imprime struct livro
void imprimirLivro(Livro l) {
  printf("\n\tCódigo: %d\n\tTítulo: %s\n\tTipo: %d\n\tAutor: %s\n", l.codigo,
         l.titulo, l.tipo, l.autor);
}

int main() {
  int opcao, valor, contador = 0;
  Livro livro;
  Node *vetor_dos_tipos[3] = {NULL, NULL, NULL};
  do {
    printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Buscar nome do "
           "livro\n\t4 - Imprimir os livros\n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      printf("Cadastre o livro: \n");
      printf("Digite o tipo do livro: (Lembre-se que 1 = romance, 2 = policial "
             "e 3 = não ficção): ");
      scanf("%d", &livro.tipo);
      if (livro.tipo != 1 && livro.tipo != 2 && livro.tipo != 3) {
        printf("Tipo inválido");
        break;
      }
      printf("Digite o código do livro: ");
      scanf("%d", &livro.codigo);
      printf("Digite o título do livro: ");
      scanf(" %49[^\n]", livro.titulo);
      printf("Digite o autor do livro: ");
      scanf(" %49[^\n]", livro.autor);
      inserir_livro(vetor_dos_tipos, livro.codigo, livro.titulo, livro.tipo,
                    livro.autor);
      break;
    case 2:
      printf("Digite o código do livro a ser removido: ");
      scanf("%d", &valor);
      for (int i = 0; i < 3; i++) {
        buscar_e_remover(&vetor_dos_tipos[i], valor);
      }
    case 3:
      printf("Digite o código do livro a ser impresso: ");
      scanf("%d", &valor);
      for (int i = 0; i < 3; i++) {
        Node *aux = vetor_dos_tipos[i];
        while (aux != NULL) {
          if (aux->livro.codigo == valor) {
            imprimirLivro(aux->livro);
            break;
          }
          aux = aux->prox;
        }
      }
      break;
    case 4:
      imprimirLivrosPorTipo(vetor_dos_tipos, 3);
      break;

    default:
      if (opcao != 0)
        printf("\nOpção inválida!\n");
    }
  } while (opcao != 0);
}
