/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Escreva um programa que le um numero inteiro n ≥ 1 e que compute e imprima o valor
 de somatorio de i, i=1 ate j; sendo um valor por linha
 Nao use formulas, tal como a soma de uma progressao aritmetica.
 */
#include <stdio.h>

int somatorio2(){
    int i = 1, n, som = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        som = som+ i;
        printf ("%d\n",som);
    }
    return 0;
}