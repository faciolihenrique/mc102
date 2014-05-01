/* Henrique Noronha Facioli
 * RA : 157986
 * Lab 07a - The Voice - Blind Auditions
 */

#include <stdio.h>

int main(){
    /*Desclaracao de variaveis*/
    int N;
    int dados[100][8], grupo[100][4];
    int i, j, achou, aux;
    
    /*Leitura dos dados fornecidos*/
    scanf("%d", &N);
    
    for(i = 0 ; i < N; i++){
        for(j = 0; j < 8; j++){
            scanf("%d", &dados[i][j]);
        }
    }
    
    /*zera todas as posicoes da matriz grupo*/
    for(i = 0; i < N; i++){
        for(j = 0; j < 4; j++){
            grupo[i][j] = 0;
        }
    }
    
    /*Compara , a partir da 4a colunas ( preferencia) se a posicao escrita 
     *do numero dessa colunas lida, contem 1; se sim, salva na matriz 'grupo'
     *a posicao desse vetor lido, criando uma matriz 'grupo', 4xN, que em cada
     *linha significa o numero do candidato e as colunas a coluna o grupo que entrou
     */
    
    for(i = 0; i < N; i++){
        achou = 0;
        for(j = 0;j < 4 && !achou; j++){
            aux = dados[i][j+4] - 1;
            if(dados[i][aux]){
                grupo[i][aux] = 1;
                achou = 1;
            }
            
        }
    }
    
    /*Impressao da saida, checando coluna por coluna da matriz 'grupo'
     *e quando a valor for 1, o participante esta no grupo
     */
    for(i = 0; i < 4; i++){
        achou = 0;
        printf("Time %d:", i+1);
        for(j = 0; j < N; j++){
            if(grupo[j][i] == 1){
                printf(" %d",j+1);
                achou = 1;
            }else if(!achou && j == N-1){
                printf(" Nenhum participante");
            }
                
        }
        printf("\n");
        
    }
    
    return 0;
}
