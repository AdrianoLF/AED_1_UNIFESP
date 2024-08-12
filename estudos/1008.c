#include <stdio.h>

int main() {

    int n, h;
    float valorhr, salario;
    scanf("%d\n%d\n%f", &n, &h, &valorhr);
    salario = h * valorhr;
    printf("NUMBER = %d\n", n);
    printf("SALARY = U$ %.2f\n", salario);

    return 0;
}
