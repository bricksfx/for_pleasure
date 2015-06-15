#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int map[100][100];
string x, y;

void OutPut(int n, int m)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            printf("%6d", map[i][j]);
        }
        printf("\n");
    }
}

void lcs(int n, int m)
{
    for(int i = 0; i <= n; i++)
        map[i][0] = 0;
    for(int j = 0; j <= m; j++)
        map[0][j] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i] == y[j])
            {
                map[i][j] = map[i-1][j-1] + 1;
            }
            else{
                map[i][j] = map[i-1][j] > map[i][j-1]?map[i-1][j]:map[i][j-1];
            }
        }
    }
}

void change(string a, string& b)
{
    b = "0";
    for(int i = 0; i < a.length(); i++)
    {
       b += a[i]; 
    }
}

int main()
{
    string a, b;
    cin>>a;
    cin>>b;
    change(a,x);
    change(b,y);
    cout<<x<<endl;
    cout<<y<<endl;
    lcs(a.length(), b.length());
    OutPut(a.length(), b.length());
    return 0;
}
