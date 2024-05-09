#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

typedef struct Node node_t;

void insertNode(node_t**, int);
node_t* createNode(int);
void insertPosition(node_t**, int , int);
void printList(node_t*);

int main()
{
   int pos;
   node_t* head = NULL;

   insertNode(&head, 10);
   insertNode(&head, 20);
   insertNode(&head, 30);
   insertNode(&head, 40);
   insertNode(&head, 50);
   insertNode(&head, 60);
   printList(head);

   printf("Enter the position to insert : ");
   scanf("%d", &pos);
   insertPosition(&head, 70, pos);
   printList(head);
}
node_t* createNode(int data)
{
   node_t* newNode;
   newNode = (node_t*)malloc(sizeof(node_t));

   if(newNode == NULL)
   {
      printf("Memory allocation failed!");
      exit(-1);
   }

   newNode->data = data;
   newNode->next = NULL;

   return newNode;
}
void insertNode(node_t** head, int data)
{
   node_t* newNode = createNode(data);
   node_t* temp = *head;

   if(*head == NULL )
   {
      *head = newNode;
      return;
   }

   while(temp->next != NULL)
   {
      temp = temp->next;
   }

   temp->next = newNode;
}
void insertPosition(node_t** head, int data, int pos)
{
   int inc;
   node_t* newNode = createNode(data);
   node_t* temp = *head;

   if(pos == 0)
   {
      *head = newNode;
      newNode->next = temp;
   }
   else if(pos != 0)
   {
      inc = 0;
      while(temp->next != NULL)
      {
	 if (inc == (pos-1))
	 {
	    node_t* oldAdrr;
	    oldAdrr = temp->next;
	    temp->next = newNode;
	    newNode->next = oldAdrr;
	 }
	 temp = temp->next;
	 inc++;
      }
   }
}
void printList(node_t* head)
{
   node_t* temp;
   temp = head;

   while(temp->next != NULL)
   {
      printf("%d->",temp->data);
      temp = temp->next;
   }
   printf("\n");
}
