/* Henrique Noronha Facioli
 * RA : 157986
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
    char nome[30];
    char sobrenome[60];
    char cpf[12];
    int emUso;
};
typedef struct Pessoa Pessoa;


int main(){

}

void criar_cadastro(Pessoa *p){
    printf("----Cadastrando Fruta----\n")
    
    printf("Digite o nome : ");
    setbuf(stdin, 0);
    fgets(p.nome, 30, stdin);
    printf("\n");
    
    printf("Digite o sobrenome : ")
    fgets(p.sobrenome, 60, stdin);
    printf("\n");
    
    printf("Digite o CPF : ")
    scanf("%s", &p.cpf);
}

void zerar(Pessoa vetor[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        vetor[i].emUso = 0;
    }
}