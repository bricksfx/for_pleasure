#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    char str[100001];
    int res[26];
    while(gets(str))
    {
        int j = strlen(str);
        for(int i = 0; i < 26; i++)
        {
            res[i] = 0;
        }
        for(int i = 0; i < j; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                res[str[i] - 'a']++;
            }
        }
        for(int i = 0; i <= 25; i++)
        {
            printf("%c:%d\n", i+'a', res[i]);
        }
        cout<<endl;
    }
    return 0;
}
