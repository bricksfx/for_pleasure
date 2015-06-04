#include<stdio.h>
#include<math.h>
#define maxn 1000001
int valid[maxn];

int get_lagest_prime_factor()
{
    
    int tot = 0;
    valid[1] = tot;
    int i, j;
    for(i = 2; i <= maxn; i++)
    {
        if(valid[i] == 0)
        {
            tot++;
            valid[i] = tot;

            for(j = i + i; j < maxn; j += i)
            {
                valid[j] = tot;
            }
        }
    }
}

int main()
{
    int i, n;
    get_lagest_prime_factor();
    while(scanf("%d", &n)!= EOF)
    {
        printf("%d\n", valid[n]);
    }
    return 0;
}
