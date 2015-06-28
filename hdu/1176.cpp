#include<stdio.h>
#include<cstring>
#define maxn 100000 + 1
int map[11][maxn];
int max(int a, int b)
{
    return a>b?a:b;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n!= 0)
    {
        int tmp = n;
        int maxt = -0xfffffff;
        memset(map, 0, sizeof(map));
        while(tmp--)
        {
            int k, t;
            scanf("%d %d", &k, &t);
            map[k][t]++;
            if(t > maxt)
                maxt = t;
        }
        for(int i = maxt-1; i >= 0; i--)
        {
            map[0][i] = map[0][i] + max(map[1][i+1], map[0][i+1]);
            map[10][i] = map[10][i] + max(map[10][i+1], map[9][i+1]);
            for(int j = 1; j < 10; j++)
            {
                map[j][i] = map[j][i] + max(map[j-1][i+1], max(map[j][i+1], map[j+1][i+1]));
            }
        }
        printf("%d\n", map[5][0]);
    }
    return 0;
}
