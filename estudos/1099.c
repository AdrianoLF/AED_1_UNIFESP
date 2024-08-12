#include <stdio.h>
int somaImpares(int X, int Y) {
    int soma = 0;
    if (X > Y) {
        int temp = X;
        X = Y;
        Y = temp;
    }
    for (int i = X + 1; i < Y; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }
    return soma;
}
int main() {
    int N;
    scanf("%d", &N);
    for (int caso = 0; caso < N; caso++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        int resultado = somaImpares(X, Y);
        printf("%d\n", resultado);
    }
    return 0;
}
