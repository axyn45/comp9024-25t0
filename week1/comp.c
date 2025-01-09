#include <stdio.h>

// #define SIZE_ARR 4

// char *helper(char *res, char *dict)
// {
//     if (dict == NULL)
//     {
//         printf("%s", res);
//     }
//     else
//     {
//         int dictsize = sizeof(dict) / sizeof(char);
//         for (int i = 0; i < dictsize; i++)
//         {
//             helper(initArray(res, dict[i]), initDict(dict, i));
//         }
//     }
// }

// char *initArray(char *a, char newchar)
// {
//     char res[SIZE_ARR] = {0, 0, 0, 0};
//     for (int i = 0; i < SIZE_ARR; i++)
//     {
//         if (a[i] == 0)
//         {
//             res[i] = newchar;
//             return res;
//         }
//         res[i] = a[i];
//     }
//     return res;
// }

// char *initDict(char *dict, int omit)
// {
//     char *res;
//     res = (char *)malloc(sizeof(dict) - sizeof(char));
//     int offset = 0;
//     for (int i = 0; i < SIZE_ARR; i++)
//     {
//         if (i == omit)
//         {
//             offset += 1;
//         }
//         else
//         {
//             res[i - offset] = dict[i];
//         }
//     }
//     return res;
// }

// int main()
// {
//     char dict[4] = {'c', 'm', 'o', 'p'};
//     char res[4];
//     helper(res, dict);
// }

int main()
{
    char pool[4] = {'c', 'm', 'o', 'p'};

    for (int i = 0; i < 4; i++)
    {
        char res[4] = {0, 0, 0, 0};
        res[0] = pool[i];
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
                continue;
            res[1] = pool[j];
            for (int k = 0; k < 4; k++)
            {
                if (i == k || j == k)
                    continue;
                res[2] = pool[k];
                for (int l = 0; l < 4; l++)
                {
                    if (i == l || j == l || k == l)
                        continue;
                    res[3] = pool[l];
                    // printf("%s\n", res);
                    for (int m = 0; m < 4; m++)
                    {
                        printf("%c", res[m]);
                    }
                    printf("\n");
                }
            }
        }
    }
    // char str[4] = {56};
    // printf("%s", str);
}