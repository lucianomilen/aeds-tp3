#include "bruta.h"

int encontraMaior (int *rounds, int N) {
        int maior = rounds[1], i;
        for(i = 1; i <= N; i++) {
                if(rounds[i] > maior)
                        maior = rounds[i];
        }
        return maior + 1;
}

int **leGrafo (int nVertices, int nArestas) {
  int i, u, v;
  int **Grafo = (int **)malloc((nVertices + 1) * sizeof(int *));

  for(i = 0; i <= nVertices; i++) {
          Grafo[i] = (int *)malloc((nVertices + 1) * sizeof(int));
  }

  int j;
  for(i = 1; i <= nVertices; i++){
    for(j = 1; j <= nVertices; j++){
      Grafo[i][j] = 0;
    }
  }

  for (i = 0; i < nArestas; i++) {
          scanf("%d %d", &u, &v);
          Grafo[u][v] = 1;
          Grafo[v][u] = 1;
  }

  return Grafo;
}

void geraValorRounds (int vertice_atual, int nVertices, int limite_sup, int *rounds, int **Grafo) {
        int j;
        while(1) {
                int vA = rounds[vertice_atual] + 1;
                int vB = limite_sup + 1;
                rounds[vertice_atual] = vA % vB;
                if(rounds[vertice_atual] == 0)
                        return;
                for(j = 1; j <= nVertices; j++) {
                        if(Grafo[vertice_atual][j] && rounds[vertice_atual] == rounds[j])
                                break;
                }
                if(j == nVertices + 1)
                        return;
        }
}

void percorre (int vertice_atual, int nVertices, int *rounds, int **Grafo) {
        int limite_sup = nVertices - 1;

        geraValorRounds(vertice_atual, nVertices, limite_sup, rounds, Grafo);

        if(rounds[vertice_atual] == 0)
                return;

        if(vertice_atual == nVertices)
                return;

        else {
                vertice_atual += 1;
                percorre(vertice_atual, nVertices, rounds, Grafo);
        }
}
