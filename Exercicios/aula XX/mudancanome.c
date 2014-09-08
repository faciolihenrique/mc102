#include <stdio.h>
#include <string.h>

/* Tamanho do vetor usado como cadastro */
#define TAM 5 

struct Aluno {
  char nome[100];
  int RA;
};
typedef struct Aluno Aluno;

/* Funcao que imprime todo o conteudo do cadastro */
void imprimeCadastro(char nomeArq[]);
/* Funcao que altera o nome de uma pessoa, dado seu RA */
void alteraNome(int ra, char nome[], char nomeArq[]);

int main() {
    /* Nome do arquivo do cadastro de alunos */
    char nomeArq[] = "alunos.bin";
    Aluno cadastro[TAM] = { {"Joao da Silva", 111111},{"Jose Souza", 121212}, {"Luis Santos", 131313},{"Maria Pereira", 141414}, {"Ana Alves", 151515} };
    
    /* Abre o arquivo para escrita */
    FILE *arq = fopen(nomeArq, "w+b");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de cadastro de alunos.\n");
        return 0;
    }
    
    /*Escreve o cadastro em arquivo.bin*/
    fwrite(cadastro, sizeof(Aluno), TAM, arq);
    fclose(arq);
    
    imprimeCadastro(nomeArq);
    
    alteraNome(131313, "Luisa Saints", nomeArq);
    
    imprimeCadastro(nomeArq);
    
    return 0;    
}

void imprimeCadastro(char nomeArq[]) {
    Aluno aluno;
    /* Abre o arquivo para leitura */
    FILE *arq = fopen(nomeArq, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de cadastro de alunos.\n");
        return;
    }
    printf("----- Imprimindo Cadastro -----\n");
    while (fread(&aluno, sizeof(Aluno), 1, arq)){
        printf("%06d %s\n", aluno.RA, aluno.nome);
    }
    printf("\n");
    fclose(arq);
}

void alteraNome(int ra, char nome[], char nomeArq[]) {
    Aluno aluno;
    int OK = 0;
    /* Abre o arquivo para leitura e escrita */
    FILE *arq = fopen(nomeArq, "r+b");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de cadastro de alunos.\n");
        return;
    }
    while ((OK == 0) && fread(&aluno, sizeof(Aluno), 1, arq)){
        if (aluno.RA == ra) {
        /* Altera o nome no registro */
        strcpy(aluno.nome, nome); 
        /* Volta uma posicao */
        fseek(arq, -1 * sizeof(Aluno), SEEK_CUR);
        /* Sobrescreve o registro */
        fwrite(&aluno, sizeof(Aluno), 1, arq);
        OK = 1;
        }
    }
    fclose(arq);
}
