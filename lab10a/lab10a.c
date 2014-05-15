/* Henrique Noronha Facioli
 * RA : 157986
 * 
 */

#include <stdio.h>

#define LINHAS 15
#define CHARS 501

void selection_sort(int matriz[2][26]);
void trocar(int *a, int *b);
void preparar_matriz(int matriz[2][26]);
void contagem_letras(char texto[LINHAS][CHARS], int N, int matriz_contagem[2][26]);
void encriptar(int matriz_ordenada[2][26], char texto[LINHAS][CHARS], int N);

int main(){
    char texto[LINHAS][CHARS];
    int contagem[2][26];
    int i, N;
    
    /*Leitura do numero de linhas*/
    scanf("%d\n", &N);
    
    /*Leitura do texto*/
    for(i = 0; i < N; i++){
        fgets(texto[i], 501, stdin);
    }
    
    contagem_letras(texto, N, contagem);
    selection_sort(contagem);
    encriptar(contagem, texto, N);
    
    for(i = 0; i < N; i++){
        printf("%s", texto[i]);
    }
    
    return 0;
}

/*Contagem de aparecimentos das letras, sendo que na posicao 0 eh a/A e 25 z/Z*/
void contagem_letras(char texto[LINHAS][CHARS], int N, int matriz_contagem[2][26]){
    int i, j;
    
    preparar_matriz(matriz_contagem);
    
    /*Caso a letra seja minuscula; o valor de a em ascii eh 97
     *Caso a letra seja maiuscula, o valor de A em ascii eh 65
     */
    for(i = 0 ;i < N; i++){
        for(j = 0; texto[i][j] != '\0' ; j++){
            if(texto[i][j] >= 'a' && texto[i][j] <= 'z'){
                matriz_contagem[1][(texto[i][j] - 97)]++;
            }else if(texto[i][j] >= 'A' && texto[i][j] <= 'Z'){
                matriz_contagem[1][(texto[i][j] - 65)]++;
            }
        }
    }
    
}

/*Zera a linha 2 da matriz e enumera a linha 1*/
void preparar_matriz(int matriz[2][26]){
    int i;
    for(i = 0; i < 26; i++){
        matriz[0][i] = i;
        matriz[1][i] = 0;
    }
}

/*Funcao para fazer trocas de numeros*/
void trocar(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/*Ordenacao do vetor contagem em ordem descrescente*/
void selection_sort(int matriz[2][26]){
    int a, b, maior;
    for(a = 0; a < 25; a++){
        maior = a;
        for(b = (a+1);b < 26; b++){
            if(matriz[1][b] > matriz[1][maior]){
                maior = b;
            }else if(matriz[1][b] == matriz[1][maior]){
                /*Caso as aparicoes sejam iguais, quem tem menor indice, tem preferencia*/
                if(matriz[0][maior] > matriz[0][b]){
                    maior = b;
                }
            }    
        }
        trocar(&matriz[1][maior], &matriz[1][a]);
        trocar(&matriz[0][maior], &matriz[0][a]);
    }
}

/*Troca das letras na matriz de saida*/
void encriptar(int matriz_ordenada[2][26], char texto[LINHAS][CHARS], int N){
    int i, j, k, letra1_min, letra2_min, letra1_mai, letra2_mai;
    for(k = 0; k < 26; k = k + 2){
        letra1_min = matriz_ordenada[0][k]+65;
        letra2_min = matriz_ordenada[0][k+1]+65;
        letra1_mai = matriz_ordenada[0][k]+97;
        letra2_mai = matriz_ordenada[0][k+1]+97;
        for(i = 0; i < N; i++){
            for(j = 0; texto[i][j] != '\n'; j++){
                if(texto[i][j] == letra1_min){
                    texto[i][j] = letra2_min;
                }else if(texto[i][j] == letra2_min){
                    texto[i][j] = letra1_min;
                }else if(texto[i][j] == letra1_mai){
                    texto[i][j] = letra2_mai;
                }else if(texto[i][j] == letra2_mai){
                    texto[i][j] = letra1_mai;
                }
                
            }
        }
    }
}
