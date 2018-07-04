//LUCIANO OTONI MILEN [2012079754]
#include "bruta.h"

int main(int argc, char *argv[]) {
        int i, nVertices, nArestas;
        FILE *alocacao = fopen("alocacao.txt", "w+"); //arquivos de saída
        FILE *rodada = fopen("rodada.txt", "w+");
        scanf("%d", &nVertices);
        scanf("%d", &nArestas);

        int **Grafo = leGrafo(nVertices, nArestas);

        int rounds[nVertices]; //serão no máximo nVertices rounds

        int vertice_inicial = 1; //começa pelo começo

        for(i = 1; i <= nVertices; i++){
          rounds[i] = 0; //zera os rounds disponíveis
        }

        percorre(vertice_inicial, nVertices, rounds, Grafo); //percorre o grafo alocando os rounds e verificando vértices adjacentes

        for(i = 1; i <= nVertices; i++) {
                if(rounds[i] == 0) //o algoritmo define 0 para o round maior. a função encontraMaior corrige o nº do round
                        rounds[i] = encontraMaior(rounds, nVertices);
                fprintf(alocacao, "%d %d\n", i, rounds[i]); //imprime no arquivo
        }

        for(i = 0; i <= nVertices; i++)
          free(Grafo[i]);
        free(Grafo); //libera as memórias alocadas

        fprintf(rodada, "%d", encontraMaior(rounds, nVertices) - 1);
        fclose(alocacao);
        fclose(rodada);

        return 0;

}
