//LUCIANO OTONI MILEN [2012079754]
#include "heuristica.h"

int main(int argc, char *argv[]){
        int nVertices, nArestas, *alocacaoRounds, c;
        FILE *alocacao = fopen("alocacao.txt", "w+"); //arquivos de saída
        FILE *rodada = fopen("rodada.txt", "w+");

        scanf("%d %d", &nVertices, &nArestas);

        alocacaoRounds = (int *) malloc(nVertices * sizeof(int));
        alocacaoRounds[0] = 0; //o primeiro vértice é o primeiro round ( = 0)

        node **Grafo = leGrafo(nVertices, nArestas);

        geraRounds(nVertices, Grafo, alocacaoRounds);
        liberaGrafo(Grafo, nVertices);

        for(c = 0; c < nVertices; c++)
                fprintf(alocacao, "%d %d\n", c+1, alocacaoRounds[c]+1); //+1 para fazer equivalência com os nós de entrada
        fprintf(rodada, "%d", encontraMaior(alocacaoRounds, nVertices));

        free(alocacaoRounds);
        fclose(alocacao);
        fclose(rodada);
        return 0;
}
