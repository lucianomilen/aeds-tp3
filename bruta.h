#ifndef BRUTA
#define BRUTA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encontraMaior (int *rounds, int N);

int **leGrafo (int nVertices, int nArestas);

void geraValorRounds (int vertice_atual, int nVertices, int limite_sup, int *rounds, int **Grafo);

void percorre (int vertice_atual, int nVertices, int *rounds, int **Grafo);

#endif
