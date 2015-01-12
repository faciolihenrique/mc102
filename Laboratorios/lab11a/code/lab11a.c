/* Henrique Noronha Facioli
 * RA : 157986
 * Lab 11a - Copa do Mundo
 */

#include <stdio.h>
#include <string.h>

#define QUANTIDADEdeTIMES 32

/*Declaracao do registro Caracteristicas, que armazenara as caractersiticas dos times*/
struct Caracteristicas{
    char nome[15];
    char grupo;
    int pontos;
    int gols_feitos;
    int gols_tomados;
    int saldo_gols;
};

typedef struct Caracteristicas Caracteristicas;

void zerar(Caracteristicas time[]);
void insere_pontuacao(Caracteristicas time[], int k ,int gols_feitos,int gols_tomados);
void insere_time(Caracteristicas time[], int k, char nome_time[]);
void busca_time(Caracteristicas time[], char nome_time[],int *posicao);
void ordenacao(Caracteristicas time[], int indice);

int main(){
    /*Declaracao de variaveis*/
    Caracteristicas time[QUANTIDADEdeTIMES];
    int posicao_time;
    char nome_time1[15], nome_time2[15];
    int gols_time1, gols_time2;
    int i, j;
    
    /*Zera os pontos, e os gols de todos os times*/
    zerar(time);
    
    /*Leitura da matriz*/
    for(i = 0; i < 48; i++){
        scanf("%s %d x %d %s", nome_time1, &gols_time1, &gols_time2, nome_time2);
        /*Procura se o maior time digitado ja existe, adcionando-o ao registro se nao
         *e adicionando o numero de gols levados e feitos
         */
        busca_time(time, nome_time1, &posicao_time);
        insere_pontuacao(time, posicao_time, gols_time1, gols_time2);
        /*Faz o mesmo que foi feito ao time 1 ao time 2
         */
        busca_time(time, nome_time2, &posicao_time);
        insere_pontuacao(time, posicao_time, gols_time2, gols_time1);
    }
    
    for(i = 0; i < 32 ; i = i+4){
        ordenacao(time, i);
    }
    
    /*Impressao da matriz ordenada com os grupos*/
    for(i = 0; i < 8; i++, j = 0){
        printf("Grupo %c:\n", time[4*i + j].grupo);
        for(j = 0; j < 4; j++){
             printf("%-15s %3d %3d %3d %3d\n", time[4*i + j].nome, time[4*i + j].pontos, time[4*i + j].gols_feitos, time[4*i + j].gols_tomados, time[4*i + j].saldo_gols);
        }
        printf("\n");
    }
    
    /*Impressao dos jogos da 8 de final*/
    printf("Oitavas de final:\n");
    for(i = 0; i < 32;i = i+8){
        printf("%15s x %s\n", time[i].nome, time[i+5].nome);
        printf("%15s x %s\n", time[i+4].nome, time[i+1].nome);
    }
    
    return 0;
}



/*INICIO DAS FUNCOES*/

/*Checa se ja existe um time com o nome informado, se sim retorna a sua posicao
 *se nao, retorna a ultima posicao que esta livre para ser escrita
 */
void busca_time(Caracteristicas time[], char nome_time[],int *posicao){
    int i, acabou = 0;
    for(i = 0; i < QUANTIDADEdeTIMES && !acabou; i++){
        if(strcmp(nome_time, time[i].nome) == 0){
            *posicao = i;
            acabou = 1;
        }else if(strcmp("NAOHA", time[i].nome) == 0){
            insere_time(time, i, nome_time);
            *posicao = i;
            acabou = 1;
        }
    }
}

/*Insere o nome de um time ao registro na posicao k do vetor*/
void insere_time(Caracteristicas time[], int k, char nome_time[]){
    strcpy(time[k].nome, nome_time);
}

/*Adiciona a pontuacao ao time da posicao k*/
void insere_pontuacao(Caracteristicas time[], int k ,int gols_feitos,int gols_tomados){
    time[k].gols_feitos += gols_feitos;
    time[k].gols_tomados += gols_tomados;
    time[k].saldo_gols = time[k].gols_feitos - time[k].gols_tomados;
    if(gols_feitos > gols_tomados){
        time[k].pontos += 3; 
    }else if(gols_feitos == gols_tomados){
        time[k].pontos += 1;
    }
}

/*Zera o numero de pontos, os gols marcados e tomados e adiciona a grupo aos times*/
void zerar(Caracteristicas time[]){
    int i;
    for(i = 0; i < QUANTIDADEdeTIMES; i++){
        time[i].pontos = 0;
        time[i].gols_feitos = 0;
        time[i].gols_tomados = 0;
        time[i].saldo_gols = 0;
        strcpy(time[i].nome, "NAOHA");
        if(i < 4){
            time[i].grupo = 'A';
        }else if(i < 8){
            time[i].grupo = 'B';
        }else if(i < 12){
            time[i].grupo = 'C';
        }else if(i < 16){
            time[i].grupo = 'D';
        }else if(i < 20){
            time[i].grupo = 'E';
        }else if(i < 24){
            time[i].grupo = 'F';
        }else if(i < 28){
            time[i].grupo = 'G';
        }else if(i < 32){
            time[i].grupo = 'H';
        }
        
        
    }
}


/*Ordena o vetor time usando o selection sort,
 *ordenando de 4 em 4, de modo que organize apenas
 *os grupos
 */
void ordenacao(Caracteristicas time[], int indice){
    Caracteristicas aux;
    int i, j, maior;
    for(i = indice; i < (indice + 4); i++){
        maior = i;
        for(j = i+1; j < indice+4; j++){
            /*Compara quem tem mais pontos*/
            if(time[maior].pontos < time[j].pontos){
                maior = j;
            }else if(time[maior].pontos == time[j].pontos){
                /*Compara quem tem maior saldo de gols caso haja empate nos pontos*/
                if(time[maior].saldo_gols < time[j].saldo_gols){
                    maior = j;
                }else if(time[maior].saldo_gols == time[j].saldo_gols){
                    /*Compara gols feitos caso haja empate no saldo de gols*/
                    if(time[maior].gols_feitos < time[j].gols_feitos){
                        maior = j;
                    }else if(time[maior].gols_feitos == time[j].gols_feitos){
                        /*Compara a ordem alfabetica dos times*/
                        if(strcmp(time[maior].nome, time[j].nome) > 0){
                            maior = j;
                        }
                    }
                }
            }
        }
        /*Faz a troca*/
        aux = time[i];
        time[i] = time[maior];
        time[maior] = aux;
    }
}
