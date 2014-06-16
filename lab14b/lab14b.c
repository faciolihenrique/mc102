/* * * * * * * * * * * * * * * * * *
 * Henrique Noronha Facioli		    *
 * RA : 157986				        *
 * henrique.facioli@gmail.com      *
 * henrique.facioli@ic.unicamp.br  *
 * github : henriquefacioli        * 
 * lab14b - Liber8                 *
 * * * * * * * * * * * * * * * * * */

#include <stdio.h>

#define TAM 51

/*Faz a leitura da entrada do programa*/
void leitura_mapa(char mapa[][TAM], int *linhas, int *colunas, int *pos_i, int *pos_j);
/*Calcula o tamanho da explosao*/
int tamanho_explosao(char mapa[][TAM], int i, int j);
/*Funcao que calcula o tamanho da explosao e modifica a matriz */
void explosao(char mapa[][TAM], int tam_explosao, int pos_i, int pos_j, int tam_tab_i, int tam_tab_j);
/*Faz a impressao do final do programa*/
void impressao(char mapa[][TAM], int linhas, int colunas, int pos_i, int pos_j);

int main(){
    /*Declaracao de variaveis*/
    char mapa[TAM][TAM];
    int posicao_i, posicao_j;
    int n_linhas, n_colunas;
    int primeira_explosao;
    
    leitura_mapa(mapa, &n_linhas, &n_colunas, &posicao_i, &posicao_j);
    
    primeira_explosao = tamanho_explosao(mapa, posicao_i-1 , posicao_j-1);
    
    explosao(mapa, primeira_explosao, posicao_i-1, posicao_j-1, n_linhas, n_colunas);
    
    impressao(mapa, n_linhas, n_colunas, posicao_i, posicao_j);

    return 0;
}

/*Funcao que realiza a leitura do numero de linhas e colunas, posicao da bomba e do mapa*/
void leitura_mapa(char mapa[][TAM], int *linhas, int *colunas, int *pos_i, int *pos_j){
    int i;
    /*Faz a leitura do tamanho do mapa, e da posicao da bomba*/
    scanf("%d %d %d %d",&*linhas , &*colunas, &*pos_i, &*pos_j);
    /*Leitura do mapa*/
    for(i = 0; i < *linhas; i++){
        scanf("%s", mapa[i]);
    }
    
    
}

/*Funcao que faz a convercao do caractere numero para um inteiro
 *e transforma a posicao em B
 */
int tamanho_explosao(char mapa[][TAM], int i, int j){
    return (mapa[i][j] - '0');
}

/*Funcao que realiza a explosao*/
/*A funcao recebe a posicao da jogada e realiza em torno dela uma verredura 
 *de uma submatriz de tamanho 2N+1*2N+1, sendo N o tamanho da explosao e
 *substitui os pontos por X, e caso encontre algum numero, chama novamente 
 *a funcao para o ponto em que foi encontrada outra bomba
 */
void explosao(char mapa[][TAM], int tam_explosao, int pos_i, int pos_j, int tam_tab_i, int tam_tab_j){
    /*Declaracao de variaveis contadoras e armazenador tamanho da bomba*/
    int i, j, tamanho;
    
    /*Dois loops que percorrem uma submatriz substituindo . -> X e caso encontre uma bomba, explode-a*/
    for(i = (pos_i-tam_explosao); i <= (pos_i+tam_explosao); i++){
        for(j = (pos_j-tam_explosao); (j <= pos_j+tam_explosao); j++){
            /*Checa se a explosao ocorre dentro da area do mapa*/
            if((j >= 0) && (j < tam_tab_j) && (i >= 0) && (i < tam_tab_i)){
                /*Caso a posicao do mapa seja diferente de '.' 'X' 'B' entao ele eh um numero*/
                if(mapa[i][j] != '.' && mapa[i][j] != 'x' && mapa[i][j] != 'B'){
                    /*Define qual sera o tamanho da explosao*/
                    tamanho = tamanho_explosao(mapa, i, j);
                    
                    /*Muda o numero por B*/
                    mapa[i][j] = 'B';
                    
                    /*Faz a explosao ocorrer no local onde foi encontrado outra bomba*/
                    explosao(mapa, tamanho, i, j, tam_tab_i, tam_tab_j);
                }else if(mapa[i][j] != 'B'){
                    mapa[i][j] =  'x';
                }
            }
        }
    }
    
}

/*Imprime a matriz que representa o mapa*/
void impressao(char mapa[][TAM], int linhas, int colunas, int pos_i, int pos_j){
    int i;
    for(i = 0; i < linhas; i++){
        printf("%s\n", mapa[i]);
    }    
}
