#include <stdio.h>
#include <stdlib.h>

unsigned long long fib(int n)
{
    if (n < 3)
        return 1;
    unsigned long long *arr = NULL;
    arr = malloc(sizeof(unsigned long long) * n);
    if (arr == NULL)
        return 0;
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        // printf("%d:%llu ", i + 1, arr[i]);
    }
    unsigned long long a = arr[n - 1];
    free(arr);
    return a;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 0;
    }
    // printf("%d\n", sizeof(int));
    // printf("%d\n", sizeof(unsigned long int));

    int n = atoi(argv[1]);
    // int n = 60;
    printf("%llu", fib(n));
    return 0;
}