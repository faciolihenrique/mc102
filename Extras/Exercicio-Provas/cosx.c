#include <stdio.h>
#include <math.h>

int main(){
    int k, i;
    double cosx = 1, x, fat = 1;
    printf("Digite o tamanho do angulo em radiano, e qual a precisao desejada");
    scanf("%lf %d",&x,&k);
    for(i = 1, j = 1; i < k ;i++, j += 2){
        
        cosx = cosx + (pow(-1,i)*pow(x,2*i))/fat;
    }
    printf("%f", cosx);
    printf("%d", fat);
    return 0;
}
