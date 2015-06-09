#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 100000+1
#define min -2147483647
int map[maxn];

int *find_cross(int low, int mid, int high)
{
    int max_left = min;
    int left_num;
    int i, j;
    int sum = 0;
    for(i = mid; i >= low; i--)
    {
       sum += map[i];
       if(sum >= max_left)
       {
           left_num = i;
           max_left = sum;
       }
    }
    int max_right = min;
    int right_num;
    sum = 0;
    for(j = mid+1; j <= high; j++)
    {
        sum += map[j];
        if(sum > max_right)
        {
            right_num = j;
            max_right = sum;
        }
    }
    int* result = new int[3];
    result[0] = max_left + max_right;
    result[1] = left_num;
    result[2] = right_num;
    return result;
}
int *find_max(int low, int high)
{
    if(low == high)
    {
        int* result = new int[3];
        result[0] = map[low];
        result[1] = low;
        result[2] = high;
        return result;
    }
    else
    {
        int mid = (low + high)/2;
        int* left = find_max(low, mid);
        int* right = find_max(mid+1, high);
        int* cross = find_cross(low, mid, high);
       // printf("left%d %d %d\n", left[0], left[1], left[2]);
        //printf("right%d %d %d\n", right[0], right[1], right[2]);
        //printf("cross%d %d %d\n", cross[0], cross[1], cross[2]);
        
        if((left[0] >= right[0]) && (left[0] >= cross[0]))
            return left;
        else if((right[0] > left[0]) && (right[0] > cross[0]))
            return right;
        else
            return cross;
    }
}

int main()
{
    int n, tmp, i;
    scanf("%d", &n);
    for(int j = 1; j <= n; j++)
    {
        scanf("%d", &tmp);
        for(i = 0; i < tmp; i++)
        {
            scanf("%d", &map[i]);
        }
        int* result = find_max(0, tmp-1);
        printf("Case %d:\n", j);
        printf("%d %d %d\n", result[0], result[1]+1, result[2]+1);
        printf(j == n?"":"\n");
    }
    return 0;
}
            

