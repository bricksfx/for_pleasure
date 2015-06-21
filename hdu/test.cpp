#include<stdio.h>
int f[100] = {0, 1, 2, 4, 6, 9};

void get_m()
{
    for(int i = 4; i < 100; i++)
    {
       f[i] = f[i-1] + f[i-3] + f[i-4]; 
    }
}

int main()
{
   get_m();
   for(int i = 3; i < 100; i++)
   {
       printf("%d ", f[i]);
   }
   printf("\n");
   int n, m;
   while(scanf("%d %d", &n, &m))
   {
       printf("%d\n", f[n]%m);
   }
   return 0;
}
