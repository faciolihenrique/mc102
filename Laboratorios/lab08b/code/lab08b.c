/* Henrique Noronha Facioli
 * 157986
 * Lab 08b - Processamento de imagens
 */

#include <stdio.h>
#include <string.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

/* Le uma imagem em formato PGM a partir da entrada padrao.
 * Retorna 1 se a leitura for realmente de um arquivo PGM
 * e 0 caso contrario.
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO                       */
int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
            int *F, double *Px, double *Py) {
    char nome_formato[3];
    char c;
    int i,j;

    /* Le o formato da imagem. P2 indica o formato PGM */
    scanf("%s ", nome_formato);
    if (strcmp(nome_formato, "P2") != 0)
        return 0;

    /* Le o '#', que indica um comentario, e os numeros indicando
     * o filtro e o parametro, se houver */
    scanf("%[#]c", &c);
    scanf("%d", F);
    if (*F == 4) {
        scanf("%lf %lf", Px, Py);
    } 
 
    /* Le dimensoes e intensidade maxima da imagem */
    scanf("%d", W);
    scanf("%d", H);
    scanf("%d", MaxV);
 
    /* Le o valor de cada pixel da imagem */
    for (i = 0; i < (*H); i++) {
        for (j = 0; j < (*W); j++) {
            scanf("%d", &img[i][j]);
        }
    }

    return 1;
}

/* Escreve a imagem em formato pgm na saida padrao 
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO               */
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    /* Escreve os atributos da imagem */
    /* Tipo da imagem: P2 significa pgm*/
    printf("P2\n");
    /* Dimensoes e intensidade maxima da imagem */
    printf("%d %d %d\n", W, H, MaxV);

    /* Escreve os pixels da imagem */
    for (i = 0; i < H; i++) {
        printf("%d", img[i][0]);
        for (j = 1; j < W; j++) {
            printf(" %d", img[i][j]);
        }
        printf("\n");
    }
}

/* Negativo */
void negativo(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;
    for(i = 0;i < H;i++){
        for(j = 0;j < W;j++){
           img[i][j] = MaxV-img[i][j];
        }
    }
}

/* Rotacao de 180 graus */
void rotacao180(int img[][MAX_TAM], int W, int H) {
    int i, j, k = 0, aux;
    for(i = 0;i < H;i++){
        for(j = 0;(j < W) && (k < (W*H)/2);j++){
            aux = img[(H-1)-i][(W-1)-j];
            img[(H-1)-i][(W-1)-j] = img[i][j];
            img[i][j] = aux;
            k++;
        }
    }
}

/* Deteccao de bordas */
void detectaBorda(int img[][MAX_TAM], int W, int H, int MaxV) {
    /*Criacao da matriz copia*/
    int i, j, copia_img[MAX_TAM][MAX_TAM];
    for(i = 0;i < H; i++){
        for(j = 0;j < W; j++){
            copia_img[i][j] = img[i][j];
        }
    }
    for(i = 1;i < (H-1); i++){
        for(j = 1; j < (W-1); j++){
            /*Soma as diagonais em volta do numero multiplicando por -1*/
            img[i][j] = ((-1)*copia_img[i-1][j-1]) + ((-1)*copia_img[i+1][j-1]) + ((-1)*copia_img[i-1][j+1]) + ((-1)*copia_img[i+1][j+1]);
            /*Soma as horizontais e verticias, multiplicando por -4*/
            img[i][j] =  img[i][j] + ((-4)*copia_img[i-1][j])  + ((-4)*copia_img[i][j+1]) +((-4)*copia_img[i+1][j])  + ((-4)*copia_img[i][j-1]);
            /*Soma o numero original multiplicado de 20*/
            img[i][j] = img[i][j] +  + (20*copia_img[i][j]);
            if(img[i][j] > MaxV){
                img[i][j] = MaxV;
            }else if(img[i][j] < 0){
                img[i][j] = 0;
            }
        }
    }
}

/* Cisalhamento */
void cisalhamento(int img[][MAX_TAM], int W, int H, double Px, double Py) {
    int x_linha, y_linha;
    int i, j, copia_img[MAX_TAM][MAX_TAM];
    /*Faz a copia da img*/
    for(i = 0;i < H;i++){
        for(j = 0;j < W; j++){
            copia_img[i][j] = img[i][j];
            img[i][j] = 0;
        }
    }
    for(i = 0;i < H; i++){
        for(j = 0;j < W; j++){
            x_linha = j + (Px * i);
            y_linha = i + (Py * j);
            img[y_linha][x_linha] = copia_img[i][j];
        }
    }
}


/* VOCE NAO DEVE ALTERAR A FUNCAO PRINCIPAL */
int main() {
    /* Matriz que armazena os pixels da imagem */
    int img[MAX_TAM][MAX_TAM]; 
    /* Atributos da imagem */
    int W, H, MaxV;
    /* Identificador do filtro a ser utilizado */
    int F;
    /* Parametro a ser passado para o cisalhamento */
    double Px, Py;

    /* Le a imagem */
    if (ler_pgm(img, &W, &H, &MaxV, &F, &Px, &Py) != 1) {
        printf("Error: nao foi possivel ler a imagem\n");
        return 0;
    }
 
    /* Seleciona o filtro */
    switch (F) {
        case 1:
            negativo(img, W, H, MaxV);
            break;
        case 2:
            rotacao180(img, W, H);
            break;
        case 3:
            detectaBorda(img, W, H, MaxV);
            break;
        case 4:
            cisalhamento(img, W, H, Px, Py);
            break;
    }

    /* Escreve a imagem */
    escrever_pgm(img, W, H, MaxV);

    return 0;
}
