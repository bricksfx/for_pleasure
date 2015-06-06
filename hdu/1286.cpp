#include<stdio.h>

int gcd(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else
    {
        gcd(b, a%b);
    }
}

int main()
{
    int n, members,tmp, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int sum = 0;
        scanf("%d", &members);
        for(j = 1; j < members; j++)
        {
            int result = gcd(members, j);
            if(result == 1){
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
