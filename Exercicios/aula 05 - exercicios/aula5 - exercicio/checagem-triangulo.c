/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Escreva um programa que, dados os comprimentos de tres segmentos de reta, determine se eles podem formar um triangulo e, em caso positivo, imprima se o triangulo e equilatero, isosceles ou escaleno.
 */
#include <stdio.h>
#include <math.h>

int main() {
    int l1, l2, l3;
    printf("Digite tres segmentos de reta.(Numeros inteiros apenas): ");
    scanf("%d %d %d", &l1, &l2, &l3);

    if ((l1 <= l2+l3) && (l2 <= l1+l3) && (l3 <= l1+l2)) {
        if (l1 == l2 && l1 == l3) {
            printf("Com esses tres segmentos voce obtem um triangulo equilatero\n");
        } else if ((l1 == l2 != l3) || (l2 == l3 != l1)) {
            printf("Com esses tres segmentos voce obtem um triangulo isociles\n");
        } else {

        }
    } else {
        printf("Não existe um triangulo formado por esse segmentos\n");
    }
    return 0;
}