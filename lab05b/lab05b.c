#include <stdio.h>

int main(){
    /* Inicializacao de strings e variaveis*/
    char mRNA[100], oligo[25], inverso_oligo[25];
    int tR, tO, i, j, aux, flag = 1;
    /*Entrada do programa; tamanha do mRNA e do Oligo, e quais são o mRNA e Oligo*/
    scanf("%d %d",&tR, &tO);
    scanf("%s",mRNA);
    scanf("%s",oligo);
    
    /*Invertendo o oligo e tornando-o sua base inversa
     *faz o char que esta na ultima-1 se tornar o primeiro
     *e assim por diante... (penultimo-1 -> 2) e o ultimo char = '\0'
     *
     */
    i = 0;
    inverso_oligo[tO] = '\0';
    do{
        inverso_oligo[i] = oligo[tO-(1+i)];
        if(inverso_oligo[i] == 'A'){
            inverso_oligo[i] = 'U';
        }else if(inverso_oligo[i] == 'U'){
            inverso_oligo[i] = 'A';
        }else if(inverso_oligo[i] == 'C'){
            inverso_oligo[i] = 'G';
        }else if(inverso_oligo[i] == 'G'){
            inverso_oligo[i] = 'C';
        }
        i++;
    }while(i <= tO);
    
    /*Procurar na mRNA se existe a inverso_oligo:
     *para isso, o programa varia o mRNA[0 -> (tR-tO)] e compara com o primeiro digito de inverso_oligo
     *se forem iguais, ele continua a comparação com os proximos de mRNA e inverso_oligo, e se todos foram iguais ele imprime silenciado
     *se nao, ele vai para o proximo mRNA e continua comparando, até que chegue em tR-tO, que é o ultimo para poder fazer comparacao, e se
     *nao encontrar nenhum igual, imprime, Nao silenciado.
     */
    for(i = 0;(i <= (tR-tO)) && (flag); i++){
        aux = i;
        j = 0;
        if(mRNA[aux] == inverso_oligo[j]){
            while(mRNA[aux] == inverso_oligo[j]){
                if(j == tO-1){
                    flag = 0;
                    printf("Silenciado em %d\n",i+1);
                }
                j++;
                aux++;
            }
        }
        if(i == (tR-tO) && flag){
            printf("Nao silenciado\n");
        }
    }    
    return 0;
}
