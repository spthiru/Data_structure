#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* prev;
   struct Node* next;
};

typedef struct Node node_t;

node_t* createNode(int);
void insertNode(node_t**, int);
void printNode(node_t*);
void circularLink(node_t**);
int main()
{
   node_t* head = NULL;

   insertNode(&head, 10);
   insertNode(&head, 20);
   insertNode(&head, 30);
   insertNode(&head, 40);
   insertNode(&head, 50);
   insertNode(&head, 60);
   insertNode(&head, 70);

   //circularLink(&head);
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
   newNode->prev = NULL;
   newNode->next = NULL;

   return newNode; 
}

void insertNode(node_t** head, int data)
{
   node_t* newNode = createNode(data);

   if (*head == NULL)
   {
      *head = newNode;
      newNode->prev = *head;
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
   (*head)->prev = newNode;
   newNode->prev = temp;
}

void printNode(node_t* head)
{
   node_t* temp;
   temp = head;

   while(temp->next != head)
   {
      
      
      printf("%d->", temp->data);
      temp = temp->next;       
   }
      printf("%d\n", temp->data);

   while(temp->prev != head)
   {
      printf("%d->", temp->data);
      temp = temp->prev; 
   }
      printf("%d->", temp->data);
      temp = temp->prev; 
      printf("%d\n", temp->data);
}

/*void circularLink(node_t** head)
{
   node_t* temp = *head;
   node_t* temp1 = *head;
   printf("%p\n", temp);
   printf("%p\n", temp1);

   while(temp->next != NULL)
   {
      temp = temp->next;
   }
   (*head)->prev = temp;
   temp->next = *head;
}*/
