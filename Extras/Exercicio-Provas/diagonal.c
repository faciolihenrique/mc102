#include <stdio.h>

int main(){
	int n, i, j;
	printf("Digite um numero: ");
	scanf("%d", &n);
	/*Linha*/
	for(i = 1; i <= n; i++){
		/*Coluna*/
		for(j = 1; j <= n; j++){
		if(j == i){
			printf("X");
		}else{
			printf("+");
		}
		}
		printf("\n");
	}
	return 0;
}
