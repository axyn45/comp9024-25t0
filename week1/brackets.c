#include <stdio.h>
#include "charStack.h"

#define INPUT_STRLEN 512

int main(void)
{
    char str[INPUT_STRLEN];

    printf("Enter a string: ");
    scanf("%[^\n]511s", str);

    StackInit();

    char ch;
    int i = 0;
    int balanced = 1;
    while (balanced && (ch = str[i]) != '\0')
    {
        // if(ch=='\0')printf("1\n");
        /* NEEDS TO BE IMPLEMENTED */
        if (ch == '(' || ch == '[' || ch == '{')
        {
            StackPush(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (StackIsEmpty())
            {
                balanced = 0;
            }
            else
            {
                char opening = StackPop();
                switch (ch)
                {
                case ')':
                    if (opening != '(')
                    {
                        balanced = 0;
                    }
                    break;
                case ']':
                    if (opening != '[')
                    {
                        balanced = 0;
                    }
                    break;
                case '}':
                    if (opening != '{')
                    {
                        balanced = 0;
                    }
                    break;
                default:
                    balanced = 0;
                }
            }
        }
        i++;
    }
    if (!StackIsEmpty())
        balanced = 0;
    if(balanced)
        printf("correctly balanced\n");
    else
        printf("brackets unbalanced");
    return balanced;
}