/* Henrique Noronha Facioli
 * RA : 157986
 * 
 */

#include <stdio.h>

int main(){
    int numeros[100];
    int par = 0, impar = 0, i, n;
    printf("Quantos numeros serao digitados?");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d", &numeros[i]);
        if(numeros[i]%2 == 1){
            impar++;
        }else{
            par++;
        }
    }
    printf("Impar : %d | Par : %d", impar, par);
    return 0;
}
