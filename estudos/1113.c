#include <stdio.h>

int main()
{

    int a, b;
    scanf("%d %d", &a, &b);

    while (a != b)
    {

        if (b > a)
        {

            printf("Crescente\n");
        }
        else
        {

            printf("Decrescente\n");
        }
        scanf("%d %d", &a, &b);
    }
}