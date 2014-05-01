/* Henrique Noronha Facioli
 * RA : 157986
 * Deep Web
 */

#include <stdio.h>

int main(){
    /* Cria dois vetores, senha e multiplicacao com 16 posicoes (a posicao 0 nao sera usada)*/
    int senha[16],  multiplicacao[16];
    int n, i, soma, ultima_posicao;
    
    /*Entrada de números ja conhecido*/
    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        scanf("%d", &senha[i]);
    }
    
    /**/
    while(n <= 15){
        soma = 0;
        /*Atribui valor ao vetor multiplicacao;valor da posicao[i] do multiplicacao = valor posicao[i] da senha * posicao[i]* n*/
        /*Faz esse processo até a posicao n ( ultima posicao com informcaos do vetor senha*/
        for(i = 1;i <= n; i++){
            multiplicacao[i] = i*senha[i]*n;
        }
        /*soma os valores da multiplicacao*/
        for(i = 1;i <= n; i++){
            soma = soma + multiplicacao[i];
        }
        /*Incrementa n*/
        n++;
        
        /* Define o valor da ultima posicao: Resto da divisao da soma dos valores da multiplicacao por 11*/
        ultima_posicao = soma%11;
        if(ultima_posicao == 10){
            senha[n]= 0;
        }else{
            senha[n] = ultima_posicao;
        }
    }
    for(i = 1; i <= 15; i++){
        printf("%d", senha[i]);
    }
    printf("\n");
    return 0;
}
