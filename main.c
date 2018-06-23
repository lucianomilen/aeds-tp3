#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leGrafo();

int **criaGrafo();

void Gen_Col_Value(int k,int N, int m, int *color_tab, int **G)
{
        int j;
        while(1)
        {
                int a=color_tab[k]+1;
                int b=m+1;
                color_tab[k] = a%b;
                if(color_tab[k]==0) return;
                for(j=1; j<=N; j++)
                {
                        if(G[k][j] && color_tab[k]==color_tab[j])
                                break;
                }
                if(j==N+1) return;
        }
}
void Gr_coloring(int k, int N, int *color_tab, int **G)
{
        int m = N - 1;
        Gen_Col_Value(k, N, m, color_tab, G);
        if(color_tab[k]==0) return;
        if(k==N) return;
        else Gr_coloring(k+1, N, color_tab, G);
}

int main()
{
        int v1, v2, i, N, M;
        scanf("%d%d",&N,&M);
        int **grafo = (int **)malloc((N) * sizeof(int *));
        for(i = 0; i <= N; i++){
          grafo[i] = (int *)malloc(sizeof(int));
        }
        int *color_tab = (int*) malloc((N) * sizeof(int));
        for (i=1; i<=M; i++)
        {
                scanf("%d %d", &v1, &v2);
                grafo[v1][v2] = grafo[v2][v1] = 1;
        }
        Gr_coloring(1, N, color_tab, grafo);
        printf("\nResultado:\n");
        for(i=1; i<=N; i++) {
                if(color_tab[i] == 0)
                        color_tab[i] = i;
                printf("\n %d %d",i,color_tab[i]);
        }
        return 0;
}
