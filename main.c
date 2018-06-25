#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node //estrutura recursiva de lista encadeada
{
    struct node *prox;
    int vertice; //identifica o valor do próximo nó
} node;

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

void colore(int N, node **Grafo) {
  int result[N];
  result[0] = 1;
  int u;
  for(u = 1; u < N; u++){
    result[u] = -1;
  }
  int available[N];
  int cr;
  for(cr = 0; cr < N; cr++){
    available[cr] = 0;
  }

  for(u = 1; u < N; u++){

    node *i = Grafo[u];
    int a = 1;
    while (i != NULL){
      if(result[a] != -1)
        available[result[a]] = 1;
      a++;
      i = i->prox;
    }

    for(cr = 1; cr < N; cr++){
      if(available[cr] == 0)
        break;
    }
    result[u] = cr;
    node *k = Grafo[0];
    a = 1;
    while(k != NULL){
      if(result[a] != -1)
        available[result[a]] = 0;

      a++;
      k = k->prox;
    }

  }

  int c;
  for(c = 0; c < N; c++)
    printf("\n%d %d\n", c+1, result[c]);
}

int main(int argc, char *argv[]){
        int nVertices, nArestas;
        scanf("%d %d", &nVertices, &nArestas);
        node **Grafo = leGrafo(nVertices, nArestas);
        colore(nVertices, Grafo);
      }

// void leGrafo();
//
// int **criaGrafo();
//
// int encontraMaior(int *color_tab, int N){
//   int maior = color_tab[1], i;
//   for(i = 1; i <= N; i++){
//     if(color_tab[i] > maior)
//       maior = color_tab[i];
//   }
//   return maior+1;
// }
//
// void Gen_Col_Value(int k,int N, int m, int *color_tab, int **G)
// {
//         int j;
//         while(1)
//         {
//                 int a=color_tab[k]+1;
//                 int b=m+1;
//                 color_tab[k] = a%b;
//                 if(color_tab[k]==0) return;
//                 for(j=1; j<=N; j++)
//                 {
//                         if(G[k][j] && color_tab[k]==color_tab[j])
//                                 break;
//                 }
//                 if(j==N+1) return;
//         }
// }
// void Gr_coloring(int k, int N, int *color_tab, int **G)
// {
//         int m = N - 1;
//         Gen_Col_Value(k, N, m, color_tab, G);
//         if(color_tab[k]==0) return;
//         if(k==N) return;
//         else Gr_coloring(k+1, N, color_tab, G);
// }
//
// int main()
// {
//         int v1, v2, i, N, M;
//         scanf("%d%d",&N,&M);
//         int **grafo = (int **)malloc((N + 1) * sizeof(int *));
//         for(i = 0; i <= N; i++){
//           grafo[i] = (int *)malloc(sizeof(int));
//         }
//         int *color_tab = (int*) malloc((N + 1) * sizeof(int));
//         for (i=1; i<=M; i++)
//         {
//                 scanf("%d %d", &v1, &v2);
//                 grafo[v1][v2] = grafo[v2][v1] = 1;
//         }
//         Gr_coloring(1, N, color_tab, grafo);
//         printf("\nResultado:\n");
//         for(i=1; i<=N; i++) {
//                 if(color_tab[i] == 0)
//                         color_tab[i] = encontraMaior(color_tab, N);
//                 printf("\n %d %d",i,color_tab[i]);
//         }
//         return 0;
// }
