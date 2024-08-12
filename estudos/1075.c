#include <stdio.h>

int main() {
    int Y;
    scanf("%d", &Y);
    for (int i = 1; i <= 10000; i++) {
        if (i % Y == 2) {
            printf("%d\n", i);
        }
    }
    return 0;
}
