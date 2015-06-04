#include<stdio.h>
#define maxn 1000000+1

int ans[maxn];
int valid[maxn];

void get_max_factor()
{
    int i, j;
    int tot = 0;
    ans[1] = tot;
    for(i = 2; i < maxn; i++)
        valid[i] = 1;
    for(i = 2; i < maxn; i++)
    {
        if(valid[i])
        {
            tot++;
            ans[i] = tot;
            for(j = i+i; j < maxn; j += i)
            {
                valid[j] = 0;
                ans[j] = tot;
            }
        }
    }
}

int main()
{
    get_max_factor();
    int i, n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", ans[n]);
    }
    return 0;
}
