#include<stdio.h>
#include<string.h>
#define maxT 100000+10
#define maxX 10+2
int map[maxT][maxX];
int res[maxT][maxX];
int max(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n != 0)
    {
        memset(map, 0, sizeof(map));
        memset(res, 0, sizeof(map));
        int x, t;
        scanf("%d%d", &x, &t);
        int maxt = 0;
        int mint = maxT;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &t);
            map[t][x]++;
            if(t < mint)
                mint = t;
            if(t > maxt)
                maxt = maxt;
        }
        for(int i = mint; i <= maxt; i++)
        {
            for(int j = 1; j <= 10; j++)
            {
                res[i][j] = map[i][j] + max(map[i-1][j-1], map[i-1][j-1], map[i-1][j]);
            }
        }
    }
    return 0;
}
