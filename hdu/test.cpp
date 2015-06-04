#include<stdio.h>
#include<math.h>
#define maxn 1000000+1
int valid[maxn];
int ans[maxn];
int max = 0;

void getPrime(int n)
{
    max = 0;
    int i, j;
    for(i = 2; i <= n; i++)
        valid[i] = 1;
    for(i = 2; i <= n; i++)
    {
        if(valid[i]){
            if(n/i < i)
                break;
            for(j = i*i; j <= n; j += i)
                valid[j] = 0;
        }
    }
    for(i = 2; i <=n; i++)
    {
        if(valid[i])
        {
            ans[++max] = i;
            valid[i] = max;
        }
            
    }
}

int main()
{
    getPrime(1000000);
    /*
    getPrime(10);
    int i, j, n;
    for(i = 0; i <= 10; i++)
    {
        printf("%d: %d\n", i, valid[i]);
    }
    */
    int i, j, n;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 1){
            printf("%d\n", valid[n]);
        }
        else if(valid[n])
        {
            printf("%d\n", valid[n]);
        }
        else
        {
            for(i = max; i >= 0; i--)
            {
                if(n%ans[i] == 0)
                {
                    printf("%d\n", valid[ans[i]]);
                    break;
                }
            }
        }
    }
    return 0;
}

