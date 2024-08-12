#include <stdio.h>

int main() {
    int c1, c2, n1, n2;
    float v1, v2, pagar;
    scanf("%d %d %f\n%d %d %f", &c1, &n1, &v1,
                                &c2, &n2, &v2);
    pagar = n1 * v1 + n2 * v2;
    printf("VALOR A PAGAR: R$ %.2f\n", pagar);

    return 0;
}