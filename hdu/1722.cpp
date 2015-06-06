#include<stdio.h>
int gcd(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else{
        gcd(b, a%b);
    }
}
void swap(int &a, int &b)
{
    if(a > b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
}

int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        swap(a, b);
        int ans = a + b - gcd(b, a);
        printf("%d\n", ans);
    }
    return 0;
}
