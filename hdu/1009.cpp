#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int cmp(int *p, int *q)
{
    return (p[0]*1.0)/p[1] > (q[0]*1.0)/q[1];
}
int **list =new int*[1001];
int main()
{
    int m, n;
    int i;
    while(scanf("%d %d", &m, &n) != EOF && m != -1 && n != -1)
    {
        for(i = 0; i < n; i++)
        {
            list[i] = new int[2];
            scanf("%d %d", &list[i][0], &list[i][1]);
        }
        sort(list, list+n, cmp);
        double surplus = m;
        double sum = 0;
        for(i = 0; i < n; i++)
        {
            if (surplus == 0)
            {
                break;
            }
            if (surplus >= list[i][1])
            {
                sum += list[i][0];
                surplus -= list[i][1];
            }
            else{
                sum += ((list[i][0]*1.0)/list[i][1] * surplus);
                surplus -= surplus;
            }
        }
        printf("%.3lf\n", sum);
    }
    return 0;
}
