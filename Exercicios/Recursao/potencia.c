/* * * * * * * * * * * * * * * * * *
 * Henrique Noronha Facioli		    *
 * RA : 157986				        *
 * henrique.facioli@gmail.com      *
 * henrique.facioli@ic.unicamp.br  *
 * github : henriquefacioli        * 
 * * * * * * * * * * * * * * * * * */

#include <stdio.h>

int potencia(int n, int k);

int main(){
    int numero;
    numero = potencia(2, 10);
    
    printf("%d", numero);
    return 0;
}

int potencia(int n, int k){
    if(k == 0){
        return 1;
    }
    return (n * potencia(n, k-1));
}
