#include <stdio.h>
struct Node
{
   int data;
   struct Node* next;
};

typedef struct Node node_t;

int main()
{
   node_t* head;
   printf("%d\n", sizeof(node_t));
}
