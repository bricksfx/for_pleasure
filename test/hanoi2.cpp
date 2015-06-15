#include<stdio.h>
int aa[64], bb[64], cc[64];
int sum;

void OutPut();
void Init(int n)
{
    for(int i = 0; i <= n; i++)
    {
        bb[i] = 0;
        cc[i] = 0;
    }
    aa[0] = n;
    int j = 1;
    for(int i = n, j = 1; i >= 1; i--, j++)
    {
        aa[j] = i; 
    }
}

void loop(int *a)
{
    printf("%d ", a[0]);
    for(int i = 1; i <= a[0]; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void move(int* a, int* b)
{
    b[b[0] + 1] = a[a[0]];
    a[0]--;
    b[0]++;
    printf("第%d次移动\n", ++sum);
    OutPut();
}

void hanoi(int n, int* a, int* c, int* b)
{
    if(n > 0)
    {
        hanoi(n-1, a, b, c);
        move(a, c);
        hanoi(n-1, b, c, a);
    }
}

void OutPut()
{
    loop(aa);
    loop(bb);
    loop(cc);
}

int main()
{
    int n;
    while(true)
    {
        sum = 0;
        scanf("%d", &n);
        Init(n);
        hanoi(n, aa, cc, bb);
    }
}
