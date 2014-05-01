/* Nome: Henrique Noronha Facioli
 * RA: 157986
 * Lab 02a - INSS e IRPF
 */
#include <stdio.h>

int main(){
    double S, INSS, IRPF, BaseIRPF;
    int D;
    scanf("%lf %d", &S, &D);
    if (S <= 1317.07){
        INSS = 0.08 * S;
    }else if (S >= 1317.08 && S <= 2195.12){
        INSS = 0.09 * S;
    }else if (S >= 2195.13 && S <= 4390.24){
        INSS = 0.11 * S;
    }else if (S > 4390.24){
        INSS = 482.93;
    }
    
    BaseIRPF = (S-(INSS+(D*179.71)));
    
    if (BaseIRPF <= 1787.77){
        IRPF = 0;
    }else if (BaseIRPF >= 1787.78 && BaseIRPF <= 2679.29){
        IRPF = (0.075 * (BaseIRPF-1787.78));
    }else if (BaseIRPF >= 2679.30 && BaseIRPF <= 3572.43){
        IRPF = (0.15 * (BaseIRPF-2679.30)) + (0.075*(2679.29-1787.78));
    }else if (BaseIRPF >= 3572.44 && BaseIRPF <= 4463.81){
        IRPF = (0.225 * (BaseIRPF-3572.44)) + (0.15*(3572.43-2679.30)) + (0.075*(2679.29-1787.78));
    }else if (BaseIRPF > 4463.81){
        IRPF = (0.275 * (BaseIRPF-4463.81)) + (0.225*(4463.81-3572.44)) + (0.15*(3572.43-2679.30)) + (0.075*(2679.29-1787.78));
    }
    printf("INSS: R$ %.2f\nBase: R$ %.2f\nIRPF: R$ %.2f\n", INSS, BaseIRPF, IRPF);
    return 0;
}