#include <stdio.h>

#define SIZE 1000

int *makeArrayOfInts();

int main()
{
    int *arr = makeArrayOfInts();
    printf("%d\n", arr[500]);
    return 0;
}

int *makeArrayOfInts()
{
    static int arr[1000];
    //    arr=(int*)malloc(sizeof(int)*1000);
    int i;
    for (i = 0; i < 1000; i++)
    {
        arr[i] = i;
    }
    return arr;
}

// int *makeArrayOfInts()
// {
//     static int arr[SIZE];
//     int i;
//     for (i = 0; i < SIZE; i++)
//     {
//         arr[i] = i;
//     }
//     return arr;
// }