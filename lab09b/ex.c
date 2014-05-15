/* Henrique Noronha Facioli
 * RA : 157986
 * 
 */

#include <stdio.h>

#define TAM 30

void ordenacao_matriz(float matriz[5][TAM], int k, float matriz_saida[5][TAM]);
void troca(float *a, float *b);
float media_participante(float matriz[5][TAM], int j);

int main(){
    /*Declaracao de variaveis*/
    float matriz[5][TAM], media[TAM], matriz_ordenada[5][TAM];
    int K;
    int i, j;
    
    /*Leitura da variavel K*/
    scanf("%d", &K);
    /*Leitura da matriz*/
    for(i = 0; i < 5; i++){
        for(j = 0; j < K; j++){
            scanf("%f", &matriz[i][j]);
        }
    }
    
    /*Cria a matriz_ordenada*/
    for(i = 0; i < 5; i++){
        for(j = 0; j < K; j++){
            matriz_ordenada[i][j] = j;
        }
    }
    
    /*Calcula a media de cada participante*/
    for(i = 0; i < K; i++){
        media[i] = media_participante(matriz, i);
    }
    
    /*Organiza a matriz em ordem crescente*/
    ordenacao_matriz(matriz, K, matriz_ordenada);
    
    
    
    /*Impressao da nota media*/
    printf("Nota Média:");
    for(j = 0;j < K; j++){        
        printf(" %.1f", media[j]);
    }
    printf("\n");
    
    /*Impressao matriz ordenada*/
    printf("Preferencia:\n");
    for(i = 0;i < 5; i++){
        printf("Membro %d", i+1);
        for(j = 0;j < K; j++){
            printf(" %f", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;

}

float media_participante(float matriz[5][TAM], int j){
    int i;
    float soma = 0;
    for(i = 0 ;i < 5; i++){
        soma = soma + matriz[i][j];
    }
    return (soma/5);
}

/*Ordena a linha j fornecida pelo usuario salvando-a na matriz_saida*/
void ordenacao_matriz(float matriz[5][TAM], int k, float matriz_saida[5][TAM]){
    int a, b, i, maior; 
    float aux;
    /*Primeiro for para modificar as linhas*/
    for(i = 0;i < 5; i++){
        /*Funcao SELECTION SORT*/

    }
}

void ordenaçao(){
    int a, b, maior;
    for(a = 0; a < (k-1); a++){
        maior = a;
        for(b = (a+1); b < k; b++){
            if(matriz[i][b] > matriz[i][maior]){
                maior = b;
            }
        }
        if(a != maior){
            aux = matriz[i][a];
            matriz[i][a] = matriz[i][maior];
            matriz[i][maior] = aux;
        }
    
    }
}

void preferencia(float matriz_preferencia[5][TAM], pref[TAM], int k){
    int i, aux[TAM];
    for(i = 0; i < k; i++){
        zerar(pref, k);
        for(j = 0; j < 5; j++){
            aux[(matriz_preferencia[j][i]-1)] = 1;
        }
        
    }
}

/*Trocar posição*/
void trocar(float *a, float *b){
    float aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/*Zerar vetor*/
void zerar(int vetor[], int k){
    int i;
    for(i = 0; i < k; i++){
        vetor[i] = 0;
    }
}

/*Checagem de vetor*/
void(int vetor[5])