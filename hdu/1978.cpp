#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int map[130][130];
int x[130][130];

int dp(int n, int m)
{
    memset(x, 0, sizeof(x));
    x[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int k = 0; k <= map[i][j]; k++)
            {
                for(int l = 0; l+k <= map[i][j]; l++)
                {
                    if(k == 0 && l == 0)
                        continue;
                    x[i+k][j+l] = (x[i+k][j+l] + x[i][j]) % 10000;
                }
            }
        }
    }
    return x[n][m];
}

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        memset(map, 0, sizeof(map));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1;j <= m; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }
        printf("%d\n", dp(n, m));
    }
}

