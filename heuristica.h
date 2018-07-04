//LUCIANO OTONI MILEN [2012079754]
#ifndef HEURISTICA
#define HEURISTICA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node //estrutura recursiva de lista encadeada
{
        struct node *prox;
        int vertice; //identifica o valor do próximo nó
} node;

void insere(int vi, int vj, node **Grafo);

node **leGrafo(int nVertices, int nArestas);

void liberaGrafo(node **Grafo, int nVertices);

void geraRounds(int N, node **Grafo, int *alocacao);

int encontraMaior (int *alocacao, int nVertices);

void percorre (int vertice_atual, int nVertices, int *rounds, int **Grafo);

#endif
