/* Henrique Noronha Facioli
 * RA : 157986
 * Tarefa 03a de mc102qrst — Composição de senha
 */
#include <stdio.h>

int main(){
    /*'soma' e' o somatorio do valor das letras da linha e 'letras' é o numero de letras contidas na linha*/
    char linha;
    float soma = 0;
    short int letras = 0;
    /* Primeiramente ele repetira o loop enquanto o '*' nao for digitado*/
    do{
        soma = 0;
        letras = 0;
        /*Recolhe o valor de linha e checa quais sao os caracteres nele digitado */
        /*Se o valor digitado for '*', o programa chama a saida pelo return 0 */
        do{
            scanf("%c", &linha);
            if(linha == 'A'){
                soma = soma + 1;
                letras++;
            }else if(linha == 'B'){
                soma = soma + (0.5);
                letras++;
            }else if(linha == 'C'){
                soma = soma + (0.25);
                letras++;
            }else if(linha == 'D'){
                soma = soma + (0.125);
                letras++;
            }else if(linha == 'E'){
                soma = soma + (0.0625);
                letras++;
            }else if(linha == 'F'){
                soma = soma + (0.03125);
                letras++;
            }else if(linha == 'G'){
                soma = soma + (0.015625);
                letras++;
            }else if(linha == 'H'){
                soma = soma + (0.0078125);
                letras++;
            }else if(linha == '*'){
                printf("\n");
                return 0;
            }
        }while(linha != '\n');
        /*Checagem da soma dos valores da linha, se for 1, imprime o numero de letras da linha, se for 0, 0*/
        if(soma == 1){
            printf("%d",letras);
        }else{
            printf("0");
        }
    }while(linha != '*');
    return 0;
}