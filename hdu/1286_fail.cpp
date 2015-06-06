#include<stdio.h>
#define maxn 32768+1

int map[maxn];
void list()
{
    for(int i = 1; i < maxn; i++)
    {
        map[i] = 0;
    }
    int i, j;
    for(int i = 2; i < maxn; i++)
    {
        int sum = 0;
        if(map[i] == 0)
        {
            for(j = i; j < maxn; j+=i)
            {
                map[j] += sum;
                sum++;
            }
        }
    }
}

int main()
{
    list();
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        printf("%d\n", tmp-1-map[tmp]);
    }
    return 0;
}
