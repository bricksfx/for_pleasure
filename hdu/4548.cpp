#include<stdio.h>
#include<math.h>
#define maxn 1000000+1

int prime[maxn];
int count[maxn];
bool is_beauty_prime(int n);
int tot = 0;
void getPrime()
{
    int i, j;
    int tmp = int((double)sqrt(maxn) + 1);
    for(i = 2; i < maxn; i++)
    {
        prime[i] = 1;
    }
    for(i = 2; i < maxn; i++)
    {
        if(prime[i])
        {
            if(i < tmp)
            {
                for(j = i*i; j < maxn; j+=i)
                    prime[j] = 0;
            }
        }
    }
    for(i = 2; i < maxn; i++)
    {
        if(prime[i] && is_beauty_prime(i))
        {
            count[++tot] = i;
        }
    }
}

bool is_beauty_prime(int n)
{
    int tmp = 0;
    while(n)
    {
        tmp += n%10;
        n /= 10;
    }
    if(prime[tmp])
        return true;
    return false;
}
int binary_search(int l, int h, int num)
{
    while(l <= h)
    {
        int mid = (l+h)/2;
        if(num == count[mid])
            return mid;
        else if(count[mid] > num)
        {
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return l;
}

int beauty_prime(int a, int b)
{
    int i;
    int sum = 0;
    for(i = a; i <= b; i++)
    {
        if(prime[i])
        {
           if(is_beauty_prime(i))
               sum++;
        }
    }
    return sum;
}

int main()
{
    int n, a, b, i, j;
    getPrime();

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        int top = 0;
        int down = 0;
        scanf("%d %d", &a, &b);
        down = binary_search(1, tot, a);
        top = binary_search(1, tot, b);
        if(count[top] == b)top++;
        down--;
        int num = top-down-1;
        printf("Case #%d: %d\n", i, num);
    }
}
