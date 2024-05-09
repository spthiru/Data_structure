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
void insertAfter(node_t**, int, int);
void printList(node_t*);

int main()
{
   int position;

   node_t* head = NULL;

   insertNode(&head, 10);
   insertNode(&head, 20);
   insertNode(&head, 30);
   insertNode(&head, 40);
   insertNode(&head, 50);

   scanf("%d", &position);
   insertAfter(&head, 70, position);
  printList(head);
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

void printList(node_t* head)
{
   node_t* temp;
   temp = head;

   while (temp->next != NULL)
   {
      printf("%d->", temp->data);
      temp = temp->next;
   }
   printf("%d->null\n", temp->data);

   while (temp->prev != NULL)
   {
      printf("%d->", temp->data);
      temp = temp->prev;
   }
   printf("%d->head\n", temp->data);
}
void insertAfter(node_t** head, int data, int pos)
{
   int inc = 0;
   node_t* newNode = createNode(data);

   node_t* temp = *head;
   node_t* temp1 = *head;

   while (temp1->next != NULL)
   {
      if(inc == pos)
      {
	 newNode->next = temp1->next;
      	 temp1->next = newNode;
	 break;
      }
      temp1 = temp1->next;
      inc++;
   }
   inc = 0;
   while (temp->next != NULL)
   {
      temp = temp->next;
      if (inc == pos+1)
      {
	 newNode->prev = temp->prev;
	 temp->prev = newNode;
	 break;
      }
      inc++;
   }
}
