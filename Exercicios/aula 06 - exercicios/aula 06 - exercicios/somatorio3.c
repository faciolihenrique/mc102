/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Escreva um programa que le um numero inteiro n ≥ 1 e que compute e imprima o valor
 de somatorio de somatorio, i=1 ate j, com j até n
 Nao use formulas, tal como a soma de uma progressao aritmetica.
 (Somatorio das somas das linhas do somatorio2)
 */

#include <stdio.h>

int main(){
    int i = 1, n, som = 0, som2 = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        som = som + i;
        som2 = som2 + som;
        printf ("%d\n",som2);
    }
    return 0;
}