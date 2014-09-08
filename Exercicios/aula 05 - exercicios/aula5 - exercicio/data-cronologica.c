/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Escreva um programa que, dadas duas datas, determine qual delas ocorreu cronologicamente primeiro. Cada data e composta de 3 numeros inteiros, um representando o dia, outro o mˆes e outro o ano.
 */

#include <stdio.h>

int data(){
    int d1, d2, m1, m2, a1, a2;
    printf("Entre uma data no formato dd mm aaaa : ");
    scanf("%d/%d/%d", &d1, &m1, &a1);
    printf("Entre outra data no formato dd mm aaaa : ");
    scanf("%d/%d/%d", &d2, &m2, &a2);

    if (a1 > a2) {
        printf("A maior data é : %d/%d/%d\n",d1, m1, a1);
    } else if (a1 < a2) {
         printf("A maior data é : %d/%d/%d\n",d2, m2, a2);
    } else{
         if (m1 < m2){
             printf("A maior data é : %d/%d/%d\n",d2, m2, a2);
        } else if (m1 > m2){
            printf("A maior data é : %d/%d/%d\n",d1, m1, a1);
        } else {
            if (d1 < d2) {
                printf("A maior data é : %d/%d/%d\n",d2, m2, a2);
            } else if (d1 > d2) {
                printf("A maior data é : %d/%d/%d\n",d1, m1, a1);
            } else {
                printf("As duas datas são iguais\n");
            }
        }
    }
    return 0;
}