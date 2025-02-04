// Linked list interface ... COMP9024 25T0
#include <stdbool.h>

typedef struct Node *List;

List insertLL(List, int);
List deleteLL(List, int);
bool inLL(List, int);
List appendLL(List, int);
void freeLL(List);
void showLL(List);
void showTrail(List);