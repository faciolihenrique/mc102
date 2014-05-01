/* Henrique Noronha Facioli
 * RA: 157986
 * Tarefa 02b de mc102qrst — Pedra - Papel - Tesoura - Lagarto - Spock
 *
 * O cógigo recebe o numero de jogadas que serão feitas (n),em seguida
 recebe n vezes os valores das jogadas feitas por Sheldon (s) e Leonard (l), e 
 atravez dos dados oferecidos no problema, computa quem foi o ganhador da rodada 
 , imprime quem ganhou e adiciona o ponto ao vencedor,(psheo) para Sheldon e 
 (pleo) para Leonard.
 */

#include <stdio.h>

int main(){
    int i, n, l, s, pleo = 0, pshel = 0;
  
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d %d",&s ,&l);
        /* Caso Empate*/
        if(s == l){
            printf("Empate\n");
            
        }
        /*Pedra e Papel */
        else if (s == 1 && l == 2){
            printf("Leonard: Papel embrulha Pedra\n");
            pleo++;
            
        }else if (s == 2 && l ==1){
            printf("Sheldon: Papel embrulha Pedra\n");
            pshel++;
            
        }
        /*Pedra e Tesoura*/
        else if (s == 1 && l == 3){
            printf("Sheldon: Pedra quebra Tesoura\n");
            pshel++;
            
        }else if (s == 3 && l ==1){
            printf("Leonard: Pedra quebra Tesoura\n");
            pleo++;
        }
        /*Pedra e Lagarto*/
        else if (s == 1 && l == 4){
            printf("Sheldon: Pedra amassa Lagarto\n");
            pshel++;
            
        }else if (s == 4 && l == 1){
            printf("Leonard: Pedra amassa Lagarto\n");
            pleo++;
            
        }
       /*Pedra e Spock*/
       else if(s == 1 && l == 5){
           printf("Leonard: Spock vaporiza Pedra\n");
           pleo++;
           
       }else if(s == 5 && l == 1){
           printf("Sheldon: Spock vaporiza Pedra\n");
           pshel++;
           
       }
       /*Papel e Tesoura*/
       else if(s == 2 && l == 3){
           printf("Leonard: Tesoura corta Papel\n");
           pleo++;
           
       }else if(s == 3 && l == 2){
           printf("Sheldon: Tesoura corta Papel\n");
           pshel++;
           
       }
       /*Papel e Lagarto*/
       else if(s == 2 && l == 4){
           printf("Leonard: Lagarto come Papel\n");
           pleo++;
       }else if(s == 4 && l == 2){
           printf("Sheldon: Lagarto come Papel\n");
           pshel++;
       }
       /*Papel e Spock*/
       else if(s == 2 && l == 5){
           printf("Sheldon: Papel refuta Spock\n");
           pshel++;
       }else if(s == 5 && l == 2){
           printf("Leonard: Papel refuta Spock\n");
           pleo++;   
       }
       /*Tesoura e Lagarto*/
       else if(s == 3 && l == 4){
           printf("Sheldon: Tesoura decepa Lagarto\n");
           pshel++;
       }else if(s == 4 && l == 3){
           printf("Leonard: Tesoura decepa Lagarto\n");
           pleo++;
       }
       /*Tesoura e Spock*/
       else if(s == 3 && l == 5){
           printf("Leonard: Spock quebra Tesoura\n");
           pleo++;
       }else if(s == 5 && l == 3){
           printf("Sheldon: Spock quebra Tesoura\n");
           pshel++;
       }
       /*Lagarto e Spock*/
       else if(s == 4 && l == 5){
           printf("Sheldon: Lagarto envenena Spock\n");
           pshel++;
       }else if( s == 5 && l == 4){
           printf("Leonard: Lagarto envenena Spock\n");
           pleo++;
       }
    }
    printf("Sheldon %d x %d Leonard\n", pshel, pleo);
    return 0;
}