/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Laboratorio 01b - Notas do vestibular unicamp
 */

#include <stdio.h>

int main(){
    /*Variaveis, N = Nota, M= Media, DP = Desvio Padrao, A = Grupo, NMO= Nota minima, NP = Nota Padrao, NF = Nota final
     cg = conhecimentos gerais, in = lingua inglesa, po = lingua Poruguesa, ch = conhecimentos humanos, cn = ciencia da natureza
     ma = matematica
     */
    int A, NMO;
    double Pcg, Pin, Ppo, Pma, Pch, Pcn, Ncg, Mcg, DPcg, NPcg;/* Variaveis da primeira fase */
    double Nin, Min, DPin, Npo, Mpo, DPpo, Nma, Mma, DPma, Nch, Mch, DPch, Ncn, Mcn, DPcn, NPin, NPpo, NPma, NPch, NPcn, NF;    /* Variaveis da segunda fase */

    scanf("%d %d", &A, &NMO);
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&Pcg, &Pin, &Ppo, &Pma, &Pch, &Pcn, &Ncg, &Mcg, &DPcg);

    NPcg = ((((Ncg-Mcg)/DPcg)*100))+500;    /*Calcula Nota Padrao : NP = ((N-M)*100/DP)+500) */

    if (NPcg >= 550) {      /* Checa de passa na segunda fase*/
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&Nin, &Min, &DPin, &Npo, &Mpo, &DPpo, &Nma, &Mma, &DPma, &Nch, &Mch, &DPch, &Ncn, &Mcn, &DPcn);

        NPin = ((((Nin-Min)/DPin)*100))+500;    /* Linha 25 ~ 30 , calculo da Nota Padrãro e Final */
        NPpo = ((((Npo-Mpo)/DPpo)*100))+500;
        NPma = ((((Nma-Mma)/DPma)*100))+500;
        NPch = ((((Nch-Mch)/DPch)*100))+500;
        NPcn = ((((Ncn-Mcn)/DPcn)*100))+500;
        NF = ((NPcg*Pcg + NPin*Pin + NPpo*Ppo + NPma*Pma + NPch*Pch + NPcn*Pcn)/(Pcg+Pin+Ppo+Pma+Pch+Pcn));

        printf("Primeira Fase: %.1f\n", NPcg);
        printf("Segunda Fase: %.1f\n", NF);
        if ((A== 1) && (NPma >= NMO) && (NPcn >= NMO)) {    /* Linhas 34 ~ 42 , checagem do grupo */
            printf("Grupo 1\n");
        } else if ((A == 2) && (NPpo >= NMO) && (NPch >= NMO)){
            printf("Grupo 1\n");
        } else if ((A == 3) && (NPcn >= NMO)){
            printf("Grupo 1\n");
        }else{
            printf("Grupo 2\n");
        }
    }else {
        printf("Primeira Fase: %.1f\n", NPcg);
    }
    return 0;
}
