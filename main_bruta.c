#include "bruta.h"

int main(int argc, char *argv[]) {
        int i, N, M;
        FILE *alocacao = fopen("alocacao.txt", "w+");
        FILE *rodada = fopen("rodada.txt", "w+");
        scanf("%d %d",&N, &M);

        int **Grafo = leGrafo(N, M);

        int *rounds = (int*) malloc((N + 1) * sizeof(int));

        int vertice_inicial = 1;

        percorre(vertice_inicial, N, rounds, Grafo);

        for(i = 1; i <= N; i++) {
                if(rounds[i] == 0)
                        rounds[i] = encontraMaior(rounds, N);
                fprintf(alocacao, "%d %d\n", i, rounds[i]);
        }

        fprintf(rodada, "%d", encontraMaior(rounds, N) - 1);
        fclose(alocacao);
        fclose(rodada);

        return 0;

}
// #define MAX 250
//
// void geraCombinacao(int j){
//   int *num ;
//   char matriz[MAX][MAX];
//   /* input é a string de entrada, e str
//    * receberá cada permutação.
//    */
//   char input[MAX], str[MAX] ;
//   int n, r, i, k ;
//
//   // printf("Entre com o conjunto inicial: ") ;
//   // scanf("%s", input) ;
//
//   for( i = 0; i < j; i++ ){
//     input[i] = i + 1 + '0';
//   }
//
//   r = j;
//
//   /* Aqui elimina-se caracteres repetidos na entrada.
//    * Esse procedimento não faz parte do algoritmo, e
//    * só é feito por questões práticas.
//    */
//   n = strlen(input) ;
//   j = 0;
//   str[0] = 0 ;
//   for ( i = 0; i < n; i++ ) {
//       if ( strchr(str, input[i]) == NULL ) {
//           str[j] = input[i] ;
//           j++ ;
//           str[j] = 0 ;
//       }
//   }
//   strcpy(input, str) ;
//   n = strlen(input) ;
//
//   /* Cria o nosso número. Ele é um vetor de
//    * r+1 posições, sendo que a última é
//    * reservada para indicar quando todos os
//    * números de tamanho r foram gerados. */
//   num = (int *) calloc( (r+1), sizeof(int)) ;
//
//   /* Termina quando a última posição do vetor
//    * for 1. */
//    int q = 0;
//   while ( num[r] == 0 ) {
//       for ( i = 0; i < n; i++ ) {
//           /* processo de mapeamento. */
//           for ( j = 0, k = r-1; j < r; j++ ) {
//               str[k] = input[num[j]] ;
//               k-- ;
//           }
//           /* Mostra o resultado. */
//           str[r] = 0 ;
//           strcpy(matriz[q], str);
//
//           /* incrementa o algarismo menos significativo. */
//           num[0]++ ;
//       }
//       q++;
//
//       /* Muda de "casa" e lança os vai uns. */
//       for ( i = 0; i < r; i++ ) {
//           if ( num[i] == n ) {
//               num[i] = 0 ;
//               num[i+1]++ ;
//           }
//       }
//   }
//   for( i = 0; i < n; i++)
//   printf("%s\n", matriz[i]) ;
//
// }
//
// int main() {
//     /* Nosso número na base n. Ele é um vetor
//      * de n+1 posições representando um número
//      * na base n.
//      */
//     geraCombinacao(5);
//
//     return 0 ;
// }
