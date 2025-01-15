#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool hasRepeatedLetter(char A[]);

int main()
{
    char str[32];
    printf("Enter a word: ");
    scanf("%31s", str);
    if (hasRepeatedLetter(str))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}

bool hasRepeatedLetter(char A[])
{
    int i = 0;
    bool lut[26] = {false};

    while (A[i] != '\0')
    {
        if (!lut[A[i] - 97])
            lut[A[i] - 97] = true;
        else
            return true;
        i++;
    }
    return false;
}
