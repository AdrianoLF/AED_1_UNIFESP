#include <stdio.h>
 
int main() {
    int n, valor = 0;
	scanf("%d", &n);

    for (int i = 1; i <= 10; i++) {
      valor += n;
      printf("%d x %d = %d\n", i, n, valor);
    }
 
    return 0;
}