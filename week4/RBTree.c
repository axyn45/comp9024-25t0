// Red-Black Tree ADT implementation ... COMP9024 25T0

#include "RBTree.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINT_COLOR_RED "\x1B[31m"
#define PRINT_COLOR_RESET "\x1B[0m"

#define data(tree) ((tree)->data)
#define left(tree) ((tree)->left)
#define right(tree) ((tree)->right)
#define color(tree) ((tree)->color)
#define isRed(tree) ((tree) != NULL && (tree)->color == RED)

typedef enum { RED, BLACK } Colr;

typedef struct Node {
    Item data;
    Colr color;
    Tree left, right;
} Node;

// create a new empty Tree
Tree newTree() { return NULL; }

// make a new node containing data
Tree newNode(Item it) {
    Tree new = malloc(sizeof(Node));
    assert(new != NULL);
    data(new) = it;
    color(new) = RED;
    left(new) = right(new) = NULL;
    return new;
}

Tree rotateRight(Tree);
Tree rotateLeft(Tree);

// insert a new item into a tree
// Tree TreeInsert(Tree t, Item it) {
//     printf("Not yet implemented.\n");
//     printf("Returning a fixed tree instead:\n");

//     Tree testTree = newNode(2);
//     color(testTree) = BLACK;
//     left(testTree) = newNode(1);
//     right(testTree) = newNode(3);
//     return testTree;
// }

// check whether a key is in a Tree
bool TreeSearch(Tree t, Item it) {
    if (t == NULL)
        return false;
    else if (it < data(t))
        return TreeSearch(left(t), it);
    else if (it > data(t))
        return TreeSearch(right(t), it);
    else  // it == data(t)
        return true;
}

Tree rotateRight(Tree n1) {
    if (n1 == NULL || left(n1) == NULL) return n1;
    Tree n2 = left(n1);
    left(n1) = right(n2);
    right(n2) = n1;
    return n2;
}

Tree rotateLeft(Tree n2) {
    if (n2 == NULL || right(n2) == NULL) return n2;
    Tree n1 = right(n2);
    right(n2) = left(n1);
    left(n1) = n2;
    return n1;
}

// free memory associated with Tree
void freeTree(Tree t) {
    if (t != NULL) {
        freeTree(left(t));
        freeTree(right(t));
        free(t);
    }
}

// display Tree sideways
void showTreeR(Tree t, int depth) {
    if (t != NULL) {
        showTreeR(right(t), depth + 1);
        int i;
        for (i = 0; i < depth; i++) putchar('\t');  // TAB character
        if (isRed(t))
            printf("%s%d%s\n", PRINT_COLOR_RED, data(t), PRINT_COLOR_RESET);
        else
            printf("%d\n", data(t));
        showTreeR(left(t), depth + 1);
    }
}

void showTree(Tree t) { showTreeR(t, 0); }

Tree reArrangeRB(Tree t) {
    if (left(t) && right(left(t)) && color(left(t)) == RED &&
        color(right(left(t))) == RED) {
        left(t) = rotateLeft(left(t));
    }
    if (right(t) && left(right(t)) && color(right(t)) == RED &&
        color(left(right(t))) == RED) {
        right(t) = rotateRight(right(t));
    }

    if (left(t) && left(left(t)) && color(left(t)) == RED &&
        color(left(left(t))) == RED) {
        t = rotateRight(t);
        color(t) = BLACK;
        color(right(t)) = RED;
    }
    if (right(t) && right(right(t)) && color(right(t)) == RED &&
        color(right(right(t))) == RED) {
        t = rotateLeft(t);
        color(t) = BLACK;
        color(left(t)) = RED;
    }
    return t;
}

Tree insertRB(Tree t, Item it) {
    if (t == NULL)
        return newNode(it);
    else if (it == data(t))
        return t;
    if (left(t) && right(t) && color(left(t)) == RED &&
        color(right(t)) == RED) {
        color(left(t)) = BLACK;
        color(right(t)) = BLACK;
        color(t) = RED;
    }
    if (it < data(t)) {
        left(t) = insertRB(left(t), it);
        t = reArrangeRB(t);
    } else {
        right(t) = insertRB(right(t), it);
        t = reArrangeRB(t);
    }
    return t;
}

Tree TreeInsert(Tree t, Item it) {
    t = insertRB(t, it);
    color(t) = BLACK;
    return t;
}