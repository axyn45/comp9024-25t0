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
    return 0;
}

bool isValidInt(char a[])
{
    for (int i = 0; i < 32 && a[i] != 0; i++)
    {
        if ((a[i] < 48 || a[i] > 57) && a[i] != '-' && a[i] != ' ')
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

NodeT **divideLL(NodeT *list)
{
    NodeT **res = (NodeT **)malloc(sizeof(NodeT *) * 2);
    res[0] = NULL;
    res[1] = NULL;
    int counter = 0;
    NodeT *cur = list, *l1 = NULL, *l2 = NULL;
    while (cur != NULL)
    {
        if (counter % 2)
        {
            if (!res[0])
            {
                res[0] = makeNode(cur->data);
                l1 = res[0];
            }
            else
            {
                l1->next = makeNode(cur->data);
                l1 = l1->next;
            }
        }
        else
        {
            if (!res[1])
            {
                res[1] = makeNode(cur->data);
                l2 = res[1];
            }
            else
            {
                l2->next = makeNode(cur->data);
                l2 = l2->next;
            }
        }
        cur = cur->next;
        counter++;
    }
    return res;
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
            printf("Done.");
            if (all)
            {
                printf(" List is ");
                showLL(all);
                NodeT **res = divideLL(all);
                if (res[0])
                {
                    printf("\n");
                    printf("Even-numbered elements are: ");
                    showLL(res[0]);
                }
                if (res[1])
                {
                    printf("\n");
                    printf("Odd-numbered elements are: ");
                    showLL(res[1]);
                }
            }

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