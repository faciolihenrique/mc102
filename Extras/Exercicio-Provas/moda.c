/* Henrique Noronha Facioli
 * RA : 157986
 * Indicar moda
 */

#include <stdio.h>

int main(){
    int moda[101];
    int i, n, numero;
    /*Zera o vetor*/
    for(i = 0; i < 101; i++ ){
        moda[i] = 0;
    }
    printf("Quantos numero voce deseja digitar (1 ~ 100)?");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d", &numero);
        moda[numero]++;
    }
    for(i = 1; i < 101; i++){
        if(moda[i] >= moda[0]){
            moda[0] = i8;
        }
    }
    printf("A moda e' %d", moda[0]);
    return 0;
}
