#include <stdio.h>

int main() {
    int N, qtd, total_cobaias = 0;
    int coelhos = 0, ratos = 0, sapos = 0;
    char tipo;
    float perc_coelhos, perc_ratos, perc_sapos;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %c", &qtd, &tipo);
        total_cobaias += qtd;
        if (tipo == 'C') {
            coelhos += qtd;
        } else if (tipo == 'R') {
            ratos += qtd;
        } else if (tipo == 'S') {
            sapos += qtd;
        }
    }
    perc_coelhos = (coelhos * 100.0) / total_cobaias;
    perc_ratos = (ratos * 100.0) / total_cobaias;
    perc_sapos = (sapos * 100.0) / total_cobaias;
    printf("Total: %d cobaias\n", total_cobaias);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", perc_coelhos);
    printf("Percentual de ratos: %.2f %%\n", perc_ratos);
    printf("Percentual de sapos: %.2f %%\n", perc_sapos);
    return 0;
}