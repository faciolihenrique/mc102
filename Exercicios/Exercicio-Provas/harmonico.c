#include <stdio.h>

int main(){
    double harmonico, i, numero;
    scanf("%lf", &numero);
    for(i = 1, harmonico = 0;i <= numero;i++){
        harmonico = harmonico + (1/i);
    }
    printf("%lf", harmonico);
    return 0;
}
