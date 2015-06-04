#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else{
        gcd(b, a%b);
    }
}

int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        int max = a > b?gcd(a, b):gcd(b, a);
        int out = (a*b)/max;
        printf("%d\n", out);
    }
    return 0;
}
