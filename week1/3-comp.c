#include <stdio.h>

#define SIZE_ARR 4

char *helper(char *res, char *dict)
{
    if (dict == NULL)
    {
        printf("%s", res);
    }
    else
    {
        int dictsize = sizeof(dict) / sizeof(char);
        for (int i = 0; i < dictsize; i++)
        {
            helper(initArray(res, dict[i]), initDict(dict, i));
        }
    }
}

char *initArray(char *a, char newchar)
{
    char res[SIZE_ARR] = {0, 0, 0, 0};
    for (int i = 0; i < SIZE_ARR; i++)
    {
        if (a[i] == 0)
        {
            res[i] = newchar;
            return res;
        }
        res[i] = a[i];
    }
    return res;
}

char *initDict(char *dict, int omit)
{
    char *res;
    res = (char *)malloc(sizeof(dict) - sizeof(char));
    int offset = 0;
    for (int i = 0; i < SIZE_ARR; i++)
    {
        if (i == omit)
        {
            offset += 1;
        }
        else
        {
            res[i - offset] = dict[i];
        }
    }
    return res;
}

// void pstr(char *arr)
// {
//     int arrsize = sizeof(arr);
//     for (int i = 0; i < arrsize; i++)
//     {
//         printf("%c", arr[i]);
//     }
//     printf("\n");
// }

int main()
{
    char dict[4] = {'c', 'm', 'o', 'p'};
    char res[4];
    helper(res, dict);
}