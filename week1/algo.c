#include <stdio.h>

int main()
{
    char pool[4] = {'a', 'g', 'l', 'o'};

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