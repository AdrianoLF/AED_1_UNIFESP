#include <stdio.h>

int main() {

    char nome[20];
    double fix, totalVendas, receber;
    scanf("%s\n%lf\n%lf", &nome, &fix, &totalVendas);
    receber = fix + 0.15 * totalVendas;
    printf("TOTAL = R$ %.2lf\n", receber);

    return 0;
}
