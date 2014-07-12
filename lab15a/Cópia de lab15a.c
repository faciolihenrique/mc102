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

/*Funcao para leitura da entrada*/
void leitura_inicial(char numero[10], int *soma);
/*Funcao que realiza um arranjo com repeticao*/
void arranjo(int tamanho_comb, int operacao[], int size, int valor_dado, int *achou, char numero[10]);
/*Funcao que faz a soma de do numero de acordo com a combinacao dada*/
int soma(char numero[10], int operacao[8]);
/*Impressao da saida*/
void impressao(int achou);


int main(){
    /*operacao armazena o modo que deve ser realizado as operacoes*/
    int operacao[8];
    /*Soma desejada armazena a soma de entrada , e achou eh uma flag*/
    int soma_desejada, achou = 0;
    /*numero armazena o numero da entrada*/
    char numero[10];
    
    leitura_inicial(numero, &soma_desejada);
    
    arranjo(8, operacao, 0, soma_desejada, &achou, numero);
    
    impressao(achou);

    return 0;
}

/*Realiza a leitura de um inteiro e armazena seus digitos em
 *um vetor de caracteres
 */
void leitura_inicial(char numero[10], int *soma){
    scanf("%s", numero);
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
void arranjo(int tamanho_comb, int operacao[], int size, int valor_dado, int *achou, char numero[10]) {
    int i, valor_calc;
    if (size == tamanho_comb){
        valor_calc = soma(numero, operacao);
        if(valor_calc == valor_dado){
            *achou = 1;
        }
    }else if(*achou == 0){
        for(i = -1; i <= 1; i++){
            operacao[size] = i;
            arranjo(tamanho_comb, operacao, size + 1, valor_dado, achou, numero);
        }
    }
}

/*Funcao que realiza a soma dos numeros de acordo com as operacoes
 *indicada.Para isso ela cria uma matriz de caracteres que armazena
 *os valores em cada linha e no final faz uma conversao de caracter
 *para int, e soma os valores*/
int soma(char numero[10], int operacao[8]){
    /*i serve para contar o numero de operacoes*/
    /*j serve para contar a quantidade de numeros que haverao*/
    /*k serve para contar os digitos de cada numero*/
    int i, j = 0, k = 0, soma = 0;
    char sum[9][10];
    
    /*Primeira linha, primeira posicao é o primeiro numero*/
    sum[0][0] = numero[0];
    for(i = 0; i < 8; i++){
        /*Cado a operacao seja 0, nao eh nescessario pular de linha
         *(nao aumenta o j), mas nescessario pular a posicao do digito
         *(aumenta o k)
         */
        if(operacao[i] == 0){
            k++;
            sum[j][k] = numero[i+1];
        }
        /*Caso nao seja 0, eh nescessario terminar a linha
         *anterior(sum[j][k] = '\0'), pular de linnha(j++) 
         *e ir para o primeiro digito(k = 0)
         */
        else{
            sum[j][k] = '\0';
            k = 0;
            j++;
            if(operacao[i] == -1){
                sum[j][k] = '-';
                sum[j][++k] = numero[i+1];
            }if(operacao[i] == +1){
                sum[j][k] = '+';
                sum[j][++k] = numero[i+1];
            }
        }
    } 
    
    /*Percorre o numero de linhas fazendo a 
     *conversao e somando os valores*/
    for(i = 0; i < j; i++){
        soma = soma + atoi(sum[i]);
    }
    printf("%d\n", soma);
    return soma;
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
