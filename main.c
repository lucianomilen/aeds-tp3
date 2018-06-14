#include <stdio.h>
#include <stdlib.h>

typedef struct node //estrutura recursiva de lista encadeada
{
    struct node *prox;
    int vertice; //identifica o valor do próximo nó
} node;

void DFS(node **Grafo, int nodeAtual, int *vNodeVisitados)
{
    node *p = Grafo[nodeAtual]; //inicializa um nó p do grafo na posicao atual de busca
    vNodeVisitados[nodeAtual] = 1; //visitamos o nó atual, logo o vetor de nós visitados é atualizado
    printf("%d\n", p->vertice);
    while (p != NULL) //percorre o grafo até seu fim
    {
        nodeAtual = p->vertice;
        if (!vNodeVisitados[nodeAtual]) //se não visitamos o nó atual e temos sua idade < 35
        {
            DFS(Grafo, nodeAtual, vNodeVisitados); //recursivamente entramos nas adjs do nó
        }
        p = p->prox; //vamos para o próximo nó
    }
}
void imprimeGrafo(node **Grafo, int n){
    int j;
    for (j = 1; j <= n; j++)
    {
        node *i = Grafo[j];
        while (i != NULL)
        {
            printf("\n%d vertice %d\n", j, i->vertice);
            i = i->prox;
        }
    }
}

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
    return Grafo; //retorna ponteiro para o grafo
}

int main(){
  int N, M;
  scanf("%d %d", &N, &M);
  node **Grafo = leGrafo(N, M);
  int *vNodeVisitados = (int*) malloc((N + 1) * sizeof(int)); //vetor para armazenar nós visitados pelo DFS
        int i;
        for (i = 0; i <= N; i++)
            vNodeVisitados[i] = 0;
        //memset(vNodeVisitados, 0, (size_t) (nVertices)); //inicializa o vetor de nós visitados como 0
        for(i = 1; i <= N; i++){
        DFS(Grafo, i, vNodeVisitados); //faz busca em profundidade no grafo
        vNodeVisitados[i] = 0;
        printf("\n\n");
        }
  // imprimeGrafo(Grafo, N);
  return 0;
}
