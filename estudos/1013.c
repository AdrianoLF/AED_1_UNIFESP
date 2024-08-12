#include<stdio.h>

#include<math.h>

int main()

{
    int x, y, z, maxxy, max;
    scanf("%d %d %d", &x, &y, &z);
    maxxy = ((x + y + abs(x - y)) / 2);
    max =  ((maxxy + z + abs(maxxy - z)) / 2);
    printf("%d eh o maior\n", max);
    return 0;
}