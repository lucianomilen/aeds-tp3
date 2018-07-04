//LUCIANO OTONI MILEN [2012079754]
#include "bruta.h"

int encontraMaior (int *rounds, int N) {
        int maior = rounds[1], i; //encontra o maior valor dos rounds
        for(i = 1; i <= N; i++) {
                if(rounds[i] > maior)
                        maior = rounds[i];
        }
        return maior + 1; // + 1 para fazer a equivalẽncia com os vértices
}

int **leGrafo (int nVertices, int nArestas) {
        int i, u, v;
        int **Grafo = (int **)malloc((nVertices + 1) * sizeof(int *)); //armazena numa matriz de ajacências os vértices de entrada

        for(i = 0; i <= nVertices; i++) {
                Grafo[i] = (int *)malloc((nVertices + 1) * sizeof(int));
        }

        int j;
        for(i = 1; i <= nVertices; i++) {
                for(j = 1; j <= nVertices; j++) {
                        Grafo[i][j] = 0; //inicializa os valores do grafo como 0 para populá-lo depois
                }
        }

        for (i = 0; i < nArestas; i++) {
                scanf("%d %d", &u, &v);
                Grafo[u][v] = 1; //bidirecional...
                Grafo[v][u] = 1;
        }

        return Grafo;
}

void geraValorRounds (int vertice_atual, int nVertices, int limite_sup, int *rounds, int **Grafo) {
        int j;
        while(1) { //loop infinito que para quando o round está disponível
                int vA = rounds[vertice_atual] + 1;
                int vB = limite_sup + 1;
                rounds[vertice_atual] = vA % vB; // a próxima maior cor disponível
                if(rounds[vertice_atual] == 0)
                        return; //os rounds foram escolhidos
                for(j = 1; j <= nVertices; j++) {
                        if(Grafo[vertice_atual][j] && rounds[vertice_atual] == rounds[j]) //verifica se o round definido é diferente dos escolhidos para os vértices adjacentes
                                break;
                }
                if(j == nVertices + 1) { //um novo round foi necessário
                        return;
                }
        }
}

void percorre (int vertice_atual, int nVertices, int *rounds, int **Grafo) {
        int limite_sup = nVertices - 1; //o limite para verificar os rounds

        geraValorRounds(vertice_atual, nVertices, limite_sup, rounds, Grafo);

        if(rounds[vertice_atual] == 0) // finaliza alocação
                return;

        if(vertice_atual == nVertices) // todos os rounds foram alocados com servidores
                return;

        else {
                vertice_atual += 1; //percorre o próxmo vértice para alocar o round corretamente
                percorre(vertice_atual, nVertices, rounds, Grafo);
        }
}
