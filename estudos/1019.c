#include<stdio.h>
int main(){
   int hr, min, s, n;
   scanf("%d", &n);
   hr = n / 3600;
   min = n % 3600 / 60;
   s = n % 60;
   printf("%d:%d:%d\n", hr, min, s);
   return 0;
}