/* Henrique Noronha Facioli
 * RA : 157986
 * Lab 11b - BibTeX
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Registro*/
struct Campos{
    char label[451];
    char title[501];
    char author[501];
    char journal[101];
    char year[51];
    char volume[51];
    char number[51];
    char page[51];
    int preferencia;
};
typedef struct Campos Campos;

/*Funcoes*/
int leitura_numero_articles();
void leitura_article(Campos articles[], int num);
int leitura_linha_article(Campos articles[], int num);
int buscar_letra(char vetor[], char letra);
void ordenacao(Campos articles[], int N);
void impressao(Campos articles[], int i);
void zerar_vetor(Campos articles[], int N);

/*Bloco princial*/
int main(){
    /*Declaracao variavel*/
    Campos *articles;
    int n;
    int i;
    /*Leitura do numero de articles fonecidos*/
    n = leitura_numero_articles();
    /*Alocacao dinamica do numero n de articles*/
    articles = malloc(n*sizeof(Campos));
    
    zerar_vetor(articles, n);
    
    /*Leitura do texto fornecido*/
    for(i = 0; i < n; i++){
        leitura_article(articles, i);
    }
    
    /*Ordena o veor ja lido*/
    ordenacao(articles, n);
    
    
    /*Impressao da bibliografia de modo odenado*/
    for(i = 0 ; i < n; i++){

       impressao(articles , i);
    }
    
    free(articles);
    return 0;
}



/*Funcao para ler a primeira linha,desconsiderando o %, (trash)*/
int leitura_numero_articles(){
    char trash;
    int N;
    scanf("%c", &trash);
    scanf("%d\n", &N);
    return N;
}

/*Zerar*/
/* Coloca em toda primeira posicao \0, para diferenciar dos campos usados*/
void zerar_vetor(Campos articles[], int N){
    int i;
    for(i = 0; i < N; i++){
        articles[i].title[0] = '\0';
        articles[i].author[0] = '\0';
        articles[i].journal[0] = '\0';
        articles[i].volume[0] = '\0';
        articles[i].number[0] = '\0';
        articles[i].page[0] = '\0';
        articles[i].year[0] = '\0';
    }

}

/*Leitura de cada article*/
/*Le cada linha enquanto não chegar ao final do articles(retorno 0)
 */
void leitura_article(Campos articles[], int num){
    int linha = 1;
    /*Pegar o pulo de linha(\n)*/
    getchar();
    /*Define qual é o article lido, somente para caso existam dois iguais*/
    articles[num].preferencia = num;
    
    while(linha != 0){
        linha = leitura_linha_article(articles, num);
        
    }        
}

/*Leitura de linha*/
/*Faz a leitura de uma unica linha e procura o que ela contem:
 *Pela primeira letra ele sabe sobre o topico( title, journal...)que 
 *a linha se trata, ja que não existem 2 com o mesmo comeco,
 *A partir dessa informacao, copia para o vetor de Campos a informa-
 *cao contida na linha que esta entre '{' e '}'
 */
int leitura_linha_article(Campos articles[], int num){
    char linha[520];
    int i, j; 
    
    /*Leitura da linha*/
    fgets(linha, 520 , stdin);
    
    /*Procura onde inicar a copia ( depois do '{')*/
    i = buscar_letra(linha, '{') + 1;
    j = 0;
    
    if(linha[0] == '@'){
        while(linha[i] != ','){
            articles[num].label[j] = linha[i];
            i++;
            j++;
        }
        articles[num].label[j] = '\0';
    }else if(linha[1] == 't'){
        while(linha[i] != '}'){
            articles[num].title[j] = linha[i];
            i++;
            j++;
        }
        articles[num].title[j] = '\0';
    }else if(linha[1] == 'a'){
        while(linha[i] != '}'){
            articles[num].author[j] = linha[i];
            i++;
            j++;
        }
        articles[num].author[j] = '\0';
    }else if(linha[1] == 'j'){
        while(linha[i] != '}'){
            articles[num].journal[j] = linha[i];
            i++;
            j++;
        }
        articles[num].journal[j] = '\0';
    }else if(linha[1] == 'y'){
        while(linha[i] != '}'){
            articles[num].year[j] = linha[i];
            i++;
            j++;
        }
        articles[num].year[j] = '\0';
    }else if(linha[1] == 'v'){
        while(linha[i] != '}'){
            articles[num].volume[j] = linha[i];
            i++;
            j++;
        }
        articles[num].volume[j] = '\0';
    }else if(linha[1] == 'n'){
        while(linha[i] != '}'){
            articles[num].number[j] = linha[i];
            i++;
            j++;
        }
        articles[num].number[j] = '\0';
    }else if(linha[1] == 'p'){
        while(linha[i] != '}'){
            articles[num].page[j] = linha[i];
            i++;
            j++;
        }
        articles[num].page[j] = '\0';
    }else if(linha[0] == '}'){
        return 0;
    }
    return 1;
}

/*Buscas Letra*/
/*Procura em uma string pela letra desejada, se encontrada,
 *retorna a sua posicao na string*/
int buscar_letra(char string[], char letra){
    int i;
    for(i = 0;(string[i] != '\n') && (string[i] != '\0'); i++){
        if(string[i] == letra){
            return i;
        }
    }
    return 0;
}

/*Ordenacao da impressao*/
/*Selection Sort que ordena o vetor de Campos por ordem alfabetica do Title*/
void ordenacao(Campos articles[], int N){
    Campos aux;
    int i, j, maior;
    for(i = 0; i < N; i++){
        maior = i;
        for(j = i; j < N; j++){
            if(strcmp(articles[maior].title, articles[j].title) > 0){
                maior = j;
            }else if(strcmp(articles[maior].title, articles[j].title) == 0){
                if(articles[maior].preferencia > articles[j].preferencia){
                    maior = j;
                }
            }
        }
        if(maior != i){
            aux = articles[i];
            articles[i] = articles[maior];
            articles[maior] = aux;
        }
    }
}

/*Funcao para fazer a impressao do modo que foi ordenado,
 *Somente imprimindo os campos que foram utilizados
 */
void impressao(Campos articles[], int i){
    if(articles[i].title[0] != '\0'){
        printf("%s", articles[i].title);
    }
    if(articles[i].author[0] != '\0'){
        printf(", %s", articles[i].author);
    }
    if(articles[i].journal[0] != '\0'){
        printf(", %s", articles[i].journal);
    }
    if(articles[i].volume[0] != '\0'){
        printf(", %s", articles[i].volume);
    }
    if(articles[i].number[0] != '\0'){
        printf(", %s", articles[i].number);
    }
    if(articles[i].page[0] != '\0'){
        printf(", %s", articles[i].page);
    }
    if(articles[i].year[0] != '\0'){
        printf(", %s", articles[i].year);
    }
    printf(".\n\n");
}
