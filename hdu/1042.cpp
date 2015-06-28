#include<stdio.h>
#include<string.h>
#define maxn 36000+10
int map[maxn];
int len;
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(map, 0, sizeof(map)); 
        map[0] = 1;
        for(int i = 2; i <= n; i++)
        {
            int c = 0;
            for(int j = 0; j < maxn; j++)
            {
                int tmp = map[j] * i + c;
                map[j] = tmp%10;
                c = tmp/10;
            }
        }
        int j;
        for(j = maxn-1; j >= 0; j--)
        {
            if(map[j])
                break;
        }
        printf("j:%d\n", j);
        for(int i = j; i >= 0; i--)
        {
            printf("%d", map[i]);
        }
        printf("\n");
    }
}
