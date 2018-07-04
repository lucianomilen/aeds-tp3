//LUCIANO OTONI MILEN [2012079754]
#include "heuristica.h"

int encontraMaior (int *alocacao, int nVertices) {
        int maior = alocacao[0], i; //encontra o maior round do vetor de alocação de rounds
        for(i = 0; i < nVertices; i++) {
                if(alocacao[i] > maior)
                        maior = alocacao[i];
        }
        return maior + 1; // + 1 para encontrar o maior round correto
}

void insere(int vi, int vj, node **Grafo) {
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
                insere(vi-1, vj-1, Grafo); // -1 para ocupar menos espaço
                insere(vj-1, vi-1, Grafo); //insere bidirecionalmente
        }
        return Grafo; //retorna ponteiro para o grafo
}

void liberaGrafo(node **Grafo, int nVertices)
{
        int j = nVertices;
        while(j >= 0) //começa liberando o grafo pela ultima posição da lista
        {
                node *head = Grafo[j];
                while (head != NULL)
                {
                        node *tmp = head;
                        head = head->prox;
                        free(tmp);
                }
                j--;
                free(head);
        }
        free(Grafo); //libera o grafo no geral
}

void geraRounds(int nVertices, node **Grafo, int *alocacao) {
        int i;
        for(i = 1; i < nVertices; i++) {
                alocacao[i] = -5; //significa que o servidor ainda não foi alocado
        }
        int *rounds = (int *) malloc(nVertices * sizeof(int));
        int countRound;
        for(countRound = 0; countRound < nVertices; countRound++) {
                rounds[countRound] = 0; //o round está disponível para atualizar (= 0)
        }

        for(i = 1; i < nVertices; i++) {
                node *aux = Grafo[i];
                while (aux != NULL) {
                        if(alocacao[aux->vertice] != -5) { //se já foi alocado,
                                rounds[alocacao[aux->vertice]] = 1; //marca o round como indisponivel para o vértice
                        }
                        aux = aux->prox;
                }

                for(countRound = 0; countRound < nVertices; countRound++) {
                        if(rounds[countRound] == 0) { //o round está disponível para alocar o servidor
                                break;
                        }
                }
                alocacao[i] = countRound; //atribui o round ao servidor

                aux = Grafo[i];
                while(aux != NULL) {
                        if(alocacao[aux->vertice] != -5) { //se já foi alocado,
                                rounds[alocacao[aux->vertice]] = 0; //zera o vetor para a próxima rodada
                        }
                        aux = aux->prox;
                }

        }
        free(rounds); //libera o vetor de rounds
}
