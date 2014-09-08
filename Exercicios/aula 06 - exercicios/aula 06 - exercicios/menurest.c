/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Escreva um programa que imprima um menu com o nome de 4 pratos e uma quinta opcao
 para sair do programa. O programa deve imprimir a descricao do prato solicitado e 
 deve terminar quando a quinta opcao for escolhida. 
 */

#include <stdio.h>

int menu(){
    int prato;
    do {
        printf("1-Prato-1\n2-Prato-2\n3-Prato-3\n4-Prato-4\n5-Sair\nDigite a opçao desejada: ");
        scanf("%d",&prato);
        if (prato == 1) {
            printf("\nPrato 1 = blablabla\n\n");
        }else if (prato == 2){
            printf("\nPrato 2 = blablabla\n\n");
        }else if (prato == 3){
            printf("\nPrato 3 = blablabla\n\n");
        }else if (prato == 4){
            printf("\nPrato 4 = blablabla\n\n");
        }
    } while (prato != 5);
    return 0;
}