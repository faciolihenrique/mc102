/* Henrique Noronha Facioli
 * RA : 157986
 * Lab 06b - Fruit Crush Saga - Part II
 */

#include <stdio.h>

#define TAM 51

int jogada(char tab[TAM][TAM], int l, int j);
void gravidade(char tab[TAM][TAM], int m, int n);


int main(){
    /*Declaracao de variaveis, tabuleiro eh a matriz, M N K sao o tamanho do tabuleiro e o
    numero de jogadas, I e J sao a posicao da jogada, c eh um contador, e pontuacao o Score
     */
    char tabuleiro[TAM][TAM];
    int M, N, K;
    int I, J;
    int c;
    int pontuacao = 0;
    
    scanf("%d %d %d", &M, &N, &K);
    
    /*Leitura do tabuleiro*/
    for(c = 0; c < M; c++){
        scanf("%s", tabuleiro[c]);
    }
    
    /*Loop que executa a funcao jogada e gravidade por K veses, definida pelo usuario*/
    for(c = 0; c < K; c++){
        scanf("%d %d", &I, &J);
        pontuacao = pontuacao + jogada(tabuleiro, I, J);
        gravidade(tabuleiro, M, N);
    }
    
    /*Impressão do tabuleiro final e da pontuacao*/
    printf("Score: %d\n", pontuacao);
    for(c = 0; c < M; c++){
        printf("%s\n", tabuleiro[c]);
    }
    
    return 0;
    
}


/*Função para procurar em cima, a baixo, direita e a esquerda por 
numeros iguais ao da posicao selecionada e substitui os iguais por X;
ao mesmo tempo, conta quantas veses o procedimento foi feito e o retorna
*/
int jogada(char tab[TAM][TAM], int i, int j){
    char fruta_escolhida;
    int a, b;
    int direita = 1, esquerda = 1, cima = 1, baixo = 1, aparicoes = 1;
    
    fruta_escolhida = tab[i-1][j-1];
    
    /*Se a posicao escolhida nao for uma fruta*/
    if(fruta_escolhida == '.' || fruta_escolhida == 'X'){
        return 0;
    }
    
    /*Direita*/
    for(a = (i-1), b = (j); direita ; b++){
        if(tab[a][b] == fruta_escolhida){
            tab[a][b] = 'X';
            aparicoes++;
        }else{
            direita = 0;
        }
    }
        
     /*Esquerda*/
     for(a = (i-1), b = (j-2); esquerda ; b--){
         if(tab[a][b] == fruta_escolhida){
             tab[a][b] = 'X';
             aparicoes++;
         }else{
             esquerda = 0;
         }
     }
        
     /*Acima*/
     for(a = (i-2), b = (j-1); cima ; a--){
         if(tab[a][b] == fruta_escolhida){
             tab[a][b] = 'X';
             aparicoes++;
         }else{
             cima = 0;
         }
     }
        
     /*Abaixo*/
     for(a = (i), b = (j-1); baixo ; a++){
         if(tab[a][b] == fruta_escolhida){
             tab[a][b] = 'X';
             aparicoes++;
         }else{
             baixo = 0;
         }
     }
     tab[i-1][j-1] = 'X';
     return aparicoes*aparicoes;
}

/* A função gravidade procura os locais com 'X' na matriz e faz o que esta acima
ir para o lugar dela...*/
void gravidade(char tab[TAM][TAM], int m, int n){
    int i, j, aux;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(tab[i][j] == 'X'){    
                aux = i + 1;
                do{
                    aux--;
                    tab[aux][j] = tab[aux-1][j];
                }while(aux != 0);
                tab[aux][j] = '.';
            }
        }
    }
    
}
