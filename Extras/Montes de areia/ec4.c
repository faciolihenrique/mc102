/* * * * * * * * * * * * * * * * * *
 * Henrique Noronha Facioli		    *
 * RA : 157986				        *
 * henrique.facioli@gmail.com      *
 * henrique.facioli@ic.unicamp.br  *
 * github : henriquefacioli        * 
 * * * * * * * * * * * * * * * * * */

/*
   Sobre as especificações das funções:

   Nos protótipos das funções, adotamos nomes em minúsculas 
   para os parâmetros. 

   Nas especificações, esses nomes aparecem vertidos para 
   maiúsculas para destacar o papel de cada parâmetro.
*/

#include <stdio.h>   /* scanf(), printf(), fscanf(), feof(), fclose() */
#include <stdlib.h>  /* exit(), EXIT_FAILURE */

/*--------------------------------------------------------------*/
/* 
   C O N S T A N T E S  
 */

#define ENTER  '\n' 

/* tipos de vizinhanca */
#define TORRE  't'
#define DIAG   'd'
#define REI    'r'

/* regras de impressao das matrizes */
#define NUNCA       0  
#define INICIOEFIM  1
#define SEMPRE      2

/* dimensao maxima da matriz*/
#define MAX  128

/* casa nunca ativada */
#define INATIVO     -1

/* tamanho maximo de um string */
#define MAXSTR 128

/* MATRIZ e' uma abreviatura para int[MAX][MAX] */
typedef int matriz[MAX][MAX];

/*--------------------------------------------------------------*/
/*
   P R O T O T I P O S   D A S   F U N C O E S
 */

/*--------------------------------------------------------------*/
/* funcoes fornecidas por completo nesse esqueleto              */
void leia_configuracao_inicial(matriz T, int *nlin, int *ncol);

char leia_char();

void pause();

/*--------------------------------------------------------------*/
/* funcoes que devem ser escritas                               */ 
int  espalhe(matriz casas, matriz acorda, int nlin, int ncol, char tipo,
             int instante, int regra, int *novos); 

void imprima_matriz(matriz t, int nlin, int ncol);

void zere_matriz(matriz t, int nlin, int ncol);

/*--------------------------------------------------------------*/
/* sugerimos que voce escreva a funcao abaixo, ela sera util    */
void copie_matriz(matriz orig, matriz dest, int nlin, int ncol);


/*--------------------------------------------------------------*/
/* 
 * M A I N  
 *
 * A secao "Comportamento do programa" do enunciado pode
 * servir como guia para escrever o main.
 */
int main()
{
    return 0;
}

/*--------------------------------------------------------------*/
/* 
   I M P L E M E N T A Ç Õ E S  D A S   F U N Ç Õ E S
 */

/*--------------------------------------------------------------*/
/* 
   espalhe()
   
   Efetua uma sessao de espalhamento em CASAS no instante INSTANTE,
   ACORDA registra o instante de primeira ativação de cada casa,
   ambas matrizes são NLINxNCOL e as vizinhanças são dadas por TIPO
   devolve em NOVOS quantas casas novas foram ativadas e retorna 
   o numero de espalhadas no instante. 
   
   CASAS é impressa conforme estipulado em REGRA. Para isso a 
   funcao deve utilizar a funcao imprima_matriz.
 */
int espalhe(matriz casas, matriz acorda, int nlin, int ncol, char tipo,
        int instante, int regra, int *novos) 
{
    return 1; /* para o compilador nao reclamar do esqueleto */
              /* deve ser removida depois que a funcao for escrita */
}

/*-----------------------------------------------------------*/
/*
   leia_configuracao_inicial()
 
   Leitura dos dados.
   Devolve a matriz NLINxNCOL T descrita no arquivo pedido
   pela função.
 
   Formato do arquivo:
  
     * no. de linhas:  inteiro positivo
     * no. de colunas: inteiro positivo  
     * sequencia de linhas no formato:
          - indice de linha
          - indice de coluna
          - numero de graos   

   Esta funcao utiliza a funcao zere_matriz. 
 */
void leia_configuracao_inicial(matriz t, int *nlin, int *ncol)
{
    FILE *arq;
    int lin, col, graos;

    char nome_arquivo[MAXSTR];

    printf("Simulador de monte de areia\n");
    printf("Digite o nome do arquivo (sem espacos) contendo a configuracao inicial: ");

    scanf("%s", nome_arquivo);

    /* remova ENTER do buffer */
    leia_char();
    
    if ((arq = fopen(nome_arquivo,"r")) == NULL) {
        printf("Hmmm. Erro na abertura do arquivo '%s'\n", nome_arquivo);
        pause(); /* acrescentado em 03/JUN para no Windows a janela nao fechar
                    antes que o aluno leia a mensagem de erro. */
        exit(EXIT_FAILURE);  /* abandona a execucao do programa */
    }

    /* leia as dimensoes do tabuleiro */
    fscanf(arq,"%d %d", nlin, ncol);
    
    /* casas vazias por default */
    zere_matriz(t, *nlin, *ncol);
    fscanf(arq,"%d %d %d", &lin, &col, &graos);    
    while (!feof(arq)) {
        t[lin][col] = graos;
        fscanf(arq,"%d %d %d", &lin, &col, &graos);    
    }

    fclose(arq);
}

/*--------------------------------------------------------------*/
/*
   imprima_matriz()
  
   Imprime a matriz de inteiros NLINxNCOL T bonitinha, usando o formato 
   mais compacto compativel com o número de dígitos, e, se necessário,
   sinal.
   Apos imprimir a matriz para a execucao do programa utilizando
   a funcao pause().
 */
void imprima_matriz(matriz t, int nlin, int ncol)
{
    pause();
}

/*-----------------------------------------------------------*/
/*
   pause()
  
   Para a execucao do programa ate que o usuario tecle ENTER.
 */
void pause()
{
  printf("Tecle ENTER para continuar. ");
  leia_char();
}

/*-----------------------------------------------------------*/
/* 
   leia_char()
  
   Devolve o ultimo caractere lido antes do ENTER. 
*/
char leia_char()
{
    char ch, ultimo = 0;
    
    scanf("%c", &ch);
    while (ch != ENTER) {
        ultimo = ch;
        scanf("%c", &ch);
    }
    return ultimo;
}

/*-----------------------------------------------------------*/
/* 
   zere_matriz()
   
   Coloca zero em todas as posicoes da matriz NLINxNCOL T.
  
 */
void zere_matriz(matriz t, int nlin, int ncol)
{
    /* remova o trecho de codigo abaixo apos escrever esta funcao */
    printf("Vixe! Ainda nao fiz a funcao zere_matriz\n");
    exit(EXIT_FAILURE);
}

/*-----------------------------------------------------------*/
/* 
   copie_matriz()
  
   Copia todos os elementos da matriz NLINxNCOL ORIG para 
   a matriz NLINxNCOL DEST.
 
 */
void copie_matriz(matriz orig, matriz dest, int nlin, int ncol)
{
}
