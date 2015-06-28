#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000+10
using namespace std;
char list[maxn];
int sorted[maxn];

int main()
{
    while(cin>>list)
    {
        int i = 0;
        int length = strlen(list);
        int count = 0;
        int sum = 0;
        int flag = 0;
        while(i < length)
        {
            if(list[i] == '5' && flag == 1)
            {
                i++;
                sorted[count++] = sum;
                sum = 0;
                flag = 0;
            }
            else if(list[i] == '5' && flag == 0)
            {
                i++;
                flag = 0;
            }
            else{
                sum *= 10;
                sum += (list[i++] - '0');            
                flag = 1;
            }
        }
        if(list[length-1] != '5')
        {
            sorted[count++] = sum;
        }
        sort(sorted, sorted+count);
        for(int i = 0; i < count; i++)
        {
            printf("%d%c", sorted[i], i == count-1?'\n':' ');
        }
    }
    return 0; 
}
