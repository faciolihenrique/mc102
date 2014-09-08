#include <stdio.h>

#define TAM 50

<<<<<<< HEAD
/*Declaracao de funcoes*/
int eh_igual(char letra1, char letra2);
int direita(char tab[TAM][TAM+1], int i, int j, char palavra[], int tamanho_palavra, char saida[TAM][TAM+1]);
int diagonal(char tab[TAM][TAM+1], int i, int j, char palavra[], int tamanho_palavra, char saida[TAM][TAM+1]);
int baixo(char tab[TAM][TAM+1], int i, int j, char palavra[], int tamanho_palavra, char saida[TAM][TAM+1]);

int main(){
    /*Declaracao de variaveis*/
    /*Contadores e tamanho do tabuleiro (M, N)*/
    int N, M, i, j;
    int soma_dir = 0, soma_dia = 0, soma_bai = 0, aparicoes = 0;
    int  tamanho_palavra;
    /*Delcaracao de strings, palavra, tabuleiro e tabuleiro de saida(contendo os '.'*/
    char palavra[26], tabuleiro[TAM][TAM+1], tabuleiro_saida[TAM][TAM+1];
    
    /*Entrada do tamanho do tabuleiro e da palavra que deve ser achada*/
=======
int direita(char tab[TAM][TAM+1], int N, int M, int tamanha_palavra);
int diagonal(char tab[TAM][TAM+1], int N, int M, int tamanho_palavra);
int baixo(char tab[TAM][TAM+1], int N, int M, int tamanho_palavra);

int main(){
    int N, M;
    char palavra[26], tabuleiro[TAM][TAM+1];
    /*int tamanho_palavra;*/
    int i;
    
>>>>>>> 1e8d804a4f707179712d5daf4e4d11d1373f7513
    scanf("%d %d", &N, &M);
    scanf("%s", palavra);
    
    /*Descobre o tamanho da palavra*/
    for(i = 0; palavra[i] != '\0'; i++);
<<<<<<< HEAD
    tamanho_palavra = i;
=======
    /*tamanho_palavra = i;*/
>>>>>>> 1e8d804a4f707179712d5daf4e4d11d1373f7513
   
    /*Leitura do tabuleiro*/
    for(i = 0; i < N; i++){
        scanf("%s", tabuleiro[i]);
    }
    
<<<<<<< HEAD
    /*Cria uma matriz de saida com todas as posicoes com '.'*/
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            tabuleiro_saida[i][j] = '.';
        }
        tabuleiro_saida[i][j] = '\0';
    }
    
    
    /*Busca na matriz tabuleiro a primeira letra da palavra fornecida
     *se encontrada, chama as funcoes de comparacao*/
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            if(eh_igual(tabuleiro[i][j], palavra[0])){
                /*Vai ate a posicao M-tamanho buscando palavras na diagonal, horizonatal e vertical*/
                if(j <= (M-tamanho_palavra)){
                    soma_dir = soma_dir + direita(tabuleiro, i, j, palavra, tamanho_palavra, tabuleiro_saida);
                    soma_dia = soma_dia + diagonal(tabuleiro, i, j, palavra, tamanho_palavra, tabuleiro_saida);
                    soma_bai = soma_bai + baixo(tabuleiro, i, j, palavra, tamanho_palavra, tabuleiro_saida);
                }
                /*Se passar de M-tamanho_palavra, so faz a busca na vertical*/
                else{
                    soma_bai = soma_bai + baixo(tabuleiro, i, j, palavra, tamanho_palavra, tabuleiro_saida);
                }
            }
        }
    }
    aparicoes = soma_dir + soma_dia + soma_bai;
    
    /*Impressao da saida*/
    printf("%s %d\n",palavra, aparicoes);
    for(i = 0; i < N; i++){
        printf("%s\n",tabuleiro_saida[i]);
    }
    
    return 0;
}

/*Funcao que checa se a letra da palavra e do tabuleiro sao iguais, se sim, retorn 1, se nao, retorna 0*/
int eh_igual(char letra1, char letra2){
    /*Checa se as letras são identicas*/
    if(letra1 == letra2){
        return 1;
    }
    /*Caso especial que server para todos*/
    else if(letra1 == '_'){
        return 1;
    }
    /*Caso especial em que a letra da palavra e uma vogal*/
    else if(letra1 == '#' && (letra2 == 'a' ||     letra2 == 'e' || letra2 == 'i' || letra2 == 'o' || letra2 == 'u')){
        return 1;
    }
    /*Caso especial seja uma consoante*/
    else if(letra1 == '%' && (letra2 != 'a' && letra2 != 'e' && letra2 != 'i' && letra2 != 'o' && letra2 != 'u')){
        return 1;
    }
    /*Se nao aconteceu nenhum dos casos anteriores, eh por que nao sao iguais*/
    else{
        return 0;
    }
}

/* Funcao que verifica a direita se a palavra realmente esta la; como entrada, tem-se o tabuleiro,
a posicao da letra encontrada (i,j) a palavra, e o tamanho da palavra*/
int direita(char tab[TAM][TAM+1], int i, int j, char palavra[26], int tamanho_palavra, char saida[TAM][TAM+1]){
    /*Declaracao de variaveis auxiliares de contagem*/
    int a,b;
    /*Loop para checar se a há a palavra na posicao encontrada, se achar alguma diferente, retorn 0*/
    for(a = 0, b = j; a < tamanho_palavra; a++, b++){
        if(eh_igual(tab[i][b], palavra[a]) == 0){
            return 0;
        }
    }
    /*Se o programa chegar ate aqui, e porque a palavra existe na posicao. Este trecho copia a palavra na matriz de saida*/
    for(a = 0, b = j ;a < tamanho_palavra; a++, b++){
         saida[i][b] = tab[i][b];
    }
    return 1;
}

/* Funcao que verifica a diagonal se a palavra realmente esta la; como entrada, tem-se o tabuleiro,
a posicao da letra inicial encontrada (i,j) a palavra, e o tamanho da palavra*/
int diagonal(char tab[TAM][TAM+1], int i, int j, char palavra[26], int tamanho_palavra, char saida[TAM][TAM+1]){
    /*Declaracao de variaveis auxiliares de contagem*/
    int a, b, c;
    /*Loop para checar se a há a palavra na posicao encontrada, se achar alguma diferente, retorn 0*/
    for(a = 0, b = i, c = j; a < tamanho_palavra; a++, b++, c++){
        if(eh_igual(tab[b][c], palavra[a]) == 0){
            return 0;
        }
    }
    /*Exatamente como o anterior, copia a palavra para a matriz de saida*/
    for(a = 0, b = i, c = j; a < tamanho_palavra; a++, b++, c++){
        saida[b][c] = tab[b][c];
    }
    return 1;
}

int baixo(char tab[TAM][TAM+1], int i, int j, char palavra[], int tamanho_palavra, char saida[TAM][TAM+1]){
    /*Declaracao de variaveis auxiliares de contagem*/
    int a,b;
    /*Loop para checar se a há a palavra na posicao encontrada, se achar alguma diferente, retorn 0*/
    for(a = 0, b = i; a < tamanho_palavra; a++, b++){
        if(eh_igual(tab[b][j], palavra[a]) == 0){
            return 0;
        }
    }
    /*Exatamente como o anterior, copia a palavra para a matriz de saida*/
    for(a = 0, b = i ;a < tamanho_palavra; a++, b++){
         saida[b][j] = tab[b][j];
    }
    return 1;
}
=======
    /*Busca na matriz tabuleiro a primeira letra da palavra fornecida
     *se encontrada, chama as funcoes para comparar
     */
    
    for(i = 0, i < N, i++){
        for(j = 0, j < (M-tamanho_palavra), j++){
            if(palavra[0] == tabuleiro[i][j]){
                direita(tabuleiro, N, M, tamanho_palavra)
    
    return 0;
}
>>>>>>> 1e8d804a4f707179712d5daf4e4d11d1373f7513
