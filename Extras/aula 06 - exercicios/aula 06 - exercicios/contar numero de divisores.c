/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Escreva um programa que le um número inteiro positivo e imprima numero de divisores de n.
 */

#include <stdio.h>

int numdiv(){
    int d, num, i;
    scanf("%d",&num);
    for (i = 1, d = 1; i <= num/2; i++) {
        if (num % i == 0) {
            d++;
        }
    }
    printf("%d\n",d);
    return 0;
}
