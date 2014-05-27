/***********************************************************
 * Autor: 
 * RA:
 * Laboratorio 12a: CUT++
 *
 ***********************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMEARQ 101

/* Prototipo das funcoes utilizadas pela main */
void gera_csv_reduzido(char fnamein[], char fnameout[]);
/*Procura a posicao da coluna no arquivo*/
int numero_coluna(FILE *arq);
/*Retorna o numero de linhas do arquivo*/
int numero_linha(FILE *arq);
/*Faz leitura de uma unica linha do arquivo, salvando a linha em uma matriz de caracteres*/
void leitura_linha(FILE *arqCSV, char **valores, int numero_colunas);
/*Aloca uma matriz*/
char ** aloca_matriz(int linhas);
/*Desaloca uma matriz*/
void desaloca_matriz(int **matriz, int linhas);
/*Escreve os valores no arquivo*/
void escrever_arquivo(FILE *arqCSV_out, char **valores, int ordem[], int N);

int main(int argc, char *argv[]) {
    char fnamein[MAX_NOMEARQ], fnameout[MAX_NOMEARQ];
    
    /*Passando o nome do arquivo de entrada e saida para fnamein/out*/
    strcpy(fnamein, argv[1]);
    strcpy(fnameout, argv[2]);

    gera_csv_reduzido(fnamein, fnameout);

    return 0;
}


void gera_csv_reduzido(char fnamein[], char fnameout[]){
    int N, ncolums, nlines;
    int *ordem_impressao;
    char **valores ;
    int i;
    
    /*Abertura do arquivo de entrada*/
    FILE *arqCSV, *arqCSV_out;
    arqCSV = fopen(fnamein, "r");
    arqCSV_out = fopen(fnameout, "w");
    
    /*Descobre quantas colunas existem no arquivo*/
    ncolums = numero_coluna(arqCSV);
    nlines = numero_linha(arqCSV);
    
    /*Leitura da primeira linha, contendo quais campos sao desejados*/
    scanf("%d", &N);
    ordem_impressao = malloc(N*sizeof(int));
    for(i = 0; i < N; i++){
        scanf("%d", &ordem_impressao[i]);
    }
    
    /*Criacao de um vetor de strings, que contem a linha lida*/
    valores = aloca_matriz(ncolums);
    i = 0;
    while(i < nlines){
        leitura_linha(arqCSV, valores, ncolums);
        escrever_arquivo(arqCSV_out, valores,  ordem_impressao, N);
        i++;
    }
    
    fclose(arqCSV_out);
    fclose(arqCSV);
    
}

/*Funcao que conta o numero de colunas*/
int numero_coluna(FILE *arq){
    int i = 1;
    char aux = '0';
    while(aux != '\n'){
        fscanf(arq, "%c", &aux);
        if(aux == ','){
            i++;
        }
    }
    rewind(arq);
    return i;
}

int numero_linha(FILE *arq){
    int i = 0;
    char aux;
    while(fscanf(arq,"%c", &aux) != EOF){
        if(aux == '\n'){
            i++;
        }
    }
    rewind(arq);
    return i;
}

/*Alocacao de uma matriz de characteres*/
char ** aloca_matriz(int linhas) {
    char **matriz;
    int i;
    matriz = malloc(linhas * sizeof(char *));
    for (i = 0; i < linhas; i++)
        matriz[i] = malloc(501*sizeof(char));
    return matriz;
}
/*Desalocacao de uma matriz de characteres*/
void desaloca_matriz(int **matriz, int linhas) {
    int i;
    for (i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}


/*Faz a leitura de uma linha do arquivo lido;
 *separando em uma matrzi de caracteres os campos separados por virgula
 *Termina quando chegar no \n
 */
void leitura_linha(FILE *arqCSV, char **valores, int numero_colunas){
    int i, j;
    char letra;
    for(i = 0; i < numero_colunas; i++){
        fscanf(arqCSV, "%c", &letra);
        for(j = 0;letra != ',' && letra != '\n'; j++){
            valores[i][j] = letra;
            fscanf(arqCSV, "%c", &letra);
        }
        valores[i][j] = '\0';
    }
}

void escrever_arquivo(FILE *arqCSV_out, char **valores, int ordem[], int N){
    int i;
    for(i = 0; i < N; i++){
        if(i != N-1){
            fprintf(arqCSV_out, "%s,", valores[(ordem[i]-1)]);
        }else{
            fprintf(arqCSV_out, "%s", valores[(ordem[i]-1)]);
        }
        
    }
    fprintf(arqCSV_out, "\n");
}
