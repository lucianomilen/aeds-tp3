#include "heuristica.h"

int main(int argc, char *argv[]){
        int nVertices, nArestas;
        scanf("%d %d", &nVertices, &nArestas);
        node **Grafo = leGrafo(nVertices, nArestas);
        geraRounds(nVertices, Grafo);
}
