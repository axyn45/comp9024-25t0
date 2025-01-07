#include <stdio.h>
#include <math.h>

int reverse(int a)
{
    int res = 0;
    for (int i = 6; i >= 0; i--)
    {
        res += (a % 10) * pow(10, i);
        a /= 10;
    }
    return res;
}

int main()
{
    for (int i = 1000000; i < 1250000; i++)
    {
        if (i * 8 == reverse(i) + 1)
        {
            printf("%d\n", i);
        }
    }
    // int a[4];
    // printf("%d", sizeof(a));
}