/* Laboratorio 14b - Whiteworse
 * Autor: Henrique Noronha Facioli - 157986
 * e-mail: henrique.facioli@gmail.com || henrique.facioli@ic.unicamp.br
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tamanho maximo do nome do titular */
#define MAXNOME 21
/* Tamanho maximo do nome dos arquivos de entrada/saida */
#define MAXNOMEARQ 101
/* Numero maximo de contas */
#define MAXCONTAS 20
/* Numero maximo de transacoes */
#define MAXTRANS 40
/* Valor da taxa de deposito em conta com saldo negativo */
#define TAXA 5.00

/* Conta
 * ag = numero da agencia
 * cc = numero da conta corrente
 * titular = Nome do titular da conta
 * saldo = Saldo da conta
 */
struct Conta {
    int ag;
    int cc;
    char titular[MAXNOME];
    double saldo;
};

typedef struct Conta Conta;

/* Transacao
 * tipo - 'D' para Depositos e 'S' para Saques
 * ag - Numero da agencia
 * cc - Numero da conta corrente
 * valor - Valor da operacao
 */
struct Transacao {
    char tipo;
    int ag;
    int cc;
    double valor;
};

typedef struct Transacao Transacao;

int main(int argc, char **argv) {
    FILE *arqCon;
    FILE *arqTrans;
    FILE *arqOut;
    
    Conta *contas;
    Transacao transacoes;
    /* Nome do arquivo binario com as contas */
    char nomeArqConta[MAXNOMEARQ];
    /* Nome do arquivo binario com as transacoes */
    char nomeArqTrans[MAXNOMEARQ];
    /* Nome do arquivo binario de saida */
    char nomeArqSaida[MAXNOMEARQ];
    /*Declaracao de variaveis*/
    int n, noperacoes;
    /*Contadores e flag*/
    int i, j = 0, flag;
    
    
    /* Obtendo o nome dos arquivos */
    strcpy(nomeArqConta, argv[1]);
    strcpy(nomeArqTrans, argv[2]);
    strcpy(nomeArqSaida, argv[3]);
    
    /*Declaracao e abertura dos arquivos*/
    arqCon = fopen(nomeArqConta, "rb");
    arqTrans = fopen(nomeArqTrans, "rb");
    arqOut = fopen(nomeArqSaida, "wb");
    
    /*Alocacao dinamica do numero de contas*/
    fread(&n,sizeof(int), 1, arqCon);
    contas = malloc(n*sizeof(Conta));
    /*Leitura do numero de operacoes a serem realizadas*/
    fread(&noperacoes,sizeof(int), 1, arqTrans);
    
    /*Lendo o arquivo de contas*/
    for(i = 0; i < n; i++){
        fread(&contas[i], sizeof(Conta), 1,arqCon);
    }
    
    /*Faz a leitura do arquivo de transacoes*/
    for(i = 0; i < noperacoes; i++){
        flag = 0;
        fread(&transacoes, sizeof(Transacao), 1, arqTrans);
        
        /*Procura no vetor de contas, a conta informada*/
        for(j = 0; (j < n) && ((transacoes.ag != contas[j].ag) || (transacoes.cc != contas[j].cc)) ; j++);
        /*Caso a transcao seja um saque e bem aprovada e encontre a transacao(j != n-1)
         *Primeiramente checa se a transacao vai gerar um saldo maior que 0
         *Em segundo, caso a transacao gere um saldo negativo, mas com valor maiso que -100
         *Terceiro caso a operacao seja um deposito, que nao tem limites.
         */
        if(j != n){
            if((transacoes.tipo == 'S') && (contas[j].saldo > 0) && (contas[j].saldo-transacoes.valor >= 0)){
                contas[j].saldo = contas[j].saldo - transacoes.valor;
                flag = 1;
            }else if((transacoes.tipo == 'S') && (contas[j].saldo > 0) && (contas[j].saldo-transacoes.valor > -100)){
                contas[j].saldo = contas[j].saldo - transacoes.valor - TAXA;
                flag = 1;
            }else if(transacoes.tipo == 'D'){
                contas[j].saldo = contas[j].saldo + transacoes.valor;
                flag = 1;
            }
        }
        
        /*Flag para caso seja bem sucedida a transacao*/
        if(flag){
            printf("T%d: %c %d %d %.2f\n",i, transacoes.tipo, transacoes.ag, transacoes.cc, transacoes.valor);
        }
    }
    
    /*Faz a saida no arquivo texto das Contas
     */
    fwrite(&n , sizeof(int) , 1 , arqOut);
    for(i = 0; i < n; i++){
        fwrite(&contas[i] , sizeof(Conta) , 1 , arqOut);
    }
    
    /*Desalocacao do vetor, e fechamento dos arquivos lidos*/
    free(contas);
    fclose(arqCon);
    fclose(arqTrans);
    fclose(arqOut);
    
    return 0;
}
