/* Henrique Noronha Facioli
 * RA : 157986
 * Semanada
 */

#include <stdio.h>

int main(){
    int D, R, numero[100], maior[100], i, j = 0, retirados = 0, ultimo_retirado = 0, flag = 1;
    /*Entrada de D, R e do Numero fornecido pelo pai e zera o vetor maior*/
    scanf("%d %d", &D, &R);
    for (i = 0;i < D; i++) {
        scanf("%d", &numero[i]);
        maior[i] = 0;
    }
    
    for(i = 0; i < D-R; i++){
        maior[i] = numero[j];
        flag = 1;
        while(j < D-retirados){
            j++;
            if(maior[i] < numero[j]){
                maior[i] = numero[j];
                retirados = retirados + (j - ultimo_retirado);
                ultimo_retirado = j;
                j++;
            }
        }
    }
    
    for(i = 0; i < D-R; i++){
        printf("%d",maior[i]);
    }
    return 0;
}
