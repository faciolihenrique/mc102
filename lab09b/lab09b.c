/* Henrique Noronha Facioli
 * RA : 157986
 * Concurso Público para Professor da UNICAMP
 */

#include <stdio.h>

#define TAM 30

void ordenacao_matriz(double matriz[5][TAM], int k, int matriz_saida[5][TAM]);
void trocar_double(double *a, double *b);
void trocar_int(int *a, int*b);
void pref_class(int k, int class[TAM],int matriz[5][TAM], double media[TAM]);
void zerar(int vetor[], int k);
double media_participante(double matriz[5][TAM], int j);
void andar_linha(int numero, int matriz[5][TAM], int k);



int main(){
    /*Declaracao de variaveis*/
    /*Matriz que tem a entrada das notas e o vetor que tem a media*/
    double matriz[5][TAM], media[TAM];
    /*Vetor para armazenar a classificacao, e matrizes para armazenar a preferencia*/
    int classificacao[TAM], matriz_preferencia[5][TAM], matriz_preferencia2[5][TAM];
    /*Contadores, i e j, e numero de candidatos K*/
    int i, j, K;
    
    /*Leitura da variavel K*/
    scanf("%d", &K);
    
    /*Leitura da matriz*/
    for(i = 0; i < 5; i++){
        for(j = 0; j < K; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
    
    /*Cria a matriz_preferencia, que contem numeros de 1 a K*/
    for(i = 0; i < 5; i++){
        for(j = 0;j < K;j++){
            matriz_preferencia[i][j] = (j + 1);
        }
    }
    
    /*Calcula a media de cada participante*/
    for(i = 0; i < K; i++){
        media[i] = media_participante(matriz, i);
    }
    
    /*Organiza a matriz em ordem de notas crescente*/
    ordenacao_matriz(matriz, K, matriz_preferencia);
    
    /*Faz uma copia da matriz preferencia para poder ser 
     *modificada na funcao pref_class
     */
    for(i = 0; i < 5; i++){
        for(j = 0;j < K;j++){
            matriz_preferencia2[i][j] = matriz_preferencia[i][j];
        }
    }
    
    /*Organizacao da classificacao*/
    pref_class(K, classificacao, matriz_preferencia2, media);
    
    
    /*INICIO DAS IMPRESSOES*/
    /*Impressao da nota media*/
    printf("Nota Media:");
    for(j = 0;j < K; j++){        
        printf(" %.1f", media[j]);
    }
    printf("\n");
    printf("\n");
    /*Impressao matriz ordenada*/
    printf("Preferencia:\n");
    for(i = 0;i < 5; i++){
        printf("Membro %d:", i+1);
        for(j = 0;j < K; j++){
            printf(" %d", matriz_preferencia[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    /*Impressao classificacao*/
    printf("Classificacao:");
    for(i = 0; i < K; i++){
        printf(" %d", classificacao[i]);
    }
    printf("\n");
    return 0;

}


/*Funcao para calcular a media dos participantes
 *faz a soma de cada coluna e retorna a soma/5
 */
double media_participante(double matriz[5][TAM], int j){
    int i;
    double soma = 0;
    for(i = 0 ;i < 5; i++){
        soma = soma + matriz[i][j];
    }
    return (soma/5);
}

/*Ordena cada linha com a funcao selection sort e salva-a na matriz_saida*/
void ordenacao_matriz(double matriz[5][TAM], int k, int matriz_saida[5][TAM]){
    int a, b, i, maior;
    /*Selection sort repetido 5 vezes, um para cada linha*/
    for(i = 0;i < 5; i++){
        for(a = 0; a < (k-1); a++){
            maior = a;
            for(b = (a+1);b < k; b++){
                if(matriz[i][b] > matriz[i][maior]){
                    maior = b;
                }else if(matriz[i][b] == matriz[i][maior]){
                    /*Caso as notas sejam iguais, quem tem menor indice, tem preferencia*/
                    if(matriz_saida[i][maior] > matriz_saida[i][b]){
                        maior = b;
                    }
                }    
            }
            trocar_double(&matriz[i][a], &matriz[i][maior]);
            trocar_int(&matriz_saida[i][a], &matriz_saida[i][maior]);
        }
    }
}


/*Calcula a preferencia:
 *Ve cada coluna a e calculca quantas veses cada candidato aparece nela
 *Depois checa quem apareceu mais vezes, caso haja empate, observa a media desses candidatos
 *Se houver empate novamente, o desempate fica por conta do indice
 */
void pref_class(int k, int class[TAM],int matriz[5][TAM], double media[TAM]){
    int i, j, maior, aux;
    int coluna[TAM];
    
    /*Loop para repetir k vezes o processo de contar quantas vezes algum candidato
     *aparece na primeira coluna. Quando achar quem apareceu mais, escreve na posicao j do vetor
     *class quem foi que apareceu mais, e retira-o da matriz com a funcao andar_linha*/
    for(j = 0; j < k; j++){
        /*Zera o vetor coluna, que eh um contador*/
        zerar(coluna, k);
        /*Incrementa 1 na posicao da */
        for(i = 0; i < 5; i++){
            coluna[(matriz[i][0]-1)]++;
        }
        /*No vetor que fez a contagem de aparicoes da primeira coluna,
         *faz a checagem de quem apareceu o maior numero de vezes e verifica
         *casos especiais, como empate, e empate de media
         */
        aux = 0;
        maior = coluna[0];
        for(i = 1; i < k; i++){
            /*Se encontrar alguem com mais aparicoes*/
            if(maior < coluna[i]){
                maior = coluna[i];
                aux = i;
            }else if((coluna[i] == maior) && (coluna[i] != 0)){
                if(media[i] > media[aux]){
                    maior = coluna[i];
                    aux = i;
                }else if(media[i] == media[aux]){
                    if(i < aux){
                        maior = coluna[i];
                        aux = i;
                    }
                }
            }
        }
        andar_linha((aux+1), matriz, k);
        class[j] = aux+1;
    }
   
}

/*Trocar posição double*/
void trocar_double(double *a, double *b){
    double aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/*Trocar posição int*/
void trocar_int(int *a, int*b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}



/*Zerar vetor*/
void zerar(int vetor[TAM], int tam){
    int i;
    for(i = 0; i < tam; i++){
        vetor[i] = 0;
    }
}


/*Faz com que o numero encontrado seja excluido da matriz, 
 *trazendo todos os numero para uma posicao anterior e 
 *tornando a ultima coluna 0
 */
void andar_linha(int numero, int matriz[5][TAM], int k){
    int i, j, l;
    for(i = 0; i < 5; i++){
        for(j = 0; j < k; j++){
            if(matriz[i][j] == numero){
                for(l = j;l < k-1; l++){
                    matriz[i][l] = matriz[i][l+1];
                }
            }
        }
        matriz[i][k-1] = 0;
    }
}
