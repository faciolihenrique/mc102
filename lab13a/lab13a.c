/* * * * * * * * * * * * * * * * * *
 * Henrique Noronha Facioli		    *
 * RA : 157986				        *
 * henrique.facioli@gmail.com      *
 * henrique.facioli@ic.unicamp.br  *
 * github : henriquefacioli        * 
 * * * * * * * * * * * * * * * * * */

#include <stdio.h>

/*Funcao que faz a soma dos pesos dos móbiles*/
int soma_pesos(int *equilibrio);

int main(){
    /*Variaveis para armazenar a soma e flag para equilibrio*/
    int equilibrio = 1, soma = 0;
    soma = soma_pesos(&equilibrio);
    
    /*Faze de impressa, se esta equilibrado ou nao e do peso*/
    if(equilibrio){
        printf("Mobile equilibrado");
    }else{
        printf("Mobile desequilibrado");
    }
    printf("\nPeso total: %d\n", soma);
    
    return 0;
}


int soma_pesos(int *equilibrio){
    /*Variaveis para armazenar os pesos e distancias lidas*/
    int peso1, dist1, peso2, dist2;
    
    /*Leitura dos pesos e distancia*/
    scanf("%d %d %d %d", &peso1, &dist1, &peso2, &dist2);
    
    /*Caso em que a barra da esquerda esta ligada a outra barra*/
    if(peso1 == 0){
          peso1 = soma_pesos(equilibrio);
    }   
    /*Caso em que a barra da direita esta ligada a outra barra*/ 
    if(peso2 == 0){
          peso2 = soma_pesos(equilibrio);
    }
    /*Se a funcao ja entrou nos casos acima, significa que os pesos nao sao
     * mais zeros, entao pode ver se ha o equilibrio*/
    if(peso1 * dist1 != peso2 * dist2){
        *equilibrio = 0;
    }
    
    return peso1 + peso2;
}
