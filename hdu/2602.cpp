#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define maxn 1000+1
int map[maxn][maxn];
int w[maxn], v[maxn];

int max(int a, int b)
{
    return a > b? a:b;
}
int backpack(int n, int c)
{
    memset(map, 0, sizeof(map));
    for(int j = 0; j <= c; j++)
    {
        if(w[n] <= j)
        {
            map[n][j] = v[n];
        }
        else
            map[n][j] = 0;
    }
    int max1 = 0;
    for(int i = n-1; i >= 1; i--)
    {
        for(int j = 0; j <= c; j++)
        {
            if(j >= w[i])
            {
                map[i][j] = max(map[i+1][j], map[i+1][j-w[i]] + v[i]);
            }
            else{
                map[i][j] = map[i+1][j];
            }
            if(max1 < map[i][j])
            {
                max1 = map[i][j];
            }
        }
    }
    return max1;
}
int main()
{
    int t, n, c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &c);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &v[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &w[i]);
        }
        int res = backpack(n, c);
        printf("%d\n", res);
    }
    return 0;
}
