/* Henrique Noronha Facioli
 * RA : 157986
 * Fringe
 */

#include <stdio.h>

int main(){
    /*sequencia e' a variavel para armazenar o tamanho da sequencia de 0s e 1s
     *leitura é o termo scaneado pelo computador
     */
    int fatorS, mols, sequencia = 0, sequencia_2 = 0, sequencia_aux = 0, sequencia_maior = 0, numero_fase = 0, existe_fase = 0;
    int leitura, leitura_anterior, numero_mols;

    /*Leitura de Mols e do Fator S*/
    scanf("%d %d",&mols , &fatorS);

    /* Inicio da sequencia de 1s e 0s que e' nescessario desconsiderar */
    scanf("%d", &leitura);
    do{
        leitura_anterior = leitura;
        scanf("%d", &leitura);
    }while(leitura == leitura_anterior);

    /* O código le 2 sequencias seguidas e compara para ver se possuem o mesmo numero de termos desde que nao comecem com -1 */
    while(leitura != -1){
        /*Zera as sequencias*/
        if(leitura != -1){
            sequencia_aux = sequencia_2;
            sequencia_2 = sequencia;
            sequencia = 1;
        }
        /** Leitura de uma sequencia **/
        if(leitura != -1){
            leitura_anterior = leitura;
            scanf("%d", &leitura);
        }
        while((leitura == leitura_anterior) && (leitura != -1)){
            sequencia++;
            leitura_anterior = leitura;
            scanf("%d", &leitura);
        }
        
        /* Compara as duas sequencias lidas; primeiro, se as duas sequencias são iguais e nao houve nenhuma sequencia ainda, segundo se as sequencias são iguais mas são a maior sequencia encontada, a terciera é para caso ache mais uma sequencia do maior tamanho ja encontrado e a quarta é para não usara a ultima sequencia encontrada antes do -1*/
        if ((existe_fase == 0) && (sequencia == sequencia_2) && (leitura != -1)) {
            existe_fase = 1;
            numero_fase = 2;
            sequencia_maior = sequencia;
        }else if((sequencia == sequencia_2) && (sequencia != sequencia_aux) && (sequencia > sequencia_maior) && (leitura != -1)){
            sequencia_maior = sequencia;
            numero_fase = 2;
        }else if((sequencia == sequencia_2) && (sequencia != sequencia_aux) && (sequencia == sequencia_maior) && (leitura != -1)){
            numero_fase = numero_fase + 2;
        }else if((sequencia == sequencia_2) && (sequencia == sequencia_aux) && (leitura != -1)  && (sequencia == sequencia_maior)){
                    numero_fase++;
        }else if((sequencia > sequencia_maior) && (leitura == -1)){
            numero_fase = 0;
        }
        
        /**Leitura da sequencia posterior**/
        if(leitura != -1){
            sequencia_aux = sequencia_2;
            sequencia_2 = sequencia;
            sequencia = 1;
            leitura_anterior = leitura;
            scanf("%d", &leitura);
        }
        while((leitura == leitura_anterior) && (leitura != -1)){
            sequencia++;
            leitura_anterior = leitura;
            scanf("%d", &leitura);
        }

        /*Compara as duas sequencias lidas, assim como anteriormente*/
        if ((existe_fase == 0) && (sequencia == sequencia_2) && (leitura != -1)) {
            existe_fase = 1;
            numero_fase = 2;
            sequencia_maior = sequencia;
        }else if((sequencia == sequencia_2) && (sequencia != sequencia_aux) && (sequencia > sequencia_maior) && (leitura != -1)){
            sequencia_maior = sequencia;
            numero_fase = 2;
        }else if((sequencia == sequencia_2) && (sequencia != sequencia_aux) && (sequencia == sequencia_maior) && (leitura != -1)){
            numero_fase = numero_fase + 2;
        }else if((sequencia == sequencia_2) && (sequencia == sequencia_aux) && (leitura != -1)  && (sequencia == sequencia_maior)){
                    numero_fase++;
        }else if((sequencia > sequencia_maior) && (leitura == -1)){
            numero_fase = 0;
        }
    }
    /*Acha o numero de mols, e caso houve mais fases que o fator S, imprime quantos mols foram*/
    numero_mols = mols*sequencia_maior;

    if (numero_fase >= fatorS) {
        printf("%d mols\n",numero_mols);
    }else{
        printf("Portal nao abriu\n");
    }
    
    return 0;
    
}
