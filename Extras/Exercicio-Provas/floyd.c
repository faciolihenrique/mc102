#include <stdio.h>

int main(){
    int cont = 0, n, i, j;
    /*linha*/
    scanf("%d", &n);
    for(i = 1; i < n;i ++){
        for(j = 1; j <= i; j++){
            cont++;
            printf("%d ",cont);
        }
        printf("\n");
    }
    return 0;
}
