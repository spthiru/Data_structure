#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

typedef struct Node node_t;

void insertAtEnd(node_t**, int);
node_t* createNode(int);
void printList(node_t*);

int main()
{
   node_t* head = NULL;

   insertAtEnd(&head, 10);
   insertAtEnd(&head, 20);
   printList(head);
}

node_t* createNode(int data)
{
   node_t* newNode;
   newNode = (node_t*) malloc(sizeof(node_t));
   if(newNode == NULL)
   {
      printf("Memory allocation failed!\n");
      exit(-1);
   }
   
   newNode->data = data;
   newNode->next = NULL;

   return newNode;
}

void insertAtEnd(node_t** head, int data)
{
   node_t* newNode = createNode(data);

   if(*head == NULL)
   {
      *head = newNode;
      return;
   }

   node_t* temp = *head;
   while(temp->next != NULL)
   {
      temp = temp->next;
   }

   temp->next = newNode;
}
void printList(node_t* head)
{
   node_t* temp;
   temp = head;

   while(temp->next != NULL)
   {
      printf("%d\n",temp->data);
      temp = temp->next;
   }
}
