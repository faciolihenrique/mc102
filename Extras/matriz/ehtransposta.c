/* Henrique Noronha Facioli
 * RA : 157986
 * 
 */

#include <stdio.h>

#define TAM 100

int main(){
    int matriz[TAM][TAM];
    int tam, i, j;
    scanf("%d", &tam);
    for(i =0; i< tam; i++){
        for(j = 0; j < tam; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for(i =0; i< tam; i++){
        for(j = 0; j < tam; j++){
            if(matriz[i][j] != matriz[j][i]){
                printf("nao transposta");
                return 0;
            }
        }
    }
    printf("transposta");
    return 0;

}
