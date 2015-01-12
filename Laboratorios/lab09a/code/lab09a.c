/* Henrique Noronha Facioli
 * RA : 157986
 * 
 */

#include <stdio.h>

#define TAM 30

int andar_frente(int *posicao_x, int *posicao_y, int frente, int matriz[TAM][TAM], int D);
int direita(int frente);
int esquerda(int frente);

int main(){
    /*Declaracao de variaveis*/
    /*D eh o tamanho da labirinto, T o tempo,
     *oliver indica o valor da casa x, y que oliver esta
     *oliver_frente indica o lado que ira andar
     */
    int D, T, oliver, oliver_frente = 0, x, y;
    /*Flags*/
    int k = 0, achou = 0;
    /*Matriz labirinto*/
    int labirinto[TAM][TAM];

    
    /*Leitura de D e T*/
    scanf("%d %d", &D, &T);
    /*Leitura da matriz labirinto*/
    for(y = 0;y < D; y++){
        for(x = 0;x < D; x++){
            scanf("%d", &labirinto[y][x]);  
        }
    }
   
    /*Zera a posicao x e y e deixa oliver na posicao 0,0*/
    x = 0;
    y = 0;
    oliver = labirinto[y][x];
    
    
    /*Loop para andar com oliver.
     *Se oliver estiver em uma casa com 0, ele anda para frente diretamente
     *Se for a casa for 1, gira para a direita (frente + 1) e anda frente
     *Se for a casa for 2, gira para esquerda (frente - 1) e anda frente
     *Se for 3, a metralhadora é acionada e ele morre (oliver = -1)
     *Se for 4, ele achou.
     */
    
    while((oliver != -1) && (k < T) && (!achou)){
        if(oliver == 0){
            labirinto[y][x] = 1;
            oliver = andar_frente(&x, &y, oliver_frente, labirinto, D);
            k++;
        }else if(oliver == 1){
            labirinto[y][x] = 2;
            oliver_frente = esquerda(oliver_frente);
            oliver = andar_frente(&x, &y, oliver_frente, labirinto, D);
            k++;
        }else if(oliver == 2){
            labirinto[y][x] = 0;
            oliver_frente = direita(oliver_frente);
            oliver = andar_frente(&x, &y, oliver_frente, labirinto, D);
            k++;
        }else if(oliver == 3){
            oliver = -1;
        }else if(oliver == 4){
            achou = 1;
        }
    }
    
    /*Imprime se oliver conceguiu, ou nao*/
    if(achou){
        printf("Oliver destroi o dispositivo em %d segundos\n", k);
    }else if(oliver == -1){
        printf("Oliver morre\n");
    }else if(oliver != -1){
        printf("Oliver nao chega ao dispositivo a tempo\n");
    }
    
    return 0;
}

/* Funcao que faz oliver ir para a casa da frente, 
 * recebe sua posicao x, y , a direcao que ira andar (frente) o labirinto e o tamanho do labirinto
 * -->frente pode ser 0 para leste, 1 para norte, 2 para oeste, 3 para sul
 */

int andar_frente(int *posicao_x, int *posicao_y, int frente, int matriz[TAM][TAM], int D){
    if(frente == 0){
        (*posicao_x)++;
    }else if(frente == 1){
        (*posicao_y)--; 
    }else if(frente == 2){
        (*posicao_x)--;
    }else if(frente == 3){
        (*posicao_y)++;
    }
    
    /*Checa se a posicao x ou y ultrapassou o limite*/
    if(*posicao_y > D-1 || *posicao_y < 0 || *posicao_x > D-1 || *posicao_x < 0){
        return -1;
    }else{
        return matriz[*posicao_y][*posicao_x];
    }
}

int esquerda(int frente){
    if(frente == 3){
        return 0;
    }else{
        return (frente + 1);
    }
}
int direita(int frente){
    if(frente == 0){
        return 3;
    }else{
        return (frente - 1);
    }
}
