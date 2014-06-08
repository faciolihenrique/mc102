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
void leitura_tabuleiro(char tab[][TAM], int linha);
/*Funcao para impressao desejada*/
void imprime_tabuleiro(char tab[][TAM], int linha, int pontuacao);
/*Zera o contador de aparicoes*/
void zera_contador(int *contador);
/*Funcao para descobrir qual foi a fruta selecionada*/
char descobre_fruta(char tab[][TAM], int i, int j);
/*Funcao que realiza as operacoes para encontrar as frutas*/
void jogada(char tab[][TAM],char fruta, int i, int j, int *pontuacao);
/*Funcao que realiza a gravidade, ou seja, faz com que as peças "caiam"*/
void gravidade(char tab[][TAM], int linhas, int colunas);

int main(){
    int pontuacao = 0, aparicao = 0;
    char tabuleiro[50][TAM], fruta;
    int linhas, colunas, jogadas;
    int i, j, cont;
    
    /*Leitura do numero de linhas, colunas e jogadas*/
    scanf("%d %d %d", &linhas, &colunas, &jogadas);
    
    leitura_tabuleiro(tabuleiro, linhas);
    
    for(cont = 0; cont < jogadas; cont++){
        scanf("%d %d", &i, &j);
        fruta = descobre_fruta(tabuleiro, i, j);
        zera_contador(&aparicao);
        jogada(tabuleiro, fruta, i-1, j-1, &aparicao);
        printf("%d\n", aparicao);
        gravidade(tabuleiro, linhas, colunas);
        pontuacao = pontuacao + aparicao*aparicao;
    }
    
    imprime_tabuleiro(tabuleiro, linhas, pontuacao);

    return 0;
}

/*Faz a leitura do tabuleiro um vetor de strings*/
void leitura_tabuleiro(char tab[][TAM], int linha){
    int i;
    for(i = 0; i < linha; i++){
        scanf("%s", tab[i]);
    }
}

/*Faz a impressao do tabuleiro como um vetor de strings e imprime a pontuacao*/
void imprime_tabuleiro(char tab[][TAM], int linha, int pontuacao){
    int i;
    printf("Score: %d\n", pontuacao);
    for(i = 0; i < linha; i++){
        printf("%s\n", tab[i]);
    }
}

/*Funcao que retorna qual é a fruta selecionada na jogada*/
char descobre_fruta(char tab[][TAM], int i, int j){
    /*Define qual eh a fruta escolhida na jogada*/
    return tab[i-1][j-1];
}

/*Zera o contador de aparicoes*/
void zera_contador(int *contador){
    *contador = 0;
}

/*Funcao recursiva que checa as posicoes adjacentes da posicao i, j informada
 * e busca de fruta escolhida, caso ache, chama a funcao novamente para a posi
 *cao encontada
 */
void jogada(char tab[][TAM],char fruta, int i, int j, int *contador){
    /*Transforma o caractere da posicao i, j em X */
    tab[i][j] = 'X';
    /*Incrementa o contador de aparicoes, se isso for executado
     *eh porque foi encontrado uma fruta igual*/
    (*contador)++;  
    /*Direita*/
    if(tab[i][j+1] == fruta){
        jogada(tab, fruta, i, j+1, contador);
    }
    /*Esquerda*/
    if(tab[i][j-1] == fruta){
        jogada(tab, fruta, i, j-1, contador);
    }
    /*Cima*/
    if(tab[i-1][j] == fruta){
        jogada(tab, fruta, i-1, j, contador);
    }
    /*Baixo*/
    if(tab[i+1][j] == fruta){
        jogada(tab, fruta, i+1, j, contador);
    }
}

/*Funcao que procura X na matriz, e quando encontra faz com que as
 *pecas acima dela movam para a casa abaixo, enquanto nao chega no
 *teto ( aux = 0) ou no gelo (tab[aux][j] = * )
 */
void gravidade(char tab[][TAM], int linhas, int colunas){
    int i, j, aux;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if(tab[i][j] == 'X'){    
                aux = i + 1;
                do{
                    aux--;
                    tab[aux][j] = tab[aux-1][j];
                }while(aux != 0 && tab[aux][j] != '*');
                if(aux != i+1){
                    tab[aux][j] = '.';
                }
            }
        }
    }
}
