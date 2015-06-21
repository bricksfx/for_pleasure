#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int map[22][22];
int res[22][22];

int min(int a, int b)
{
    return a < b?a:b;
}

int dp(int n, int m)
{
    int maxnum = 0xfffffff;
    memset(res, 0, sizeof(res));
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            res[i][j] = res[i-1][0] + abs(map[i][j] - map[i-1][0]); 
            for(int k = 1; k < m; k++)
            {
               res[i][j] = min(res[i][j], (res[i-1][k] + abs(map[i][j] - map[i-1][k]))); 
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(maxnum > res[n-1][i])
        {
            maxnum = res[n-1][i];
        }
    }
    return maxnum;
}
int main()
{
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF)
    {
        memset(map, 0, sizeof(map));
        for(int i = 0; i < n; i++)
        {
           for(int j = 0; j < k; j++)
           {
               scanf("%d", &map[i][j]);
           }
        }
        printf("%d\n", dp(n, k));
    }
    return 0;
}

