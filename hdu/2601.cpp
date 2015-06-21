#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 10000000000+1

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        long long tmp;
        scanf("%lld", &tmp);
        int sum = 0;
        tmp++;
        int s = int(sqrt(tmp*1.0));
        for(int j = 2; j <= s; j++)
        {
            if((tmp)%j == 0)
            {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
