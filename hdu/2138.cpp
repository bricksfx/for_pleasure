#include<stdio.h>
#include<math.h>
bool is_prime(int p){
    int q = sqrt(p);
    int i;
    for(i = 2; i <= q; i++)
    {
        if(p%i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            if(is_prime(tmp))
            {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
