/* Henrique Noronha Facioli
 * RA : 157986
 * Implemente as operacoes de soma, subtracao, multiplicacao e transposicao de matrizes quadradas n × n.
 */

#include <stdio.h>

#define TAM 100

int main(){
    /*Declaracao de variaveis; i sera linha, j sera coluna, k sera auxiliar para a multiplicacao*/
    int matriz_1[TAM][TAM], matriz_2[TAM][TAM], soma[TAM][TAM], sub[TAM][TAM], mult[TAM][TAM], trans_1[TAM][TAM], trans_2[TAM][TAM];
    int i, j, k, tamanho;
    
    /*Entrada das Matrizes*/
    printf("Qual o tamanho da matriz quadrada?\n");
    scanf("%d", &tamanho);
    
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            printf("Digite o numero da posicao %dx%d :",i+1 , j+1);
            scanf("%d", &matriz_1[i][j]);
        }
    }
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            printf("Digite o numero da posicao %dx%d :",i+1 , j+1);
            scanf("%d", &matriz_2[i][j]);
        }
    }
    
    printf("Primeira Matriz :\n");
    for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++)
        printf("%d ", matriz_1[i][j]);
      printf("\n");
    }
    
    printf("Segunda Matriz :\n");
    for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++)
        printf("%d ", matriz_2[i][j]);
      printf("\n");
    }
    printf("\n");
    
    /*Soma*/
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            soma[i][j] = (matriz_1[i][j] + matriz_2[i][j]);
        }
    }
     
    /*Subtracao*/
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            sub[i][j] = matriz_1[i][j] - matriz_2[i][j];
        }
    }
    
    /*Multiplicacao*/
    /* Primeiro zeramos a matriz mult, ja que a multiplicacao depende da soma*/
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            mult[i][j] = 0;
        }
    }
    /*Multiplica*/
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            for(k = 0; k < tamanho; k++){
                mult[i][j] = mult[i][j] + matriz_1[i][k]*matriz_2[k][j];
            }
        }
    }
    
    /*Transpoisicao*/
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            trans_1[i][j] = matriz_1[j][i];
            trans_2[i][j] = matriz_2[j][i];
        }
    }
    
    /*Impressao das matrizes*/
    
    printf("Matriz soma:\n");
    for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++)
        printf("%d ", soma[i][j]);
      printf("\n");
    }
    printf("Matriz subtracao:\n");
    for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++)
        printf("%d ", sub[i][j]);
      printf("\n");
    }
    printf("Matriz multiplicacao:\n");
    for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++)
        printf("%d ", mult[i][j]);
      printf("\n");
    }
    printf("Matriz transposta 1:\n");
    for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++)
        printf("%d ", trans_1[i][j]);
      printf("\n");
    }
    printf("Matriz transposta 2:\n");
    for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++)
        printf("%d ", trans_2[i][j]);
      printf("\n");
    }
    
    return 0;
    
}

