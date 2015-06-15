#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int axis[101][2];
bool cmp(int *p, int *q)
{
    if(p[0] == q[0])
        return p[1] < q[1];
    else
        return p[0] < q[0];
}

int fun(int n, int **tmp, int begin, int end)
{
    axis[0][0] = tmp[0][0];
    axis[0][1] = tmp[0][1];
    int count = 0;
    for(int i = 1; i < n; i++)
    {
        if(tmp[i][0] <= axis[count][1] + 1)
        {
            if(tmp[i][1] > axis[count][1])
                axis[count][1] = tmp[i][1];
        }

        else
        {
            axis[count][0] = tmp[i][0]; 
            axis[count][1] = tmp[i][1];
        }
    }
    if(end > axis[count][1])
    {
        return end;
    }
    else if(axis[count][0] <= begin && axis[count][1] >= end)
    {
        return -7000000;
    }
    else
    {
        return axis[count][0]-1;
    }
    
}
int main()
{
    int n, begin, end;
    while(scanf("%d", &n) != EOF)
    {
        int **tmp = new int*[101];
        scanf("%d %d", &begin, &end); 
        for(int i = 0; i < n; i++)
        {
            char s[100];
            tmp[i] = new int[2];
            scanf("%d %d %*[^\n]%*c", &tmp[i][0], &tmp[i][1]);
        }
        sort(tmp, tmp+n, cmp);
        int res = fun(n, tmp, begin, end);
        if(res == -7000000)
        {
            printf("Badly!\n");
        }
        else
            printf("%d\n", res);
    }
   return 0; 
}
