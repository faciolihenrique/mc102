/* Henrique Noronha Facioli
 * RA : 157986
 * Lab 08a - Amigos dos amigos
 */

#include <stdio.h>

#define TAM 100

int main(){
    /*Declaracao de variaveis*/
    int N, U;
    int i, j, achou = 0;
    /*Declaracao da matriz que contem os amigos*/
    int matriz_amigos[TAM][TAM];
    /*Declaracao dos vetores que armazenarao que sao os amigos de U, 
     *e quem sao os amigos dos amigos de U
     */
    int amigos_U[TAM],amigos_amigos[TAM];
    

    /*Leitura do numero de usuarios, do usuario escolhido*/
    scanf("%d %d", &N, &U);
    /*Zera o vetor amigos_U e nao_amigos_U*/
    for(i = 0;i < N;i++){
        amigos_U[i] = 0;
        amigos_amigos[i] = 0;
    }
    /*Leitura da matriz de amigos*/
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &matriz_amigos[i][j]);
        }
    }
    /*Descobre quem são os amigos do usuario*/
    for(i = 0; i < N; i++){
        if(matriz_amigos[U][i]){
            amigos_U[i] = 1;
        }
    }
    
    /*Funcão que seleciona os amigos do usuario selecionado e ve se são os mesmos do usuario,
     * se nao sao, os coloca na matriz amigos_amigos*/
    for(i = 0; i < N; i++){
        /*Se for amigo do usuario, ele entra no loop*/
        if(amigos_U[i] == 1){
            for(j = 0; j < N; j++){
                /*Se tiver 1, na posicao i,j da matriz e nao tiver 1 na posicao i do vetor amigos, 
                 *eh porque o amigo do amigo de U nao eh amigo de U*/
                if(matriz_amigos[i][j] && !amigos_U[j]){
                    amigos_amigos[j] = 1;
                }
            }
        }
    }
    
    /*Impressao da saida, que imprime, respectivamente 
     *1o-Caso ache algum 1 na vo vetro amigos_amigo
     *2o-caso ja tenha encontrado algum 1 em amigos_amigos
     *3o-caso nao tenha encontrado nenhum 1 ateh o ultimo numero
     */
    for(i = 0;i < N; i++){
        if(amigos_amigos[i] && !achou){
            achou = 1;
            printf("Sugestao de amigos: %d", i);
        }else if(amigos_amigos[i] && achou){
            printf(" %d", i);
        }else if(i == N-1 && !achou){
            printf("Sem sugestao de novos amigos");
        }
    }
    printf("\n");    
    
    return 0;
}
