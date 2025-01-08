#include <stdio.h>

void collatz(int a)
{
    printf("%d\n", a);
    if (a == 1)
    {
        return;
    }
    int b = a;
    while (b != 1)
    {
        if (b % 2)
        {
            b = 3 * b + 1;
        }
        else
        {
            b /= 2;
        }
        printf("%d\n", b);
    }
}

int fibonacci(int a)
{
    if (a < 3 && a > 0)
        return 1;
    return fibonacci(a - 1) + fibonacci(a - 2);
}

int main()
{
    // collatz(3);
    int res = 0;
    for (int i = 1; i <= 12; i++)
    {
        res = fibonacci(i);
        printf("Fib(%d) = %d\n", i, res);
        collatz(res);
    }
}