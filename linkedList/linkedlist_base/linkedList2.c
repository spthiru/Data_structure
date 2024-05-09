#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

//typedef struct Node node_t;

int main()
{
   struct Node* head;
   printf("%ld\n", sizeof(struct Node));

   head = (struct Node*)malloc(sizeof(struct Node));
   printf("%ld\n", sizeof(head));
}
