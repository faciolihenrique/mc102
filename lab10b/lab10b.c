/* Henrique Noronha Facioli
 * RA : 157986
 * Lab XXy - DON'T PANIC - Part I
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 102

/*Faz a mudanca da strip de 1 a i-1 movendo ate a posicao j-1*/
void transposicao_prefixo(int pos_i, int pos_j, int vetor[TAM], int n){
    int cont ,k , *aux;
    aux = malloc((pos_j-pos_i) * sizeof(int));
    /*Faz uma copia dos elementos entre i e j*/
    for(k = pos_i, cont = 0; k < pos_j ; k++, cont++){
        aux[cont] = vetor[k];
    }
    /*Faz com que os valores do vetor andem j-i casas para a direita*/
    for(k = pos_j-1; k > pos_j-pos_i; k--){
        vetor[k] = vetor[k-(pos_j-pos_i)];
    }
    /*Faz com que os valores de 1 ate i-j sejam o da matriz aux*/
    for(k = 1, cont = 0; k <= (pos_j-pos_i); k++, cont++){
        vetor[k] = aux[cont];
    }
    free(aux);
}

/*Localiza o breakpoint e retorna a posicao em que ele ocorre*/
int breakpoint(int vetor[TAM], int n){
    int i;
    for(i = 2; i < n; i++){
        if(vetor[i]-vetor[i-1] != 1){
            return i;
        }
    }
    return 0;
}

void busca_troca(int vetor[TAM], int n, int *pos_i, int *pos_j,int *continuar){
    int a, fim, achou = 0;
    fim = breakpoint(vetor, n);
    for(a = fim ; a <= n && !achou && fim ; a++){
        if(vetor[a] == vetor[fim-1]+1){
            *pos_i = fim;
            *pos_j = a;
        }else if(vetor[a] == vetor[1]-1){
            *pos_i = fim;
            *pos_j = a+1;
        }
    }
    if(fim == 0){
        *continuar = 0;
    }
}


int main(){
    int permutacao[TAM];
    int n, pos_i, pos_j;
    int a, continuar = 1;
    
    /*Leitura do numero de panqueas*/
    scanf("%d", &n);
    /*Leitura da pilha de panquecas*/
    permutacao[0] = 0;
    for(a = 1; a <= n; a++){
        scanf("%d", &permutacao[a]);
    }
    permutacao[n+1] = n+1;
    
    /*Continuacao*/
    while(continuar){
        busca_troca(permutacao, n, &pos_i, &pos_j, &continuar);
        transposicao_prefixo(pos_i, pos_j, permutacao, n);
        for(a = 1; a <= n; a++){
            printf("%d ", permutacao[a]);
        }
        printf("\n");
    }
    
    return 0;
}
