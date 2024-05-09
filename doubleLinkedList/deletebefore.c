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
void deleteNode(node_t**, int);

int  main()
{
   int pos;
   node_t* head = NULL;

   insertNode(&head, 10);
   insertNode(&head, 20);
   insertNode(&head, 30);
   insertNode(&head, 40);
   insertNode(&head, 50);
   insertNode(&head, 60);
   insertNode(&head, 70);

   scanf("%d", &pos);
   deleteNode(&head, pos);
   printNode(head);
}

node_t* createNode(int data)
{
   node_t* newNode;

   newNode = (node_t*)malloc(sizeof (node_t*));

   if (newNode == NULL)
   {
      printf("Memory allocation failed!");
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
      return;
   }
   
   node_t* temp = *head;

   while (temp->next != NULL)
   {
      temp = temp->next;
   }

   newNode->prev = temp;
   temp->next = newNode;
}

void printNode(node_t* head)
{
   node_t* temp;
  temp = head;

 while (temp->next != NULL)
 {
    printf("%d->", temp->data);
    temp = temp->next;
 } 
    printf("%d->NULL\n", temp->data);

 while (temp->prev != NULL)
 {
    printf("%d->", temp->data);
    temp = temp->prev;
 } 
    printf("%d->HEAD\n", temp->data);
}

void deleteNode(node_t** head, int pos)
{
   int inc = 0;
   node_t* temp = *head;
   node_t* temp1 = *head;

   if ( pos == 1)
   {
     *head = temp->next;
     (*head)->prev = NULL;
   }
   else
   {
      while (temp-> next != NULL)
      {
	 if (inc == pos-2)
	 {
	    break;
	 }
	 temp = temp->next;
	 inc++;
      }
      inc = 0;
      while (temp1-> next != NULL)
      {
	 if (inc == pos-1)
	 {
	    temp->next = temp1->next;
	    temp1 = temp1->next;
	    break;
	 }
	 temp1 = temp1->next;
	 inc++;
      }
      temp1->prev = temp;
   }
}

