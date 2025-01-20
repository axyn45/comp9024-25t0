#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} NodeT;

NodeT *makeNode(int v)
{
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->data = v;
    new->next = NULL;
    return new;
}

NodeT *insertLL(NodeT *list, int d)
{
    NodeT *new = makeNode(d);
    new->next = list;
    return new;
}

NodeT *appendLL(NodeT *list, int d)
{
    NodeT *new = makeNode(d);
    if (!list)
        return new;
    NodeT *i = list;
    while (i->next != NULL)
    {
        i = i->next;
    }
    i->next = new;
    return list;
}

NodeT *deleteHead(NodeT *list)
{
    assert(list != NULL);
    NodeT *head = list;
    list = list->next;
    free(head);
    return list;
}

void *showLL(NodeT *list)
{
    NodeT *p;
    for (p = list; p != NULL; p = p->next)
    {
        printf("%d", p->data);
        if (p->next)
            printf("->");
    }
    // return
    // return;
}

bool isValidInt(char a[])
{
    for (int i = 0; i < 32 && a[i] != 0; i++)
    {
        if (a[i] < 48 || a[i] > 57)
            return false;
    }
    return true;
}

void freeLL(NodeT *list)
{
    NodeT *p, *temp;
    p = list;
    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
}

int main()
{

    NodeT *all = NULL;
    char input[32];
    while (true)
    {
        printf("Enter a number: ");
        scanf("%31s", input);
        if (!isValidInt(input))
        {
            printf("Done. List is ");
            showLL(all);
            break;
        }
        else
        {
            int d = 0;
            d = atoi(input);
            if (d % 2)
            {
                all = insertLL(all, d);
            }
            else
            {
                all = appendLL(all, d);
            }
        }
    }
    freeLL(all);
    return 0;
}