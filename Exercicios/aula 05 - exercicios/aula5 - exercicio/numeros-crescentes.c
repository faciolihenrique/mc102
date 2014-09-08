/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Escreva um programa que le tres numeros inteiros e imprime o menor deles.
 * Escreva um programa que lˆe trˆes nu ́meros inteiros e os imprime em ordem crescente.
 */

#include <stdio.h>

int numeros(){
    int a, b, c;
    printf("Digite tres numeros naturais: \n");
    scanf("%d %d %d", &a, &b, &c);
    if (a >= b && a >=c) {
        if (b >= c) {
            printf(" Em ordem crescente, os numeros digitados são %d, %d, %d\n", c, b, a);
        }else{
            printf("Em ordem crescente, os numeros digitados são %d, %d, %d\n", b, c, a);
        }
    }else if (b >= a && b >= c){
        if (a >= c) {
            printf("Em ordem crescente, os numeros digitados são %d, %d, %d\n", c, a, b);
        }else{
            printf("Em ordem crescente, os numeros digitados são %d, %d, %d\n", a, c, b);
        }
    }else{
        if (b >= a) {
            printf("Em ordem crescente, os numeros digitados são %d, %d, %d\n", a, b, c);
        }else {
            printf("Em ordem crescente, os numeros digitados são %d, %d, %d\n", b, a, c);
        }
    }
    return 0;
}