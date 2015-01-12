#include <stdio.h>

#define TAM 51

int main(){
    /*Declaracao das variaveis de entrada */
    int M, N, I, J;
    char tabuleiro[TAM][TAM], fruta;
    /*Contadores*/
    int a, b;
    /*Flags*/
    int direita = 1, esquerda = 1, cima = 1, baixo = 1, aparicoes = 1;
    
    /*Entrada do numero de linhas e colunas e da posicao da linha e coluna escolhida*/
    scanf("%d %d %d %d", &M, &N, &I, &J);
    
    /*Entrada da matriz tabuleiro e definicao do valor da posicao I, J*/
    for(a = 0; a < M; a++){
        scanf("%s", tabuleiro[a]);
    }
    fruta = tabuleiro[I-1][J-1];
    
    /*O programa checa os numeros acima, abaixo, a direita e a esquerda
     * verifica o numero da direcao desejada, compara com o fruta
     * se for igual, substitui por X, e acresce o contador.
     * a = linha, b = coluna
     */   
    /*Direita*/
    for(a = (I-1), b = (J); direita ; b++){
        if(tabuleiro[a][b] == fruta){
            tabuleiro[a][b] = 'X';
            aparicoes++;
        }else{
            direita = 0;
        }
    }
    
    /*Esquerda*/
    for(a = (I-1), b = (J-2); esquerda ; b--){
        if(tabuleiro[a][b] == fruta){
            tabuleiro[a][b] = 'X';
            aparicoes++;
        }else{
            esquerda = 0;
        }
    }
    
    /*Acima*/
    for(a = (I-2), b = (J-1); cima ; a--){
        if(tabuleiro[a][b] == fruta){
            tabuleiro[a][b] = 'X';
            aparicoes++;
        }else{
            cima = 0;
        }
    }
    
    /*Abaixo*/
    for(a = (I), b = (J-1); baixo ; a++){
        if(tabuleiro[a][b] == fruta){
            tabuleiro[a][b] = 'X';
            aparicoes++;
        }else{
            baixo = 0;
        }
    }
    tabuleiro[I-1][J-1] = 'X';
    printf("Score: %d\n", aparicoes*aparicoes);
    for(a = 0; a < M; a++){
        printf("%s\n", tabuleiro[a]);
    }
   
    return 0;
}
