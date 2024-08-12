#include<stdio.h>

int main(){
    int tempo, media;
    float combs;
     scanf("%d %d", &tempo, &media);
     combs = ((tempo * media) / 12.0);
     printf("%.3f\n", combs);
     return 0;
}