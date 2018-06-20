#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct Q
{
 int data[MAX];
 int R,F;
}Q;

int empty(Q *P)
{
        if(P->R==-1)
                return(1);
        return(0);
}

int full(Q *P)
{
        if(P->R==MAX-1)
                return(1);
        return(0);
}

void enqueue(Q *P,int x)
{
        if(P->R==-1)
        {
                P->R=P->F=0;
                P->data[P->R]=x;
        }
        else
        {
                P->R=P->R+1;
                P->data[P->R]=x;
        }
}

int dequeue(Q *P)
{
        int x;
        x=P->data[P->F];
        if(P->R==P->F)
        {
                P->R=-1;
                P->F=-1;
        }
        else
                P->F=P->F+1;
        return(x);
}

typedef struct node //estrutura recursiva de lista encadeada
{
        struct node *prox;
        int vertice; //identifica o valor do próximo nó
} node;

void BFS(int v, int n, node **G)
{
        int w,i,visited[MAX];
        Q q;

        node *p;
        q.R=q.F=-1;       //initialise
        for(i=0; i<=n; i++)
                visited[i]=0;
        enqueue(&q,v);
        printf("\nVisit\t%d",v);
        visited[v]=1;
        while(!empty(&q))
        {
                v=dequeue(&q);
                //insert all unvisited,adjacent vertices of v into queue
                for(p=G[v]; p!=NULL; p=p->prox)
                {
                        w=p->vertice;
                        if(visited[w]==0)
                        {
                                enqueue(&q,w);
                                visited[w]=1;
                                printf("\nvisit\t%d",w);
                        }
                }
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
          BFS(1, N, Grafo); //faz busca em profundidade no grafo
          // vNodeVisitados[i] = 0;
        // imprimeGrafo(Grafo, N);
        return 0;
}
