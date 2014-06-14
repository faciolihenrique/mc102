/* * * * * * * * * * * * * * * * * *
 * Henrique Noronha Facioli		    *
 * RA : 157986				        *
 * henrique.facioli@gmail.com      *
 * henrique.facioli@ic.unicamp.br  *
 * github : henriquefacioli        * 
 * Lab 14a -Gerenciador de memoria *
 * * * * * * * * * * * * * * * * * */

#include <stdio.h>

/*Funcao para fazer a leitura e verificar a alocacao da memoria*/
void alocacao(int *memoria_livre, int *alocada);
/*Funcao para fazer a impressao desejada*/
void impressao(int livre, int alocada);

int main(){
    int memoria_livre = 1, memoria_alocada = 0;
    
    alocacao(&memoria_livre, &memoria_alocada);
    impressao(memoria_livre, memoria_alocada);
    
    return 0;
}


/*A memoria quando é iniciada contem um unico espaco,
 *Se for lido #, nada eh executado
 *quando é lido D, divide-se a memoria em 3,fazendo com
 *que haja 2 espacos livre e uma alocacao: (livre+2, e alocacao+1) 
 *Se nao é lido D,é lido I, entao só eh alocado um espaco
 *(alocada+1) e nao ocorre a criacao de memoria livre 
 */
void alocacao(int *memoria_livre, int *memoria_alocada){
    char tipo;
    /*Leitura da letra*/
    scanf("%c", &tipo);
    
    /*Inicio da verificacao das letras descrita acima*/
    if(tipo != '#'){
        if(tipo == 'D'){
            *memoria_livre += 2;    
        }
        *memoria_alocada += 1;
        alocacao(memoria_livre, memoria_alocada);
    }
    
}

/*1 Se existir mais espacos alocados que livres, ela eh invalida
 *2 Se alocados e livres forem iguais, é porque houve alocacao total
 *3 Se livre for maior que a parcial, existe memoria disponivel(parcial)
 */
void impressao(int livre, int alocada){
    if(livre < alocada){
        printf("Alocacao invalida\n");
    }else if(livre == alocada){
        printf("Alocacao total\n");
    }else if(livre > alocada){
        printf("Alocacao parcial\n");
    }
}
