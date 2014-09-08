/* Henrique Noronha Facioli
 * RA : 157986
 * Escreva um programa que leia uma cadeia de caracteres de at ́e 80 caracteres e teste se ela  ́e um pal ́ındromo.
 */

#include <stdio.h>

int main(){
    char cadeia[80],cadeia_e[80];
    int i, j;
    
    fgets(cadeia, 80, stdin);
    
    /*Retirar os espacos do vetor caso ele seja digitado*/
    for(i = 0, j = 0; i != '\0';i++, j++){
        if(cadeia[i] != 'n'){
            cadeia[i] = cadeia_e[j];
        }else{
            j--;
        }
    }
    
    printf("%s", cadeia_e);
    
    return 0;
}
