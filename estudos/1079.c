#include <stdio.h>

int main() {
    int Y;
    scanf("%d", &Y);
    for (int i = 0; i < Y; i++) {
        float v1, v2, v3;
        scanf("%f %f %f", &v1, &v2, &v3);
        float media_ponderada = (v1 * 2 + v2 * 3 + v3 * 5) / 10;
        printf("%.1f\n", media_ponderada);
    }
    return 0;
}