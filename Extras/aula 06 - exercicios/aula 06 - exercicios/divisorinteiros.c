/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Escreva um programa que lˆe um nu ́mero inteiro positivo e imprima os divisores de n. 
 */

#include <stdio.h>

int divisor(){
    int n, i;
    scanf("%d",&n);
    for (i = 1; i <= n/2; i++) {
        if (n % i == 0){
            printf("%d é um divisor de %d\n",i ,n);
        }
    }
    printf("%d é divisor de %d\n",n ,n);
    return 0;
}


/* Solucao zanoni*/
int main2() {
    int i, n;
    printf("Entre com um inteiro positivo: ");
    scanf("%d", &n);
    for (i = 1; i <= n / 2; i++)
        if (n % i == 0)
            printf("%d\n", i);
    printf("%d\n", n);
    return 0;
}