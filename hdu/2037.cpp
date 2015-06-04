#include <iostream>
#include<cstdio>
#include <algorithm>
#include <ctime>
using namespace std;

bool cmp(int *p,int *q)
{
    if(p[1]==q[1])
    {
        return p[0]<q[0];
    }
    else return p[1]<q[1];
}
int main()
{
    int i;
    int **a=new int*[101];
    int n;
    while(scanf("%d", &n) != EOF && n != 0)
    {
        for(i = 0; i < n; i++)
        {
            a[i] = new int[2];
            a[i][0] = 0;
            a[i][1] = 0;
        }
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a[i][0], &a[i][1]);
        }
        sort(a, a+n, cmp);
        int pre_end = 0;
        int sum = 0;
        for(i = 0;i < n; ++i)
        {
            if(a[i][0] >= pre_end)
            {
                sum++;
                pre_end = a[i][1];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
