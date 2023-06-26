#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 1000

typedef unsigned short us;

typedef struct tipoNoQueue {
    int dado;
    struct tipoNoQueue *proximo;
} tipoNoQueue;

typedef struct tipoFila {
    tipoNoQueue *primeiro;
    tipoNoQueue *ultimo;
} tipoFila;

typedef struct tipoNoPilha {
    int dado;
    struct tipoNoPilha *proximo;
} tipoNoPilha;

typedef struct tipoPilha {
    tipoNoPilha *topo;
} tipoPilha;

typedef struct pqueue {
    int dado;
    int prioridade;
} pqueue;

typedef struct _pqueue {
    int qtd;
    struct pqueue dados[MAXSIZE];
} _pqueue;

void initializeQueue(tipoFila *fila);
void enqueue(tipoFila *fila, int x);
int front(tipoFila *fila);
void dequeue(tipoFila *fila);

void initializeStack(tipoPilha *pilha);
void push(tipoPilha *pilha, int x);
void pop(tipoPilha *pilha);
int top(tipoPilha *pilha);

_pqueue *initializePriorityQueue();
void pushPriorityQueue(_pqueue *filaP, int prioridade, int id);
void popPriorityQueue(_pqueue *filaP);
int topPriorityQueue(_pqueue *filaP);
void balanceRemove(_pqueue *filaP, int pai);
void balanceInsert(_pqueue *filaP, int filho);

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int x, comando, i;
        _Bool queueN, stackN, priorityQueue;
        _pqueue *priority_queue = initializePriorityQueue();
        tipoFila fila;
        tipoPilha stack;

        initializeQueue(&fila);
        initializeStack(&stack);

        queueN = stackN = priorityQueue = true;
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &comando, &x);

            if (comando == 1) {
                pushPriorityQueue(priority_queue, x, x);
                push(&stack, x);
                enqueue(&fila, x);
            } else {
                if (top(&stack) != x)
                    stackN = false;
                else
                    pop(&stack);

                if (front(&fila) != x)
                    queueN = false;
                else
                    dequeue(&fila);

                if (topPriorityQueue(priority_queue) != x)
                    priorityQueue = false;
                else
                    popPriorityQueue(priority_queue);
            }
        }

        if (!stackN && !queueN && !priorityQueue)
            printf("impossible\n");
        else if (stackN && priorityQueue)
            printf("not sure\n");
        else if (stackN && queueN)
            printf("not sure\n");
        else if (priorityQueue && queueN)
            printf("not sure\n");
        else if (priorityQueue)
            printf("priority queue\n");
        else if (queueN)
            printf("queue\n");
        else if (stackN)
            printf("stack\n");
    }

    return 0;
}

void initializeQueue(tipoFila *fila) {
    fila->primeiro = fila->ultimo = NULL;
}

void enqueue(tipoFila *fila, int x) {
    tipoNoQueue *auxiliar;

    auxiliar = (tipoNoQueue *) malloc(sizeof(tipoNoQueue));

    if (!auxiliar)
        return;

    auxiliar->dado = x;
    auxiliar->proximo = NULL;

    if (fila->ultimo)
        fila->ultimo->proximo = auxiliar;
    else
        fila->primeiro = auxiliar;

    fila->ultimo = auxiliar;
}

int front(tipoFila *fila) {
    if (fila->primeiro)
        return fila->primeiro->dado;
    else
        return -1;
}

void dequeue(tipoFila *fila) {
    tipoNoQueue *auxiliar;

    if (!fila->primeiro)
        return;

    auxiliar = fila->primeiro;

    fila->primeiro = fila->primeiro->proximo;

    if (!fila->primeiro)
        fila->ultimo = NULL;

    free(auxiliar);
}

void initializeStack(tipoPilha *pilha) {
    pilha->topo = NULL;
}

void push(tipoPilha *pilha, int x) {
    tipoNoPilha *auxiliar;

    auxiliar = (tipoNoPilha *) malloc(sizeof(tipoNoPilha));

    if (!auxiliar)
        return;

    auxiliar->dado = x;
    auxiliar->proximo = pilha->topo;
    pilha->topo = auxiliar;
}

void pop(tipoPilha *pilha) {
    tipoNoPilha *auxiliar;

    if (!pilha->topo)
        return;

    auxiliar = pilha->topo;

    pilha->topo = pilha->topo->proximo;

    free(auxiliar);
}

int top(tipoPilha *pilha) {
    if (pilha->topo)
        return pilha->topo->dado;
    else
        return -1;
}

_pqueue *initializePriorityQueue() {
    _pqueue *filaP;

    filaP = (_pqueue *) malloc(sizeof(_pqueue));

    if (filaP)
        filaP->qtd = 0;

    return filaP;
}

void pushPriorityQueue(_pqueue *filaP, int prioridade, int id) {
    if (filaP->qtd >= MAXSIZE)
        return;

    int atual = filaP->qtd++;

    filaP->dados[atual].dado = id;
    filaP->dados[atual].prioridade = prioridade;

    balanceInsert(filaP, atual);
}

void popPriorityQueue(_pqueue *filaP) {
    if (filaP->qtd <= 0)
        return;

    filaP->qtd--;
    filaP->dados[0] = filaP->dados[filaP->qtd];

    balanceRemove(filaP, 0);
}

int topPriorityQueue(_pqueue *filaP) {
    if (filaP->qtd > 0)
        return filaP->dados[0].dado;
    else
        return -1;
}

void balanceRemove(_pqueue *filaP, int pai) {
    int filho = pai * 2 + 1;

    if (filho >= filaP->qtd)
        return;

    if (filho + 1 < filaP->qtd && filaP->dados[filho].prioridade < filaP->dados[filho + 1].prioridade)
        filho++;

    if (filaP->dados[pai].prioridade >= filaP->dados[filho].prioridade)
        return;

    pqueue aux = filaP->dados[pai];
    filaP->dados[pai] = filaP->dados[filho];
    filaP->dados[filho] = aux;

    balanceRemove(filaP, filho);
}

void balanceInsert(_pqueue *filaP, int filho) {
    if (filho == 0)
        return;

    int pai = (filho - 1) / 2;

    if (filaP->dados[pai].prioridade >= filaP->dados[filho].prioridade)
        return;

    pqueue aux = filaP->dados[pai];
    filaP->dados[pai] = filaP->dados[filho];
    filaP->dados[filho] = aux;

    balanceInsert(filaP, pai);
}
