#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 0;
    int max = 1000;
    while (max > 0)
    {
        for (int i = 0; i < max; i++)
        {
            if (argv[1][i] == '\0')
            {
                max = i;
                break;
            }
            putchar(argv[1][i]);
        }
        max--;
        if (max)
            printf("\n");
    }
}