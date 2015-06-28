#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 10000+10
typedef struct {
    int begin;
    int end;
    int value;
}map;
int array[maxn];

int main()
{
    int n;
    map dp[maxn];
    while(scanf("%d", &n) != EOF && n != 0)
    {
        int i, j, k, flag;
        flag = 0;
        for(i = 0; i <= n; i++)
        {
            dp[i].value = 0;
            dp[i].begin = 0;
            dp[i].end = 0;
        }
        dp[0].begin = 1;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &array[i]);
            if(array[i] >= 0)
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("%d %d %d\n", 0, array[1], array[n]);
        }
        else
        {
            int max = -0xffffff;
            int x, y;
            for(i = 1; i <= n; i++)
            {
                int tmp = dp[i-1].value + array[i];
                int pos;
                if(tmp > array[i])
                {
                    dp[i].begin = dp[i-1].begin;
                    dp[i].end = i;
                    dp[i].value = tmp;
                }
                else{
                    dp[i].begin = i;
                    dp[i].end = i;
                    dp[i].value = array[i];
                }

                if(max < dp[i].value)
                {
                    max = dp[i].value;
                    x = array[dp[i].begin];
                    y = array[dp[i].end];
                }
            }
            printf("%d %d %d\n", max, x, y); 
        }
    }
    return 0;
}
