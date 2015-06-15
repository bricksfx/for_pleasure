#include<iostream>
#include<cstdio>
using namespace std;

int m[100][100];
int p[100];
int s[100][100];
void martrixChain(int n)
{
    for(int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i <= n-len+1; i++)
        {
            int j = i+len-1;
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j] = i;
            for(int k = i+1; k < j; k++)
            {
                int tmp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(tmp < m[i][j])
                {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
}

void OutPut(int n)
{
    printf("截断点\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    printf("中间结果矩阵为\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%6d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    while(scanf("%d", &n))
    {
        for(int i = 0; i <= n; i++)
        {
            scanf("%d", &p[i]);
        }
        martrixChain(n);
        OutPut(n);
        cout<<"结果为"<<endl;
        cout<<m[1][n]<<endl;
    }
    return 0;
}
