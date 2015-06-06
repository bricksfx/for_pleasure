#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int gcd(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else
        gcd(b, a%b);
}

void reverse(string decimal)
{
    int non_cycle_digit = 0;
    int cycle_digit = 0;
    int total_digig = 0;
    string non_cycle;
    string cycle;
    for(int i = 2; i < decimal.length(); i++)
    {
        if (decimal[i] == '(')
            break;
        else
        {
            non_cycle_digit++;
            non_cycle += decimal[i];
        }
    }
    for(int j = non_cycle_digit + 3; j < decimal.length(); j++)
    {
        if(decimal[j] == ')')
            break;
        else
        {
            cycle_digit++;
            cycle += decimal[j];
        }
    }
    if(cycle_digit != 0 && non_cycle_digit == 0)
    {
        int Denominator = 0;
        int numerator = 0;
        for(int i = 0; i < cycle_digit; i++) 
        {
            int bit = 1;
            for(int j = 0; j < (cycle_digit - i-1); j++)
            {
                bit *= 10;
            }
            Denominator += 9*bit;
            numerator += bit*(cycle[i] - '0');
        }
        int gcd_cycle = gcd(numerator, Denominator);
        cout<<numerator/gcd_cycle<<'/'<<Denominator/gcd_cycle<<endl;
    }
    if(non_cycle_digit != 0 && cycle_digit == 0)
    {
        int Denominator = 0;
        int numerator = 0;
        for(int i = 0; i < non_cycle_digit; i++) 
        {
            int bit = 1;
            for(int j = 0; j < (non_cycle_digit - i -1); j++)
            {
                bit *= 10;
            }
            if(i == 0)
            {
                Denominator = bit;
            }
            numerator += bit*(non_cycle[i] - '0');
        }
        Denominator *= 10;
        int gcd_cycle = gcd(numerator, Denominator);
        cout<<numerator/gcd_cycle<<'/'<<Denominator/gcd_cycle<<endl;
    }
    else if(non_cycle_digit != 0 && cycle_digit != 0)
    {
        int Denominator = 0;
        int numberator = 0;
        int bit = 1;
        int remove = 0;
        int j;
        for(j = 0; j < cycle_digit; j++) 
        {
            bit = 1;
            int k;
            for(k = 0; k < (cycle_digit+non_cycle_digit - j -1); k++)
            {
                bit *= 10;
            }
            Denominator += 9*bit;
            if(j < non_cycle_digit)
            {
                numberator += bit*(non_cycle[j] - '0');
            }
            else
            {
                numberator += bit*(cycle[j - non_cycle_digit] - '0');
            }

        }
        int l = 0;
        for(;j < cycle_digit+non_cycle_digit; j++)
        {
            bit = 1;
            int k;
            for(k = 0; k < (cycle_digit + non_cycle_digit - j - 1); k++)
            {
                bit *= 10;
            }
            //numberator += bit*(cycle[l++] - '0');
            if(j < non_cycle_digit)
            {
                numberator += bit*(non_cycle[j] - '0');
            }
            else
            {
                numberator += bit*(cycle[j - non_cycle_digit] - '0');
            }
        }
        for(int j = 0; j < non_cycle_digit; j++)
        {
            int bit2 = 1;
            int k;
            for(k = 0; k < (non_cycle_digit-j-1); k++)
            {
                bit2 *= 10;
            }
            remove += bit2*(non_cycle[j] - '0');
        }

        int gcd_cycle = gcd(numberator-remove,Denominator);
        cout<<(numberator-remove)/gcd_cycle<<'/'<<Denominator/gcd_cycle<<endl;

    }
}

int main()
{
    int n;
    string decimal;
    scanf("%d", &n);
    while(n--)
    {
        cin>>decimal;
        reverse(decimal);
    }
    return 0;
}
