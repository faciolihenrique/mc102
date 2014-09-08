/* * * * * * * * * * * * * * * * * *
 * Henrique Noronha Facioli		    *
 * RA : 157986				        *
 * henrique.facioli@gmail.com      *
 * henrique.facioli@ic.unicamp.br  *
 * github : henriquefacioli        * 
 *Lab 15a-Transferência de Bitcoins*
 * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Funcao para leitura da entrada*/
void leitura_inicial(int numero[9], int *soma);
/*Funcao que realiza um arranjo com repeticao*/
void arranjo(int tamanho_comb, int operacao[], int size, int valor_dado, int *achou, int numero[9]);
/*Funcao que faz a soma de do numero de acordo com a combinacao dada*/
int soma(int numero[9],int operacao[8]);
/*Funcao de soma antiga*/
int soma_antiga(char numero[9], int operacao[8]);
/*Impressao da saida*/
void impressao(int achou);


int main(){
    /*operacao armazena o modo que deve ser realizado as operacoes*/
    int operacao[8];
    /*Soma desejada armazena a soma de entrada , e achou eh uma flag*/
    int soma_desejada, achou = 0;
    /*numero armazena o numero da entrada*/
    int numero[9];
    
    leitura_inicial(numero, &soma_desejada);
    
    arranjo(8, operacao, 0, soma_desejada, &achou, numero);
    
    impressao(achou);

    return 0;
}

/*Realiza a leitura de um inteiro e armazena seus digitos em
 *um vetor de inteiros
 */
void leitura_inicial(int numero[10], int *soma){
    int num, i;
    scanf("%d", &num);
    for(i = 8; i >= 0; i--){
        numero[i] = num%10;
        num = num/10;
    }
    
    scanf("%d", &*soma);
}


/*Funcao recursiva que gera um arranjo combinatorio
 *com 8 posicoes com valores -1, 0 ,1, e os armazena
 *no vetor operacao.
 *-1 eh para quando for fazer uma subtracao
 *0 eh para unir os numeros
 *1 eh para somar
 *Quando ele termina de formar um arranjo, chama-se a funcao
 *soma que retorna a soma daquela combinacao, vendo se ela
 *tem o mesmo valor que a desejada, se sim, termina a funcao
 *e diz que achou*/
void arranjo(int tamanho_comb, int operacao[], int size, int valor_dado, int *achou, int numero[9]) {
    int i, valor_calc;
    /*PETA, esse valor calc eh so pra facilitar agora na visualizacao*/
    if(*achou == 0){
        if (size == tamanho_comb){
            valor_calc = soma(numero, operacao);
            if(valor_calc == valor_dado){
                *achou = 1;
            }
        }else{
            for(i = -1; i <= 1; i++){
                operacao[size] = i;
                arranjo(tamanho_comb, operacao, size + 1, valor_dado, achou, numero);
            }
        }
    }
}


/*Faz a soma de acordo com as operacoes dadas*/
/*Salva o numero em ma variavel auxiliar, se a
 *leitura for 0, multiplica esse auxiliar por 10
 *e soma o proximo numero, caso nao seja, faz 
 *a soma ou subtracao do numero auxiliar na vari
 *avel soma
 *No final retorna soma+aux
 */
int soma(int numero[9],int operacao[8]){
    int i, j = 0, soma = 0, aux;
    
    aux = numero[8];
    
    for(i = 7; i >= 0 ; i--){
        if(operacao[i] == 0){
            j++;
            aux = numero[i]*pow(10,j) + aux;
        }else{
            if(operacao[i] == 1){
                soma = soma + aux;
            }else if(operacao[i] == -1){
                soma = soma - aux;
            }
            j = 0;
            aux = numero[i];
        }
    }
    
    return (soma+aux);
}


/*Faz a impressao se a transferencia foi aceita ou nao
 *de acordo com o valor de achou
 */
void impressao(int achou){
    if(achou)
        printf("Transferencia aceita\n");
    else
        printf("Transferencia abortada\n");
}
