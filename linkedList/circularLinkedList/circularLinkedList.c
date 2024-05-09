#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

typedef struct Node node_t;

void insertCircularNode(node_t**, int);
node_t* createNode(int);
void printNode(node_t*);

int main()
{
   node_t* head = NULL;

   insertCircularNode(&head, 10);
   insertCircularNode(&head, 20);
   insertCircularNode(&head, 30);
   insertCircularNode(&head, 40);
   insertCircularNode(&head, 50);
   insertCircularNode(&head, 60);
   printNode(head);
}
node_t* createNode(int data)
{
   node_t* newNode;

   newNode = (node_t*)malloc(sizeof (node_t));

   if (newNode == NULL)
   {
      printf("Memory allocation failed!\n");
      exit(-1);
   }

   newNode->data = data;
   newNode->next = NULL;

   return newNode;
}

void insertCircularNode(node_t** head, int data)
{
   node_t* newNode = createNode(data);

   if (*head == NULL)
   {
      *head = newNode;
      newNode->next = *head;
      return;
   }

   node_t* temp = *head;

   while (temp->next != *head)
   {
      temp = temp->next;
   }

    temp->next = newNode;
    newNode->next = *head;
}

void printNode(node_t* head)
{
   node_t* temp;

   temp = head;

   while (temp->next != head)
   {
      printf("%d->", temp->data);
      temp = temp->next;
   }
      printf("%d\n", temp->data);
}

