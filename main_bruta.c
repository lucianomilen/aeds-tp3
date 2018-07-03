#include "bruta.h"

int main(int argc, char *argv[]) {
        int i, N, M;
        FILE *alocacao = fopen("alocacao.txt", "w+");
        FILE *rodada = fopen("rodada.txt", "w+");
        scanf("%d", &N);
        scanf("%d", &M);

        int **Grafo = leGrafo(N, M);

        printf("%d\n", N);

        int rounds[N];

        int vertice_inicial = 1;

        for(i = 1; i <= N; i++){
          rounds[i] = 0;
        }

        percorre(vertice_inicial, N, rounds, Grafo);

        for(i = 1; i <= N; i++) {
                if(rounds[i] == 0)
                        rounds[i] = encontraMaior(rounds, N);
                fprintf(alocacao, "%d %d\n", i, rounds[i]);
        }

        for(i = 0; i <= N; i++)
          free(Grafo[i]);
        free(Grafo);

        fprintf(rodada, "%d", encontraMaior(rounds, N) - 1);
        fclose(alocacao);
        fclose(rodada);

        return 0;

}
