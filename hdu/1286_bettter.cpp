#include<stdio.h>
#define max 1000001
int minDiv[max];
int phi[max];

void getPhi(){
    for(int i = 0; i < max; i++)
    {
        minDiv[i] = i;
    }
    for(int i = 2; i*i < max; i++)
    {
        if(minDiv[i] == i)
        {
            for(int j = i*i; j < max; j += i)
            {
                minDiv[j] = i;
            }
        }
    }
    phi[1] = 1;
    for(int i = 2; i < max; i++)
    {
        phi[i] = phi[i/minDiv[i]];
        if(i/minDiv[i] % minDiv[i] == 0)
        {
            phi[i] *= minDiv[i];
        }
        else{
            phi[i] *= (minDiv[i] - 1);
        }
    }

}
int main()
{
    getPhi();
    phi[1] = 0;
    int n, tmp;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &tmp);
        printf("%d\n", phi[tmp]);
    }
    return 0;
}



