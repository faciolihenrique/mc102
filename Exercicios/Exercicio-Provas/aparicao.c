/* Henrique Noronha Facioli
 * RA : 157986
 * Dadas duas sequˆencias de n e m valores inteiros, onde n ≤ m, escrever um programa que verifique quantas vezes a primeira sequˆencia ocorre na segunda.
 */

#include <stdio.h>

#define TAMANHO 100

int main(){
    int n[TAMANHO], m[TAMANHO];
    int tam_n , tam_m, i, j, aparicao = 0, aux;
    
    printf("Digite o tamanho do vetor maior: (ate 100 numeros)");
    scanf("%d",&tam_m);
    printf("Digite o tamanho do vetor menor: ");
    scanf("%d",&tam_n);
    
    printf("Digite os termos do vetor maior: ");
    for(i = 0; i < tam_m; i++){
        scanf("%d",&m[i]);
    }
    printf("Digite os termos do vetor menor: ");    
    for(i = 0; i < tam_n; i++){
        scanf("%d",&n[i]);
        }
    
    for(i = 0; i < tam_m; i++){
        aux = i;
        j = 0;
        while(n[j] == m[aux]){
            j++;
            aux++;
            if(j == tam_n){
                aparicao++;
            }
        }

    }
    printf("%d\n", aparicao);
    
    return 0;
    
}
