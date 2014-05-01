/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Laboratorio 01a - Cálculo de média das notas do semestre
 */
#include <stdio.h>
#include <math.h>

int main(){
    double p1, p2, p3, L, P, MA, MH, MG;
    /*printf("Digite a notas da P1, P2, P3 e dos trabalhos de laboratorios, nessa ordem :\n");*/
    scanf("%lf %lf %lf %lf", &p1, &p2, &p3, &L);
    P = ((3*p1)+(3*p2)+(4*p3))/10;
    MA = (P + L)/2;
    MH = (2*P*L)/(P+L);
    MG = sqrt(P*L);
    printf("Media aritmetica: %.1f\nMedia harmonica: %.1f\nMedia geometrica: %.1f\n",MA,MH,MG);
    return 0;
}