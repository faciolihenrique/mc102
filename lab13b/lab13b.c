/* * * * * * * * * * * * * * * * * *
 * Henrique Noronha Facioli		    *
 * RA : 157986				        *
 * henrique.facioli@gmail.com      *
 * henrique.facioli@ic.unicamp.br  *
 * github : henriquefacioli        * 
 * Fruit Crush Saga - Part III     *
 * * * * * * * * * * * * * * * * * */

#include <stdio.h>

#define TAM 51

/*Funcao para leitura de tabuleiro*/
void leitura_tabuleiro(char tab[][TAM], int linha, int coluna);
char primeira_jogada(char tab[][TAM], int i, int j);
void jogada(char tab[][TAM], char fruta,int *pontuacao);

int main(){
    int pontucao = 0;
    char tabuleiro[TAM][TAM], fruta;
    int linhas, colunas, jogadas;
    int i, j, cont;
    
    /*Leitura do numeor de linhas, colunas e jogadas*/
    scanf("%d %d %d", &linhas, &colunas, &jogadas);
    
    leitura_tabuleiro(tabuleiro, linhas, colunas);
    
    for(cont = 0; cont < jogadas; cont++){
        scanf("%d %d", &i, &j);
        fruta = descobre_fruta(tabuleiro, i, j);
        jogada(tabuleiro, fruta, i, j,)
        
    }   
    
    


    return 0;
}

void leitura_tabuleiro(char tab[][TAM], int linha){
    int i;
    for(i = 0; i < linha; i++){
        scanf("%s", tab[i]);
    }
}

char descobre_fruta(char tab[][TAM], int i, int j){
    /*Define qual eh a fruta escolhida na jogada*/
    return fruta_escolhida = tab[i-1][j-1];
}

int jogada(char tab[][TAM],char fruta, int i, int j, int *pontuacao){
    if(tab[i][j] != fruta){
        return 0;
    }
    /*Direita*/
    if(fruta[i-1][j+1] == fruta){
        jogada(tab, fruta, i-1, j, pontuacao);
    }
    /*Esquerda*/
    if(fruta[i-1][j-1] == fruta){
        jogada(tab, fruta, i-1, j-2, pontuacao);
    }
    /*Cima*/
    if(fruta[i-2][j-1] == fruta){
        jogada(tab, fruta, i-2, j-1, pontuacao);
    }
    /*Baixo*/
    if(fruta[i][j-1] == fruta){
        jogada(tab, fruta, i, j-1, pontuacao);
    }
}