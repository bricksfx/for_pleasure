#include<stdio.h>
int aa[64+1], bb[64+1], cc[64+1];
unsigned long sum = 0;
unsigned long m;

void Init(int n)
{
    int i, j;
    for(i = 0; i <= n; i++)
    {
        aa[i] = 0;
        bb[i] = 0;
        cc[i] = 0;
    }
    aa[0] = n;
    for(i = n, j = 1; i >= 1; j++,i--)
    {
       aa[j] = i;
    }
}
void loop(int* a)
{
    printf("%d%c", a[0], a[0] == 0? '\n' : ' ');
    for(int i = 1; i <= a[0]; i++)
    {
        printf("%d", a[i]);
        printf(i == a[0]?"\n":" ");
    }
}
void OutPut()
{
   loop(aa); 
   loop(bb);
   loop(cc);
}
bool move(int *a, int *b)
{
    if(sum != m)
    {
        b[b[0]+1] = a[a[0]];
        b[0]++;
        a[0]--;
        sum++;
    }
    if(sum == m)
        return false;
    return true;
}

void hanoi(int n, int *a, int *b, int *c)
{
    if(n > 0)
    {
        hanoi(n-1, a, c, b);
        if (!move(a, b))
            return ;
        hanoi(n-1, c, b, a);
    }
}

int main()
{
   int num, n;
   scanf("%d", &num);
   while(num--)
   {
       scanf("%d %lu", &n, &m);
       sum = 0;
       Init(n);
       hanoi(n, aa, bb, cc);
       OutPut();
   }
   return 0;
}
