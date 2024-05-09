#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

typedef struct Node node_t;

void insertData(node_t**, int);
node_t* createNode(int);
void insertPosition(node_t*, int, int);
void printList(node_t*);


int main()
{
   int pos;
   node_t* head = NULL;

   insertData(&head, 10);
   insertData(&head, 20);
   insertData(&head, 30);
   insertData(&head, 40);
   insertData(&head, 50);
   insertData(&head, 60);
   printList(head);
   printf("Enter the position:");
   scanf("%d", &pos);
   insertPosition(head, 70, pos);
   printList(head);
}
void insertData(node_t** head, int data)
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

   temp->next = newNode;
}

node_t* createNode(int data)
{
   node_t* newNode;

   newNode = (node_t*)malloc(sizeof(node_t));

   if(newNode == NULL)
   {
      printf("Memory allocation failed!\n");
      exit(-1);
   }

   newNode->data = data;
   newNode->next = NULL;

   return newNode;
}
void insertPosition(node_t* head, int data, int pos)
{
   int inc = 0;
   node_t* newNode = createNode(data);
   node_t* temp;

   temp = head;

   while (temp->next != NULL)
   {
      if(inc == pos)
      {
	 node_t* currentAdrr;
	 currentAdrr = temp->next;
	 temp->next = newNode;
	 newNode->next = currentAdrr;
      }
      temp = temp->next;
      inc++;
   }

}
void printList(node_t* head)
{
   node_t* temp;
   temp = head;

   while (temp->next != NULL)
   {
      printf("%d->",temp->data);
      temp = temp->next;
   }
   printf("\n");
}
