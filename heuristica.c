#include "heuristica.h"

void insere(int vi, int vj, node **Grafo)
{
        node *i, *j;

        j = (node *)malloc(sizeof(node)); //aloca memoria pro novo nó
        j->vertice = vj;
        j->prox = NULL;

        if (Grafo[vi]->vertice == -5) //se o vértice não foi atribuido ainda, podemos inserir o nó na posicao vi
        {
                Grafo[vi] = j;
        }

        else
        {
                i = Grafo[vi]; //caminhamos até a ultima posicao disponivel para inserir o novo nó no atual->prox
                while (i->prox != NULL) {
                        i = i->prox;
                }
                i->prox = j;
        }
}

node **leGrafo(int nVertices, int nArestas)
{
        int i, vi, vj;

        node **Grafo = (node **)malloc((nVertices + 1) * sizeof(node *)); //aloca memoria para a lista de adj
        //motivação do "nVertices+1": precisamos começar a lista por 1, até nVertices
        for (i = 0; i <= nVertices; i++)
        {
                Grafo[i] = (node *)malloc(sizeof(node)); //aloca memoria pra cada indice da lista de adj
                Grafo[i]->prox = NULL;
                Grafo[i]->vertice = -5; //motivação do "-5": significa para o programa que o vértice ainda não foi atribuido
        }

        for (i = 0; i < nArestas; i++) //lê as arestas
        {
                scanf("%d %d", &vi, &vj);
                insere(vi, vj, Grafo);
                insere(vj, vi, Grafo); //insere bidirecionalmente
        }
        printf("\n--\n");
        return Grafo; //retorna ponteiro para o grafo
}

void geraRounds(int N, node **Grafo) {
        int result[N];
        result[0] = 0;
        int u;
        for(u = 1; u < N; u++) {
                result[u] = -1;
        }
        int available[N];
        int cr;
        for(cr = 0; cr < N; cr++) {
                available[cr] = 0;
        }

        for(u = 1; u < N; u++) {

                node *i = Grafo[u];
                int a = 0;
                while (i->prox != NULL) {
                        if(result[a] != -1)
                                available[result[a]] = 1;
                        i = i->prox;
                        ++a;
                }

                for(cr = 0; cr < N; cr++) {
                        if(available[cr] == 0)
                                break;
                }
                result[u] = cr;
                node *k = Grafo[0];
                a = 0;
                while(k != NULL) {
                        if(result[a] != -1)
                                available[result[a]] = 0;

                        a++;
                        k = k->prox;
                }

        }

        int c;
        for(c = 0; c < N; c++)
                printf("%d %d\n", c, result[c]);
}
