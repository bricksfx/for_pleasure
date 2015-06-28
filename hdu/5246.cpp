#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxn 10000+1
using namespace std;
long long list[maxn];

int main()
{
    int t;
    int n, k;
    long long m;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%d%lld%d", &n, &m, &k);
        for(int j = 0; j < n; j++)
        {
            scanf("%lld", &list[j]);
        }
        sort(list, list+n);
        printf("Case #%d:\n", i);
        if(list[n-1] <= m)
        {
            printf("why am I so diao?");
        }
        else{
            for(int j = 0; j < n-1; j++)
            {
                if(m >= list[j] && m < list[j+1])
                {
                    m = list[j]+k;
                    k--;
                }
                if(list[n-1] <= m)
                    break;
            }
            printf(list[n-1] <= m?"why am I so diao?\n":"madan!\n");
        }
    }
    return 0;
}
