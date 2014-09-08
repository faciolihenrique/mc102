/* Henrique Noronha Facioli
 * 157986 
 * Lab 05a - Caça ao Tesouro
 */

#include <stdio.h>

int main(){
    /*Declaracao de variaveis
     *trilha sao os numeros da trilha
     *n eh o tamanho da trilha
     *i e j sao contadores
     *valor corresponde ao valor do vetor, na posicao que a dica mandar
     *dica eh a posicao do vetor que esta o valor
     */
    int trilha[101];
    int n, i , j, flag = 1, valor, dica;
    /*Entrada de quantos numeros exitem na trilha e quais sao eles*/
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d", &trilha[i]);
    }
    
    /*Entra em loop para comparar a posicao do numero com o seu valor
     *se forem iguais, existe o tesouro, se nao achar em ate n veses
     * que o loop rodar, nao existe tesouro
     */
    i = 1;
    j = 0;
    while(flag){
        dica  = trilha[i];
        valor = trilha[dica];
        if(dica == valor){
            printf("Tesouro existe em %d\n", dica);
            flag = 0;
        }
        i = valor;
        j++;
        if(j >= n){
            printf("Nao existe tesouro\n");
            flag = 0;
        }
    }
        
    return 0;
}   
