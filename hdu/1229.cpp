#include<stdio.h>
int main()
{
    int a, b, k;
    while(scanf("%d %d %d", &a, &b, &k) != EOF)
    {
        if(a == 0 && b == 0)
        {
            break;
        }
        else{
            int tmpa = a;
            int tmpb = b;
            int flag = 1;
            int count = 0;
            while(++count <= k)
            {
                if(tmpa%10 != tmpb%10)
                {
                    flag = 0;
                    break;
                }
                tmpa /= 10;
                tmpb /= 10;
            }
            if(flag == 1 && count-1 == k)
                printf("%d\n", -1);
            else
                printf("%d\n", a+b);
        }
    }
    return 0;
}
