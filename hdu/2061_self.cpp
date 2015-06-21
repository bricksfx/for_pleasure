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
        int s = int(sqrt(tmp*1.0));
        for(int j = 1; j <= s; j++)
        {
            if((tmp - j)%(j+1) == 0 && ((tmp-j)/(j+1) >= j))
            {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
