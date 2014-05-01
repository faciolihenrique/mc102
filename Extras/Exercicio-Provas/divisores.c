#include <stdio.h>
int main(){
	int numero, i;
	printf("Numero: ");
	scanf("%d",&numero);
	for(i = numero;i != 0;i--){
		if(numero%i == 0)
			printf("%d\n",i);
	}
	return 0;
}
