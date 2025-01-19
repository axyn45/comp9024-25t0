#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// void func(int *a)
// {
//     a = malloc(sizeof(int));
//     assert(a != NULL);
// }

// int main(void)
// {
//     int *p;

//     func(p);
//     *p = 6;
//     printf("%d\n", *p);
//     free(p);

//     return 0;
// }

void func(int **a)
{
    *a = malloc(sizeof(int));
    assert(a != NULL);
}

int main(void)
{
    int *p;

    func(&p);
    *p = 6;
    printf("%d\n", *p);
    free(p);

    return 0;
}