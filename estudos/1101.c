#include <stdio.h>


int main () {

  int m = 1, n = 1, i = 0, sum = 0, aux = 0;
  scanf("%d %d", &m, &n);

  while (m > 0 && n > 0)
  {

    if (n < m)
    {

      aux = m;
      m = n;
      n = aux;

    }

    for (i = m; i <= n; i++)
    {

        sum += i;
        printf("%d ", i);

    }

    printf("Sum=%d\n", sum);
    sum = 0;
    scanf("%d %d", &m, &n);
    
  }
}